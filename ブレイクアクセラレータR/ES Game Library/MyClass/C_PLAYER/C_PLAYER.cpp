#include "C_PLAYER.h"
#include "../C_INPUT/C_INPUT.h"
#include "../INFORMATION/INFORMATION.h"

CPlayer::CPlayer(Vector3  _pos)
{
	transform.position = (_pos + Vector3(0.f,0.3f,0.f));
	this->transform.rotation.y += 180;
	// 自分をリストに登録
		observer.addListener(this);
}
CPlayer::~CPlayer()
{
	//自分をリストから削除
	observer.removeListener(this);
}
;

void CPlayer::Init()
{
	//オリジナルのプレイヤークラスにアクセス用
	player_state_processor.player_manager = this;
	player_state_processor.ChangeState(new CPlayer::IDOL(&player_state_processor));

	IsHitObjectsInit();


	c_hitbox->main_hitbox = c_hitbox->Get_Tag_Model();

	player_model = GraphicsDevice.CreateModelFromFile(_T("model3D//自機//jiki_new1k.X"));
    player_model->SetMaterial(SetMaterial(Color(255.0f, 255.0f, 255.0f)));

	effcseer_test = EffekseerMgr.LoadEffekseer(_T("軌道//軌道.efk"));

	gia = GraphicsDevice.CreateSpriteFromFile(_T("UI/gear/タテギアゲージ2.png"));
	gia2 = GraphicsDevice.CreateSpriteFromFile(_T("UI/gear/タテギアゲージ4.png"));


	nobi = 100.0f;     gage = Color(255, 255, 255);

}


Material CPlayer::SetMaterial(Color _color)
{
	Material mtrl;

	mtrl.Diffuse  = _color;
	mtrl.Ambient  = _color;
	mtrl.Specular = _color;
	mtrl.Emissive = _color;
	mtrl.Power = 1.0f;

	return mtrl;
}

int  CPlayer::IsHitObjectsInit()
{
	c_hitbox.reset(new HitBox);
	c_hitbox->Init();
	c_hitbox->Settags("player");

	c_hitbox->SetHitBoxScale(0.2f);

	return 0;
}

void CPlayer::IsHitObjectsDraw()
{
	c_hitbox->main_hitbox = c_hitbox->Get_Tag_Model();
	c_hitbox->SetHitBoxPosition(this->transform.position);
	c_hitbox->Draw3D();
}


void CPlayer::Update()
{
	
	transform.position.z += Input.GetPadInput(5) ? 0.3f : 0.15f;//移動の速さ

	transform.position.z += Input.GetKeyState().IsKeyDown(Keys_Up) ? 0.3f : 0.15f;//移動の速さ
	
	EffekseerMgr.PlayEffekseer(effcseer_test, transform.position+ Vector3(0,0,5));

	if (transform.position.z >=  579) { monostate._game_clear_flag = true; }
	
	if (nobi <= 68) {gage = Color(0, 255, 0);	}
	if (nobi <= 37) {gage = Color(255, 255, 0); }
	


	
	this->player_state_processor.Update();
}

void CPlayer::Draw3D()
{

	this->transform.position.x = clamp(transform.position.x, -3.0f, 3.0f);
	player_model->SetPosition(this->transform.position);
	monostate.player_pos = this->transform.position;

	IsHitObjectsDraw();

	this->transform.rotation.z = rotation;

	player_model->SetRotation(this->transform.rotation);
	player_model->SetScale(this->transform.scale * 1.0f);
	player_model->Draw();
	
}

void CPlayer::OnCollisionDamage()
{
	nobi += 16.0f;
}

void CPlayer::OnCollisionClear()
{
	nobi += 16.0f;
}

void CPlayer::OnCollisionGage()
{
	nobi -= 32.0f;
}
void CPlayer::Draw2D()
{
	SpriteBatch.Draw(*gia2, Vector3(1000.0f, 0.0f, 0.0f), Rect(0, 0, 35, 132), Color(gage));
	SpriteBatch.Draw(*gia, Vector3(1000.0f, nobi, 0.0f), Rect(0, nobi, 35, 132), Color(gage));
}


