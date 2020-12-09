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

	p_model.SetModel((_T("jiki_car//jiki_car3_a.X")));

	IPlayerParametor::Instance().CreateParametor("player");

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);
	p_hitbox->Settags("player");
	p_hitbox->transform.localposition.y += 0.1f;

	p_velocity = new Velocity();
	this->ChildObj_AddList((ChildObjRef)p_velocity);
	p_velocity->gameObject = this;

	_iplayer_data.reset(new IPlayerData);
}

CPlayer::~CPlayer()
{
	
};

void CPlayer::Update()
{
	this->player_state_processor.Update();
}

void CPlayer::Draw3D()
{
	p_model.SetPosition(this->transform.position);
	p_model.SetRotation(transform.rotation);

	p_model.Draw();

	_iplayer_data->SetPlayerPosition("player", this->transform.position);
}


void CPlayer::IDOL::Update()
{

	return;
}

void CPlayer::RUNPAD::Update()
{

	return;
}

void CPlayer::RUNKEY::Update()
{

	return;
}

void CPlayer::DAMAGE::Update()
{

	return;
}
