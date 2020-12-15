#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class R_GATEOBSTATCLE : public ObstacleBase
{
public:
	R_GATEOBSTATCLE() {};
	virtual ~R_GATEOBSTATCLE() {};

	virtual void Init()        override;
	virtual void Update()      override;

private:

};