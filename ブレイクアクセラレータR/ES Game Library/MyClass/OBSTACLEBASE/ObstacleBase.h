#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"

#include "../C_HITBOX/HitBox.h"
#include "../INFORMATION/INFORMATION.h"

class ObstacleBase : public Object
{
public:
	ObstacleBase() {};
	virtual ~ObstacleBase() {};

	virtual void Init()        override = 0;
	virtual void Update()      override = 0;
	virtual void Draw3D()      override = 0;

	virtual void DrawAlpha3D() override {};
	virtual void Draw2D()      override {};

private:

protected:

	std::unique_ptr <HitBox> c_hitbox;

	Material SetMaterial(Color _color);
	float    PlayerDistance();

	Vector3  PlayerPosition();

	void   IsHitObjectsInit(std::string _tags);
	void   IsHitObjectsDraw(Vector3 _pos);

	void   Draw();

	MONOSTATE monostate;

	MODEL obstacle_model;
	std::vector<Vector3> obstacle_pos;

	Vector3 move_brock = Vector3(0.0f, 0.0f, 0.0f);
};

