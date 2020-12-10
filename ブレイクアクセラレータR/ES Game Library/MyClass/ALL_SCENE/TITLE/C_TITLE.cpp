#include "C_TITLE.h"
#include "../SCENEMANAGER/SceneManager.h"
#include "../../C_INPUT/C_INPUT.h"
#include <algorithm>


void C_TITLE::Initialize()
{
	Add_Sprite(_T("SPRITE/title.png"));
	moji = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/taitoru_sita.png"));
	moji2 = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/taitoru_ue.png"));
	moji3 = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/start.png"));
	iro = 0; moji_x = 0;

}

int C_TITLE::Update()
{
	if (Input.GetPadInputDown(1) || Input.GetKeyInputDown(Keys_Enter)) {
		return 0;
	}

	moji_x += 20;
	if (moji_x >= 1280) { moji_x = 1280;   iro += 0.01; }
	return 99;
}

void C_TITLE::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite)
		{SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });

	SpriteBatch.Draw(*moji, Vector3(1280 - moji_x, -200, 0));
	SpriteBatch.Draw(*moji2, Vector3(-1280 + moji_x, -200, 0));
	SpriteBatch.Draw(*moji3, Vector3(0, 0, 0), iro);

}

void C_TITLE::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);

}