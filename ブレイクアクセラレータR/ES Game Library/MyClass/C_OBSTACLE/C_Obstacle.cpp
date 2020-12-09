#include "C_Obstacle.h"

#include "../C_CAMERA/C_CAMERA.h"

void CObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å//hako_B.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f,1.f,1.f)));

	IsHitObjectsInit("Item_Hitbox", 0.4f);

}

void CObstacle::Update()
{

}

void CObstacle::Draw3D()
{

	auto& itr = this->_imap_data->GetPlayerPosition('O');
	auto& obstacle_it = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->obstacle_model->Draw();
		}
		if (RemoveModelDistance(-20))
		{
			obstacle_it = itr.erase(obstacle_it);
			continue;
		}

		if (CollsionTrigger())
		{
			observer.IsCollisionDamage();
		}

		obstacle_it++;
	}

}
