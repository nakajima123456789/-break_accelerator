#include "Result.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>
#include "../../C_UI/CUI.h"


void C_RESULT::Initialize()
{
	Add_Sprite(_T("SPRITE/result.png"));

	original = GraphicsDevice.CreateSpriteFont(_T("Digitalism"), 80);
	score_plus = 0;
}

int C_RESULT::Update()
{
	if (Input.GetPadInputDown(11)||Input.GetKeyInputDown(Keys_Space)) { SceneManager::ChangeScene(SceneManager::TITLE); }
	score_plus += 2;
	return 99;
}

void C_RESULT::Draw2D()
{
	float score = CUI::GetScore();
	if (score_plus >= score) { score_plus = score; }

	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
	SpriteBatch.DrawString(original, Vector2(550, 210)
		, Color(255, 0, 0), _T(" %.0f"), score_plus);
}

void C_RESULT::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}