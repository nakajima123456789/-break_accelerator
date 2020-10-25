#pragma once
#include "../../ESGLib.h"
#include "../C_OBJECT/Object.h"
#include "../INFORMATION/INFORMATION.h"

class CCamera_ : public Object
{
public:
	CCamera_() {};
	virtual ~CCamera_() {};
	
	virtual void CCamera_::Init()        override;
	virtual void CCamera_::Update()      override;
	virtual void CCamera_::Draw3D()      override { return; };

	virtual void CCamera_::DrawAlpha3D() override { return; };
	virtual void CCamera_::Draw2D()      override { return; };

	virtual void CCamera_::DrawEnd()     override;

	int CCamera_::clamp(int x, int low, int high);
private:
	CAMERA  camera;
	Light   light;

	float field_of_view_pov = 70;

	MONOSTATE monostate;
};

