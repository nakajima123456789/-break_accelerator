#include "GameResultScene.h"
#include "../SCENEMANAGER/SceneManager.h"
#include "../../UiDataBase/UiDataBase.h"

#include <stdio.h>

void GameResultScene::Initialize()
{
    Add_Sprite(_T("SPRITE//resultbackground.png"));
	Add_Sprite(_T("SPRITE//result.png"));

	ranking_sprite[RANKING::_1st] = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//1st.png"));
	ranking_sprite[RANKING::_2nd] = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//2nd.png"));
	ranking_sprite[RANKING::_3rd] = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//3rd.png"));

	font = GraphicsDevice.CreateSpriteFont(_T("digitalism"), 100);

	RoadFileCsv("Ranking//Ranking.txt");
}

void GameResultScene::Update()
{
	if (Input.GetPadInput(0,7)){SceneManager::ChangeScene(SceneManager::TITLE);}
}

void GameResultScene::Draw2D()
{
	std::for_each(sprite_list.begin(), sprite_list.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3(0, 0, 0)); });

	Color  color[] = { Color(219, 180, 0), Color(185, 195, 201),Color(184, 115, 51) };

	for (int i = 0; i < RANKING::MAX; i++) {
		SpriteBatch.Draw(*ranking_sprite[i], Vector3(200.f, 200.f * (i + 1), -1));
		SpriteBatch.DrawString(font,         Vector2(600.f, 200.f * (i + 1)), color[i], _T("%d"), ranking_score[i]);
	}
}

void GameResultScene::Add_Sprite(LPCTSTR _sprite_name)
{
	SPRITE sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list.push_back(sprite);
}

void GameResultScene::RoadFileCsv(char* file_name)
{
	FILE* fp = fopen(file_name, "r");
	char load_char[99999 + 1];

	std::vector<cstring> ranking_data;

	ranking_sort.push_back(UiDataBase.GetTimerSize() * 100);

	while (fgets(load_char, sizeof load_char - 1, fp) != NULL){
		ranking_data.push_back(load_char);
		ranking_sort.push_back(atoi(ranking_data[ranking_data.size() - 1].c_str()));
	}
	fclose(fp);

	sort(ranking_sort.begin(), ranking_sort.end());
	ranking_sort.erase(ranking_sort.begin());

	WritingFileCsv(file_name);
}

void GameResultScene::WritingFileCsv(char* file_name)
{
	FILE* fp2 = fopen(file_name, "w");

	for (int i = 0; i < ranking_sort.size(); i++) {
		ranking_score[i] = ranking_sort[2 - i];
		string data_writing = std::to_string(ranking_sort[i]) + "\n";
		fprintf(fp2, data_writing.c_str()); // ƒtƒ@ƒCƒ‹‚É‘‚­
	}

	fclose(fp2);
}

