#include "CBrockObstacle.h"

#include "../C_CAMERA/C_CAMERA.h"

void CBrockObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å_//hako_P.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("hako_P",0.4f);
}

void CBrockObstacle::Update()
{

}

void CBrockObstacle::Draw3D()
{
	
}

void CBrockObstacle::DrawAlpha3D()
{
	auto&& obstacle_it  = IMapParametor::Instance()._map_params['B']._position.begin();
	while (obstacle_it != IMapParametor::Instance()._map_params['B']._position.end())
	{
		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->obstacle_model->Draw();
		}
		if (RemoveModelDistance(-20))
		{
			obstacle_it = IMapParametor::Instance()._map_params['B']._position.erase(obstacle_it);
			continue;
		}

		if (CollsionTrigger())
		{
			
		}

		obstacle_it++;
	}
}