void CPlayer::IDOL::Update()
{
	_owner->player_manager->speed = 0.0f;

	_owner->player_manager->rotation = _owner->player_manager->rotation > 0 ? _owner->player_manager->rotation = max(_owner->player_manager->rotation -= 0.2f, 0) : _owner->player_manager->rotation = min(_owner->player_manager->rotation += 0.2f, 0);

	

	if (Input.AxisFlag()){
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::RUNPAD(&_owner->player_manager->player_state_processor));
		return;
	}

	if (Input.GetArrowkeyVector().x != 0)
	{
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::RUNKEY(&_owner->player_manager->player_state_processor));
		return;
	}

	return;
}

void CPlayer::RUNPAD::Update()
{
	auto&& AxisStateMove = [this](std::string _direction_tag)->void {
		int sign;
		if (_direction_tag == "RIGHT") { sign = 1; } else { sign = -1; };
		_owner->player_manager->rotation +=   (0.8000f * sign * 1.0f * 1.0f);
		_owner->player_manager->speed    +=   (0.0006f * sign * 1.0f * 1.0f);
		
		return;
	};



	if (Input.AxisStateX() >= 0.3f) {
		AxisStateMove("RIGHT");
		_owner->player_manager->rotation = _owner->player_manager->clamp(_owner->player_manager->rotation, -14, 14);

		if (Input.GetPadInputDown(6)) {
			this->_owner->player_manager->speed += 0.1f;
			
		}
	}
	if (Input.AxisStateX() <= -0.3f) {
		AxisStateMove("LEFT");
		if (Input.GetPadInputDown(6)) {
			this->_owner->player_manager->speed -= 0.1f;
		}
	}
	if (Input.AxisStateX() == 0.0f &&Input.GetKeyState().IsKeyUp(Keys_Right) && Input.GetKeyState().IsKeyUp(Keys_Left)){
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
		return;
	}
	

	_owner->player_manager->transform.position.x += Input.GetArrowpadVector().x * 0.008f + _owner->player_manager->speed;

	return;
}

void CPlayer::RUNKEY::Update()
{
	bool rot = false;
	auto&& AxisStateMove = [this](std::string _direction_tag)->void {
		int sign;
		if (_direction_tag == "RIGHT") { sign = 1; }
		else { sign = -1; };
		_owner->player_manager->rotation += (0.8000f * sign * 1.0f * 1.0f);
		_owner->player_manager->speed    += (0.001f * sign * 1.0f * 1.0f);
		
		return;
	};

	if (Input.GetKeyState().IsKeyDown(Keys_Right)) {
		AxisStateMove("RIGHT");
		if (Input.GetKeyBuffer().IsPressed(Keys_Space)) {
			this->_owner->player_manager->speed+=0.1f;
			rot = true;
		}
	}
	if (Input.GetKeyState().IsKeyDown(Keys_Left)) {
		AxisStateMove("LEFT");
		if (Input.GetKeyBuffer().IsPressed(Keys_Space)) {
			this->_owner->player_manager->speed-=0.1f;
			
		}
	}
	
	if (rot == true) { _owner->player_manager->transform.rotation.z += 2; }

	_owner->player_manager->transform.position.x += Input.GetArrowkeyVector().x * 0.008f + _owner->player_manager->speed;

	if (Input.GetArrowkeyVector().x == 0)
	{
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
		return;
	}
	_owner->player_manager->rotation = _owner->player_manager->clamp(_owner->player_manager->rotation, -14, 14);

}

void CPlayer::DAMAGE::Update()
{
	return;
}

double CPlayer::clamp(double x, double low, double high)
{
	ASSERT(low <= high && "最小値 <= 最大値");
	return min(max(x, low), high);
}

bool CPlayer::FrameTimeObsever(int _index)
{
	_time++;
	if (_time % _index == 0) { return true; }
	return false;
}

