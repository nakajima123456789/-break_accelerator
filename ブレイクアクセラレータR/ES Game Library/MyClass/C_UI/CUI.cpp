#include "CUI.h"
#include"../INFORMATION/INFORMATION.h"


CUI::CUI()
{
	//Ž©•ª‚ðƒŠƒXƒg‚É“o˜^
	observer.addListener(this);
}

CUI::~CUI()
{
	//Ž©•ª‚ðƒŠƒXƒg‚©‚çíœ
	observer.removeListener(this);
}

void CUI::Init()
{
	sprite_mng.CreateSpriteFromFile(_T("UI/FWƒQ[ƒW/FW_base.png"),  Vector3(365.0f, 0.0f, 0.0f));
	sprite_mng.CreateSpriteFromFile(_T("UI/FWƒQ[ƒW/FW_base2.png"), Vector3(365.0f, 0.0f, 0.0f));
	
	gage       = sprite_mng.CreateSpriteFromFileRect(_T("UI/FWƒQ[ƒW/FW_S.png"), Vector3(365.0f, 0.0f, 0.0f));
	speed_gage = sprite_mng.CreateSpriteFromFileRect(_T("UI/speedgage/sp.png"),  Vector3(0.0f, 0.0f, 0.0f));

	IUiParametor::Instance().CreateParametor("ui");

	_ui_data.reset(new UiData);
}
 
void CUI::Update()
{	


}

void CUI::OnCollisionDamage()
{
	_ui_data->SetGageParams("ui", +2);
	this->count--;
}

void CUI::OnCollisionClear()
{
	_ui_data->SetGageParams("ui", -5);
	this->count++;
}

void CUI::Draw2D()
{
	count = this->clamp(count, 1, 9);
	sprite_mng.SetRectWH(speed_gage, 192 * count, 0, 192, 192);

	sprite_mng.SetRectWH(gage, 0, 0, (540 * 0.01) * _ui_data->GetGageParams("ui"), 48);
	sprite_mng.DrawSprite();
}

