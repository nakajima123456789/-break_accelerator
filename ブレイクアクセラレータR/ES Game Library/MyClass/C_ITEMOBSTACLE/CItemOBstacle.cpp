#include "CItemOBstacle.h"


void CItemObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("‰ü’ù//program.X"));
	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));
	this->obstacle_model->SetScale(0.5f);

	IsHitObjectsInit("Item",0.4f);

}

void CItemObstacle::Update()
{
	this->transform.rotation.y = this->transform.rotation.y += 5.0f;
}

void CItemObstacle::Draw3D()
{
	auto&& obstacle_it =  IMapParametor::Instance()._map_params['I']._position.begin();
	while (obstacle_it != IMapParametor::Instance()._map_params['I']._position.end())
	{
		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f, 0.25f, 0.0f));
			this->obstacle_model->Draw();
		}
		if (RemoveModelDistance(-20))
		{
			obstacle_it = IMapParametor::Instance()._map_params['I']._position.erase(obstacle_it);
			continue;
		}
		if (DistanceTrigger(5.0f))
		{
			IsHitObjectsDraw(this->transform.position + Vector3(0.0f, 0.5f, 0.0f));
		}
		obstacle_it++;
	}
}
