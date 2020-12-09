#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include "../C_HITBOX/HitBox.h"
#include "../CPLAYERDATA/CPlayerData.h"
#include "..//OBSEVER/OBSEVER.h"
#include "../MapPlacementData/MapPlacementData.h"
#include "../UIDATABASE/UiDataBase.h"
#include "../CCHARACTER/Character.h"

class ObstacleBase : public Object
{
public:
	ObstacleBase();
	virtual ~ObstacleBase() {};

	virtual void Init()        override = 0;
	virtual void Update()      override = 0;
	virtual void Draw3D()      override = 0;

	virtual void DrawAlpha3D() override {};
	virtual void Draw2D()      override {};

private:

protected:

	//�֐��錾

	bool   OnCollsion(float distance);

	//�ϐ��錾
	HitBox*  p_hitbox;

	OBSERVER observer;

	Model    p_model;

	//�v���C���[�̃f�[�^�x�[�X
	std::unique_ptr<IPlayerData>  _iplayer_data;
	std::unique_ptr<IMapData>     _imap_data;
	std::unique_ptr<UiData>       _i_ui_data;

};

