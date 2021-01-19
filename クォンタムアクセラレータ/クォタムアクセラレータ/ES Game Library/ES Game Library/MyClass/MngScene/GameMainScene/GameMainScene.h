#pragma once
#include "../SCENEMANAGER/BaseScreen.h"
#include "../../Object/Object.h"

class GameMainScene : public BaseScene
{
public:
	GameMainScene() {};
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual void Update()     override;
	virtual void Draw3D()     override;
	virtual void Draw2D()     override;
	virtual void DrawAlpha3D()override;
	virtual void DrawEnd()    override;

private:
	ObjectManager _objectroot;
};