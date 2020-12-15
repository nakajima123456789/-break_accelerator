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

	enemy = GraphicsDevice.CreateSpriteFromFile(_T("player.png"));
	enemy_pos = Vector3(0, 0, 0);

	theta = 0.0f;

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

	//x = y ‚Ì“ñ”{

	// TODO: Add your update logic here
	

	////y = 3/5x
	//enemy_pos.x = enemy_pos.x + 1;
	//enemy_pos.y = 3.0f / 5.0f * enemy_pos.x;
	
	// Y = X * x
	/*enemy_pos.x = enemy_pos.x + 1;
	enemy_pos.y = enemy_pos.x * enemy_pos.x / 500.0f;*/

	//float x = enemy_pos.x / 20.0f;
	//enemy_pos.x = enemy_pos.x + 1;
	//enemy_pos.y = (enemy_pos.x * enemy_pos.x * enemy_pos.x - 2 * enemy_pos.x);

	/*enemy_pos.x = enemy_pos.x + 1;
	enemy_pos.y = MathHelper_Cos(enemy_pos.x) * enemy_pos.x;*/

	/*enemy_pos.x = enemy_pos.x + 1;
	enemy_pos.y = MathHelper_Cos(theta) * 100;
	theta += 2.0f;*/

	enemy_pos.x = enemy_pos.x + 1;
	enemy_pos.y = Math_Log10(enemy_pos.x) * 100.0f;

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

	SpriteBatch.Draw(*enemy, enemy_pos);

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
