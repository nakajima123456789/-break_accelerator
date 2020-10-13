#include "C_PLAYER.h"
#include "../C_INPUT/C_INPUT.h"

CPlayer::CPlayer(Vector3  _pos)
{
	transform.position = _pos;
};

void CPlayer::Init()
{
	//オリジナルのプレイヤークラスにアクセス用
	player_state_processor.player_mng = this;
	player_state_processor.ChangeState(new CPlayer::RUN(&player_state_processor));

	
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

