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
	chara = GraphicsDevice.CreateSpriteFromFile(_T("player.png"));
	chara_pos = Vector3(200, 360, 0);

	teki = GraphicsDevice.CreateSpriteFromFile(_T("player.png"));
	teki_pos = Vector3(0, 0, 0);
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
	KeyboardState key_state = Keyboard->GetState();

	//if (key.IsPressed(Keys_Space))
	//{                    //ベクトル +１        // ゴール             //スタート    
	//	chara_pos += Vector3_Normalize(Vector3(274, 190, 0) - Vector3(640, 360, 0) * 20);
	//}

	teki_pos += Vector3_Normalize(chara_pos - teki_pos * 2);

	if (key_state.IsKeyDown(Keys_Left));
	{
		chara_pos.x -= 10;
	}

	if (key_state.IsKeyDown(Keys_Right));
	{
		chara_pos.x += 10;
	}

	if (key_state.IsKeyDown(Keys_Up));
	{
		chara_pos.y -= 10;
	}

	if (key_state.IsKeyDown(Keys_Down));
	{
		chara_pos.y += 10;
	}
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
	SpriteBatch.Draw(*chara, chara_pos);
	SpriteBatch.Draw(*teki, teki_pos);

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
