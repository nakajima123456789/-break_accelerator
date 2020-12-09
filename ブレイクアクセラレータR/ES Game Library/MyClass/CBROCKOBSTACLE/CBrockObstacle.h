#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CBrockObstacle : public ObstacleBase
{
public:
	CBrockObstacle() {};
	virtual ~CBrockObstacle() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override;

	std::vector<Vector3> position;

	int count = 0;

private:
};

