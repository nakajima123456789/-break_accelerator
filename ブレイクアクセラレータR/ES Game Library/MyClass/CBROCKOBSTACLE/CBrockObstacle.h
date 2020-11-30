#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CBrockObstacle : public ObstacleBase
{
public:
	CBrockObstacle(std::vector<Vector3> _obstacle_pos);
	virtual ~CBrockObstacle() {};

	inline virtual void Init()        override;
	inline virtual void Update()      override;
	inline virtual void Draw3D()      override;

private:
};

