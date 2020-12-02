#pragma once
#include "../SCENEMANAGER/BaseScreen.h"

class C_RESULT : public BaseScene
{
public:

	C_RESULT() {};
	virtual ~C_RESULT() {};

	virtual void Initialize()  override;
	virtual int Update()      override;
	virtual void Draw3D()      override { return; };
	virtual void Draw2D()      override;
	virtual void DrawAlpha3D() override { return; };

private:
	SPRITE sprite;
	FONT original;
	float score_plus;

	void Add_Sprite(LPCTSTR _sprite_name);
	std::vector<SPRITE> sprite_list_name;
};