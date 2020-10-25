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

	//関数宣言
	

	//変数宣言

protected:

	//関数宣言
	void   IsHitObjectsInit(std::string _tags);


	void   IsHitObjectsDraw(Vector3 _pos);


	bool   RemoveModelDistance(int _distance);


	bool   DistanceTrigger(double _index);


	Material SetMaterial(Color _color);


	bool     CollsionTrigger();


	float    PlayerDistance();


	//変数宣言

	std::unique_ptr <HitBox> c_hitbox;

	MONOSTATE monostate;

	MODEL obstacle_model;
	std::vector<Vector3> obstacle_pos;
};

