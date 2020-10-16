#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"

#include "../C_HITBOX/HitBox.h"

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

protected:

	std::unique_ptr <HitBox> c_hitbox;

	Material SetMaterial(Color _color);
	float    PlayerDistance();

	void   IsHitObjectsInit(std::string _tags);
	void   IsHitObjectsDraw(Vector3 _pos);


};

