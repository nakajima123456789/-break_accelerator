#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include "../C_HITBOX/HitBox.h"
#include "../CPLAYERDATA/CPlayerData.h"
#include "..//OBSEVER/OBSEVER.h"
#include "../MapPlacementData/MapPlacementData.h"
#include "../UIDATABASE/UiDataBase.h"
#include "../CCHARACTER/Character.h"

struct BROCK_PARAMETERS
{
public:
	Vector3 pos_correction       = Vector3(0.0f,0.0f,0.0f);
	char    map_tags             = '?';
	float   move_gate_position   = 0.0f;
	Vector3 move_position        = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 model_pos_correction = Vector3(0.f, 0.08f, 0.0f);

	bool    move_flag          = false;
	bool    remove_flag        = false;

private:

};
enum ATTACK_TYPE {DAMEGE,ITEM,END};

struct ATTACK_PARAMETERS
{
public:
	//�^����_���[�W��
	float _AddDamege = 0.0f;
	//����
	ATTACK_TYPE _Type;
private:
};

class ObstacleBase : public Object
{
public:
	ObstacleBase();
	virtual ~ObstacleBase() {};

	virtual void Init()        override = 0;
	virtual void Update()      override = 0;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override { return; };

	ATTACK_PARAMETERS GetAttackParameters() const { return attack_parameters; };
private:

protected:
	//�֐��錾

	//�Փ˔���֐�
	bool   OnCollsion(float distance, Vector3 _position = Vector3(0.0f, 0.5f, 0.0f));

	//�Փ˂����Ƃ��̏���
	virtual void IsCollsion() { return; };

	bool LopePositionSetModel(float distance,std::vector<Vector3>::iterator& itr);

	ATTACK_PARAMETERS attack_parameters;
	BROCK_PARAMETERS  brock_parameters;

	//�ϐ��錾
	HitBox*  p_hitbox;
	OBSERVER observer;
	Model    p_model;

	const int     OBSTACLE_DRAW_RANGE   = 90;
	const float   OBSTACLE_REMOVE_RANGE = -1.0f;

	//�v���C���[�̃f�[�^�x�[�X
	std::unique_ptr<IMapData>     _imap_data;
	std::unique_ptr<UiData>       _iui_data;
	std::unique_ptr<IPlayerData>  _iplayer_data;
};