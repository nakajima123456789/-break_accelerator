#include "C_Obstacle.h"

CObstacle::CObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å//hako_ao2.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f,1.f,1.f)));

	IsHitObjectsInit("Item_Hitbox");
}

void CObstacle::Update()
{

}

void CObstacle::Draw3D()
{
	auto&& obstacle_it = this->obstacle_pos.begin();
	while (obstacle_it != this->obstacle_pos.end()) {

		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.0f,0.01f,0.0f));
			this->obstacle_model->SetRotation(this->transform.rotation);
			this->obstacle_model->SetScale(this->transform.scale);
			//this->obstacle_model->Draw();
		}

		if (RemoveModelDistance(-20))
		{
			obstacle_it = this->obstacle_pos.erase(obstacle_it);
			continue;
		}

		if (this->CollsionTrigger())
		{
			observer.IsCollision();
		}

		obstacle_it++;
	}
}
