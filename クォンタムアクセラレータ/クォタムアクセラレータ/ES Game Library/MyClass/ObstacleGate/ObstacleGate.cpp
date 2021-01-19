#include "ObstacleGate.h"
#include "../UiDataBase/UiDataBase.h"

void ObstacleGate::Init()
{
	p_model[LEFT]  = GraphicsDevice.CreateModelFromFile(_T("model3D_//GATE_Left.X"));
	p_model[RIGHT] = GraphicsDevice.CreateModelFromFile(_T("model3D_//GATE_Right.X"));

	for (int i = 0; i < MAX; i++) { p_model[i]->SetMaterial(this->SetMaterial()); }

	position = CsvPoitionDataBase.GetCsvPosition('T');

	p_hitbox = new HitBox();
	p_hitbox->Settags("Gate");
	this->ChildObj_AddList((ChildObjRef)p_hitbox);
	p_hitbox->SetScale(4.f, 2.f, 0.4f);

	hitbox_position[LEFT]  = Vector3(-2.f, 0.5f, 0.0f);
	hitbox_position[RIGHT] = Vector3( 2.f, 0.5f, 0.0f);

	this->AttackType = GAMEOVER;
}

void ObstacleGate::Update()
{
	float timer = (UiDataBase.GetTimerSize() / 3) * 0.1f;

	move_position[LEFT]  = Vector3(-2.5f * timer, -0.3f, 0.0f);
	move_position[RIGHT] = Vector3( 2.5f * timer, -0.3f, 0.0f);
}

void ObstacleGate::Draw3D()
{
	Vector3 player_position = PlayerDataBase.GetPlayerPosition();

	auto&  obstacle_itr  = this->position.begin();
	while (obstacle_itr != this->position.end()) {
		this->transform.position = *obstacle_itr;
		float distance = this->transform.position.z - player_position.z;
		if (distance <= DRAWOBSTACLERANGE) {
			for (int i = 0; i < MAX; i++) { 
				this->OnCollsion(distance, move_position[i] + hitbox_position[i]);
				p_model[i]->SetPosition(transform.position  + move_position[i]);
				p_model[i]->Draw();
			}
		}
		if (distance <= REMOVEOBSTACLERANGE) {
			obstacle_itr = this->position.erase(obstacle_itr);
			continue;
		};

		obstacle_itr++;
	}
}

