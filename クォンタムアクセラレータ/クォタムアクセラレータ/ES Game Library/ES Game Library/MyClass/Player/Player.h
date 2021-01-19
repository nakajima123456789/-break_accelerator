#pragma once

#include "../Object/Object.h"

#include "../HitBox/HitBox.h"
#include "../Distance/Distance.h"
#include "../Camera/GameCamera.h"
#include "../Velocity/Velocity.h"
#include "../Accelaretor/Accelaretor.h"
#include "../Observer/Observer.h"
#include "../MngEffekseer/MngEffekseer.h"

class CPlayerStateProcessor;
class Player;

class CPlayerStateProcessor : public  StateProcessor {
public:
	Player* p_player;
};

class Player : public Object, SharedMethod
{
private:
	Observer observer;

	MODEL         p_model      = nullptr;
	GameCamera*   gameCamera   = nullptr;
	HitBox*       p_hitbox     = nullptr;
	MngEffekseer* p_effekseer  = nullptr;
	Accelaretor* p_accelaretor = nullptr;
	Accelaretor_Parameter accelaretor_parameter;

	EFFECT shader  = nullptr;
	int    alpha   = 1;
	int    color_r = 0;

	UINT effect_item;

public:
	CPlayerStateProcessor p_player_processor;
	
	//コンストラクタ
	Player(Vector3  _position);
	//デストラクタ
	virtual ~Player();

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };

	virtual void DrawAlpha3D() override;
	virtual void Draw2D()      override { return; };

	void AttackHit(int attack_type);

private:

	class IDOL : public State{
	private:
		CPlayerStateProcessor* _owner;
	public:
		IDOL(CPlayerStateProcessor* owner);
		virtual ~IDOL() { delete _owner; };
		virtual void Update() override;
	};

	class DAMAGE : public State{
	private:
		CPlayerStateProcessor* _owner;
	public:
		DAMAGE(CPlayerStateProcessor* owner);
		virtual ~DAMAGE() { delete _owner; }
		virtual int    ExitTime() override { return 30; };
		virtual void   Update()   override;
	};

	class RECOVERY : public State{
	private:
		CPlayerStateProcessor* _owner;
	public:
		RECOVERY(CPlayerStateProcessor* owner);
		virtual ~RECOVERY() { delete _owner; }
		virtual int    ExitTime() override { return 15; };
		virtual void   Update()   override;
	};

	class GETITEM : public State{
	private:
		CPlayerStateProcessor* _owner;
	public:
		GETITEM(CPlayerStateProcessor* owner);
		virtual ~GETITEM() { delete _owner; }
		virtual int    ExitTime() override { return 15; };
		virtual void   Update()   override;
	};

	//関数宣言
	void SetAccelaretorParameter();
	void SetAccelaretor();
};