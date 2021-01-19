#include "GameClearScene.h"
#include "../SCENEMANAGER/SceneManager.h"

void GameClearScene::Initialize()
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//GAMECLEAR.png"));
}

void GameClearScene::Update()
{
	if (Input.GetPadInputDown(0,7))
	{
		SceneManager::ChangeScene(SceneManager::TITLE);
		return;
	}
}

void GameClearScene::Draw2D()
{
	SpriteBatch.Draw(*sprite, Vector3_Zero);
}
