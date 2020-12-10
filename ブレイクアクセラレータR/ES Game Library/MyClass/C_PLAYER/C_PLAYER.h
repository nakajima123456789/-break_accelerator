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
#include "../../Velocity.h"
#include "../../RotationMove.h"

class CPlayerStateProcessor;
class CPlayer;

enum PLAYER_MOVE_TYPE
{
	NOMAL,
	ROTATION,
};

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

	void ChangeStateType(PLAYER_MOVE_TYPE move_type);

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
		DAMAGE(CPlayerStateProcessor* owner) : _owner(owner) {}
		virtual ~DAMAGE() {}

		virtual int    CancelLv() { return INT_MAX; };
		virtual int    ExitTime() { return 30; };

		virtual void Update() override;
	};



private:
	//関数宣言

	void ChangeMoveType (PLAYER_MOVE_TYPE move_type);

    //変数宣言

	Model     p_model;

	HitBox*   p_hitbox;
	Velocity* p_velocity;

	RotationMove* p_rotation;

	unsigned int MOVE_TYPE_MAX_SIZE = 2;

	int state_type;

	//プレイヤーのデータベース
	std::unique_ptr<IPlayerData>   _iplayer_data;
};