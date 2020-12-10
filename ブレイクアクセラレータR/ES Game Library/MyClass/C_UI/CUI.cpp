#include "CUI.h"
#include"../INFORMATION/INFORMATION.h"

#include "../C_EFFEKSEER/CEffekseer_.h"
#include "../C_INPUT/C_INPUT.h"

CUI::CUI()
{
	//���������X�g�ɓo�^
	observer.addListener(this);
}

CUI::~CUI()
{
	//���������X�g����폜
	observer.removeListener(this);
}

void CUI::Init()
{
	sprite_mng.CreateSpriteFromFile(_T("UI/FW�Q�[�W/FW_base.png"),  Vector3(365.0f, 0.0f, 0.0f));
	sprite_mng.CreateSpriteFromFile(_T("UI/FW�Q�[�W/FW_base2.png"), Vector3(365.0f, 0.0f, 0.0f));
	
	gage = sprite_mng.CreateSpriteFromFileRect(_T("UI/FW�Q�[�W/FW_S.png"), Vector3(365.0f, 0.0f, 0.0f));
	
	IUiParametor::Instance().CreateParametor("ui");

	_ui_data.reset(new UiData);
	_player_data.reset(new IPlayerData);

	item   = EffekseerMgr.LoadEffekseer(_T("�A�C�e���擾//�A�C�e���擾.efk"));
	damage = EffekseerMgr.LoadEffekseer(_T("�_���[�W//�_���[�W.efk"));
}

void CUI::Update()
{


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
	_ui_data->SetGageParams("ui", +2);
}

void CUI::OnCollisionClear()
{
	_ui_data->SetGageParams("ui", -2);

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
	sprite_mng.DrawSprite();
}

