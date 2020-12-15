#include "C_Obstacle.h"


void CObstacle::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å_//hako_B.X"));

	p_hitbox = new HitBox();
	p_hitbox->Settags("hako_B");
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	brock_parameters.map_tags = 'O';
	brock_parameters.pos_correction = Vector3(0.0f, 0.5f, 0.0f);
}

void CObstacle::Update()
{

}
