#include "GameTitleScene.h"
#include "../SCENEMANAGER/SceneManager.h"

void GameTitleScene::Initialize()
{
	//sprite = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//gemestart_02.png"));
}

void GameTitleScene::Update()
{
	if (Input.GetPadInputDown(0,7)){SceneManager::ChangeScene(SceneManager::MAIN);}
}

void GameTitleScene::Draw2D()
{
	//SpriteBatch.Draw(*sprite, Vector3_Zero);
}
