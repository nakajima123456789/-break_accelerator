#pragma once
#include "../OBSTACLEBASE/ObstacleBase.h"

class CBrockObstacle : public ObstacleBase
{
public:
	CBrockObstacle(std::vector<Vector3> _obstacle_pos);
	virtual ~CBrockObstacle() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override;

private:

	EFFECT shader;

	Vector2 moveUv = Vector2(0.0f,0.0f);

};

