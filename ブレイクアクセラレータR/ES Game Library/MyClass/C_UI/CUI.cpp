#include "CUI.h"

void CUI::Init()
{
	auto&& AddSprite = [this](LPCTSTR _filename) { sprite.push_back(GraphicsDevice.CreateSpriteFromFile(_filename));};
	
	auto&& AddSpritePos = [this](unsigned int id, Vector3 pos) {sprite_position[id].push_back(pos); };

	AddSprite(_T("UI/FW�Q�[�W/FW_base.png"));
	AddSprite(_T("UI/FW�Q�[�W/FW_base2.png"));
	

	sprite_position.resize(SPRITE_MAX);

	AddSpritePos(FW,   Vector3(320, 0, 0));
	AddSpritePos(FW2,  Vector3(320, 0, 0));
	
	
	FW_S = GraphicsDevice.CreateSpriteFromFile(_T("UI/FW�Q�[�W/FW_S.png"));
	
	fw_S = 540;
	
}

void CUI::Update()
{
	
	
	fw_S -= 2;
	if (fw_S < 0)
	{
		fw_S = 0;
	}
	 if (fw_S == 0)
	{
		fw_S = fw_S +3;
	}
	 if (fw_S > 540)
	 {
		 fw_S = 540;
	 }

	
	
}

void CUI::Draw2D()
{



	for (int y = 0; y < sprite_position.size(); y++)
	{
		for (int x = 0; x < sprite_position[y].size(); x++)
		{
			SpriteBatch.Draw(*sprite[y], sprite_position[y][x]);
		}
	}

	SpriteBatch.Draw(*FW_S, Vector3(320.0f, 0.0f, 0.0f), Rect(0, 0, fw_S, 50), 1.f, Vector3_Zero, Vector3(0, 0, 0), 1);
	

}