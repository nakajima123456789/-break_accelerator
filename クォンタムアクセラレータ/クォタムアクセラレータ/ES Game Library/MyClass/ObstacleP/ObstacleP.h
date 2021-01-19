#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class ObstacleP : public ObstacleBase
{
public:
	ObstacleP() {};
	virtual ~ObstacleP() {};

	virtual void Init()        override ;
	virtual void Update()      override ;
	virtual void Draw3D()      override ;

private:


protected:

};