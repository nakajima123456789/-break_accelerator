#include "GameTitleScene.h"
#include "../SCENEMANAGER/SceneManager.h"

void GameTitleScene::Initialize()
{
	sprite[TITLE_LEFT]  = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/quantum.png"));
	sprite[TITLE_RIGHT] = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/accelerator.png"));
	sprite[START]       = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/start.png"));
	sprite[BACK]        = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE/background.png"));
}

void GameTitleScene::Update()
{
	move_index += 20;
	move_index = Math_Min(move_index, 1280);

	start_alpha += 0.01f;

	if (Input.GetPadInputDown(0,7)){SceneManager::ChangeScene(SceneManager::MAIN);}
}

void GameTitleScene::Draw2D()
{
	SpriteBatch.Draw(*sprite[BACK], Vector3(0, 0, 0));

	SpriteBatch.Draw(*sprite[TITLE_RIGHT], Vector3( 1280 - move_index, 0, 0));
	SpriteBatch.Draw(*sprite[TITLE_LEFT],  Vector3(-1280 + move_index, 0, 0));

	SpriteBatch.Draw(*sprite[START], Vector3(0, 0, 0), start_alpha);
}
