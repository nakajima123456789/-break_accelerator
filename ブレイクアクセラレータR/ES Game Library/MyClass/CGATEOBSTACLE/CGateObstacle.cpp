#include "CGateObstacle.h"
#include "../INFORMATION/INFORMATION.h"

void CGateObstacle::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å//GATE_Left.X"));

	p_hitbox = new HitBox();
	p_hitbox->Settags("gate_L");
	p_hitbox->transform.localposition.y += 0.5f;

	this->ChildObj_AddList((ChildObjRef)p_hitbox);
}

void CGateObstacle::Update()
{

}

void CGateObstacle::Draw3D()
{
	auto& itr = this->_imap_data->GetPlayerPosition('Z');

	float player_pos_z = _iplayer_data->GetPlayerPosition("player").z;

	auto& obstacle_it = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;

		float distance = this->transform.position.z - player_pos_z;

		if (distance <= 90.0f)
		{
			this->transform.position.x += (1.5f * 0.01f) * _i_ui_data->GetGageParams("ui");

			this->p_model.SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->p_model.Draw();
		}
	
		obstacle_it++;
	}
}