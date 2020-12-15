#include "CObstacleR.h"

void CObstacleR::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å_//MOVEBOX//hako_P.X"));

	p_hitbox = new HitBox();
	p_hitbox->Settags("moveboxL");
	p_hitbox->transform.localposition.y += 0.5f;

	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	brock_parameters.map_tags = 'R';
	brock_parameters.pos_correction = Vector3(0.0f, 0.5f, 0.0f);

	brock_parameters.move_flag = true;
	brock_parameters.move_position = Vector3(0.1f, 0.0f, 0.0f);
}

void CObstacleR::Update()
{

}
