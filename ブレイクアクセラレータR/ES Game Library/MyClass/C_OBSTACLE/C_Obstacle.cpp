#include "C_Obstacle.h"

CObstacle::CObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰¼‘fÞ//hako.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f,1.f,1.f)));


	IsHitObjectsInit("item");
}

void CObstacle::Update()
{

}

void CObstacle::Draw3D()
{
	Draw();
}
