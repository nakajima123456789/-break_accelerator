#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class ObstacleB : public ObstacleBase
{
public:
	ObstacleB() {};
	virtual ~ObstacleB() {};

	virtual void Init()        override ;
	virtual void Update()      override ;
	virtual void Draw3D()      override ;

private:


protected:

};