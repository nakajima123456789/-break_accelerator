#include "CGateObstacle.h"
#include "../INFORMATION/INFORMATION.h"

void CGateObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å//GATE_Left.X"));
	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));
    
	IsHitObjectsInit("Gate_L",7.);
	
}

void CGateObstacle::Update()
{

}

void CGateObstacle::Draw3D()
{

	auto& itr = this->_imap_data->GetPlayerPosition('Z');
	auto& obstacle_it = itr.begin();
	while (obstacle_it != itr.end())
	{
		this->transform.position = *obstacle_it;
		if (DistanceTrigger(90.0f))
		{
			this->transform.position.x += (1.5f * 0.01f) * _i_ui_data->GetGageParams("ui");

			this->obstacle_model->SetPosition(this->transform.position + Vector3(0.0f, 0.08f, 0.0f));
			this->obstacle_model->Draw();
		}
		if (RemoveModelDistance(-20))
		{
			obstacle_it = itr.erase(obstacle_it);
			continue;
		}
		if (CollsionTrigger())
		{
			observer.IsCollisionDoor();
		}
		obstacle_it++;
	}
}