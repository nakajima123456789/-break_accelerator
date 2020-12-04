#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CObstacle : public ObstacleBase
{
public:
	CObstacle() {};
	virtual ~CObstacle() {};

	virtual void Init()        override ;
	virtual void Update()      override ;
	virtual void Draw3D()      override ;

private:


protected:

};