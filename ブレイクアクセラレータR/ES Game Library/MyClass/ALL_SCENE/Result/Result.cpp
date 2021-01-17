#include "Result.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>
#include <fstream>


void C_RESULT::Initialize()
{
	Add_Sprite(_T("SPRITE//resultbackground.png"));
	result = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//result.png"));
	_1st = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//1st.png"));
	_2nd = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//2nd.png"));
	_3rd = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//3rd.png"));

	font = GraphicsDevice.CreateSpriteFont(_T("digitalism"), 150);

	std::ifstream infile("score.dat");

	infile >> ranking_score[0] >> ranking_score[1] >> ranking_score[2];

	if (CUI::total > ranking_score[2]) {
		int work = ranking_score[2];
		ranking_score[2] = CUI::total;
	}

	if (ranking_score[2] > ranking_score[1]) {
		int work = ranking_score[1];
		ranking_score[1] = ranking_score[2];
		ranking_score[2] = work;
	}
	if (ranking_score[1] > ranking_score[0]) {
		int work = ranking_score[0];
		ranking_score[0] = ranking_score[1];
		ranking_score[1] = work;
	}
	std::ofstream outfile("score.dat");
	outfile << ranking_score[0] <<" "<< ranking_score[1] << " " << ranking_score[2];

}

void C_RESULT::Update()
{
	if (Input.GetKeybordInput(Keys_Enter)) { SceneManager::ChangeScene(SceneManager::TITLE); }


}

void C_RESULT::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });
	SpriteBatch.Draw(*result, Vector3(0, 0, -1));
	SpriteBatch.Draw(*_1st, Vector3(200, 200, -1));
	SpriteBatch.Draw(*_2nd, Vector3(200, 400, -1));
	SpriteBatch.Draw(*_3rd, Vector3(200, 600, -1));
	SpriteBatch.DrawString(font, Vector2(600.0f, 200.0f), Color(219,180,0), _T("%d"), ranking_score[0]);
	SpriteBatch.DrawString(font, Vector2(600.0f, 400.0f), Color(185,195,201), _T("%d"), ranking_score[1]);
	SpriteBatch.DrawString(font, Vector2(600.0f, 600.0f), Color(184,115,51), _T("%d"), ranking_score[2]);
}

void C_RESULT::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}