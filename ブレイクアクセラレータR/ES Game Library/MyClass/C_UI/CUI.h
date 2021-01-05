#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include"../OBSEVER/OBSEVER.h"

#include "../CSHAREDMETHOD/CSharedMethod.h"
#include "../C_SPRITE/C_Sprite.h"
#include "../C_UI/CUI.h"
#include "../UIDATABASE/UiDataBase.h"

#include "../CPLAYERDATA/CPlayerData.h"

class CUI : public Object, OBSERVERLISTENER, CSharedMethod
{
public:

	CUI();
	~CUI();

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;
	
	//オブザーバー関数
	virtual void CUI::OnCollision(std::string collsion_tag)     override;

	virtual void CUI::CollisionTypeDamage();
	virtual void CUI::CollisionTypeRecovery();
	virtual void CUI::CollisionTypeGameOver();
	virtual void CUI::CollisionTypeItemBrock();
private:
	OBSERVER      observer;
	SpriteManager sprite_mng;

	int gage;
	int speed_gage;
	int black_out;

	FONT  font;
	int game_timer;
	int MAX_TIMER = 30;
	int gagefcomveter = 0;

	bool black_out_flag = false;

	//プレイヤーのデータベース
	std::unique_ptr<UiData>        _ui_data;
};