#include "C_PLAYER.h"
#include "../C_INPUT/C_INPUT.h"

Vector3 CPlayer::test_pos = Vector3_Zero;

CPlayer::CPlayer(Vector3  _pos)
{
	transform.position = _pos + Vector3(0,0,1);
};

void CPlayer::Init()
{
	//オリジナルのプレイヤークラスにアクセス用
	player_state_processor.player_mng = this;
	player_state_processor.ChangeState(new CPlayer::RUN(&player_state_processor));

	test_model = GraphicsDevice.CreateModelFromFile(_T("CubeModel//cube.X"));

	Material mtrl;

	Color _color = Color(1.0f, 1.0f, 1.0f);

	mtrl.Diffuse = _color;
	mtrl.Ambient = _color;
	mtrl.Specular = _color;
	mtrl.Emissive = _color;
	mtrl.Power = 1.0f;

	test_model->SetMaterial(mtrl);
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

	test_pos = this->transform.position += Input.GetArrowkeyVector() * 0.1;

	this->player_state_processor.Update();
}

void CPlayer::Draw3D()
{
	test_model->SetPosition(this->transform.position);
	test_model->SetRotation(this->transform.rotation);
	test_model->SetScale(this->transform.scale);
	test_model->Draw();
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

