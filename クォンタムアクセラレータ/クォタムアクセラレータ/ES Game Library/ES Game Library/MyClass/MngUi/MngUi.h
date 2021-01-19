#pragma once
#include "../Object/Object.h"
#include "../Observer/Observer.h"

#include "../SharedMethod/SharedMethod.h"
#include "../MngSprite/MngSprite.h"

#include "../UiDataBase/UiDataBase.h"

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

	virtual void MngUi::CollisionTypeDamage();
	virtual void MngUi::CollisionTypeItem();
	virtual void MngUi::CollisionTypeRecovery();

private:
	Observer      observer;
	MngSprite     mng_sprite;

	int gage;
	int speed_gage;
	int blackOut;

	FONT  font;
	int game_timer;

	int MAX_TIMER     = 30;
	int gagefcomveter = 100;

	bool game_over_flag = false;

};