#include "C_Obstacle.h"

CObstacle::CObstacle(Vector3 pos)
{
	this->transform.position = pos;

	IsHitObjectsInit("item");

	IsHitObjectsDraw(this->transform.position);
}

void CObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("CubeModel//cube.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f,1.f,1.f)));

	this->obstacle_model->SetPosition(this->transform.position);
	this->obstacle_model->SetRotation(this->transform.rotation);
	this->obstacle_model->SetScale   (this->transform.scale);
}

void CObstacle::Update()
{
	if (PlayerDistance() <= 0.25)
	{
		if (c_hitbox->IsHitObjects("player")) 
			IsRemove_flag(true);
	}

	if (this->transform.position.z <= (PlayerPosition().z - 10))
		this->IsRemove_flag(true);
}

void CObstacle::Draw3D()
{
	if(PlayerDistance() <= 30)
	   obstacle_model->Draw();
}
