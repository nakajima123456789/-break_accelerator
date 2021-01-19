#pragma once
#include "../Object/Object.h"
#include "../Observer/Observer.h"

#include "../SharedMethod/SharedMethod.h"
#include "../MngSprite/MngSprite.h"

#include "../UiDataBase/UiDataBase.h"

#include "../GameMastaer/GameMastaer.h"
#include "../Timer/Timer.h"

class MngUi : public Object, Observerlistener, SharedMethod
{
public:

	MngUi();
	~MngUi();

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;

	//オブザーバー関数
	virtual void MngUi::OnCollision(int collsionType) override;
	virtual void MngUi::OnAddTiemr (int add_timer)    override;

	virtual void MngUi::CollisionTypeDamage();
	virtual void MngUi::CollisionTypeItem();
	virtual void MngUi::CollisionTypeRecovery();

	void PlayerSpeedUp();

private:
	Observer      observer;
	MngSprite*    mng_sprite;
	Time*         timer;
	GameMastaer   gameMastaer;

	enum { SPEED, BLACK, SPEED_UP,SPRITE_MAX, };
	int  sprite[SPRITE_MAX];

	bool gameoverFlag  = false;

	bool speed_up_flag = false;

	int add_item_point = 1;
};