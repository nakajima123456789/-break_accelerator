#include "ObstacleBase.h"
#include "../Player/Player.h"

ObstacleBase::ObstacleBase()
{

}

bool ObstacleBase::OnCollsion(float distance, Vector3 lerp_position)
{
	if (distance >= 10) return false;
	p_hitbox->SetHitBoxPosition(this->transform.position + lerp_position);
	std::list<HitBox*> hitlist = p_hitbox->HitHitBoxlist();
	for (auto&& other : hitlist) {
		if (other->gameObject == this->gameObject) continue;
		if (typeid(*other->gameObject) == typeid(Player))
		{
			((Player*)(other->gameObject))->AttackHit(AttackType);
			return true;
		}
	}
	return false;
}

Material ObstacleBase::SetMaterial()
{
	Material mtrl;	

	mtrl.Diffuse  = Color(1.0f, 1.0f, 1.0f);
	mtrl.Ambient  = Color(1.0f, 1.0f, 1.0f);
	mtrl.Specular = Color(1.0f, 1.0f, 1.0f);
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);
	mtrl.Power = 1.0f;

	return Material(mtrl);
}
