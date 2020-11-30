#include "C_Obstacle.h"

CObstacle::CObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å_//hako_B.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f,1.f,1.f)));

	IsHitObjectsInit("Item_Hitbox");

	brock_break_ef = EffekseerMgr.LoadEffekseer(_T("Effects//"));
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
			this->obstacle_model->SetPosition(this->transform.position);
			this->obstacle_model->SetRotation(this->transform.rotation);
			this->obstacle_model->SetScale(this->transform.scale);
			this->obstacle_model->Draw();
		}

		if (RemoveModelDistance(-20))
		{
			obstacle_it = this->obstacle_pos.erase(obstacle_it);
			continue;
		}

		if (this->CollsionTrigger())
		{
			observer.IsCollisionClear();
			EffekseerMgr.PlayEffekseer(brock_break_ef, *obstacle_it + Vector3(0.0f, 0.08f, 0.0f));
			obstacle_it = obstacle_pos.erase(obstacle_it);
			continue;
		}

		obstacle_it++;
	}
}
