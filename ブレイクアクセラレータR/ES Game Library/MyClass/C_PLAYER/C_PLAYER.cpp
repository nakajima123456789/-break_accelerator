#include "C_PLAYER.h"
#include "../C_INPUT/C_INPUT.h"
#include "../INFORMATION/INFORMATION.h"

CPlayer::CPlayer(Vector3  _pos)
{
	transform.position = (_pos);
	this->transform.rotation.y += 180;
};

void CPlayer::Init()
{
	//オリジナルのプレイヤークラスにアクセス用
	player_state_processor.player_manager = this;
	player_state_processor.ChangeState(new CPlayer::IDOL(&player_state_processor));

	player_model.SetModel((_T("jiki_car//jiki_car3_a.X")));

	IPlayerParametor::Instance().CreateParametor("player");

	_hitbox.reset(new HitBox("player"));
	_hitbox->SetHitBoxScale(0.25);

	_iplayer_data.reset(new IPlayerData);
}


void CPlayer::IsHitObjectsDraw()
{
	_hitbox->SetHitBoxPosition(this->transform.position);
	_hitbox->Draw3D();
}

CPlayer::~CPlayer()
{
	
};

void CPlayer::Update()
{
	transform.position.z += Input.GetPadInput(5) ? 0.12f : 0.25f;//移動の速さ
	
//	transform.position.z += Input.GetKeyState().IsKeyDown(Keys_Up) ? 0.4f : 0.3f;//移動の速さ

	this->player_state_processor.Update();
}

void CPlayer::Draw3D()
{
	this->transform.position.x = clamp(transform.position.x, -1.3f, 1.3f);
	player_model.SetPosition(this->transform.position);

	_iplayer_data->SetPlayerPosition("player", this->transform.position);

	IsHitObjectsDraw();

	this->transform.rotation.z = rotation;

	player_model.SetRotation(this->transform.rotation);
	player_model.SetScale(this->transform.scale);
	player_model.Draw();
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
		if (_direction_tag == "RIGHT") { sign = 1; }
		else { sign = -1; };
		_owner->player_manager->speed    += (0.006f * sign);
	};

	auto&& hit_box = _owner->player_manager->_hitbox->Get_Tag_HitBox("Gate_R");
	MODEL  hit_model = hit_box->Get_Tag_Model();

	float distance_left  = FLT_MAX;
	float distance_right = FLT_MAX;

	hit_model->IntersectRay(_owner->player_manager->transform.position, Vector3_Left,  &distance_left);
	hit_model->IntersectRay(_owner->player_manager->transform.position, Vector3_Right, &distance_right);
	
	float min_distance = distance_left > distance_right ? distance_right : distance_left;

	if (min_distance >= 0.25f)
	{
	   _owner->player_manager->transform.position.x += Input.GetArrowpadVector().x * 0.05f;
	}
	else 
	{
		int num = distance_left == FLT_MAX ? -1 : 1;
		_owner->player_manager->transform.position.x += 0.015 * num;
	}


	if (Input.AxisStateX() == 0) 
	{
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
		return;
	}
	return;
}

void CPlayer::RUNKEY::Update()
{
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
	}
	if (Input.GetKeyState().IsKeyDown(Keys_Left)) {
		AxisStateMove("LEFT");
	}
	_owner->player_manager->rotation = _owner->player_manager->clamp(_owner->player_manager->rotation, -14, 14);

	_owner->player_manager->transform.position.x += _owner->player_manager->speed;


	if (Input.GetArrowkeyVector().x == 0)
	{
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
		return;
	}

}

void CPlayer::DAMAGE::Update()
{

	return;
}
