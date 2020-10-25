#include "CItemOBstacle.h"

CItemObstacle::CItemObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CItemObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//program//program_v01.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("item");

}

void CItemObstacle::Update()
{
	this->transform.rotation.y++;
}

void CItemObstacle::Draw3D()
{
	Draw();
}
