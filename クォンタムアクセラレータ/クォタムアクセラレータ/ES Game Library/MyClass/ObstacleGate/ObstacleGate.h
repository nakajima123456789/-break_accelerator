#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class ObstacleGate : public ObstacleBase
{
public:
	ObstacleGate() {};
	virtual ~ObstacleGate() {};

	virtual void Init()        override ;
	virtual void Update()      override ;
	virtual void Draw3D()      override ;

private:

	enum{LEFT,RIGHT,MAX};
	MODEL   p_model[MAX];

	Vector3 move_position  [MAX];
	Vector3 hitbox_position[MAX];

protected:

};