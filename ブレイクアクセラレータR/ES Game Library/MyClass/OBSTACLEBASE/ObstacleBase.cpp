#include "ObstacleBase.h"

bool ObstacleBase::OnCollsion(float distance,Vector3 _position)
{
	if (distance <= 5.0f)
	{
		this->p_hitbox->GetModel()->SetPosition(this->transform.position + _position);

		if (p_hitbox->IsHitObjects("player"))return true; 
	}
	return false;
}

ObstacleBase::ObstacleBase()
{
	_iplayer_data.reset(new IPlayerData);
	_imap_data.   reset(new IMapData);
	_i_ui_data.   reset(new UiData);
}




