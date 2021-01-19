#pragma once

#include "../Object/Object.h"

enum ACCELARETOR_TYPE {NOMAL,ROW,MEDIUM,HARD,_END};

struct Accelaretor_Parameter {
public:
	//—^‚¦‚éƒ_ƒ[ƒW—Ê
	float _max_velocity;
	float _min_velocity;
	float _start_velocity;
};

class Accelaretor : public Object
{
private:
	static float _speed;
	float _accelaretor = 0.0030f;

	float _max_speed;
	float _min_speed;

	int   time = 0;

	void Accelaretor::AccelaretorSpeed();
	void Accelaretor::DragSpeed();

	Accelaretor_Parameter _accelaretor_parameter;

public:

	void Accelaretor::SetAccelaretorParameter(Accelaretor_Parameter accelaretor_parameter) { _accelaretor_parameter = accelaretor_parameter; };
	void Init()   override;
	void Update() override;

	bool GetMyMaxSpeedTriggr() { return _speed >= _max_speed ? true : false; };

};

