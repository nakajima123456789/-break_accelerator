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

float CPlayer::AccelaretorTime()
{
	if (frame % 60 == 0) { time++; }; frame++;
	return 0.0025f * time;
}

CPlayer::~CPlayer()
{
	
};

void CPlayer::Update()
{
	if (Input.GetKeyState().IsKeyDown(Keys_Up)){ accelaretor = accelaretor + AccelaretorTime() * 0.5f;
		transform.position.z = transform.position.z + accelaretor;
	}
	else 
	{
		if (accelaretor <= 0.3f){accelaretor = 0.3f;}else { accelaretor = accelaretor * 0.99; }
		transform.position.z = transform.position.z + accelaretor;
	};

	this->player_state_processor.Update();
}

void CPlayer::Draw3D()
{
	this->transform.position.x = clamp(transform.position.x, -1.3f, 1.3f);
	player_model.SetPosition(this->transform.position);


	_iplayer_data->SetPlayerPosition("player", this->transform.position);

	player_model.SetRotation(transform.rotation);

	IsHitObjectsDraw();

	player_model.Draw();
}


void CPlayer::IDOL::Update()
{
	_owner->player_manager->speed =  _owner->player_manager->speed * 0.9f;

	_owner->player_manager->transform.position.x += _owner->player_manager->speed;

	_owner->player_manager->time  = 0;
	_owner->player_manager->frame = 0;

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
	if (Input.AxisStateX() >= 0.3f){ speed = speed + _owner->player_manager->AccelaretorTime();}
	else 
	if (Input.AxisStateX() <= 0.3f){ speed = speed - _owner->player_manager->AccelaretorTime();}

	_owner->player_manager->speed = speed;
	_owner->player_manager->transform.position.x = _owner->player_manager->transform.position.x + speed;

	if (Input.AxisStateX() == 0){
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
		return;
	}

	return;
}

void CPlayer::RUNKEY::Update()
{
	if (Input.GetArrowkeyVector().x >= 0.3f){ speed = speed + _owner->player_manager->AccelaretorTime();}
	else
	if (Input.GetArrowkeyVector().x <= 0.3f){ speed = speed - _owner->player_manager->AccelaretorTime();}

	_owner->player_manager->speed = speed;
	_owner->player_manager->transform.position.x = _owner->player_manager->transform.position.x + speed;

	if (Input.GetArrowkeyVector().x == 0){
		_owner->player_manager->player_state_processor.ChangeState(new CPlayer::IDOL(&_owner->player_manager->player_state_processor));
		return;
	}
	
}

void CPlayer::DAMAGE::Update()
{

	return;
}
