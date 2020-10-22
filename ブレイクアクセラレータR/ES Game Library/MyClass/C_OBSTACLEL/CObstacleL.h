#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CObstacleL : public ObstacleBase
{
public:
	CObstacleL(std::vector<Vector3> _obstacle_pos);
	virtual ~CObstacleL() {};

	inline virtual void Init()        override;
	inline virtual void Update()      override;
	inline virtual void Draw3D()      override;

private:

};

