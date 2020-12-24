#include "CItemOBstacle.h"


void CItemObstacle::Init()
{
	this->p_model.SetModel(_T("‰ü’ù//program.X"));
	this->p_model.SetScale(0.5f);

	p_hitbox = new HitBox();
	this->ChildObj_AddList((ChildObjRef)p_hitbox);

	p_hitbox->Settags("item");
	p_hitbox->transform.localposition.y += 0.5f;

	brock_parameters.map_tags = 'I';
	brock_parameters.pos_correction       = Vector3(0.0f, 0.5f, 0.0f);
	brock_parameters.model_pos_correction = Vector3(0.0f, 0.25f, 0.0f);

	brock_parameters.remove_flag = true;
	this->attack_parameters._Type = ATTACK_TYPE::ITEM;
}

void CItemObstacle::Update()
{
	
}

void CItemObstacle::IsCollsion()
{
	observer.IsCollisionClear();
}

