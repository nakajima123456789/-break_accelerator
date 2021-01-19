#pragma once
#include "../Object/Object.h"

#include "../SharedMethod/SharedMethod.h"

class GameCamera : public Object, SharedMethod
{
public:
	GameCamera() {};
	virtual ~GameCamera() {};
	
	virtual void GameCamera::Init()        override;
	virtual void GameCamera::Update()      override;
	virtual void GameCamera::Draw3D()      override { return; };

	virtual void GameCamera::DrawAlpha3D() override { return; };
	virtual void GameCamera::Draw2D()      override { return; };

	virtual void GameCamera::DrawEnd()     override;

	CAMERA GetCamera() const { return camera; };
	Light  GetLight()  const { return light; };

private:
	CAMERA  camera;
	Light   light;

};

