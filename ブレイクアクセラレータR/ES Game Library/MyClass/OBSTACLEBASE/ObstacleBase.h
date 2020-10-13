#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"

class ObstacleBase : public Object
{
public:
	ObstacleBase() {};
	virtual ~ObstacleBase() {};

	virtual void Init()        override = 0;
	virtual void Update()      override = 0;
	virtual void Draw3D()      override = 0;

	virtual void DrawAlpha3D() override = 0;
	virtual void Draw2D()      override = 0;

private:

	Vector3 player_pos;

protected:

	Material SetMaterial(Color _color);
};

