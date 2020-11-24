#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"
#include "../INFORMATION/INFORMATION.h"
class CGateObstacle : public ObstacleBase
{
public:
	CGateObstacle(std::vector<Vector3> _obstacle_pos);
	virtual ~CGateObstacle() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;
	
private:

	MONOSTATE monostate;
	float x = 0;
};


