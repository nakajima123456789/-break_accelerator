// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));


	player = GraphicsDevice.CreateSpriteFromFile(_T("note.png"));
	for (int i = 0; i < 10; i++) {
		player_x_[i] = 0 - 70 * i;
		player_y_[i] = 0.0f;
        player_state_[i] = 0;
        bezier_t_[i] = 0;
	}

	game_scene_ = MAIN_SCENE;
	
	
	//位置
	
	

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here
}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here

	// キーボード入力

	if (game_scene_ == TITLE_SCENE) {
		// タイトルシーン?処理
		TitleSceneUpdate();
	}
	else if (game_scene_ == MAIN_SCENE) {
		// メインシーン?処理
		MainSceneUpdate();
	}
	else if (game_scene_ == RESULT_SCENE) {
		// リザルトシーン?処理
		ResultSceneUpdate();
	}

	return 0;
}
void GameMain::TitleSceneUpdate()
{

}

void GameMain::MainSceneUpdate()
{
	KeyboardState key_state = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	for (int i = 0; i < 10; i++)
	{

		if (player_state_[i] == 0)
		{
			player_x_[i] += 5.0;

			if (player_x_[i] >= 700)
			{
				player_state_[i] = 1;
			}

		}

		if (player_state_[i] == 1)
		{
			
				Vector3 bezier = Vector3_Bezier(Vector3(700.0f, 0.0f, 0.0f),
				Vector3(400.0f, 400.0f, 0.0f),
				Vector3(400.0f, -400.0f, 0.0f),
				Vector3(700.0f, 500.0f, 0.0f), bezier_t_[i]);

				player_x_[i] = bezier.x;
				player_y_[i] = bezier.y;
			

				bezier_t_[i] += 0.005;
				if (bezier_t_[i] >= 1.0f)
				{
					player_state_[i] = 2;
				}
			
		}

		if (player_state_[i] == 2)
		{
			player_x_[i] -= 5.0;
		}


	}














		////スピード
		////if (player_state_ != 1)
		////{
		////	bezier_t_ += 0.1f;
		////}


		////////////
		//if (player_state_ == 0) {
		//	bezier_t_ += 0.01f;
		//	if(bezier_t_ >= 1.0f)
		//	{
		//		player_state_ = 1;
		//	}
		//}
		//else if (player_state_ == 1) {
		//	bezier_t_ -= 0.01f;
		//	if (bezier_t_ <= 0.0f)
		//	{
		//		player_state_ = 0;
		//	}
		//}




	
}

void GameMain::ResultSceneUpdate()
{

}


/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);
	
	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();
	if (game_scene_ = MAIN_SCENE)
	{
		for (int i = 0; i < 10; i++) {
			SpriteBatch.Draw(*player, Vector3(player_x_[i], player_y_[i], 0));
		}
	}



	SpriteBatch.End();

	GraphicsDevice.EndScene();

}
