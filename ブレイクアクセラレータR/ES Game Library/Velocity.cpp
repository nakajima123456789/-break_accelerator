#include "Velocity.h"
#include "MyClass/C_INPUT/C_INPUT.h"

void Velocity::Init()
{
	_velocity_processor._velocity = this;
	_velocity_processor.ChangeState(new Velocity::IDOL(&_velocity_processor));

	accelaretors = (new AccelaretorFront);
	this->ChildObj_AddList((ChildObjRef)accelaretors);

	accelaretors->gameObject = gameObject;
}

void Velocity::Update()
{
	this->_velocity_processor.Update();

	gameObject->transform.position.x = Math_Min(gameObject->transform.position.x,  _MOVEMENT_SCENE);
	gameObject->transform.position.x = Math_Max(gameObject->transform.position.x, -_MOVEMENT_SCENE);
}

void Velocity::IDOL::Update()
{
	_owner->_velocity->_drag_speed = _owner->_velocity->_drag_speed * 0.9f;

	_owner->_velocity->gameObject->transform.position.x += _owner->_velocity->_drag_speed;

	_owner->_velocity->_speed = 0.0f;

	if (Input.GetArrowkeyVector().x != 0)
	{
		_owner->_velocity->_velocity_processor.ChangeState(new Velocity::RUN(&_owner->_velocity->_velocity_processor));
		return;
	}
}

void Velocity::RUN::Update()
{
	if (Input.GetArrowkeyVector().x >= 0.3f) { 
		_owner->_velocity->_speed = _owner->_velocity->_speed + 0.003f;
		_owner->_velocity->_speed = Math_Min(_owner->_velocity->_speed,  _owner->_velocity->_MAX_SPEED);
	}
	else
	if (Input.GetArrowkeyVector().x <= 0.3f) { 
		_owner->_velocity->_speed = _owner->_velocity->_speed - 0.003f;
		_owner->_velocity->_speed = Math_Max(_owner->_velocity->_speed, -_owner->_velocity->_MAX_SPEED);
	}

	_owner->_velocity->_drag_speed = _owner->_velocity->_speed;

	_owner->_velocity->gameObject->transform.position.x += _owner->_velocity->_speed;

	if (Input.GetArrowkeyVector().x == 0) 
	{
		_owner->_velocity->_velocity_processor.ChangeState(new Velocity::IDOL(&_owner->_velocity->_velocity_processor));
		return;
	}
}