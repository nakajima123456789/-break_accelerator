#include "Result.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>


void C_RESULT::Initialize()
{
	Add_Sprite(_T("SPRITE//resultbackground.png"));
	result = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//result.png"));
	_1st = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//1st.png"));
	_2nd = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//2nd.png"));
	_3rd = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//3rd.png"));
}

void C_RESULT::Update()
{
	if (Input.GetKeybordInputDown(11)) { SceneManager::ChangeScene(SceneManager::RESULT); }
}

void C_RESULT::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
	SpriteBatch.Draw(*result, Vector3(0, 0, -1));
	SpriteBatch.Draw(*_1st, Vector3(100, 250, -1));
	SpriteBatch.Draw(*_2nd, Vector3(100, 400, -1));
	SpriteBatch.Draw(*_3rd, Vector3(100, 550, -1));
}

void C_RESULT::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}