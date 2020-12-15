#include "CItemOBstacle.h"


void CItemObstacle::Init()
{
	this->p_model.SetModel(_T("‰ü’ù//program.X"));
	this->p_model.SetScale(0.5f);

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	p_hitbox->Settags("item");
	p_hitbox->transform.localposition.y += 0.5f;

}

void CItemObstacle::Update()
{
	
}

void CItemObstacle::Draw3D()
{
	//auto& itr = this->_imap_data->GetPlayerPosition('I');

	//float player_pos_z = _iplayer_data->GetPlayerPosition("player").z;

	//auto& obstacle_it   = itr.begin();
	//while (obstacle_it != itr.end())
	//{
	//	this->transform.position = *obstacle_it;

	//	float distance = this->transform.position.z - player_pos_z;

	//	if (distance <= OBSTACLE_DRAW_RANGE){

	//		if (OnCollsion(distance)) { 
	//			this->observer.IsCollisionClear(); 
	//			obstacle_it = itr.erase(obstacle_it);
	//			continue;
	//		};

	//		if (distance <= OBSTACLE_REMOVE_RANGE) { obstacle_it = itr.erase(obstacle_it); continue; };

	//		this->p_model.SetPosition(this->transform.position + Vector3(0.f, 0.25f, 0.0f));
	//		this->p_model.Draw();

	//	}

	//	obstacle_it++;
	//}
}
