#include "ObstacleBase.h"


Material ObstacleBase::SetMaterial(Color _color)
{
	Material mtrl;

	mtrl.Diffuse  = _color;
	mtrl.Ambient  = _color;
	mtrl.Specular = _color;
	mtrl.Emissive = _color;
	mtrl.Power = 1.0f;

	return mtrl;
}

float ObstacleBase::PlayerDistance()
{
	float dis;
	Vector3 player_pos = monostate.player_pos;

	dis = Vector3_Distance(this->transform.position, player_pos);

	return dis;
}

Vector3  ObstacleBase::PlayerPosition() 
{ 
	Vector3 player_pos = monostate.player_pos;

	return  player_pos;
};

//ヒットボックス生成
void  ObstacleBase::IsHitObjectsInit(std::string _tags)
{
	c_hitbox.reset(new HitBox);
	c_hitbox->Init();
	c_hitbox->Settags(_tags);

	c_hitbox->SetHitBoxScale(0.18f);
}

//ヒットボックス描画
void  ObstacleBase::IsHitObjectsDraw(Vector3 _pos)
{
	c_hitbox->SetHitBoxPosition(_pos);
	c_hitbox->Draw3D();
}


