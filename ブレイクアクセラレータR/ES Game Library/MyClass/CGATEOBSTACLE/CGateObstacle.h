#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CGateObstacle : public ObstacleBase
{
public:
	CGateObstacle() {};
	virtual ~CGateObstacle() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;
	
private:

	float x = 0;
};


