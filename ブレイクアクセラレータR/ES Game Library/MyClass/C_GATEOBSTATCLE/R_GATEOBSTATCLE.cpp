#include "R_GATEOBSTATCLE.h"
#include"../C_UI/CUI.h"


void R_GATEOBSTATCLE::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å//GATE_Right.X"));

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	p_hitbox->Settags("gate_R");
	p_hitbox->SetScale(Vector3(3.f, 0.5f, 0.5f));
}

void R_GATEOBSTATCLE::Update()
{
}

void R_GATEOBSTATCLE::Draw3D()
{
	auto& itr = this->_imap_data->GetPlayerPosition('G');

	float player_pos_z = _iplayer_data->GetPlayerPosition("player").z;

	auto& obstacle_it = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;

		float distance = this->transform.position.z - player_pos_z;

		if (distance <= 90.0f)
		{
			this->transform.position.x -= (1.5f * 0.01f) * _i_ui_data->GetGageParams("ui");

			if (OnCollsion(distance, Vector3(1.48f, 0.5, 0.0f))) { }

			this->p_model.SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->p_model.Draw();
		}

		obstacle_it++;
	}
}
