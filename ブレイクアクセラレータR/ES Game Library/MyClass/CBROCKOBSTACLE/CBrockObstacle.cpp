#include "CBrockObstacle.h"

#include "../C_CAMERA/C_CAMERA.h"

void CBrockObstacle::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å_//hako_P.X"));

	p_hitbox = new HitBox();
	p_hitbox->Settags("hako_P");
	this->ChildObj_AddList((ChildObjRef)p_hitbox);
}

void CBrockObstacle::Update()
{

}

void CBrockObstacle::Draw3D()
{
	
}

void CBrockObstacle::DrawAlpha3D()
{
	auto& itr = this->_imap_data->GetPlayerPosition('B');

	Vector3 player_pos = this->_iplayer_data->GetPlayerPosition("player");

	auto& obstacle_it   = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;
		float distance = this->transform.position.z - player_pos.z;

	    if (distance <= 90)
		{
			if (OnCollsion(distance)) { this->observer.IsCollisionDamage(); };
			if (distance <= -5.0f)    { obstacle_it = itr.erase(obstacle_it); continue; };

			this->p_model.SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->p_model.Draw();
		}
		obstacle_it++;
	}
}
