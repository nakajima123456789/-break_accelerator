#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"
#include "../INFORMATION/INFORMATION.h"



class R_GATEOBSTATCLE : public ObstacleBase
{
public:
	R_GATEOBSTATCLE(std::vector<Vector3> _obstacle_pos);
	virtual ~R_GATEOBSTATCLE() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

private:

};