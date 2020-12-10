#pragma once
#include "ESGLib.h"
#include "MyClass/C_OBJECT/Object.h"
#include "MyClass/C_STATE/C_STATE.h"
#include "AccelaretorBase.h"

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

	AccelaretorFront* accelaretors;
public:

	float _speed      = 0.0f;
	float _drag_speed = 0.0f;

	const float _MAX_SPEED       = 0.075f;
	const float _MOVEMENT_SCENE  = 1.3f;

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

	class RUN : public State
	{
	private:
		VelocityStateProcessor* _owner;
	public:
		RUN(VelocityStateProcessor* owner) : _owner(owner) {}
		virtual ~RUN() {
			delete _owner;
		}
		virtual void Update() override;
	};

};

