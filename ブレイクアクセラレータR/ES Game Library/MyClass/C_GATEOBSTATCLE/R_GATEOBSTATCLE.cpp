#include "R_GATEOBSTATCLE.h"
#include"../C_UI/CUI.h"


void R_GATEOBSTATCLE::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//������//GATE_Right.X"));
	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("Gate_R", 0.5);
}

void R_GATEOBSTATCLE::Update()
{
}

void R_GATEOBSTATCLE::Draw3D()
{

	auto&& obstacle_it  = IMapParametor::Instance()._map_params['G']._position.begin();
	while (obstacle_it != IMapParametor::Instance()._map_params['G']._position.end())
	{
		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			this->transform.position.x -= (1.5f * 0.01f) * _i_ui_data->GetGageParams("ui");

			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->obstacle_model->Draw();
		}
		if (RemoveModelDistance(-20))
		{
			obstacle_it = IMapParametor::Instance()._map_params['G']._position.erase(obstacle_it);
			continue;
		}
		if (DistanceTrigger(5.0f))
		{
			IsHitObjectsDraw(this->transform.position + Vector3(0.0f, 0.5f, 0.0f));
		}
		obstacle_it++;
	}
}
