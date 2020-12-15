#include "CGateObstacle.h"
#include "../INFORMATION/INFORMATION.h"

void CGateObstacle::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å//GATE_Left.X"));

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	p_hitbox->Settags("gate_L");
	p_hitbox->SetScale(Vector3(3.f, 0.5f, 0.5f));

	brock_parameters.map_tags = 'Z';
	brock_parameters.pos_correction = Vector3(-1.5f, 0.5f, 0.0f);
}

void CGateObstacle::Update()
{
	brock_parameters.move_gate_position = (1.5f * 0.01f) * _iui_data->GetGageParams("ui");
}
