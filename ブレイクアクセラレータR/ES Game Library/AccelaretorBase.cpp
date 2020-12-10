#include "AccelaretorBase.h"
#include "MyClass/C_INPUT/C_INPUT.h"

void AccelaretorFront::AdvanceSpeed()
{
	Input.KeyBoardButtomState(Keys_Up) ? AccelaretorSpeed() : DragSpeed();
}

void AccelaretorFront::AccelaretorSpeed()
{
	this->_speed_z = this->_speed_z + this->_accelaretor;
	this->_speed_z = Math_Min(this->_speed_z, this->_MAX_ACCELARETOR);

	gameObject->transform.position.z = gameObject->transform.position.z + this->_speed_z;
}

void AccelaretorFront::DragSpeed()
{
	this->_speed_z = this->_speed_z * 0.99;
	this->_speed_z = Math_Max(this->_speed_z, _NOMAL_SPEED);

	gameObject->transform.position.z = gameObject->transform.position.z + this->_speed_z;
}

void AccelaretorFront::Init()
{
	this->_speed_z = _NOMAL_SPEED;
}

void AccelaretorFront::Update()
{
	AdvanceSpeed();
}
