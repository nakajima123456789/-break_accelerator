#include "CObstacleL.h"

void CObstacleL::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å_//MOVEBOX//hako_P.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	this->obstacle_model->SetRotation(0, 0, 180);

	IsHitObjectsInit("Move_Box_L", 0.4f);
}

void CObstacleL::Update()
{

}

void CObstacleL::Draw3D()
{

	auto&& obstacle_it = IMapParametor::Instance()._map_params['R']._position.begin();
	while (obstacle_it != IMapParametor::Instance()._map_params['R']._position.end())
	{
		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			if (RemoveModelDistance(2.0f))
				this->transform.position = *obstacle_it -= Vector3(0.1f, 0.0f, 0.0f);

			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f, 0.85f, 0.0f));
			this->obstacle_model->Draw();
		}

		if (RemoveModelDistance(-20))
		{
			obstacle_it = IMapParametor::Instance()._map_params['R']._position.erase(obstacle_it);
			continue;
		}

		if (DistanceTrigger(5.0f))
		{
			IsHitObjectsDraw(this->transform.position + Vector3(0.0f, 0.5f, 0.0f));
		}
		obstacle_it++;
	}
}
