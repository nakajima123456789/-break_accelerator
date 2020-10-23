#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"

class CUI : public Object
{
public:

	CUI()  {};
	~CUI() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;
	
private:

	enum Sprite_Manager
	{
		FW,
		FW2,
		SPRITE_MAX,
	};
	
	std::vector<SPRITE> sprite;
	std::vector<std::vector<Vector3>> sprite_position;

	SPRITE FW_L;
	int fw_L;
	SPRITE FW_R;
	float fw_R;
	float Right;
	
};

