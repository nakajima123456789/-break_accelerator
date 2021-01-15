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
	player = GraphicsDevice.CreateSpriteFromFile(_T("player.png"));
	player_x_ = 100.0f, player_y_ = 500.0f;

	count = 0;
	player_state_ = 0;
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
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	KeyboardState key_state = Keyboard->GetState();



	if (player_state_ == 0) {

		if (key_state.IsKeyDown(Keys_Space)) {
			jump_power_ = 30;
			player_state_ = 1;
			
		}

	}

	if (player_state_ == 1) {
		player_y_ = player_y_ - jump_power_;
		jump_power_ = jump_power_ - 1.0;

		/*if (player_y_ > 500) {
			player_y_ = 500;
			player_state_ = 0;
		}*/
		
	}

	if (key_state.IsKeyDown(Keys_Left)) {
		player_x_ = player_x_ - 10;

	}

	/*if (player_state_ == 0) {

		if (key_state.IsKeyDown(Keys_Space)) {
			jump_power_ = -0.1;
			player_state_ = 1;

		}

	}

	if (player_state_ == 1) {
		player_x_ = player_x_ - jump_power_;
		jump_power_ = jump_power_ - 1.0;

		if (player_y_ > 500) {
			player_y_ = 500;
			player_state_ = 0;
		}

	}*/

	return 0;
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
	
	SpriteBatch.Draw(*player, Vector3(player_x_, player_y_ , 0.0f));

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
