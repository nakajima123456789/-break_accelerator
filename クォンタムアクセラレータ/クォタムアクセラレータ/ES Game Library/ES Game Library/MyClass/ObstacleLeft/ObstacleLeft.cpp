#include "ObstacleLeft.h"

void ObstacleLeft::Init()
{
	model    = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å_//MOVEBOX//hako_P.X"));

	model->SetMaterial(this->SetMaterial());
	model->Rotation(0.0f, 0.0f, 180.0f);

	position = CsvPoitionDataBase.GetCsvPosition('L');

	p_hitbox = new HitBox();
	p_hitbox->Settags("MoveBoxL");
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	this->AttackType = DAMAGE;
}

void ObstacleLeft::Update()
{

}

void ObstacleLeft::Draw3D()
{
	Vector3 player_position = PlayerDataBase.GetPlayerPosition();

	auto&  obstacle_itr  = this->position.begin();
	while (obstacle_itr != this->position.end()) {
		this->transform.position = *obstacle_itr;
		float distance = this->transform.position.z - player_position.z;
		if (distance <= DRAWOBSTACLERANGE) {
			if (distance <= 4.0f) { this->transform.position = *obstacle_itr += Vector3(-0.1f, 0.0f, 0.0f); };
			this->OnCollsion(distance,Vector3(0.0f, 0.5f, 0.0f));
			this->model->SetPosition(this->transform.position + Vector3(0.0f,0.77f,0.0f));
			this->model->Draw();
		}
		if (distance <= REMOVEOBSTACLERANGE) {
			obstacle_itr = this->position.erase(obstacle_itr);
			continue;
		};

		obstacle_itr++;
	}
}

