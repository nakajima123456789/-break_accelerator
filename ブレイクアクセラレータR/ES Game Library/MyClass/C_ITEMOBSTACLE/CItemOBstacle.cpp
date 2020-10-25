#include "CItemOBstacle.h"

CItemObstacle::CItemObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CItemObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//program//program_v01.X"));
	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("ObstacleItemHitBox");

}

void CItemObstacle::Update()
{
	this->transform.rotation.y++;
}

void CItemObstacle::Draw3D()
{
	auto&& obstacle_it = this->obstacle_pos.begin();
	while (obstacle_it != this->obstacle_pos.end()) {

		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->obstacle_model->SetRotation(this->transform.rotation);
			this->obstacle_model->SetScale(this->transform.scale * 0.015);
			this->obstacle_model->Draw();
		}

		if (RemoveModelDistance(-20) || CollsionTrigger())
		{
			obstacle_it = this->obstacle_pos.erase(obstacle_it);
			continue;
		}

		obstacle_it++;
	}
}
