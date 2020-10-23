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

	player_model = GraphicsDevice.CreateModelFromFile(_T("model3D/自機/jiki2.X"));
	player_model->SetPosition(jiki_x, 0.0f, jiki_z);
	jiki_x = 0.0f;
	jiki_z = 0.0f;
	speed = 0.0f;
	player_model->SetScale(0.02f);
	player_model->SetRotation(0, 180, 0);
	c_hitbox.reset(new HitBox);
	this->c_hitbox->Init();
	this->c_hitbox->Settags("player");

	this->c_hitbox->SetHitBoxScale(1.5f);

	Material material;
	Color material_color = Vector3(0.5f, 0.5f, 0.5f);
	material.Diffuse = material_color;
	material.Ambient = material_color;
	material.Specular = material_color;
	player_model->SetMaterial(material);
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
		player_model->SetPosition(jiki_x, 0.0f, jiki_z);
	this->c_hitbox->SetHitBoxPosition(this->player_model->GetPosition());

	motostate.player_pos = this->player_model->GetPosition();

	Vector3 pad=Input.GetArrowpadVector();
	Vector3 key = Input.GetArrowkeyVector();

	if (key.x < 0||pad.x<0) {
		speed += 0.005f;
		jiki_x -= speed;
	}
	else {
		speed = 0.05f;
	}
	 if (key.x>0||pad.x>0) {
		speed += 0.005f;
		jiki_x += speed;
	}
	else {
		speed = 0.05f;
	}


	if (jiki_x >= 0.8) {
		jiki_x = 0.8;
	}
	if (jiki_x < -0.6) {
		jiki_x = -0.6;
	}
	float speed_z = 0.0f;
	if (Input.GetPadInput(5)||key.z>0) {
		speed_z += 0.08f;
		jiki_z += speed_z;
	}
	else
	{
		jiki_z += 0.5f;
	
	}
	

	this->player_state_processor.Update();
}

void CPlayer::Draw3D()
{
	player_model->Draw();

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

