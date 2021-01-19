
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
	InputDevice.CreateGamePad(1);
	MediaManager.Attach(GraphicsDevice);
	WindowTitle(_T("ES Game Library"));
	TITORU = GraphicsDevice.CreateSpriteFromFile(_T("select2.png"));
	mein = GraphicsDevice.CreateSpriteFromFile(_T("タイトル画面.png"));
	movie_ = MediaManager.CreateMediaFromFile(_T("mainview.wmv"));
	bgm = SoundDevice.CreateMusicFromFile(_T("SAKURA.wav"));
	se = SoundDevice.CreateSoundFromFile(_T("タップ.wav"));
	moji = GraphicsDevice.CreateSpriteFont(_T("javanece Text"), 80);
	moji2 = GraphicsDevice.CreateSpriteFont(_T("javanece Text"), 25);
	noot_spr = GraphicsDevice.CreateSpriteFromFile(_T("notes_basic.png"));

	//フラッシュ
	FR = GraphicsDevice.CreateSpriteFromFile(_T("miss.png"));
	FR_state_ = 0;
	FR_count_ = 0;

	FR1 = GraphicsDevice.CreateSpriteFromFile(_T("good.png"));
	FR1_state_ = 0;
	FR1_count_ = 0;

	FR2 = GraphicsDevice.CreateSpriteFromFile(_T("ok.png"));
	FR2_state_ = 0;
	FR2_count_ = 0;

	FR3 = GraphicsDevice.CreateSpriteFromFile(_T("ms.png"));
	FR3_state_ = 0;
	FR3_count_ = 0;
	//フラッシュ

	game_scene_ = 0;


	for (int i = 0; i < 200; i++) {
		noot_pos  [i] = Vector3_Zero;
		noot_state[i] = 0;
	}

	//noot 1番目　
	noot_pos[0] = Vector3(275, -900, 0);
	noot_pos[1] = Vector3(275, -400, 0);
	noot_pos[2] = Vector3(275, -600, 0);
	noot_pos[3] = Vector3(275, -800, 0);
	noot_pos[4] = Vector3(275, -1000, 0);
	noot_pos[5] = Vector3(275, -1200, 0);
	noot_pos[6] = Vector3(275, -1400, 0);
	noot_pos[7] = Vector3(275, -1600, 0);
	noot_pos[8] = Vector3(275, -1800, 0);
	noot_pos[9] = Vector3(275, -2000, 0);
	noot_pos[10] = Vector3(275, -2200, 0);
	noot_pos[11] = Vector3(275, -2400, 0);
	noot_pos[12] = Vector3(275, -2600, 0);
	noot_pos[13] = Vector3(275, -2800, 0);
	noot_pos[14] = Vector3(275, -3000, 0);
	noot_pos[15] = Vector3(275, -3200, 0);
	//noot ２番目

	noot_pos[50] = Vector3(485, -600, 0);
	noot_pos[51] = Vector3(485, -900, 0);
	noot_pos[52] = Vector3(485, -600, 0);
	noot_pos[53] = Vector3(485, -800, 0);
	noot_pos[54] = Vector3(485, -1000, 0);
	noot_pos[55] = Vector3(485, -1200, 0);
	noot_pos[56] = Vector3(485, -1400, 0);
	noot_pos[57] = Vector3(485, -1600, 0);
	noot_pos[58] = Vector3(485, -1800, 0);
	noot_pos[59] = Vector3(485, -2000, 0);
	noot_pos[60] = Vector3(485, -2200, 0);
	noot_pos[61] = Vector3(485, -2400, 0);
	noot_pos[62] = Vector3(485, -2600, 0);
	noot_pos[63] = Vector3(485, -2800, 0);
	noot_pos[64] = Vector3(485, -3000, 0);
	noot_pos[65] = Vector3(485, -3200, 0);
	//noot ３番目

	noot_pos[100] = Vector3(710, -200, 0);
	noot_pos[101] = Vector3(710, -400, 0);
	noot_pos[102] = Vector3(710, -600, 0);
	noot_pos[103] = Vector3(710, -800, 0);
	noot_pos[104] = Vector3(710, -1000, 0);
	noot_pos[105] = Vector3(710, -1200, 0);
	noot_pos[106] = Vector3(710, -1400, 0);
	noot_pos[107] = Vector3(710, -1600, 0);
	noot_pos[108] = Vector3(710, -1800, 0);
	noot_pos[109] = Vector3(710, -2000, 0);
	noot_pos[110] = Vector3(710, -2200, 0);
	noot_pos[111] = Vector3(710, -2400, 0);
	noot_pos[112] = Vector3(710, -2600, 0);
	noot_pos[113] = Vector3(710, -2800, 0);
	noot_pos[114] = Vector3(710, -3000, 0);
	noot_pos[115] = Vector3(710, -3200, 0);
	//noot ４番目

	noot_pos[150] = Vector3(900, -200, 0);
	noot_pos[151] = Vector3(900, -400, 0);
	noot_pos[152] = Vector3(900, -600, 0);
	noot_pos[153] = Vector3(900, -800, 0);
	noot_pos[154] = Vector3(900, -1000, 0);
	noot_pos[155] = Vector3(900, -1200, 0);
	noot_pos[156] = Vector3(900, -1400, 0);
	noot_pos[157] = Vector3(900, -1600, 0);
	noot_pos[158] = Vector3(900, -1800, 0);
	noot_pos[159] = Vector3(900, -2000, 0);
	noot_pos[160] = Vector3(900, -2200, 0);
	noot_pos[161] = Vector3(900, -2400, 0);
	noot_pos[162] = Vector3(900, -2600, 0);
	noot_pos[163] = Vector3(900, -2800, 0);
	noot_pos[164] = Vector3(900, -3000, 0);
	noot_pos[165] = Vector3(900, -3200, 0);

	for (int i = 0; i < 200; i++) {
		if(noot_pos[i] != Vector3_Zero)
			noot_state[i] = 1;
	}

	player1 = GraphicsDevice.CreateSpriteFromFile(_T("WAKU.png"));
	player1_x_ = 275.0f, player1_y_ = 560.0f;

	player = GraphicsDevice.CreateSpriteFromFile(_T("WAKU.png"));
	player_x_ = 485.0f, player_y_ = 560.0f;

	player2 = GraphicsDevice.CreateSpriteFromFile(_T("WAKU.png"));
	player2_x_ = 710.0f, player2_y_ = 560.0f;

	player3 = GraphicsDevice.CreateSpriteFromFile(_T("WAKU.png"));
	player3_x_ = 900.0f, player3_y_ = 560.0f;

	Line = GraphicsDevice.CreateSpriteFromFile(_T("線.png"));
	Line_x_ = 0.0f, Line_y_ = 600.0f;

	good = 0;
	miss = 0;
	timer = 252;

	good_state_ = 0;
	good_count_ = 0;

	miss_state_ = 0;
	miss_count_ = 0;

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
	GamePadState pad_state = GamePad(0)->GetState();	
	GamePadBuffer pad_buffer = GamePad(0)->GetBuffer();

	  if (game_scene_ == 0) {
		  if (pad_buffer.IsPressed(GamePad_Button12)) {
			  game_scene_ = 1;
		  }
	  }


	 else if (game_scene_ == 1) {
	    if (pad_buffer.IsPressed(GamePad_Button12)) {
			
			game_scene_ = 2;
			//１番目
			noot_pos[0] = Vector3(275, -900, 0);
			//２番目

			//3番目
			noot_pos[100] = Vector3(710, -200, 0);
	        noot_pos[101] = Vector3(710, -400, 0);
			//4番目
			noot_pos[150] = Vector3(900, -200, 0);
			noot_pos[151] = Vector3(900, -400, 0);
			//1234
			movie_->Play();
			bgm->Play();
			for (int i = 0; i < 200; i++) {
				if (noot_pos[i] != Vector3_Zero)
					noot_state[i] = 1;
				good = 0;
				miss = 0;

			}
		}
	}

     if (game_scene_ == 2) {

		  count--; 
		  if (count % 60 == 0) {
			  timer--;
			  count = 60;
		  }

		//フラッシュ

		if (FR_state_ == 1) {
			FR_count_++;
			if (FR_count_ >= 5) {
				FR_state_ = 0;
			}
		}
		if (FR_state_ == 0) {
			FR_count_ = 0;
		}

		if (FR1_state_ == 1) {
			FR1_count_++;
			if (FR1_count_ >= 10) {
				FR1_state_ = 0;
			}
		}
		if (FR1_state_ == 0) {
			FR1_count_ = 0;
		}

		if (FR2_state_ == 1) {
			FR2_count_++;
			if (FR2_count_ >= 5) {
				FR2_state_ = 0;
			}
		}
		if (FR2_state_ == 0) {
			FR2_count_ = 0;
		}

		if (FR3_state_ == 1) {
			FR3_count_++;
			if (FR3_count_ >= 10) {
				FR3_state_ = 0;
			}
		}
		if (FR3_state_ == 0) {
			FR3_count_ = 0;
		}

		if (miss_state_ == 1) {
			miss_count_++;
			if (miss_count_ >= 10) {
				miss_state_ = 0;
			}
		}
		if (miss_state_ == 0) {
			miss_count_ = 0;
		}

		if (good_state_ == 1) {
			good_count_++;
			if (good_count_ >= 10) {
				good_state_ = 0;
			}
		}
		if (good_state_ == 0) {
			good_count_ = 0;
		}

		//フラッシュ



		if (movie_->IsComplete()) {
			movie_->Replay();
		}

		for (int i = 0; i < 200; i++) {
			if (noot_state[i] == 1) {
				noot_pos[i].y = noot_pos[i].y + 3.5f;
			}
		}
		//一番目
		if (pad_buffer.IsPressed(GamePad_Button1)) {
			RectWH perfect_rect(294, 616, 90, 20);

			RectWH great_up(294, 596, 90, 20);
			RectWH great_down(294, 636, 90, 20);

			RectWH ok_up(294, 576, 90, 20);
			RectWH ok_down(294, 656, 90, 20);

			RectWH miss_up(294, 556, 90, 40);
			RectWH miss_down(294, 676, 90, 20);
			for (int i = 0; i < 200; i++) {
				if (noot_state[i] == 0)
					continue;

				RectWH  note_rect(noot_pos[i].x + 10, noot_pos[i].y + 55, 100, 10);
				if (note_rect.Intersect(perfect_rect)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_up)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_down)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}
			}
		}

		//二番目

		if (pad_buffer.IsPressed(GamePad_Button2)) {
			RectWH perfect_rect(503.9, 616, 90, 20);

			RectWH great_up(503.9, 596, 90, 20);
			RectWH great_down(503.9, 636, 90, 20);

			RectWH ok_up(503.9, 576, 90, 20);
			RectWH ok_down(503.9, 656, 90, 20);

			RectWH miss_up(503.9, 556, 90, 60);
			RectWH miss_down(503.9, 676, 90, 20);
			for (int i = 0; i < 200; i++) {
				if (noot_state[i] == 0)
					continue;

				RectWH  note_rect(noot_pos[i].x + 10, noot_pos[i].y + 55, 100, 10);
				if (note_rect.Intersect(perfect_rect)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_up)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_down)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}
			}
		}

		//３番目

		if (pad_buffer.IsPressed(GamePad_Button3)) {
			RectWH perfect_rect(728, 616, 90, 20);

			RectWH great_up(728, 596, 90, 20);
			RectWH great_down(728, 636, 90, 20);

			RectWH ok_up(728, 576, 90, 20);
			RectWH ok_down(728, 656, 90, 20);

			RectWH miss_up(728, 556, 90, 60);
			RectWH miss_down(728, 676, 90, 20);
			for (int i = 0; i < 200; i++) {
				if (noot_state[i] == 0)
					continue;

				RectWH  note_rect(noot_pos[i].x + 10, noot_pos[i].y + 55, 100, 10);
				if (note_rect.Intersect(perfect_rect)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_up)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_down)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}
			}
		}


		//４番目
		if (pad_buffer.IsPressed(GamePad_Button4)) {
			RectWH perfect_rect(920, 616, 90, 20);

			RectWH great_up(920, 596, 90, 20);
			RectWH great_down(920, 636, 90, 20);

			RectWH ok_up(920, 576, 90, 20);
			RectWH ok_down(920, 656, 90, 20);

			RectWH miss_up(920, 556, 90, 60);
			RectWH miss_down(920, 676, 90, 20);
			for (int i = 0; i < 200; i++) {
				if (noot_state[i] == 0)
					continue;

				RectWH  note_rect(noot_pos[i].x + 10, noot_pos[i].y + 55, 100, 10);
				if (note_rect.Intersect(perfect_rect)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(great_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_up)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(ok_down)) {
					se->Play();
					noot_state[i] = 0;
					good += 100;
					FR2_state_ = 1;
					FR1_state_ = 1;
					good_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_up)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}

				else if (note_rect.Intersect(miss_down)) {
					se->Play();
					noot_state[i] = 0;
					miss -= 20;
					FR_state_ = 1;
					FR3_state_ = 1;
					miss_state_ = 1;
					break;
				}

				
			}
		}

	}


	 if (game_scene_ == 1) {
	     if (pad_state.Buttons[10] != 0) {
			 game_scene_ = 0;
			 bgm->Stop();
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


		if (game_scene_ == 0) {
			SpriteBatch.Draw(*mein, Vector3(0.0f, 0.0f, 0.0f));
		}

		if (game_scene_ == 1) {
			SpriteBatch.Draw(*TITORU, Vector3(0.0f, 0.0f, 0.0f));
		}

		if (game_scene_ == 2) {
			SpriteBatch.Draw(*movie_, Vector3(0.0f, 0.0f, 1000.0f), 1.0f,
				Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), 1.0f);

			//フラッシュ
			if (FR_state_ == 1) {
				SpriteBatch.Draw(*FR, Vector3(0.0f, 0.0f, 0.0f), 0.3f);
			}

			if (FR1_state_ == 1) {
				SpriteBatch.Draw(*FR1, Vector3(550.0f, 300.0f, 0.0f), 1.0f,Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), 1.5f);
			}

			if (FR2_state_ == 1) {
				SpriteBatch.Draw(*FR2, Vector3(0.0f, 0.0f, 0.0f), 0.3f);
			}

			if (FR3_state_ == 1) {
				SpriteBatch.Draw(*FR3, Vector3(550.0f, 300.0f, 0.0f), 1.0f, Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), 1.5f);
			}
			//フラッシュ

			SpriteBatch.Draw(*player, Vector3(player_x_, player_y_, 0.0f));
			SpriteBatch.Draw(*player1, Vector3(player1_x_, player1_y_, 0.0f));
			SpriteBatch.Draw(*player2, Vector3(player2_x_, player2_y_, 0.0f));
			SpriteBatch.Draw(*player3, Vector3(player3_x_, player3_y_, 0.0f));
			SpriteBatch.Draw(*Line, Vector3(Line_x_, Line_y_, 0.0f));

			for (int i = 0; i < 200; i++) {
				if (noot_state[i] == 1) {
					SpriteBatch.Draw(*noot_spr, noot_pos[i]);
				}
			}

			//文字　count スカウト
			if (good_state_ == 1) {
				
			}
			if (miss_state_ == 1) {
				SpriteBatch.DrawString(moji2, Vector2(0.0f, 170.0f), Color(0, 255, 0), _T("   miss   :%d"), miss);
			}
			SpriteBatch.DrawString(moji, Vector2(0.0f, 0.0f), Color(255, 0, 0), _T("残り:%d秒"), timer);
		}
		SpriteBatch.End();

		GraphicsDevice.EndScene();

	    Canvas canvas = GraphicsDevice.LockCanvas();

		Paint paint;

		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(Rect(0.0f,640.0f , 1280.0f, 650.0f), paint);

		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(294, 556, 90, 40), paint);
		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(294, 576, 90, 20), paint);

		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(294, 596, 90, 20), paint);
		////上
		//paint.SetPaintColor(Color(0, 0, 255));
		//canvas.DrawRect(RectWH(294,616,90,20),paint);
		////下
		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(294, 636, 90, 20), paint);

		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(294, 656, 90, 20), paint);

		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(294, 676, 90, 20), paint);

		////二番目
		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(503.9, 556, 90, 60), paint);

		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(503.9, 576, 90, 20), paint);

		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(503.9, 596, 90, 20), paint);
		////上
		//paint.SetPaintColor(Color(0, 0, 255));
		//canvas.DrawRect(RectWH(503.9, 616, 90, 20), paint);
		////下
		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(503.9, 636, 90, 20), paint);

		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(503.9, 656, 90, 20), paint);

		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(503.9, 676, 90, 20), paint);

		////三番目
		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(728, 556, 90, 60), paint);

		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(728, 576, 90, 20), paint);

		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(728, 596, 90, 20), paint);
		////上
		//paint.SetPaintColor(Color(0, 0, 255));
		//canvas.DrawRect(RectWH(728, 616, 90, 20), paint);
		////下
		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(728, 636, 90, 20), paint);

		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(728, 656, 90, 20), paint);

		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(728, 676, 90, 20), paint);

		////四番目
		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(920, 556, 90, 60), paint);

		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(920, 576, 90, 20), paint);

		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(920, 596, 90, 20), paint);
		////上
		//paint.SetPaintColor(Color(0, 0, 255));
		//canvas.DrawRect(RectWH(920, 616, 90, 20), paint);
		////下
		//paint.SetPaintColor(Color(0, 255, 0));
		//canvas.DrawRect(RectWH(920, 636, 90, 20), paint);,

		//paint.SetPaintColor(Color(255, 255, 0));
		//canvas.DrawRect(RectWH(920, 656, 90, 20), paint);

		//paint.SetPaintColor(Color(255, 0, 0));
		//canvas.DrawRect(RectWH(920, 676, 90, 20), paint);

		GraphicsDevice.UnlockCanvas();

	}
