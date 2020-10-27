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

bool ObstacleBase::CollsionTrigger()
{
	if (PlayerDistance() <= 2.0f)
	{
		IsHitObjectsDraw(this->transform.position + Vector3(0.0f,0.1f,0.0f));
		return c_hitbox->IsHitBox(c_hitbox->Get_Tag_Model()) ? true : false;
	}
	return false;
}

float ObstacleBase::PlayerDistance()
{
	float dis;
	Vector3 player_pos = monostate.player_pos;

	dis = Vector3_Distance(this->transform.position, player_pos);

	return dis;
}

//ヒットボックス生成
void  ObstacleBase::IsHitObjectsInit(std::string _tags)
{
	c_hitbox.reset(new HitBox);
	c_hitbox->Init();
	c_hitbox->Settags(_tags);

	c_hitbox->SetHitBoxScale(0.1f);
}

//ヒットボックス描画
void  ObstacleBase::IsHitObjectsDraw(Vector3 _pos)
{
	c_hitbox->SetHitBoxPosition(_pos);
	c_hitbox->Draw3D();
}

bool ObstacleBase::RemoveModelDistance(double _distance)
{
	return this->transform.position.z <= (monostate.player_pos.z  + _distance) ? true : false;
}

bool ObstacleBase::DistanceTrigger(double _index)
{
	return PlayerDistance() <= _index ? true : false;
}



