#pragma once
#include "../../ESGLib.h"
#include "../C_STATE/C_STATE.h"
#include "../C_OBJECT/Object.h"
#include "../c_Hitbox/HitBox.h"
#include "../C_INPUT/C_INPUT.h"
#include "../C_EFFEKSEER/CEffekseer_.h"
#include "../CSHAREDMETHOD/CSharedMethod.h"
#include "../CCHARACTER/Character.h"
#include "../CPLAYERDATA/CPlayerData.h"

class CPlayerStateProcessor;
class CPlayer;

class CPlayerStateProcessor : public  StateProcessor {
public:
	CPlayer* player_manager;
};

class CPlayer : public Object, CSharedMethod
{
public:
	CPlayerStateProcessor player_state_processor;
	
	CPlayer(Vector3  _pos);
	virtual ~CPlayer();

	virtual void CPlayer::Init()        override;
	virtual void CPlayer::Update()      override;
	virtual void CPlayer::Draw3D()      override;

	virtual void CPlayer::DrawAlpha3D() override { return; };
	virtual void CPlayer::Draw2D()      override { return; };

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
		float speed = 0;
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
		int   time  = 0;
		int   frame = 0;
		float speed = 0;
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
	//関数宣言
	void	 IsHitObjectsDraw();

	float    AccelaretorTime();

    //変数宣言

	int   time  = 0;
	int   frame = 0;

	Model player_model;

	float accelaretor = 0.3f;

	float  speed = 0.0f;

	double rotation = 0.0f; 
	EFFEKSEER effeckseer;
	int fire;

	//プレイヤーのデータベース
	std::unique_ptr<IPlayerData>   _iplayer_data;
};