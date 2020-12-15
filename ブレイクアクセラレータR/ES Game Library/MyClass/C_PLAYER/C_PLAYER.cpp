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
	player_state_processor.ChangeState(new CPlayer::NOMAL(&player_state_processor));

	p_model.SetModel((_T("jiki_car//jiki_car3_a.X")));

	IPlayerParametor::Instance().CreateParametor("player");

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);
	p_hitbox->Settags("player");
	p_hitbox->transform.localposition.y += 0.1f;

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

	auto&& itr = this->p_childObjects.rbegin();
	if (typeid(*((*itr).get())) == typeid(RotationMove)) {p_model.SetDirection(transform.direction);}

	p_model.Draw();

	_iplayer_data->SetPlayerPosition("player", this->transform.position);
}

void CPlayer::ChangeMoveType(PLAYER_MOVE_TYPE move_type)
{
	if (this->p_childObjects.size() > MOVE_TYPE_MAX_SIZE)	{p_childObjects.pop_back();};

	switch (move_type)
	{
	case PLAYER_MOVE_TYPE::NOMAL:
		p_velocity = new Velocity();
		this->ChildObj_AddList((ChildObjRef)p_velocity);
		p_velocity->gameObject = this;
		break;
	case PLAYER_MOVE_TYPE::ROTATION:
		p_rotation = new RotationMove();
        this->ChildObj_AddList((ChildObjRef)p_rotation);
        p_rotation->gameObject = this;
		break;
	default:
		break;
	}
}

void CPlayer::ChangeStateType(PLAYER_MOVE_TYPE move_type)
{
	if (state_type != move_type){
		switch (move_type){
		case PLAYER_MOVE_TYPE::NOMAL:
			player_state_processor.ChangeState(new CPlayer::NOMAL(&player_state_processor));
			break;
		case PLAYER_MOVE_TYPE::ROTATION:
			player_state_processor.ChangeState(new CPlayer::ROTATION(&player_state_processor));
			break;
		}
		state_type = move_type;
    }
}


void CPlayer::NOMAL::Update()
{
	if (GetTime() == 3){ _owner->player_manager->ChangeMoveType(PLAYER_MOVE_TYPE::NOMAL);   }
	return;
}

void CPlayer::ROTATION::Update()
{
	if (GetTime() == 3){ _owner->player_manager->ChangeMoveType(PLAYER_MOVE_TYPE::ROTATION);}
	return;
}

void CPlayer::DAMAGE::Update()
{
	return;
}
