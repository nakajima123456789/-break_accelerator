#include "C_TITLE.h"
#include "../SCENEMANAGER/SceneManager.h"
#include "../../C_INPUT/C_INPUT.h"
#include <algorithm>


void C_TITLE::Initialize()
{
	Add_Sprite(_T("SPRITE/title.png"));
	moji = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/taitoru 2.png"));
	
	
}

void C_TITLE::Update()
{

	if (Input.GetPadInputDown(1)||Input.GetKeyInputDown(Keys_Space)){SceneManager::ChangeScene(SceneManager::MAIN);} 

}

void C_TITLE::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite)
		{SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
	
	SpriteBatch.Draw(*moji, Vector3(0, 0, 0),Color(255,255,255));

}

void C_TITLE::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
	
}