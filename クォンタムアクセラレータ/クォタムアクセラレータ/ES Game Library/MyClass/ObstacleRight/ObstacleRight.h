#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class ObstacleRight : public ObstacleBase
{
public:
	ObstacleRight() {};
	virtual ~ObstacleRight() {};

	virtual void Init()        override ;
	virtual void Update()      override ;
	virtual void Draw3D()      override ;

private:


protected:

};