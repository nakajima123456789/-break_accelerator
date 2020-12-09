#include "ObstacleBase.h"

Material ObstacleBase::SetMaterial(Color color)
{
	Material mtrl;

	ASSERT(color <= Color(1.0f, 1.0f, 1.0f) && "色は1.0f未満");

	mtrl.Diffuse  = color;
	mtrl.Ambient  = color;
	mtrl.Specular = color;
	mtrl.Emissive = color;
	mtrl.Power = 1.0f;

	return mtrl;
}

bool ObstacleBase::CollsionTrigger()
{
	if (PlayerDistance() <= 5.0f){ 
		IsHitObjectsDraw(this->transform.position + Vector3(0.0f, 0.5f, 0.0f));
		if (_hitbox->IsHitObjects("player"))
		{
			return true;
		}
	}
	return false;
}

float ObstacleBase::PlayerDistance()
{
	return Vector3_Distance(this->transform.position, _iplayer_data->GetPlayerPosition("player"));
}

ObstacleBase::ObstacleBase()
{
	_iplayer_data.reset(new IPlayerData);
	_imap_data.   reset(new IMapData);
	_i_ui_data.   reset(new UiData);
}

//ヒットボックス生成
void  ObstacleBase::IsHitObjectsInit(std::string _tags, float scale)
{
	_hitbox.reset(new HitBox(_tags));
	_hitbox->SetHitBoxScale(scale);
}

//ヒットボックス描画
void  ObstacleBase::IsHitObjectsDraw(Vector3 _pos)
{
	_hitbox->SetHitBoxPosition(_pos);
	//_hitbox->Draw3D();
}

bool ObstacleBase::RemoveModelDistance(double _distance)
{
	return this->transform.position.z <= (_iplayer_data->GetPlayerPosition("player").z + _distance) ? true : false;
}

bool ObstacleBase::DistanceTrigger(double _index)
{
	return PlayerDistance() <= _index;
}



