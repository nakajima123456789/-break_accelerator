#pragma once
#include "../../ESGLib.h"
#include "../C_STATE/C_STATE.h"
#include "../C_OBJECT/Object.h"
#include "../c_Hitbox/HitBox.h"
#include "../C_INPUT/C_INPUT.h"
#include "../CSHAREDMETHOD/CSharedMethod.h"
#include "../CCHARACTER/Character.h"
#include "../CPLAYERDATA/CPlayerData.h"
#include "../../Velocity.h"
#include "../../RotationMove.h"
#include "../../EnumManager.h"
#include "../C_EFFEKSEER/EffekseerMng.h"
#include "../C_DIS/C_DIS.h"

class CPlayerStateProcessor;
class CPlayer;

class ObstacleBase;

class CPlayerStateProcessor : public  StateProcessor {
public:
	CPlayer* p_player;
};

class CPlayer : public Object, CSharedMethod, OBSERVERLISTENER
{
public:
	CPlayerStateProcessor p_state_processor;

	CPlayer(Vector3  _pos);
	virtual ~CPlayer();

	virtual void CPlayer::Init()        override;
	virtual void CPlayer::Update()      override;
	virtual void CPlayer::Draw3D()      override { return; };

	virtual void CPlayer::DrawAlpha3D() override;
	virtual void CPlayer::Draw2D()      override { return; };

	void AttackHit(ObstacleBase* attack_parameters);

private:

	class NOMAL : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		NOMAL(CPlayerStateProcessor* owner) : _owner(owner) { };
		virtual ~NOMAL() {};

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return INT_MAX; };

		virtual void Update() override;
	};

	class ROTATION : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		ROTATION(CPlayerStateProcessor* owner) : _owner(owner) {}
		virtual ~ROTATION() {}

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return INT_MAX; };

		virtual void Update() override;
	};

	class DAMAGE : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		DAMAGE(CPlayerStateProcessor* owner);
		virtual ~DAMAGE() {};

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return 30; };

		virtual void Update() override;
	};

	class IDOL : public State
	{
	private:
		CPlayerStateProcessor* _owner;
	public:
		IDOL(CPlayerStateProcessor* owner);
		virtual ~IDOL() {};

		virtual void Update() override;
	};

private:
	//関数宣言

	void ChangeMoveType (PLAYER::PLAYERMOVETYPE move_type);
	void LordEffekseer   ();
	void GameObjectIsMove();

    //変数宣言
	MODEL         p_model;
	RotationMove* p_rotation;
	HitBox*       p_hitbox;
	EffekseerMng* p_effekseerMng;
	Velocity*     p_velocity;

	OBSERVER      obsever;

	int state_type = -1;

	EFFECT shader = nullptr;
	int  alpha   = 1;
	int  color_r = 0;

	//プレイヤーのデータベース
	std::unique_ptr<IPlayerData>   _iplayer_data;

};