#include "CObstacleL.h"

CObstacleL::CObstacleL(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CObstacleL::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//Move_Wall//MoveBoxL.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("item");

	this->move_brock = Vector3(-0.001, 0.0f, 0.0f);
}

void CObstacleL::Update()
{

}

void CObstacleL::Draw3D()
{
	Draw();
}