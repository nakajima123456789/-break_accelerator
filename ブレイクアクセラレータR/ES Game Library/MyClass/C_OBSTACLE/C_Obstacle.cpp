#include "C_Obstacle.h"

CObstacle::CObstacle(Vector3 pos)
{
	this->transform.position = pos;
}

void CObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("CubeModel//cube.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f,1.f,1.f)));

	IsHitObjectsInit("item");
}

void CObstacle::Update()
{

}

void CObstacle::Draw3D()
{
	if(PlayerDistance() <= 5)
	{
		this->obstacle_model->SetPosition(this->transform.position);
		this->obstacle_model->SetRotation(this->transform.rotation);
		this->obstacle_model->SetScale(this->transform.scale);

		IsHitObjectsDraw(this->transform.position);

		obstacle_model->Draw();
	}
}
