#include "CBrockObstacle.h"

CBrockObstacle::CBrockObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CBrockObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//Move_Wall//kari_bluebox.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("item");

}

void CBrockObstacle::Update()
{

}

void CBrockObstacle::Draw3D()
{
	Draw();
}
