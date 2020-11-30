#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CObstacle : public ObstacleBase
{
public:
	CObstacle(std::vector<Vector3> _obstacle_pos);
	virtual ~CObstacle() {};

	inline virtual void Init()        override ;
	inline virtual void Update()      override ;
	inline virtual void Draw3D()      override ;

private:

	int brock_break_ef;
	int effcseer_id;
protected:

};