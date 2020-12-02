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

void CPlayer::Init()
{
    //オリジナルのプレイヤークラスにアクセス用
    player_state_processor.player_manager = this;
    player_state_processor.ChangeState(new CPlayer::IDOL(&player_state_processor));

    IsHitObjectsInit();

    c_hitbox->main_hitbox = c_hitbox->Get_Tag_Model();

    player_model = GraphicsDevice.CreateModelFromFile(_T("model3D//自機//jiki_car3.X"));
    player_model->SetMaterial(SetMaterial(Color(255.0f, 255.0f, 255.0f)));

    effcseer_test = EffekseerMgr.LoadEffekseer(_T("軌道//軌道.efk"));

    gia = GraphicsDevice.CreateSpriteFromFile(_T("UI/gear/タテギアゲージ2.png"));
    gia2 = GraphicsDevice.CreateSpriteFromFile(_T("UI/gear/タテギアゲージ4.png"));

    speed2 = 0;        acc = 0.1;
    nobi = 100.0f;     gage = Color(255, 255, 255);
}


Material CPlayer::SetMaterial(Color _color)
{
    Material mtrl;

	mtrl.Diffuse  = Color(0.0f, 0.0f, 0.0f);
	mtrl.Ambient  = Color(0.0f, 0.0f, 0.0f);
	mtrl.Specular = Color(0.0f, 0.0f, 0.0f);
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);
	mtrl.Power = 0.0f;

    return mtrl;
}

int  CPlayer::IsHitObjectsInit()
{
    c_hitbox.reset(new HitBox);
    c_hitbox->Init();
    c_hitbox->Settags("player");

    return 0;
}

void CPlayer::IsHitObjectsDraw()
{
    c_hitbox->main_hitbox = c_hitbox->Get_Tag_Model();
    c_hitbox->SetHitBoxPosition(this->transform.position);
    c_hitbox->Draw3D();
    c_hitbox->SetHitBoxScale(0.2f);
}

void CPlayer::Update()
{
    if (nobi <= 68) { gage = Color(0, 255, 0);     acc = 0.2f; }
    if (nobi <= 37) { gage = Color(255, 255, 0);   acc = 0.3f; }

    transform.position.z += 0.2f + speed2;  speed2 -= 0.0025f;
    if (speed2 <= 0) { speed2 = 0.0f; }
    if (speed2 >= acc){speed2 = acc;}
    if (Input.GetKeyState().IsKeyDown(Keys_Up)||Input.GetPadInput(5)) { speed2 += 0.008; }
    
    //if (transform.position.z >=  772) { monostate._game_clear_flag = true; }

    if (transform.position.z >= 100) { monostate._game_clear_flag = true; }

    this->player_state_processor.Update();
}

void CPlayer::Draw3D()
{

    this->transform.position.x = clamp(transform.position.x, -1.3f, 1.3f);
    player_model->SetPosition(this->transform.position);
    monostate.player_pos = this->transform.position;

    IsHitObjectsDraw();

    this->transform.rotation.y= rotation;

	player_model->SetRotation(this->transform.rotation);
	player_model->SetScale(this->transform.scale);
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
    _owner->player_manager->speed = 0;
    //_owner->player_manager->rotation = _owner->player_manager->rotation > 0 ? _owner->player_manager->rotation = max(_owner->player_manager->rotation -= 0.2f, 0) : _owner->player_manager->rotation = min(_owner->player_manager->rotation += 0.2f, 0);

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
        /*_owner->player_manager->rotation +=   (1.5f * sign * 1.0f * 1.0f);*/
        _owner->player_manager->speed    +=   (0.002f * sign * 1.0f * 1.0f);
        return;
    };

    if (Input.AxisStateX() >= 0.3f) {
        AxisStateMove("RIGHT");
        if (Input.GetPadInputDown(6)) {
            this->_owner->player_manager->speed += 0.03f;
        }
    }
    if (Input.AxisStateX() <= -0.3f) {
        AxisStateMove("LEFT");
        if (Input.GetPadInputDown(6)) {
            this->_owner->player_manager->speed -= 0.03f;
        }
    }

    if (Input.AxisStateX() == 0.0f && _owner->player_manager->speed > 0) { _owner->player_manager->speed -= 0.003f; }
    if (Input.AxisStateX() == 0.0f && _owner->player_manager->speed < 0) { _owner->player_manager->speed += 0.003f; }

    if (_owner->player_manager->speed <= 0.002 && _owner->player_manager->speed >= -0.001)
    {
        _owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
        return;
    }
    
    _owner->player_manager->rotation = _owner->player_manager->clamp(_owner->player_manager->rotation, -7, 7);
    _owner->player_manager->speed = _owner->player_manager->clamp(_owner->player_manager->speed, -0.025, 0.025);
    _owner->player_manager->transform.position.x += Input.GetArrowpadVector().x * 0.008f + _owner->player_manager->speed;

    return;
}

void CPlayer::RUNKEY::Update()
{
    auto&& AxisStateMove = [this](std::string _direction_tag)->void {
        int sign;
        if (_direction_tag == "RIGHT") { sign = 1; }
        else { sign = -1; };
        /*_owner->player_manager->rotation += (1.5f * sign * 1.0f * 1.0f);*/
        _owner->player_manager->speed += (0.002f * sign * 1.0f * 1.0f);
        return;
    };

    if (Input.GetKeyState().IsKeyDown(Keys_Right)) {
        AxisStateMove("RIGHT");
        if (Input.GetKeyInputDown(Keys_Space)) {
            _owner->player_manager->speed+=0.02f;
        }
    }
    if (Input.GetKeyState().IsKeyDown(Keys_Left)) {
        AxisStateMove("LEFT");
        if (Input.GetKeyInputDown(Keys_Space)) {
            _owner->player_manager->speed -= 0.02f;
        }
    }
    _owner->player_manager->speed    = _owner->player_manager->clamp(_owner->player_manager->speed, -0.025f, 0.025f);
    _owner->player_manager->rotation = _owner->player_manager->clamp(_owner->player_manager->rotation, -7, 7);
    
    _owner->player_manager->transform.position.x +=   _owner->player_manager->speed;

    if (Input.GetArrowkeyVector().x == 0 && _owner->player_manager->speed >= 0) {_owner->player_manager->speed  -= 0.0035f; }
    if (Input.GetArrowkeyVector().x == 0 && _owner->player_manager->speed < 0)  { _owner->player_manager->speed += 0.0035f; }

    if (_owner->player_manager->speed <=0.002&& _owner->player_manager->speed >= -0.002)
    {
        _owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
        return;
    }
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

