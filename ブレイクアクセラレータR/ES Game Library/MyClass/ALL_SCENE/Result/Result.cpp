#include "Result.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>
#include "../../C_UI/CUI.h"


void C_RESULT::Initialize()
{
	Add_Sprite(_T("SPRITE/result.png"));

	original = GraphicsDevice.CreateSpriteFont(_T("Digitalism"), 180);

}

void C_RESULT::Update()
{
	if (Input.GetPadInputDown(11)||Input.GetKeyInputDown(Keys_Space)) { SceneManager::ChangeScene(SceneManager::TITLE); }
}

void C_RESULT::Draw2D()
{
	float unko = CUI::GetScore();
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
	SpriteBatch.DrawString(original, Vector2(650, 260)
		, Color(255, 0, 0), _T(" %.0f"), unko);
}

void C_RESULT::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}