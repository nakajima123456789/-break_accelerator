#include "Accelaretor.h"

float Accelaretor::_speed = 0.1f;

void Accelaretor::AccelaretorSpeed()
{
	this->_speed = this->_speed + this->_accelaretor;
	this->_speed = Math_Min(this->_speed, this->_max_speed);

	gameObject->transform.position.z = gameObject->transform.position.z + this->_speed;
}

void Accelaretor::DragSpeed()
{
	this->_speed = this->_speed * 0.99;
	this->_speed = Math_Max(this->_speed, _min_speed);

	gameObject->transform.position.z = gameObject->transform.position.z + this->_speed;
}

void Accelaretor::Init()
{
	_speed    += _accelaretor_parameter._start_velocity;
	_max_speed = _accelaretor_parameter._max_velocity;
	_min_speed = _accelaretor_parameter._min_velocity;
}

void Accelaretor::Update()
{
	Input.GetPadInput(0,6) && _speed <= this->_max_speed ? AccelaretorSpeed() : DragSpeed();

}