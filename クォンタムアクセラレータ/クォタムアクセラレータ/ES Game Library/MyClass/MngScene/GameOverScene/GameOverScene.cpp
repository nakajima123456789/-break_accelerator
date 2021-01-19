#include "GameOverScene.h"
#include "../SCENEMANAGER/SceneManager.h"

void GameOverScene::Initialize()
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//GameOver.png"));
}

void GameOverScene::Update()
{
	if (Input.GetPadInputDown(0,7)){
		SceneManager::ChangeScene(SceneManager::TITLE);
		return;
	}
}

void GameOverScene::Draw2D()
{
	SpriteBatch.Draw(*sprite, Vector3_Zero);
}
