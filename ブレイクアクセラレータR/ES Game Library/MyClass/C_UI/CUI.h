#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include"../OBSEVER/OBSEVER.h"

#include "../CSHAREDMETHOD/CSharedMethod.h"
#include "../C_SPRITE/C_Sprite.h"
#include "../C_UI/CUI.h"
#include "../UIDATABASE/UiDataBase.h"

#include "../C_EFFEKSEER/CEffekseer_.h"
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
	virtual void CUI::OnCollisionDamage()    override;
	virtual void CUI::OnCollisionClear()     override;
	virtual void CUI::OnCollisionGage()      override;
	
	int count_num();

private:
	OBSERVER      observer;
	SpriteManager sprite_mng;

	int gage;

	int speed_meta;
	int count = 1;


	//プレイヤーのデータベース
	std::unique_ptr<UiData>        _ui_data;
	std::unique_ptr<IPlayerData>   _player_data;

	int item,damage;
};

