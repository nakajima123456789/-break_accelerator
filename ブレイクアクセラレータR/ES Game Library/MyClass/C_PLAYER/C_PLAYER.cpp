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

	this->player_model = GraphicsDevice.CreateModelFromFile(_T("CubeModel//cube.X"));
	this->player_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));
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
	this->player_model->SetPosition(this->transform.position);
	this->player_model->SetRotation(this->transform.rotation);
	this->player_model->SetScale(this->transform.scale);
	this->player_model->Draw();
}


void CPlayer::IDOL::Update()
{

	return;
}

void CPlayer::RUN::Update()
{

	_owner->player_mng->transform.position.x += (Input.GetArrowkeyVector().x * 0.05);
	_owner->player_mng->transform.position.z += (Input.GetArrowkeyVector().z * 0.05);

	return;
}

void CPlayer::DAMAGE::Update()
{

	return;
}

