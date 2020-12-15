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
	//1280=720
	InputDevice.CreateGamePad(1);
	InputDevice.CreateMouse();

	HAIKEI = GraphicsDevice.CreateSpriteFromFile(_T("背景.jpg"));
	HAIKEI_x_ = 0.0f; HAIKEI_y_ = 0.0f;

	chara = GraphicsDevice.CreateSpriteFromFile(_T("kyara.png"));
	chara_x_ = 0.0f, chara_y_ = 0.0f;
	
	a = GraphicsDevice.CreateSpriteFromFile(_T("player.jpg"));
    a_x_ = 0.0f, a_y_ = 0.0f;

	camera_x_ = 0.0f, camera_y_ = 0.0f;
	
	EF = GraphicsDevice.CreateSpriteFromFile(_T("アアニメーション.png"));
	

	/*chara = GraphicsDevice.CreateSpriteFromFile(_T("kyara.png"));
	chara_x_ = 200.0f, chara_y_ = 300.0f, chara_z_ = 0.0f;*/

    count1 = 0;
	count = 0;

//	a_state_ = 0;

	chara_state_ = 5;

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
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	//GamePadState pad_state = GamePad(0)->GetState();
	MouseState mouse_state
		= Mouse->GetState();

	if (key_state.IsKeyDown(Keys_Left)) {
		a_x_ = a_x_ - 10.0f;
		a_state_ = 1;
	}
	if (key_state.IsKeyDown(Keys_Right)) {
		a_state_ = 2;
		a_x_ = a_x_ + 10.0f;
	}
	if (key_state.IsKeyDown(Keys_Down)) {
		a_state_ = 0;
		a_y_ = a_y_ + 10.0f;
	}
	if (key_state.IsKeyDown(Keys_Up)) {
		a_state_ = 3;
		a_y_ = a_y_ - 10.0f;
	}

	/*if (pad_state.X > Axis_Center) {
		a_x_ = a_x_ + 7.0f;
			a_state_ = 2;
	}

	if (pad_state.X < Axis_Center) {
		a_x_ = a_x_ - 7.0f;
		a_state_ = 1;
	}

	if (pad_state.Y < Axis_Center) {
		a_y_ = a_y_ - 7.0f;
		a_state_ = 3;
	}

	if (pad_state.Y > Axis_Center) {
		a_y_ = a_y_ + 7.0f;
		a_state_ = 0;
	}*/

	//if (mouse_state.X > Axis_Center) {
	//	a_x_ = a_x_ + 7.0f;
	//	a_state_ = 2;
	//}

	//if (mouse_state.X < Axis_Center) {
	//	a_x_ = a_x_ - 7.0f;
	//	a_state_ = 1;
	//}

	//if (mouse_state.Y < Axis_Center) {
	//	a_y_ = a_y_ - 7.0f;
	//	a_state_ = 3;
	//}

	//if (mouse_state.Y > Axis_Center) {
	//	a_y_ = a_y_ + 7.0f;
	//	a_state_ = 0;
	//}

	//a_x_ = a_x_ + mouse_state.X * 10;

	//a_y_ = a_y_ + mouse_state.Y * 10;

	//if (key_state.IsKeyDown(Keys_Left)) {
	//	camera_x_ = camera_x_ - 10;
	//}
	//if (key_state.IsKeyDown(Keys_Right)) {
	//	camera_x_ = camera_x_ + 10;
	//}
	//if (key_state.IsKeyDown(Keys_Down)) {
	//	camera_y_ = camera_y_ + 10;
	//}
	//if (key_state.IsKeyDown(Keys_Up)) {
	//	camera_y_ = camera_y_ - 10;
	//}


	//if (pad_state.Buttons[0]!= 0) {
	//	a_x_ = a_x_ - 10.0f;
	//	a_state_ = 1;
	//}

	//if (pad_state.Buttons[3]!= 0) {
	//	a_x_ = a_x_ + 10.0f;
	//	a_state_ = 2;
	//}

	count1++;
	count++;

	//a_y_ = a_y_ + 2.5f;

	//a_x_ = a_x_ + 5.0f;

	//(count1 % (60 * 2) = 0) 

	if (count > 4) {
		player_frame = player_frame + 200;
		count = 0;
	}
	

	if (player_frame >= 2800)
		player_frame = 0;


	/*chara_z_ = chara_z_ + 10.0f;*/

     if (chara_state_ == 5) {
		 chara_x_ = chara_x_ + 100.0f;
		 if (chara_x_ > 4000) {
			 chara_state_ = 6;
		 }
	  }
	
	 if (chara_state_ == 6) {
		 chara_x_ = chara_x_ - 100.0f;
		 if (chara_x_ < 0) {
			 chara_state_ = 5;
		 }
	 }

	 if (a_x_ < 0) {
		 a_x_ = 0;
	 }

	 if (a_x_ > 4000) {
		 a_x_ = 4000;
	 }

	 if (a_y_ < 0) {
		 a_y_ = 0;
	 }

	  if (a_y_ > 4000) {
		 a_y_ = 4000;
	 }


	  if (camera_x_ < 0) {
		  camera_x_ = 0;
	  }

	  if (camera_x_ > 2700) {
		  camera_x_ = 2700;
	  }

	  if (camera_y_ < 0) {
		  camera_y_ = 0;
	  }

	  if (camera_y_ > 3000) {
		  camera_y_ = 3000;
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
	SpriteBatch.Draw(*HAIKEI, Vector3(HAIKEI_x_- camera_x_, HAIKEI_y_ - camera_y_, 1000.00f));

	if (chara_state_ == 5) {
		SpriteBatch.Draw(*chara, Vector3(chara_x_ - camera_x_, chara_y_ - camera_y_, 0.00f));
	}

	if (chara_state_ == 6) {
		SpriteBatch.Draw(*chara, Vector3(chara_x_ - camera_x_, chara_y_ - camera_y_, 0.00f));
	}

	//SpriteBatch.Draw(*a, Vector3(a_x_ - camera_x_, a_y_ - camera_y_, 0.0f));

	if (a_state_ == 0) {
		SpriteBatch.Draw(*EF, Vector3(a_x_, a_y_, 0.0f), RectWH(player_frame, 0, 200, 300)); /*1.0f,
			Vector3(20.0f, 0.0f, 0.0f), Vector3(50.0f, 50.0f, 0.0f);*/
	}
	
	if (a_state_ == 1) {
		SpriteBatch.Draw(*EF, Vector3(a_x_, a_y_, 0.0f), RectWH(player_frame, 310, 200, 300));
	}

	if (a_state_ == 2) {
		SpriteBatch.Draw(*EF, Vector3(a_x_, a_y_, 0.0f), RectWH(player_frame, 620, 200, 300));
	}

	if (a_state_ == 3) {
		SpriteBatch.Draw(*EF, Vector3(a_x_, a_y_, 0.0f), RectWH(player_frame, 930, 200, 300));
	}

	/*SpriteBatch.Draw(*chara, Vector3(chara_x_, chara_y_, 0.0f), 1.0f,
		Vector3(0.0f, 0.0f, chara_z_), Vector3(0.0f, 0.0f, 0.0f), 1.0f);*/

	SpriteBatch.End();

	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;

	/*paint.SetPaintColor(Color(0, 0, 255));
	canvas.DrawRect(Rect(a_x_ + 0, a_y_ + 0, a_x_ + 100, a_y_ + 100), paint);*/

	/*paint.SetPaintColor(Color(0, 255, 0));
	canvas.DrawRect(Rect(640.0f,0.0f,650.0f,720.0f), paint);*/
	
    GraphicsDevice.UnlockCanvas();

}
