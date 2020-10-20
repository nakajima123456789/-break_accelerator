#include "CUI.h"

void CUI::Init()
{
	auto&& AddSprite = [this](LPCTSTR _filename) { sprite.push_back(GraphicsDevice.CreateSpriteFromFile(_filename));};
	
	auto&& AddSpritePos = [this](unsigned int id, Vector3 pos) {sprite_position[id].push_back(pos); };

	AddSprite(_T("UI/FWÉQÅ[ÉW/FW_base.png"));
	AddSprite(_T("UI/FWÉQÅ[ÉW/FW_base2.png"));
	AddSprite(_T("UI/FWÉQÅ[ÉW/FW_left.png"));
	AddSprite(_T("UI/FWÉQÅ[ÉW/FW_R.png"));

	sprite_position.resize(SPRITE_MAX);

	AddSpritePos(FW,   Vector3(0, 0, 0));
	AddSpritePos(FW2,  Vector3(0, 0, 0));
	AddSpritePos(FW_L, Vector3(0, 0, 0));
	AddSpritePos(FW_R, Vector3(0, 0, 0));



}

void CUI::Update()
{
}

void CUI::Draw2D()
{

	sprite_position[FW][0].x++;

	for (int y = 0; y < sprite_position.size(); y++)
	{
		for (int x = 0; x < sprite_position[y].size(); x++)
		{
			SpriteBatch.Draw(*sprite[y], sprite_position[y][x]);
		}
	}


}
