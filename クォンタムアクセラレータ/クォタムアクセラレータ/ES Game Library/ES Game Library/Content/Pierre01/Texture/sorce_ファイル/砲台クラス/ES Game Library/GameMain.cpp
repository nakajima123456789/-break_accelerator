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

	

	/*for(int i = 0; i < 100; i++)
	{
		enemy1[i].Initialize(Vector3(1280.0f + i * 100,0,0));
	}
	

	bg1.Initialize();
	enemy2_2.Initialize();
	note2.ini();*/

	player1.Initialize(Vector3(0,0,0),_T("6053568i.png"));
	player_2.Initialize(Vector3(0,200,0),_T("Brock.png"));
	

	//shot_.ini();
	 
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
	
	KeyboardState Key_state = Keyboard->GetState();
	KeyboardBuffer Key_buffer = Keyboard->GetBuffer();

	player1.Update(Key_state,Key_buffer);
	player_2.Update(Key_state, Key_buffer);



	//for (int i = 0; i < 100; i++)
	//{
	//	enemy1[i].Update();
	//}
	//enemy2_2.UpDate();

	//bg1.Update();
	//note2.Up();


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

	player1.Draw();
	/*for (int i = 0; i < 100; i++)
	{
		enemy1[i].Draw();
	}
	bg1.Draw();
	enemy2_2.Draw();
	note2.Draw();*/
	player_2.Draw();
	//shot_.Draw();
	

	Rect collision1 = player1.GetCollision();
	Rect collision2 = player_2.GetCollision();

	/*if (collision1.Intersect(collision2)) {
		GraphicsDevice.Clear(Color_Red);
	}
	else {
		bg1.Draw();
	}*/

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}

//Intersect Œð·‚µ‚Ä‚é‚©

