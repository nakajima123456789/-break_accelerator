#include "R_GATEOBSTATCLE.h"
#include"../C_UI/CUI.h"
#include "../INFORMATION/INFORMATION.h"
R_GATEOBSTATCLE::R_GATEOBSTATCLE(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void R_GATEOBSTATCLE::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å//GATE_Right.X"));
	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));
	IsHitObjectsInit("ZateHitbox");
}

void R_GATEOBSTATCLE::Update()
{
}

void R_GATEOBSTATCLE::Draw3D()
{

	auto&& obstacle_it = this->obstacle_pos.begin();
	while (obstacle_it != this->obstacle_pos.end()) {

		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{

			float x = 3 * 0.01 * monostate.num;

			this->transform.position = Vector3(this->transform.position.x + -(x), this->transform.position.y, this->transform.position.z);

			monostate.move_flag = false;
		

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



		obstacle_it++;
	}
}
