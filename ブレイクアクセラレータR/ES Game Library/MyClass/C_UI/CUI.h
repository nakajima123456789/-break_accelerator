#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include"../OBSEVER/OBSEVER.h"
#include "../CSHAREDMETHOD/CSharedMethod.h"
#include "../C_SPRITE/C_Sprite.h"
#include "../C_UI/CUI.h"
#include "../UIDATABASE/UiDataBase.h"

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
	
private:
	OBSERVER      observer;
	SpriteManager sprite_mng;

	int gage;

	//プレイヤーのデータベース
	std::unique_ptr<UiData>   _ui_data;
};

