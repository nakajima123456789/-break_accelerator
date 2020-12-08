#include "CUI.h"
#include"../INFORMATION/INFORMATION.h"

#include "../C_EFFEKSEER/CEffekseer_.h"
#include "../C_INPUT/C_INPUT.h"

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
	sprite_mng.CreateSpriteFromFile(_T("UI/FWゲージ/FW_base.png"),  Vector3(365.0f, 0.0f, 0.0f));
	sprite_mng.CreateSpriteFromFile(_T("UI/FWゲージ/FW_base2.png"), Vector3(365.0f, 0.0f, 0.0f));
	
	sprite_mng.CreateSpriteFromFile(_T("UI/speedgage/speedbase_2.png"), Vector3(0, 0, 0));

	gage_apha.resize(3);

	gage_apha[0].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage1.png"), Vector3(0, 0, 0)));
	gage_apha[0].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage2.png"), Vector3(0, 0, 0)));
	gage_apha[0].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage3.png"), Vector3(0, 0, 0)));

	gage_apha[1].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage4.png"), Vector3(0, 0, 0)));
	gage_apha[1].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage5.png"), Vector3(0, 0, 0)));
	gage_apha[1].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage6.png"), Vector3(0, 0, 0)));
																				  
	gage_apha[2].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage7.png"), Vector3(0, 0, 0)));
	gage_apha[2].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage8.png"), Vector3(0, 0, 0)));
	gage_apha[2].push_back(sprite_mng.CreateSpriteFromFileAlpha(_T("UI/speedgage/gage9.png"), Vector3(0, 0, 0)));

	sprite_mng.CreateSpriteFromFile(_T("UI/speedgage/speed_0.png"), Vector3(0, 0, 0));
	




	gage = sprite_mng.CreateSpriteFromFileRect(_T("UI/FWゲージ/FW_S.png"), Vector3(365.0f, 0.0f, 0.0f));
	
	IUiParametor::Instance().CreateParametor("ui");

	_ui_data.reset(new UiData);
	_player_data.reset(new IPlayerData);

	item   = EffekseerMgr.LoadEffekseer(_T("アイテム取得//アイテム取得.efk"));
	damage = EffekseerMgr.LoadEffekseer(_T("ダメージ//ダメージ.efk"));

}

void CUI::Update()
{
	if (Input.GetKeyBuffer().IsPressed(Keys_Space))
	{
		
	}
}

void CUI::OnCollisionDamage()
{
	int id = -1;
	Vector3 player_pos = _player_data->GetPlayerPosition("player");
	EFFEKSEER effekseer = EffekseerMgr.GetEffekseer(damage);
	id = effekseer->Play(player_pos - Vector3(0, 0, -1));
	if (id != -1)
	{
		effekseer->SetPosition(id, player_pos - Vector3(0, 0, -1));
	}
	_ui_data->SetGageParams("ui", +1);
}

void CUI::OnCollisionClear()
{
	_ui_data->SetGageParams("ui", -1);
	size++;

}

void CUI::OnCollisionGage()
{
	int id = -1;
	Vector3 player_pos = _player_data->GetPlayerPosition("player");
	EFFEKSEER effekseer = EffekseerMgr.GetEffekseer(item);
	id = effekseer->Play(player_pos - Vector3(0, 0, -1));
	if (id != -1)
	{
		effekseer->SetScale(id, 0.5);
		effekseer->SetPosition(id, player_pos - Vector3(0, 0, -1));
	}

}

void CUI::Draw2D()
{
	sprite_mng.SetRectWH(gage, 0, 0, (540 * 0.01) * _ui_data->GetGageParams("ui"), 48);

	size = this->clamp(size, 0, 3);

	for (int i = 0; i < size; i++)
	{
		sprite_mng.SetAlpha(gage_apha[count][i], 1.0f);
		if (i == 2)
		{
			if(this->FrameTimeObsever(30))
			{
				if (count != 2) {
					for (int i = 0; i < 3; i++)
					{
						sprite_mng.SetAlpha(gage_apha[count][i], 0.0f);
					}
				}
				size = 1;
				count++;
				count = this->clamp(count, 0, 2);
			}
		}
	}


	sprite_mng.DrawSprite();
}

