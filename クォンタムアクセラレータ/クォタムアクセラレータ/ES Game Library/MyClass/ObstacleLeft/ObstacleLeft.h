#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class ObstacleLeft : public ObstacleBase
{
public:
	ObstacleLeft() {};
	virtual ~ObstacleLeft() {};

	virtual void Init()        override ;
	virtual void Update()      override ;
	virtual void Draw3D()      override ;

private:


protected:

};