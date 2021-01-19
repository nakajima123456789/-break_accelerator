#include "Velocity.h"


void Velocity::Init()
{
	_velocity_processor._velocity = this;
	_velocity_processor.ChangeState(new Velocity::IDOL(&_velocity_processor));
}

void Velocity::Update()
{
	this->_velocity_processor.Update();

	gameObject->transform.position.x = Math_Min(gameObject->transform.position.x,  _MOVEMENT_SCENE);
	gameObject->transform.position.x = Math_Max(gameObject->transform.position.x, -_MOVEMENT_SCENE);

	gameObject->transform.rotation.z = Math_Min(gameObject->transform.rotation.z,  _MAX_ROTATION);
	gameObject->transform.rotation.z = Math_Max(gameObject->transform.rotation.z, -_MAX_ROTATION);

	if (gameObject->transform.position.x >= _MOVEMENT_SCENE || gameObject->transform.position.x <= -_MOVEMENT_SCENE) { 
		this->_speed = 0; 
	};

}

void Velocity::IDOL::Update()
{
	_owner->_velocity->_speed = _owner->_velocity->_speed * 0.9f;

	_owner->_velocity->gameObject->transform.rotation.z = _owner->_velocity->gameObject->transform.rotation.z * 0.9f;

	_owner->_velocity->gameObject->transform.position.x += _owner->_velocity->_speed;

	if (Input.GetArrowkeyVector().x != 0)
	{
		_owner->_velocity->_velocity_processor.ChangeState(new Velocity::RUNKEY(&_owner->_velocity->_velocity_processor));
		return;
	}

	if (Input.GetArrowPadVectorNomal(0).x != Axis_Center)
	{
		_owner->_velocity->_velocity_processor.ChangeState(new Velocity::RUNPAD(&_owner->_velocity->_velocity_processor));
		return;
	}

}

void Velocity::RUNKEY::Update()
{
	if (Input.GetArrowkeyVector().x > 0) { 
		_owner->_velocity->_speed = _owner->_velocity->_speed + _owner->_velocity->_ADD_SPEEDS;
		_owner->_velocity->gameObject->transform.rotation.z 
			                     = _owner->_velocity->gameObject->transform.rotation.z + _owner->_velocity->_ADD_ANGLES;

		_owner->_velocity->_speed = Math_Min(_owner->_velocity->_speed,  _owner->_velocity->_MAX_SPEED);
	}
	else
	if (Input.GetArrowkeyVector().x < 0) { 
		_owner->_velocity->_speed = _owner->_velocity->_speed - _owner->_velocity->_ADD_SPEEDS;
		_owner->_velocity->gameObject->transform.rotation.z 
			                     = _owner->_velocity->gameObject->transform.rotation.z - _owner->_velocity->_ADD_ANGLES;

		_owner->_velocity->_speed = Math_Max(_owner->_velocity->_speed, -_owner->_velocity->_MAX_SPEED);
	}

	_owner->_velocity->gameObject->transform.position.x += _owner->_velocity->_speed;

	if (Input.GetArrowkeyVector().x == 0) 
	{
		_owner->_velocity->_velocity_processor.ChangeState(new Velocity::IDOL(&_owner->_velocity->_velocity_processor));
		return;
	}
}

void Velocity::RUNPAD::Update()
{
	if (Input.GetArrowPadVectorNomal(0).x > 0) {
		_owner->_velocity->_speed = _owner->_velocity->_speed + _owner->_velocity->_ADD_SPEEDS;
		_owner->_velocity->gameObject->transform.rotation.z
			= _owner->_velocity->gameObject->transform.rotation.z + _owner->_velocity->_ADD_ANGLES;

		_owner->_velocity->_speed = Math_Min(_owner->_velocity->_speed, _owner->_velocity->_MAX_SPEED);
	}
	else
	if (Input.GetArrowPadVectorNomal(0).x < 0) {
		_owner->_velocity->_speed = _owner->_velocity->_speed - _owner->_velocity->_ADD_SPEEDS;
		_owner->_velocity->gameObject->transform.rotation.z
			= _owner->_velocity->gameObject->transform.rotation.z - _owner->_velocity->_ADD_ANGLES;

		_owner->_velocity->_speed = Math_Max(_owner->_velocity->_speed, -_owner->_velocity->_MAX_SPEED);
	}

	_owner->_velocity->gameObject->transform.position.x += _owner->_velocity->_speed;

	if (Input.GetArrowPadVectorNomal(0).x == 0)
	{
		_owner->_velocity->_velocity_processor.ChangeState(new Velocity::IDOL(&_owner->_velocity->_velocity_processor));
		return;
	}
}