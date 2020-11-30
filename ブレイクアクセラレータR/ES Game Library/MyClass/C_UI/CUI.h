#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include"../OBSEVER/OBSEVER.h"
#include "../C_EFFEKSEER/CEffekseer_.h"
#include "../OBSTACLEBASE/ObstacleBase.h"

class CUI : public Object, OBSERVERLISTENER
{
public:

	CUI();
	~CUI();

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;
	
	//オブザーバー関数
	virtual void CUI::OnCollisionDamage()    override;
	virtual void CUI::OnCollisionClear()     override;
	virtual void CUI::OnCollisionGage()     override;

private:

	enum Sprite_Manager
	{
		FW,
		FW2,
		SPRITE_MAX,
	};
	
	std::vector<SPRITE> sprite;
	std::vector<std::vector<Vector3>> sprite_position;

	SPRITE FW_S;
	float fw_S;

	SPRITE _hit_ef;

	bool _damage_collsion_flag = false;
	float fiedout_alpha = 0.0f;
	
	double clamp(double x, double low, double high);
	
	OBSERVER observer;

	SPRITE gia;
	SPRITE gia2;
	float nobi;

	int _color_state;
	MONOSTATE monostate;
	EFFEKSEER effekseer;
	int item,damage;
	Color gage;



};

