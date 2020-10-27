#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include"../OBSEVER/OBSEVER.h"

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
	virtual void CUI::OnCollision()     override;

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
	
	double clamp(double x, double low, double high);
	
	OBSERVER observer;
};

