#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include "../INFORMATION/INFORMATION.h"

class C_MAP : public Object
{
public:

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;


private:

	enum MAP_MODEL
	{
		GROUND,
		BILL1,
		BILL2,
		BILL3,
		BILL4,
		BILL5,
		MAP_MODEL_SIZE,
	};

	std::vector<MODEL> model;
	std::vector<std::vector<Vector3>> model_position;

	Vector3 player_pos = Vector3(0.0f,0.0f,0.0f); 

	inline void CreateMapPrefarence();

	MEDIA bg;

	MONOSTATE monostate;

	int ground_model_scene[MAP_MODEL_SIZE];
protected:

};

