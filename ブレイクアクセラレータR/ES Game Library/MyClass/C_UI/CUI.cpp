#include "CUI.h"

void CUI::Init()
{
	auto&& AddSprite = [this](LPCTSTR _filename) { sprite.push_back(GraphicsDevice.CreateSpriteFromFile(_filename));};
	
	auto&& AddSpritePos = [this](unsigned int id, Vector3 pos) {sprite_position[id].push_back(pos); };

	AddSprite(_T("UI/FWÉQÅ[ÉW/FW_base.png"));
	AddSprite(_T("UI/FWÉQÅ[ÉW/FW_base2.png"));
	

	sprite_position.resize(SPRITE_MAX);

	AddSpritePos(FW,   Vector3(320, 0, 0));
	AddSpritePos(FW2,  Vector3(320, 0, 0));
	
	
	FW_L = GraphicsDevice.CreateSpriteFromFile(_T("UI/FWÉQÅ[ÉW/FW_left.png"));
	FW_R = GraphicsDevice.CreateSpriteFromFile(_T("UI/FWÉQÅ[ÉW/FW_R.png"));
	fw_L = 233;
	fw_R = 0;
	Right = 10;
}

void CUI::Update()
{
	
	
	fw_L -= 1;
	if (fw_L<0)
	{
		fw_L = 0;
	}
	else if (fw_L==0)
	{
		fw_L = fw_L+1;
		
	}
	

	fw_R = fw_R + 1;
	
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

	SpriteBatch.Draw(*FW_L, Vector3(350.0f, 10.0f, 0.0f), Rect(0, 0, fw_L, 50), 1.f, Vector3_Zero, Vector3(0, 0, 0), 1);
	SpriteBatch.Draw(*FW_R, Vector3(fw_R+580, 10.0f, 0.0f), Rect(fw_R, 0, 590, 50), 1.f, Vector3_Zero, Vector3(0, 0, 0), 1);
	

}