#include "CObstacleR.h"

CObstacleR::CObstacleR(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CObstacleR::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//Move_Wall//MoveBoxR.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("item");

	this->move_brock = Vector3(0.001, 0.0f, 0.0f);
}

void CObstacleR::Update()
{

}

void CObstacleR::Draw3D()
{
	Draw();
}
