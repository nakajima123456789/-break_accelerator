#include "Result.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>


void C_RESULT::Initialize()
{
	Add_Sprite(_T("‰æ‘œ"));
}

void C_RESULT::Update()
{
	if (Input.GetPadInputDown(11)) { SceneManager::ChangeScene(SceneManager::RESULT); }
}

void C_RESULT::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
}

void C_RESULT::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}