#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CObstacleR : public ObstacleBase
{
public:
	CObstacleR(std::vector<Vector3> _obstacle_pos);
	virtual ~CObstacleR() {};

	inline virtual void Init()        override;
	inline virtual void Update()      override;
	inline virtual void Draw3D()      override;

private:

};


