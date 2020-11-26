#pragma once
#include "../../ESGLib.h"
#include "../C_STATE/C_STATE.h"
#include "../C_OBJECT/Object.h"
#include "../c_Hitbox/HitBox.h"
#include "../C_INPUT/C_INPUT.h"
#include "../C_SE/C_SE.h"
#include "../INFORMATION/INFORMATION.h"
#include "../C_EFFEKSEER/CEffekseer_.h"
#include "../C_CAMERA/C_CAMERA.h"
#include "../OBSEVER/OBSEVER.h"


#include <functional>


class CPlayerStateProcessor;
class CPlayer;

class CPlayerStateProcessor : public  StateProcessor {
public:
	CPlayer* player_manager;
};

class CPlayer : public Object, OBSERVERLISTENER
{
public:
	CPlayerStateProcessor player_state_processor;
	
	CPlayer(Vector3  _pos);
	virtual ~CPlayer();

	virtual void CPlayer::Init()        override;
	virtual void CPlayer::Update()      override;
	virtual void CPlayer::Draw3D()      override;

	virtual void CPlayer::DrawAlpha3D() override { return; };
	virtual void CPlayer::Draw2D()      override ;

	virtual void CPlayer::OnCollisionDamage()    override;
	virtual void CPlayer::OnCollisionClear()     override;
	virtual void CPlayer::OnCollisionGage()     override;
	virtual void CPlayer::OnCollisionGate()     override { return; };

private:

	class IDOL : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		IDOL(CPlayerStateProcessor* owner) : _owner(owner) { };
		virtual ~IDOL() {};

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return INT_MAX; };

		virtual void Update() override;
	};

	class RUNPAD : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		RUNPAD(CPlayerStateProcessor* owner) : _owner(owner) {}
		virtual ~RUNPAD() {}

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return INT_MAX; };

		virtual void Update() override;
	};

	class RUNKEY : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		RUNKEY(CPlayerStateProcessor* owner) : _owner(owner) {}
		virtual ~RUNKEY() {}

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return INT_MAX; };

		virtual void Update() override;
	};

	class DAMAGE : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		DAMAGE(CPlayerStateProcessor* owner) : _owner(owner) {}
		virtual ~DAMAGE() {}

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return 30; };

		virtual void Update() override;
	};




private:
	//ä÷êîêÈåæ
	Material SetMaterial(Color _color);
	int      IsHitObjectsInit();
	void	 IsHitObjectsDraw();

	double CPlayer::clamp(double x, double low, double high);

	bool   CPlayer::FrameTimeObsever(int _index);

    //ïœêîêÈåæ

	std::unique_ptr <HitBox> c_hitbox;

	MODEL player_model;

	float  speed = 0.0f;
	double rotation = 0.0f; 

	MONOSTATE monostate;
	OBSERVER observer;

	int _time = 0;

	int effcseer_test;
	EFFEKSEER effekseer;
	int effcseer_id;

	SPRITE gia;
	SPRITE gia2;
	Color gage;

	float nobi;
	bool acc_flag = false;

};