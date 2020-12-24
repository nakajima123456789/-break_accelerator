#include "CBrockObstacle.h"

#include "../C_CAMERA/C_CAMERA.h"
#include "../../EnumManager.h"

void CBrockObstacle::Init()
{
	this->p_model.SetModel(_T("model3D//‰ü’ù”Å_//hako_P.X"));

	p_hitbox = new HitBox();
	p_hitbox->Settags("hako_P");
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	brock_parameters.map_tags = 'B';
	brock_parameters.pos_correction = Vector3(0.0f, 0.5f, 0.0f);

	this->attack_parameters._Type = ATTACK_TYPE::DAMEGE;

	return;
}

void CBrockObstacle::Update()
{

	return;
}

void CBrockObstacle::IsCollsion()
{



	return;
}
