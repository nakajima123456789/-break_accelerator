#include "C_PLAYER.h"
#include "../C_SHADER/C_SHADER.h"
#include "../../C_Tonnel.h"
#include "../../CMapMove.h"
#include "../OBSTACLEBASE/ObstacleBase.h"

CPlayer::CPlayer(Vector3  _pos)
{
	transform.position = (_pos);
	this->transform.rotation.y += 180;

	obsever.addListener(this);
};

void CPlayer::Init()
{
	//オリジナルのプレイヤークラスにアクセス用
	p_state_processor.p_player = this;
	p_state_processor.ChangeState(new CPlayer::NOMAL(&p_state_processor));

	p_model = GraphicsDevice.CreateModelFromFile(_T("jiki_car//jiki_car3_a.X"));
	shader = GraphicsDevice.CreateEffectFromFile(_T("FX//ShaderPlayer.hlsl"));

	SPRITE texture = nullptr;
	texture = GraphicsDevice.CreateSpriteFromFile(_T("jiki_car//jiki_car3.png"));
	shader->SetTexture("modelTex1", *texture);

	IPlayerParametor::Instance().CreateParametor("player");

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);p_hitbox->Settags("player");

	p_hitbox->transform.localposition.y += 0.1f;

	p_effekseerMng = new EffekseerMng();
	this->ChildObj_AddList((ChildObjRef)p_effekseerMng);
	p_effekseerMng->transform.localscale = 0.1f;

	auto&& c_distance = new C_Distance();
	this->ChildObj_AddList((ChildObjRef)c_distance);c_distance->IsTagSet("player");

	this->LordEffekseer();

	_iplayer_data.reset(new IPlayerData);
}

void CPlayer::LordEffekseer()
{

}

void CPlayer::GameObjectIsMove()
{
	if (gameObject->gameObject == nullptr){ ChangeMoveType(PLAYER::PLAYERMOVETYPE::NOMAL);
	    return;
	}

	if (typeid(*gameObject->gameObject) == typeid(C_Tonnel)){ChangeMoveType(PLAYER::PLAYERMOVETYPE::ROTATION);};
}

CPlayer::~CPlayer()
{
	obsever.removeListener(this);
};

void CPlayer::Update()
{
	this->p_state_processor.Update();

	GameObjectIsMove();
}

void CPlayer::DrawAlpha3D()
{
	p_model->SetPosition(this->transform.position);

	//データベース更新
	_iplayer_data->SetPlayerPosition("player", this->transform.position);

	p_model->SetRotation(transform.rotation);

	auto&& itr = this->p_childObjects.rbegin();
	if (typeid(*((*itr).get())) == typeid(RotationMove)) {p_model->SetDirection(transform.direction);}

	shader->SetTechnique("Sobel");
	Matrix world    = p_model->GetWorldMatrix();
	Matrix viewproj = CShaderAnimation::camera->GetCamera().GetViewProjectionMatrix();
	shader->SetParameter("wvp", world * viewproj);

	shader->SetParameter("alpha",alpha);
	shader->SetParameter("r_color", color_r);

	p_model->Draw(shader);
}

void CPlayer::ChangeMoveType(PLAYER::PLAYERMOVETYPE move_type)
{
	if (state_type == move_type) return; else 	state_type = move_type;
	if (this->p_childObjects.size() > PLAYER::PLAYERMOVETYPE::PLAYERMOVETYPEMAX)	{p_childObjects.pop_back();}

	switch (move_type)
	{
	case PLAYER::PLAYERMOVETYPE::NOMAL:
		p_velocity = new Velocity();	this->ChildObj_AddList((ChildObjRef)p_velocity);
		                                                  p_velocity->gameObject = this;
		break;
	case PLAYER::PLAYERMOVETYPE::ROTATION:
		p_rotation = new RotationMove();this->ChildObj_AddList((ChildObjRef)p_rotation);
                                                          p_rotation->gameObject = this;
		break;
	default:
		break;
	}
}

void CPlayer::AttackHit(ObstacleBase* attack_parameters)
{
	p_state_processor.ChangeState(new CPlayer::DAMAGE(&p_state_processor));

	switch (attack_parameters->GetAttackParameters()._Type) 
	{
	case ATTACK_TYPE::NOCKBACK:
		break;
	case ATTACK_TYPE::SCREW:
		p_state_processor.ChangeState(new CPlayer::DAMAGE(&p_state_processor));
		break;
	case ATTACK_TYPE::SMASH:
		p_state_processor.ChangeState(new CPlayer::DAMAGE(&p_state_processor));
		break;
	}
}

void CPlayer::NOMAL::Update()
{
	if (GetTime() == 1){ _owner->p_player->ChangeMoveType(PLAYER::PLAYERMOVETYPE::NOMAL);}
}

void CPlayer::ROTATION::Update()
{
	if (GetTime() == 1){_owner->p_player->ChangeMoveType(PLAYER::PLAYERMOVETYPE::ROTATION);}
}

CPlayer::IDOL::IDOL(CPlayerStateProcessor* owner) : _owner(owner)
{
	_owner->p_player->p_hitbox = new HitBox();
	_owner->p_player->ChildObj_AddListBegin((ChildObjRef)_owner->p_player->p_hitbox);
	_owner->p_player->p_hitbox->Settags("player");
	_owner->p_player->p_hitbox->transform.localposition.y += 0.1f;
}

void CPlayer::IDOL::Update()
{
	

}

CPlayer::DAMAGE::DAMAGE(CPlayerStateProcessor* owner) : _owner(owner)
{
	if (_owner->p_player->p_hitbox != nullptr){_owner->p_player->p_hitbox->Remove();};
}

void CPlayer::DAMAGE::Update()
{
	_owner->p_player->alpha   ^= 1;_owner->p_player->color_r  = 1;

	if (this->GetTime() >= 120){

		_owner->p_player->alpha   = 1;_owner->p_player->color_r = 0;
		_owner->p_player->p_state_processor.ChangeState(new CPlayer::IDOL(&_owner->p_player->p_state_processor));
		return;
	}
	return;
}