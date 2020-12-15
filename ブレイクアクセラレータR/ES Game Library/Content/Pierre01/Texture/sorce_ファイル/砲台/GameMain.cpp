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

	chara = GraphicsDevice.CreateSpriteFromFile(_T("note1.png"));
	shot = GraphicsDevice.CreateSpriteFromFile(_T("note.png"));

	canon_angle = 0;
	shot_state = 0;

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
	KeyboardState key = Keyboard->GetState();

	if (key.IsKeyDown(Keys_Right)) 
	{
		canon_angle -= 2.0f;
	}

	if (key.IsKeyDown(Keys_Left))
	{
		canon_angle += 2.0f;
	}

	if (shot_state == 0) 
	{
		if (key.IsKeyDown(Keys_Space))
		{
			shot_state = 1;
			shot_pos = Vector3(608, 328, 0);

		}
	}
	else {
		shot_pos.y -= 4.0f;
		if (shot_pos.x <= 24 || shot_pos.x >=1280 || shot_pos.y <= 0 || shot_pos.y >= 720)
		{
			shot_state = 0;
		}
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

	/*SpriteBatch.Draw(*chara, chara_pos);*/

	SpriteBatch.Draw(*chara, Vector3(608, 328, 0.0), 1.0f,
		Vector3(0.0f, 0.0f, canon_angle),
		Vector3(52.0f, 52.0f, 0.0f), 1.0f);

	if (shot_state == 1)
	{
		SpriteBatch.Draw(*shot, shot_pos);
	}


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
