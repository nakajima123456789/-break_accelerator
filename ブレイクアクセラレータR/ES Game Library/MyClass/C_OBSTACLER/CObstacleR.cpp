#include "CObstacleR.h"

void CObstacleR::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å_//MOVEBOX//hako_P.X"));

	p_hitbox = new HitBox();
	p_hitbox->Settags("moveboxL");
	p_hitbox->transform.localposition.y += 0.5f;

	this->ChildObj_AddList((ChildObjRef)p_hitbox);
}

void CObstacleR::Update()
{

}

void CObstacleR::Draw3D()
{
	auto& itr = this->_imap_data->GetPlayerPosition('R');

	float player_pos_z = _iplayer_data->GetPlayerPosition("player").z;

	auto& obstacle_it = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;

		float distance = this->transform.position.z - player_pos_z;

		if (distance <= 90.0f)
		{
			if (distance <= 4.0f) { this->transform.position = *obstacle_it += Vector3(0.1f, 0.0f, 0.0f); }

			if (OnCollsion(distance)) { this->observer.IsCollisionDamage(); };

			if (distance <= -5.0f) { obstacle_it = itr.erase(obstacle_it); continue; };

			this->p_model.SetPosition(this->transform.position + Vector3(0.0f, 0.08f, 0.0f));
			this->p_model.Draw();
		}

		obstacle_it++;
	}
}