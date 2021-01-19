#pragma once
#include "../SCENEMANAGER/BaseScreen.h"

class GameTitleScene : public BaseScene
{
public:

	GameTitleScene() {};
	virtual ~GameTitleScene() {};

	virtual void Initialize()  override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };
	virtual void Draw2D()      override;
	virtual void DrawAlpha3D() override { return; };

private:

	enum {TITLE_LEFT,TITLE_RIGHT,START,BACK,SPRITE_MAX,};
	SPRITE sprite[SPRITE_MAX];
	
	int   move_index  = 0;
	float start_alpha = 0.0f;
};

