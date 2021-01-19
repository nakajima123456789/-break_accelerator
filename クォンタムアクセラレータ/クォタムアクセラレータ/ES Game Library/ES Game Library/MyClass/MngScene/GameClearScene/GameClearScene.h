#pragma once
#include "../SCENEMANAGER/BaseScreen.h"

class GameClearScene : public BaseScene
{
public:
	GameClearScene() {};
	virtual ~GameClearScene() {};

	virtual void Initialize();
	virtual void Update();
	virtual void Draw3D() {};
	virtual void Draw2D();
	virtual void DrawAlpha3D() {};

private:
	SPRITE sprite;

};

