#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"

class C_MAP : public Object
{
public:

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;


private:
	MODEL model;

	std::vector<Vector3> model_pos;

protected:

};

