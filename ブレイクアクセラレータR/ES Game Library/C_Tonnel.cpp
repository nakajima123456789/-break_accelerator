#include "C_Tonnel.h"

void C_Tonnel::Init()
{
	p_model.SetModel(_T("model3D//‰ü’ù”Å_//Tunnel.X"));
	_imap_data.reset(new IMapData);
}

void C_Tonnel::Update()
{

}

void C_Tonnel::Draw3D()
{
	auto& itr = this->_imap_data->GetPlayerPosition('T');

	Vector3 player_pos = this->gameObject->transform.position;

	auto& obstacle_it   = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;
		float distance = this->transform.position.z - player_pos.z;

		if (distance <= 90)
		{
			if (distance <= -5.0f) { obstacle_it = itr.erase(obstacle_it); continue; };

			this->p_model.SetPosition(this->transform.position);
			this->p_model.Draw();
		}
		obstacle_it++;
	}

}
