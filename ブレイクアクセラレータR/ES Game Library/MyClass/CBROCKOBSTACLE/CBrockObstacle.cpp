#include "CBrockObstacle.h"

CBrockObstacle::CBrockObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CBrockObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å//hako_aka2.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("Item_Hitbox");
}

void CBrockObstacle::Update()
{

}

void CBrockObstacle::Draw3D()
{
	auto&& obstacle_it = this->obstacle_pos.begin();
	while (obstacle_it != this->obstacle_pos.end()) {

		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			if (RemoveModelDistance(1.5f))
				this->transform.position = *obstacle_it += Vector3(0.0f, 0.15f, 0.0f);

			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.f, 0.08f, 0.0f));
			this->obstacle_model->SetRotation(this->transform.rotation);
			this->obstacle_model->SetScale(this->transform.scale);
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
