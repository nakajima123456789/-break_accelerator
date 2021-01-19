#include "ItemObstacle.h"

void ItemObstacle::Init()
{
	model = GraphicsDevice.CreateModelFromFile(_T("‰ü’ù//program.X"));

	model->SetMaterial(this->SetMaterial());
	model->SetScale(0.5f);

	position = CsvPoitionDataBase.GetCsvPosition('I');

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);
	p_hitbox->Settags("Item");

	p_hitbox->transform.localposition.y += 0.5f;

	this->AttackType = ITEM;
}

void ItemObstacle::Update()
{
	
}

void ItemObstacle::Draw3D()
{
	Vector3 player_position = PlayerDataBase.GetPlayerPosition();

	auto& obstacle_itr = this->position.begin();
	while (obstacle_itr != this->position.end()) {
		this->transform.position = *obstacle_itr;
		float distance = this->transform.position.z - player_position.z;
		if (distance <= DRAWOBSTACLERANGE) {
			if (this->OnCollsion(distance, Vector3(0.0f, 0.5f, 0.0f))) {
				obstacle_itr = this->position.erase(obstacle_itr); 
				continue;
			};
			this->model->SetPosition(this->transform.position + Vector3(0.0f,0.25f,0.0f));
			this->model->Draw();
		}
		if (distance <= REMOVEOBSTACLERANGE) {
			obstacle_itr = this->position.erase(obstacle_itr);
			continue;
		};
		obstacle_itr++;
	}
}




