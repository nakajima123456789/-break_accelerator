#pragma once
#include "../SCENEMANAGER/BaseScreen.h"

class GameOverScene : public BaseScene
{
public:

	GameOverScene() {};
	virtual ~GameOverScene() {};

	virtual void Initialize()  override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };
	virtual void Draw2D()      override;
	virtual void DrawAlpha3D() override { return; };

private:

	SPRITE sprite;

};

