#include "C_GAME_OVER.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>

void C_GAME_OVER::Initialize()
{
	Add_Sprite(_T("SPRITE/game_over.png"));
}

void C_GAME_OVER::Update()
{
	if (Input.GetPadInputDown(11)||Input.GetKeyInputDown(Keys_Space)) { 
		
		SceneManager::ChangeScene(SceneManager::TITLE); }
}

void C_GAME_OVER::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
}

void C_GAME_OVER::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}