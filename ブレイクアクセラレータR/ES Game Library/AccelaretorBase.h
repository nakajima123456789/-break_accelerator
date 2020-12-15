#pragma once
#include "ESGLib.h"
#include "MyClass/C_OBJECT/Object.h"

class AccelaretorFront : public Object
{
private:
	float _speed_z     = 0;
	float _accelaretor = 0.0030f;

	const float _MAX_ACCELARETOR = 0.9f;
	const float _NOMAL_SPEED     = 0.1f;

	void AccelaretorFront::AccelaretorSpeed();
	void AccelaretorFront::DragSpeed();

public:

	void Init()   override;
	void Update() override;


};

