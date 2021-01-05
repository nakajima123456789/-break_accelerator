#include "CUI.h"
#include"../INFORMATION/INFORMATION.h"


CUI::CUI()
{
	//自分をリストに登録
	observer.addListener(this);
}

CUI::~CUI()
{
	//自分をリストから削除
	observer.removeListener(this);
}

void CUI::Init()
{
	//sprite_mng.CreateSpriteFromFile(_T("UI/FWゲージ/FW_base.png"),  Vector3(365.0f, 0.0f, 0.0f));
	//sprite_mng.CreateSpriteFromFile(_T("UI/FWゲージ/FW_base2.png"), Vector3(365.0f, 0.0f, 0.0f));	
	//gage       = sprite_mng.CreateSpriteFromFileRect(_T("UI/FWゲージ/FW_S.png"), Vector3(365.0f, 0.0f, 0.0f));
	speed_gage = sprite_mng.CreateSpriteFromFileRect(_T("UI/speedgage/sp.png"),  Vector3(0.0f, 0.0f, 0.0f));

	black_out = sprite_mng.CreateSprite(Vector2(1280.0f, 720.0f), Color(0, 0, 0), Vector3(0.0f,0.0f, SpriteBatch_TopMost));

	font      = GraphicsDevice.CreateSpriteFont(_T("Comic Sans MS"), 90);

	game_timer = MAX_TIMER;

	IUiParametor::Instance().CreateParametor("ui");

	_ui_data.reset(new UiData);
}
 
void CUI::Update()
{	
	if (black_out_flag) { sprite_mng.BlackOutTrigger(black_out); };

	if (this->FrameTimeObsever(60)) 
	{
		gagefcomveter += (MAX_TIMER * 0.1f);
		game_timer--;
	};
	_ui_data->SetGageParams("ui", gagefcomveter);
}

void CUI::Draw2D()
{
	sprite_mng.SetRectWH(speed_gage, 192 * _ui_data->GetSpeedMeterParams("ui"), 0, 192, 192);

	game_timer = this->clamp(game_timer, 0, MAX_TIMER);

	SpriteBatch.DrawString(font, Vector2(595.0f, 0.0f), Color(255, 255, 255), _T("%d"), game_timer);

	sprite_mng.DrawSprite();
}

void CUI::OnCollision(std::string collsion_tag)
{
	if (collsion_tag == "DAMAGE") { 
		CollisionTypeDamage();    return;
	};
	if (collsion_tag == "RECOVERY") {
		CollisionTypeRecovery();  return;
	};
	if (collsion_tag == "GAMEOVER") {
		CollisionTypeGameOver();  return;
	};
	if (collsion_tag == "ITEMBROCK") {
		CollisionTypeItemBrock(); return;
	};
	ASSERT(FALSE && "衝突判定のタグ名が違います。");
}

void CUI::CollisionTypeDamage()
{
	game_timer -= 2;
	gagefcomveter += (MAX_TIMER * 0.1f) * 2;

	_ui_data->SetSpeedMeterParams("ui", -1);
}

void CUI::CollisionTypeRecovery()
{
	_ui_data->SetSpeedMeterParams("ui",  1);
}

void CUI::CollisionTypeGameOver()
{
	black_out_flag = true;
}

void CUI::CollisionTypeItemBrock()
{
	game_timer += 2;
	gagefcomveter -= (MAX_TIMER * 0.1f) * 2;
}

