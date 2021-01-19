#include "Player.h"

#include "../PlayerDataBase/PlayerDataBase.h"
#include "../UiDataBase/UiDataBase.h"

 /**
  * @brief コンストラクタ(初期座標)
  * @param[in] (なし)
  * @return    (なし)
  */
Player::Player(Vector3  _position)
{
	p_player_processor.p_player = this;
	p_player_processor.ChangeState(new Player::IDOL(&p_player_processor));

	transform.position          = _position;
	this->transform.rotation.y += 180;
};
	
/**
  * @brief 初期化(ファイル読み込み、データベース生成)
  * @param[in] (なし)
  * @return    (なし)
  */
void Player::Init()
{
	p_model = GraphicsDevice.CreateModelFromFile(_T("jiki_car//jiki_car3_a.X"));
	shader  = GraphicsDevice.CreateEffectFromFile(_T("FX//ShaderPlayer.hlsl"));

	SPRITE texture = GraphicsDevice.CreateSpriteFromFile(_T("jiki_car//jiki_car3.png"));
	shader->SetTexture("modelTex1", *texture);

	p_model->SetMaterial(SetMaterial());

	SetAccelaretorParameter();

	auto&& p_distance = new Distance();
	this->ChildObj_AddList((ChildObjRef)p_distance);
	p_distance->Settags("player");

	gameCamera = (new GameCamera);
	this->ChildObj_AddList((ChildObjRef)gameCamera);

	auto&& p_velocity = new Velocity();
	this->ChildObj_AddList((ChildObjRef)p_velocity);

	p_accelaretor = new Accelaretor();
	p_accelaretor->SetAccelaretorParameter(accelaretor_parameter);
	this->ChildObj_AddList((ChildObjRef)p_accelaretor);

	p_effekseer = new MngEffekseer();
	effect_item = p_effekseer->LoadEffekseer(_T("NitoriBox//qqqqqqq.efk"));
	this->ChildObj_AddList((ChildObjRef)p_effekseer);
}

Player::~Player()
{
	PlayerDataBase.ResetIPlayerDataBase();
};

/**
  * @brief 更新(当たり判定、ステートパターンの更新、スタミナの管理)
  * @param[in] (なし)
  * @return    (なし)
  */
void Player::Update()
{
	if(Input.GetPadInputDown(0,5) && UiDataBase.GetItemSize() >= 4){ SetAccelaretor();}

	this->p_player_processor.Update();
}


Player::IDOL::IDOL(CPlayerStateProcessor* owner) : _owner(owner)
{
	_owner->p_player->p_hitbox = new HitBox();
	_owner->p_player->ChildObj_AddList((ChildObjRef)_owner->p_player->p_hitbox);
	_owner->p_player->p_hitbox->Settags("player");
	_owner->p_player->p_hitbox->transform.localposition.y += 0.1f;
}

void Player::IDOL::Update()
{

}

Player::DAMAGE::DAMAGE(CPlayerStateProcessor* owner) : _owner(owner) 
{
	if (_owner->p_player->p_hitbox != nullptr) { _owner->p_player->p_hitbox->Remove(); };
}

void Player::DAMAGE::Update()
{
	_owner->p_player->alpha ^= 1; _owner->p_player->color_r = 1;

	if (this->ChangeExitState())
	{
		_owner->p_player->alpha = 1; _owner->p_player->color_r = 0;
		_owner->p_player->p_player_processor.ChangeState(new Player::IDOL(&_owner->p_player->p_player_processor));
		return;
	}
}

void Player::DrawAlpha3D()
{
	p_model->SetPosition(this->transform.position);
	p_model->SetRotation(transform.rotation);

	shader->SetTechnique("Sobel");
	Matrix world    = p_model->GetWorldMatrix();
	Matrix viewproj = gameCamera->GetCamera().GetViewProjectionMatrix();

	shader->SetParameter("wvp", world * viewproj);
	shader->SetParameter("alpha",     alpha); 
	shader->SetParameter("r_color", color_r);

	p_model->Draw(shader);

	PlayerDataBase.SetPlayerPosition(this->transform.position);
}

void Player::SetAccelaretorParameter()
{
	accelaretor_parameter._max_velocity   = 0.6f;
	accelaretor_parameter._min_velocity   = 0.3f;
	accelaretor_parameter._start_velocity = 0.0f;
}

void Player::SetAccelaretor()
{
	if (p_accelaretor != nullptr) { p_accelaretor->Remove(); };

	p_accelaretor = new Accelaretor();
	p_accelaretor->SetAccelaretorParameter(accelaretor_parameter);
	this->ChildObj_AddList((ChildObjRef)p_accelaretor);

	UiDataBase.SetItemSize(-3);
}

void Player::AttackHit(int attack_type)
{
	observer.IsCollision(attack_type);
	enum ATTACKTYPE {DAMAGE,ITEM,GAMEOVER, RECOVERY};
	switch (attack_type)
	{
	case ATTACKTYPE::DAMAGE:
		p_player_processor.ChangeState(new Player::DAMAGE(&p_player_processor));
		break;
	case ATTACKTYPE::ITEM:
		p_effekseer->PlayEffekseer(effect_item);
		break;
	case ATTACKTYPE::RECOVERY:
		p_player_processor.ChangeState(new Player::RECOVERY(&p_player_processor));
		break;
	}
}

Player::RECOVERY::RECOVERY(CPlayerStateProcessor* owner) : _owner(owner)
{
	if (_owner->p_player->p_hitbox != nullptr) { _owner->p_player->p_hitbox->Remove(); };
}

void Player::RECOVERY::Update()
{
	if (this->ChangeExitState()){
		_owner->p_player->p_player_processor.ChangeState(new Player::IDOL(&_owner->p_player->p_player_processor));
		return;
	}
}

Player::GETITEM::GETITEM(CPlayerStateProcessor* owner) : _owner(owner)
{
	if (_owner->p_player->p_hitbox != nullptr) { _owner->p_player->p_hitbox->Remove(); };

	_owner->p_player->p_effekseer->PlayEffekseer(_owner->p_player->effect_item);
}

void Player::GETITEM::Update()
{
	if (this->ChangeExitState()) {
		_owner->p_player->p_player_processor.ChangeState(new Player::IDOL(&_owner->p_player->p_player_processor));
		return;
	}
}
