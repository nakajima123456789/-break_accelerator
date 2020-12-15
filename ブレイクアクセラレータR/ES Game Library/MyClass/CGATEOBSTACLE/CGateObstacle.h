#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CGateObstacle : public ObstacleBase
{
public:
	CGateObstacle() {};
	virtual ~CGateObstacle() {};

	virtual void Init()        override;
	virtual void Update()      override;
	
private:

};


