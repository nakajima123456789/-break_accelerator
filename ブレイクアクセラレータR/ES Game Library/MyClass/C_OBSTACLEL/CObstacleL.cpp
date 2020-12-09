#include "CObstacleL.h"

void CObstacleL::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å_//MOVEBOX//hako_P.X"));
	this->p_model.SetRotation(Vector3(0.0f, 0.0f, 180.0f));

	this->p_hitbox = new HitBox();
	this->p_hitbox->Settags("moveboxL");
	this->p_hitbox->transform.localposition.y += 0.5f;

	this->ChildObj_AddList((ChildObjRef)p_hitbox);
}

void CObstacleL::Update()
{



}

void CObstacleL::Draw3D()
{
	auto& itr = this->_imap_data->GetPlayerPosition('L');

	float player_pos_z = _iplayer_data->GetPlayerPosition("player").z;

	auto& obstacle_it = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;

		float distance = this->transform.position.z - player_pos_z;

		if (distance <= 90.0f) 
		{
			if (distance <= 4.0f){this->transform.position = *obstacle_it -= Vector3(0.1f, 0.0f, 0.0f);}

			if (OnCollsion(distance)) { this->observer.IsCollisionDamage(); };

			if (distance <= -5.0f) { obstacle_it = itr.erase(obstacle_it); continue; };

			this->p_model.SetPosition(this->transform.position + Vector3(0.f, 0.85f, 0.0f));
			this->p_model.Draw();
		}

		obstacle_it++;
	}
}
