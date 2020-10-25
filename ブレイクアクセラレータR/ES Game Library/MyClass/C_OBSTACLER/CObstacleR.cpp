#include "CObstacleR.h"

CObstacleR::CObstacleR(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CObstacleR::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//Move_Wall//MoveBoxR.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));
	IsHitObjectsInit("ObstacleHitBox");
}

void CObstacleR::Update()
{

}

void CObstacleR::Draw3D()
{
	auto&& obstacle_it = this->obstacle_pos.begin();
	while (obstacle_it != this->obstacle_pos.end()) {

		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{

			if (RemoveModelDistance(2))
				this->transform.position = *obstacle_it += Vector3(0.08f, 0.0f, 0.0f);


			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f,0.08f,0.0f));
			this->obstacle_model->SetRotation(this->transform.rotation);
			this->obstacle_model->SetScale(this->transform.scale * 0.015);
			this->obstacle_model->Draw();
		}

		if (RemoveModelDistance(-20))
		{
			obstacle_it = this->obstacle_pos.erase(obstacle_it);
			continue;
		}

		obstacle_it++;
	}
}
