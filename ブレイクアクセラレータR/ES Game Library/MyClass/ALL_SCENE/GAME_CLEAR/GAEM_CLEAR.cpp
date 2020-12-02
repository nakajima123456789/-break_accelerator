#include "GAEM_CLEAR.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>


void GAEM_CLEAR::Initialize()
{
	Add_Sprite(_T("SPRITE/geme crear.png"));
}

int GAEM_CLEAR::Update()
{
	if (Input.GetPadInputDown(11)||Input.GetKeyInputDown(Keys_Space)) 
	{ 
		return 2;
	}
	return -1;
}

void GAEM_CLEAR::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
}

void GAEM_CLEAR::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}