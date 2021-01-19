#pragma once

#include "../Object/Object.h"

class VelocityStateProcessor;
class Velocity;

class VelocityStateProcessor : public  StateProcessor {
public:
	Velocity* _velocity;
};

class Velocity : public Object
{
private:
	VelocityStateProcessor _velocity_processor;

public:

	float _speed      = 0.0f;
	float _drag_speed = 0.0f;

	const float _MAX_SPEED       = 0.075f;
	const float _MAX_ROTATION    = 8.0f;

	const float _MOVEMENT_SCENE  = 1.3f;

	const float _ADD_SPEEDS = 0.003f;
	     const float _ADD_ANGLES = 0.5f;

	Velocity() {};
	virtual ~Velocity() {};

	virtual void Velocity::Init()   override;
	virtual void Velocity::Update() override;

	bool Velocity::ZeroVelocity() 
	{
		return _speed == 0.0f;
	};

	class IDOL : public State
	{
	private:
		VelocityStateProcessor* _owner;
	public:
		IDOL(VelocityStateProcessor* owner) : _owner(owner) {};
		virtual ~IDOL() {
			delete _owner;
		};

		virtual void Update() override;
	};

	class RUNKEY : public State
	{
	private:
		VelocityStateProcessor* _owner;
	public:
		RUNKEY(VelocityStateProcessor* owner) : _owner(owner) {}
		virtual ~RUNKEY() {
			delete _owner;
		}
		virtual void Update() override;
	};

	class RUNPAD : public State
	{
	private:
		VelocityStateProcessor* _owner;
	public:
		RUNPAD(VelocityStateProcessor* owner) : _owner(owner) {}
		virtual ~RUNPAD() {
			delete _owner;
		}
		virtual void Update() override;
	};

};

