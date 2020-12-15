#include "ObstacleBase.h"
#include "../C_PLAYER/C_PLAYER.h"

void ObstacleBase::OnCollsion(float distance,Vector3 _position)
{
	if (distance >= 5) return;
	this->p_hitbox->GetModel()->SetPosition(this->transform.position + _position);
	std::list<HitBox*> hitlist = p_hitbox->HitHitBoxlist();
	for (auto&& other : hitlist) {
		if (other->gameObject == this->gameObject) continue;
		if (typeid(*other->gameObject) == typeid(CPlayer)) 
		{
			((CPlayer*)(other->gameObject))->AttackHit(this);
			this->IsCollsion();
		}
	}
}

ObstacleBase::ObstacleBase()
{
	//プレイヤーのデータベース作成
	_iplayer_data.reset(new IPlayerData);
	//マップのデータベース作成
	_imap_data.   reset(new IMapData);
	//UIのデータベース作成
	_iui_data.    reset(new UiData);
}

void ObstacleBase::Draw3D()
{
	auto&& itr = this->_imap_data->GetPlayerPosition(brock_parameters.map_tags);
	Vector3 player_position = this->_iplayer_data->GetPlayerPosition("player");

	auto& obstacle_itr   = itr.begin();
	while (obstacle_itr != itr.end()) {
		this->transform.position = *obstacle_itr;
		float _with_distance = this->transform.position.z - player_position.z;

		if (_with_distance <= OBSTACLE_DRAW_RANGE) {
			this->transform.position.x += brock_parameters.move_gate_position;

			if(brock_parameters.move_flag == true)
			if (_with_distance <= 4.0f) { this->transform.position = *obstacle_itr += brock_parameters.move_position; }

			OnCollsion(_with_distance, brock_parameters.pos_correction);

			if (_with_distance <= OBSTACLE_REMOVE_RANGE) { obstacle_itr = itr.erase(obstacle_itr); continue; };

			this->p_model.SetPosition(this->transform.position + brock_parameters.model_pos_correction);
			this->p_model.Draw();
		}

		obstacle_itr++;
	}
};