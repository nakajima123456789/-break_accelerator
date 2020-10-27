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

	Material mtrl; Color _color = Vector3(1.0f, 1.0f, 1.0f);

	mtrl.Diffuse  = _color;
	mtrl.Ambient = _color;
	mtrl.Specular = _color;
	mtrl.Emissive = _color;
	mtrl.Power = 1.0f;

	player_model = GraphicsDevice.CreateModelFromFile(_T("model3D/自機/jiki_b.X"));
	player_model->SetPosition(jiki_x, 0.0f, jiki_z);
	player_model->SetRotation(0.0f, 180.0f, rot);
	jiki_x = 0.0f;
	jiki_z = 0.0f;
	speed = 0.0f;
	rot = 0.0f;
	kt = 0;
	player_model->SetScale(0.05f);
	player_model->SetMaterial(mtrl);



	c_hitbox.reset(new HitBox);
	this->c_hitbox->Init();
	this->c_hitbox->Settags("player");

	this->c_hitbox->SetHitBoxScale(0.5f);
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
	Vector3 pad=Input.GetArrowpadVector();
	Vector3 key = Input.GetArrowkeyVector();

	
	player_model->SetPosition(jiki_x, 0.1f, jiki_z);
	player_model->SetRotation(0, 180, rot+kt);
	
	speed = 0.0f;
	
	if (key.x < 0||pad.x<0) {
		speed += 0.05f;
		jiki_x -= speed;
		kt -= 0.5;
		
		if (kt <= -10) {
			kt = -10;
		}
	}
	else if (key.x>0||pad.x>0) {
		speed += 0.05f;
		jiki_x += speed;
		kt += 0.5;
		if (kt >= 10) {
			kt = 10;
		}
	}
	
		
	
		
	
	if (speed >= 0.5) {
		speed = 0.5;
	}


	if (jiki_x >= 1) {
		jiki_x = 1;
	}
	if (jiki_x < -1) {
		jiki_x = -1;
	}
	
	float speed_z = 0.15f;
	jiki_z += 0.11;
	if (Input.GetPadInput(5)||key.z>0) {
		speed_z += 0.05f;
		jiki_z+= speed_z;
	}
	
	if (speed_z <= 2) {
		speed_z = 2;
	}
		
		
	
	
	this->player_state_processor.Update();
	nomostate.player_pos = player_model->GetPosition();
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

