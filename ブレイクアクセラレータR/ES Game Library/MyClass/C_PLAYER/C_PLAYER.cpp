#include "C_PLAYER.h"

CPlayer::CPlayer(Vector3  _pos)
{
	transform.position = _pos;
};

void CPlayer::Init()
{
	//�I���W�i���̃v���C���[�N���X�ɃA�N�Z�X�p
	player_state_processor.player_manager = this;
	player_state_processor.ChangeState(new CPlayer::IDOL(&player_state_processor));

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

}


void CPlayer::IDOL::Update()
{

	return;
}

void CPlayer::RUN::Update()
{
	
	return;
}

void CPlayer::DAMAGE::Update()
{

	return;
}

