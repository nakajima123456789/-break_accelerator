#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CObstacle : public ObstacleBase
{
public:
	CObstacle(Vector3 pos);
	virtual ~CObstacle() {};

	virtual void Init()        override ;
	virtual void Update()      override ;
	virtual void Draw3D()      override ;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override { return; }

private:
	MODEL obstacle_model;


protected:

};