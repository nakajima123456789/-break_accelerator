#include "GameResultScene.h"
#include "../SCENEMANAGER/SceneManager.h"


void GameResultScene::Initialize()
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//ÉQÅ[ÉÄê‡ñæ.png"));
}

void GameResultScene::Update()
{
	if (Input.GetPadInputDown(0,7)){SceneManager::ChangeScene(SceneManager::MAIN);}
}

void GameResultScene::Draw2D()
{
	SpriteBatch.Draw(*sprite, Vector3_Zero);
}