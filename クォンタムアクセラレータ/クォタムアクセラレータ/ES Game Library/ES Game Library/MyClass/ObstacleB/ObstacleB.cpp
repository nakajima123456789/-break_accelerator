#include "ObstacleB.h"

void ObstacleB::Init()
{
	model    = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å_//hako_B.X"));

	model->SetMaterial(this->SetMaterial());

	position = CsvPoitionDataBase.GetCsvPosition('B');

	p_hitbox = new HitBox();
	p_hitbox->Settags("ObstacleB");
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	this->AttackType = RECOVERY;
}

void ObstacleB::Update()
{

}

void ObstacleB::Draw3D()
{
	Vector3 player_position = PlayerDataBase.GetPlayerPosition();

	auto&  obstacle_itr  = this->position.begin();
	while (obstacle_itr != this->position.end()) {
		this->transform.position = *obstacle_itr;
		float distance = this->transform.position.z - player_position.z;
		if (distance <= DRAWOBSTACLERANGE) {
			this->OnCollsion(distance,Vector3(0.0f,0.5f,0.0f));
			this->model->SetPosition(this->transform.position);
			this->model->Draw();
		}
		if (distance <= REMOVEOBSTACLERANGE) {
			obstacle_itr = this->position.erase(obstacle_itr);
			continue;
		};

		obstacle_itr++;
	}
}

