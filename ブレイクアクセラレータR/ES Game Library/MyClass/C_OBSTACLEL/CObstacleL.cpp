#include "CObstacleL.h"

void CObstacleL::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å_//MOVEBOX//hako_P.X"));
	this->p_model.SetRotation(Vector3(0.0f, 0.0f, 180.0f));

	this->p_hitbox = new HitBox();
	this->p_hitbox->Settags("moveboxL");
	this->p_hitbox->transform.localposition.y -= 1.0f;

	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	brock_parameters.map_tags = 'L';
	brock_parameters.pos_correction = Vector3(0.0f, 0.5f, 0.0f);

	brock_parameters.move_flag = true;
	brock_parameters.move_position = -Vector3(0.1f, 0.0f, 0.0f);

	brock_parameters.model_pos_correction = Vector3(0.0f, 0.85f, 0.0f);
}

void CObstacleL::Update()
{



}
