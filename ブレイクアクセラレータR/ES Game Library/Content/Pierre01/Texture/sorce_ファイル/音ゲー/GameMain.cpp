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
	InputDevice.CreateGamePad(1);
	MediaManager.Attach(GraphicsDevice);

	game_scene_ = 0;
	
	//タイトル画面
	title = GraphicsDevice.CreateSpriteFromFile(_T("title2.png"));
	title_x_ = 0.0f, title_y_ = 0.0f;

	//セレクト画面
	select = GraphicsDevice.CreateSpriteFromFile(_T("select6.png"));
	select_x_ = 0.0f, select_y_ = 0.0f;

	game_start = GraphicsDevice.CreateSpriteFromFile(_T("game start.png"));
	game_start_x_ = 460.0f, game_start_y_ = 550.0f;

	//リザルト画面
	RIZALT = GraphicsDevice.CreateSpriteFromFile(_T("score3.png"));
	RIZALT_x_ = 0.0f, RIZALT_y_ = 0.0f;


	//スコアカウント
	good_count = 0;
	perfect_count = 0;
	miss_count = 0;
	total_count = 0;

	/////////////////////
	start_ = 1.0;
	count1 = 0;
	count_frame = 0;

	moji2 = GraphicsDevice.CreateSpriteFont(_T("Comic Sans MS"), 90);
	moji3 = GraphicsDevice.CreateSpriteFont(_T("Comic Sans MS"), 150);

	//ゲージ
	GAGE = GraphicsDevice.CreateSpriteFromFile(_T("ゲージ本体.png"));
	GAGE_x_ = 800.0f, GAGE_y_ = 10.0f,

	gagemeter = GraphicsDevice.CreateSpriteFromFile(_T("緑ゲージ.png"));
	gagemeter_x_ = 880.0f, gagemeter_y_ = 28.0f,
	METER_POWER = 880;

	

	a = 1.0;
    /////////////////////////////////////////

	METER_POWER = 0;
	meter_state = 0;
	HP_POWER = 400;
	timer = 0.0f;
	

	Loll = GraphicsDevice.CreateSpriteFromFile(_T("1234567890.png"));
	

	/*BGM = SoundDevice.CreateMusicFromFile(_T("BGM2_1_1.wav"));*/
	

	SE = SoundDevice.CreateSoundFromFile(_T("タップ.wav"));
	SE_2 = SoundDevice.CreateSoundFromFile(_T("タップ.wav"));
	SE_3 = SoundDevice.CreateSoundFromFile(_T("button63.wav"));
	

    movie_ = MediaManager.CreateMediaFromFile(_T("mainview_2.wmv"));
	movie_EF = MediaManager.CreateMediaFromFile(_T("紙吹雪_2.wmv"));
	

	WAKU = GraphicsDevice.CreateSpriteFromFile(_T("notes_hits_line.png"));
	WAKU_x_ = 0.0f, WAKU_y_ = 550.0f;

	//HP
	HPfull = GraphicsDevice.CreateSpriteFromFile(_T("heart.png"));
	HPfull_x_ = 0.0f, HPfull_y_ = 0.0f;

	HP = GraphicsDevice.CreateSpriteFromFile(_T("heartWARE.png"));
	HP_x_ = 0.0f, HP_y_ = 0.0f;

	HP2 = GraphicsDevice.CreateSpriteFromFile(_T("heartWARE2.png"));
	HP2_x_ = 0.0f, HP2_y_ = 0.0f;

	HP3 = GraphicsDevice.CreateSpriteFromFile(_T("heartWARE3.png"));
	HP3_x_ = 0.0f, HP3_y_ = 0.0f;

	HP_state = 0;

	//アニメーション
	EF = GraphicsDevice.CreateSpriteFromFile(_T("notes_hits_line_efe.png"));
	EF_x_ = 160.0,EF_y_ = 530.0;
	EF_frame = 0;
	EF_state = 0;

	EF2 = GraphicsDevice.CreateSpriteFromFile(_T("notes_hits_line_efe.png"));
	EF2_x_ = 880.0, EF2_y_ = 530.0;
	EF2_frame = 0;
	EF2_state = 0;


    EFLoll = GraphicsDevice.CreateSpriteFromFile(_T("notes_stretch_basic2.png"));
	EFLoll_x_ = 200.0f, EFLoll_y_ = 540.0f;
	EFLoll_frame = 0;
	EFLoll_state = 0;

	EFLoll_2 = GraphicsDevice.CreateSpriteFromFile(_T("notes_stretch_basic2.png"));
	EFLoll_2_x_ = 830.0f, EFLoll_2_y_ = 540.0f;
	EFLoll_2_frame = 0;
	EFLoll_2_state = 0;

	/////////////////////////////////
	

	//サイリウム
	psyllium_ = GraphicsDevice.CreateSpriteFromFile(_T("サイリウム緑改.png"));
	psyllium_.position.x = 180.0f;
	psyllium_.position.y = 500.0f;
	psyllium_.anchorPoint = Vector3(42.0, 190, 0);

	psyllium_2 = GraphicsDevice.CreateSpriteFromFile(_T("サイリウム黄色改.png"));
	psyllium_2.position.x = 1130.0f;
	psyllium_2.position.y = 500.0f;
	psyllium_2.anchorPoint = Vector3(32.0, 190, 0);

	////////////////////////////

	//判定
	good = GraphicsDevice.CreateSpriteFromFile(_T("great.png"));
	good_x_ = 530.0f, good_y_ = 340.0f;
	count2 = 0;
	good_state_ = 0;

	perfect = GraphicsDevice.CreateSpriteFromFile(_T("perfect.png"));
	perfect_x_ = 520.0f, perfect_y_ = 340.0f;
	count3 = 0;
	perfect_state_ = 0;

	BAD = GraphicsDevice.CreateSpriteFromFile(_T("miss.png"));
	BAD_x_ = 560.0f, BAD_y_ = 340.0f;
	count4 = 0;
	BAD_state_ = 0;
	
	///////////////////////////////

	//NOOT
	noot_spr = GraphicsDevice.CreateSpriteFromFile(_T("notes_basic3_efe.png"));
	for (int i = 0; i < 200; i++) {
		noot_state[i] = -2;
		NOOT_frame[i] = 0;

	}
	//LEFT
	noot_state[0] = GameTimer.GetFPS() * 0.001;
	noot_pos[0] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[1] = GameTimer.GetFPS() * 13.8;
	noot_pos[1] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[2] = GameTimer.GetFPS() * 14.3;
	noot_pos[2] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[3] = GameTimer.GetFPS() * 16.5;
	noot_pos[3] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[4] = GameTimer.GetFPS() * 17.3;
	noot_pos[4] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[5] = GameTimer.GetFPS() * 20.4;
	noot_pos[5] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[6] = GameTimer.GetFPS() * 21.1;
	noot_pos[6] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[7] = GameTimer.GetFPS() * 23.5;
	noot_pos[7] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[8] = GameTimer.GetFPS() * 27.2;
	noot_pos[8] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[9] = GameTimer.GetFPS() * 29.1;
	noot_pos[9] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[10] = GameTimer.GetFPS() * 32.0;
	noot_pos[10] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[11] = GameTimer.GetFPS() * 34.0;
	noot_pos[11] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);
	
	noot_state[12] = GameTimer.GetFPS() * 34.7;
	noot_pos[12] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[13] = GameTimer.GetFPS() * 37.3;
	noot_pos[13] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[14] = GameTimer.GetFPS() * 38.1;
	noot_pos[14] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[15] = GameTimer.GetFPS() * 54.5;
	noot_pos[15] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	noot_state[16] = GameTimer.GetFPS() * 54.9;
	noot_pos[16] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

	

	//RIGHT
	noot_state[100] = GameTimer.GetFPS() * 0.001;
	noot_pos[100] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[101] = GameTimer.GetFPS() * 13.5;
	noot_pos[101] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[102] = GameTimer.GetFPS() * 16.0;
	noot_pos[102] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[103] = GameTimer.GetFPS() * 16.9;
	noot_pos[103] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);
	
	noot_state[104] = GameTimer.GetFPS() * 17.8;
	noot_pos[104] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[105] = GameTimer.GetFPS() * 20.7;
	noot_pos[105] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[106] = GameTimer.GetFPS() * 24.0;
	noot_pos[106] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[107] = GameTimer.GetFPS() * 25.0;
	noot_pos[107] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[108] = GameTimer.GetFPS() * 27.6;
	noot_pos[108] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[109] = GameTimer.GetFPS() * 28.6;
	noot_pos[109] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[110] = GameTimer.GetFPS() * 30.0;
	noot_pos[110] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[111] = GameTimer.GetFPS() * 31.5;
	noot_pos[111] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[112] = GameTimer.GetFPS() * 33.0;
	noot_pos[112] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[113] = GameTimer.GetFPS() * 34.3;
	noot_pos[113] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[114] = GameTimer.GetFPS() * 35.0;
	noot_pos[114] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[115] = GameTimer.GetFPS() * 37.7;
	noot_pos[115] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	noot_state[116] = GameTimer.GetFPS() * 38.5;
	noot_pos[116] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	/*noot_state[117] = GameTimer.GetFPS() * 38.6;
	noot_pos[117] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);*/

	noot_state[118] = GameTimer.GetFPS() * 54.9;
	noot_pos[118] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

	

	/*noot_state[105] = GameTimer.GetFPS() * 19.0;
	noot_pos[105] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);*/

	/*noot_state[105] = GameTimer.GetFPS() * 17,5;
	noot_pos[105] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);*/

	//Z
	Z_spr[Z_LEFT] = GraphicsDevice.CreateSpriteFromFile(_T("notes_gizagiza_line2.png"));
	Z_spr[Z_RIGHT] = GraphicsDevice.CreateSpriteFromFile(_T("notes_gizagiza_line999.png"));
	for (int i = 0; i < 200; i++) {
		Z_state[i] = -1;
	}
	//Z_LEFT
	/*Z_state[0] = GameTimer.GetFPS() * 0.6;
	Z_pos[0] = Vector3(Z_POS_LEFT, Z_INIT_Y, 0);
	Z_type[0] = Z_LEFT;

	Z_state[1] = GameTimer.GetFPS() * 0.6;
	Z_pos[1] = Vector3(Z_POS_RIGHT, Z_INIT_Y, 0);
	Z_type[1] = Z_RIGHT;*/







	//Z_NOOT
	Z_NOOT_spr[Z_NOOT_LEFT] = GraphicsDevice.CreateSpriteFromFile(_T("notes_gizagiza_basic_left.png"));
	Z_NOOT_spr[Z_NOOT_RIGHT] = GraphicsDevice.CreateSpriteFromFile(_T("notes_gizagiza_basic_right (1).png"));


	for (int i = 0; i < 200; i++) {
		Z_NOOT_state[i] = -2;
		Z_NOOT_frame[i] = 0;
	}
	//Z_LEFT
	Z_NOOT_state[0] = GameTimer.GetFPS() * 10.0;
	Z_NOOT_pos[0] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[0] = Z_NOOT_LEFT;

	Z_NOOT_state[1] = GameTimer.GetFPS() * 10.3;
	Z_NOOT_pos[1] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[1] = Z_NOOT_RIGHT;

	Z_NOOT_state[2] = GameTimer.GetFPS() * 10.7;
	Z_NOOT_pos[2] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0); 
	Z_NOOT_type[2] = Z_NOOT_LEFT;

	Z_NOOT_state[3] = GameTimer.GetFPS() * 11.2;
	Z_NOOT_pos[3] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[3] = Z_NOOT_RIGHT;

	Z_NOOT_state[4] = GameTimer.GetFPS() * 39.0;
	Z_NOOT_pos[4] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[4] = Z_NOOT_RIGHT;

	Z_NOOT_state[5] = GameTimer.GetFPS() * 39.9;
	Z_NOOT_pos[5] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[5] = Z_NOOT_LEFT;

	Z_NOOT_state[6] = GameTimer.GetFPS() * 40.8;
	Z_NOOT_pos[6] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[6] = Z_NOOT_RIGHT;

	Z_NOOT_state[7] = GameTimer.GetFPS() * 41.6;
	Z_NOOT_pos[7] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[7] = Z_NOOT_LEFT;

	Z_NOOT_state[8] = GameTimer.GetFPS() * 42.4;
	Z_NOOT_pos[8] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[8] = Z_NOOT_RIGHT;

	Z_NOOT_state[9] = GameTimer.GetFPS() * 43.2;
	Z_NOOT_pos[9] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[9] = Z_NOOT_LEFT;

	Z_NOOT_state[10] = GameTimer.GetFPS() * 44.0;
	Z_NOOT_pos[10] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[10] = Z_NOOT_RIGHT;

	Z_NOOT_state[11] = GameTimer.GetFPS() * 44.8;
	Z_NOOT_pos[11] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[11] = Z_NOOT_LEFT;

	Z_NOOT_state[12] = GameTimer.GetFPS() * 45.6;
	Z_NOOT_pos[12] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[12] = Z_NOOT_RIGHT;

	Z_NOOT_state[13] = GameTimer.GetFPS() * 46.5;
	Z_NOOT_pos[13] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[13] = Z_NOOT_LEFT;

	Z_NOOT_state[14] = GameTimer.GetFPS() * 47.4;
	Z_NOOT_pos[14] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[14] = Z_NOOT_RIGHT;

	Z_NOOT_state[15] = GameTimer.GetFPS() * 48.3;
	Z_NOOT_pos[15] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[15] = Z_NOOT_LEFT;

	Z_NOOT_state[16] = GameTimer.GetFPS() * 49.2;
	Z_NOOT_pos[16] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[16] = Z_NOOT_RIGHT;

	Z_NOOT_state[17] = GameTimer.GetFPS() * 49.6;
	Z_NOOT_pos[17] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[17] = Z_NOOT_RIGHT;

	Z_NOOT_state[18] = GameTimer.GetFPS() * 50.0;
	Z_NOOT_pos[18] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[18] = Z_NOOT_LEFT;

	Z_NOOT_state[19] = GameTimer.GetFPS() * 50.4;
	Z_NOOT_pos[19] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[19] = Z_NOOT_LEFT;

	Z_NOOT_state[20] = GameTimer.GetFPS() * 54.0;
	Z_NOOT_pos[20] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[20] = Z_NOOT_RIGHT;

	Z_NOOT_state[21] = GameTimer.GetFPS() * 54.4;
	Z_NOOT_pos[21] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[21] = Z_NOOT_LEFT;

	Z_NOOT_state[22] = GameTimer.GetFPS() * 54.8;
	Z_NOOT_pos[22] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[22] = Z_NOOT_RIGHT;

	Z_NOOT_state[23] = GameTimer.GetFPS() * 55.2;
	Z_NOOT_pos[23] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[23] = Z_NOOT_LEFT;

	Z_NOOT_state[24] = GameTimer.GetFPS() * 55.6;
	Z_NOOT_pos[24] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[24] = Z_NOOT_RIGHT;

	Z_NOOT_state[25] = GameTimer.GetFPS() * 56.0;
	Z_NOOT_pos[25] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[25] = Z_NOOT_LEFT;

	Z_NOOT_state[26] = GameTimer.GetFPS() * 56.4;
	Z_NOOT_pos[26] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[26] = Z_NOOT_RIGHT;

	Z_NOOT_state[27] = GameTimer.GetFPS() * 56.8;
	Z_NOOT_pos[27] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[27] = Z_NOOT_LEFT;

	Z_NOOT_state[28] = GameTimer.GetFPS() * 57.2;
	Z_NOOT_pos[28] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[28] = Z_NOOT_RIGHT;

	Z_NOOT_state[29] = GameTimer.GetFPS() * 57.6;
	Z_NOOT_pos[29] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[29] = Z_NOOT_LEFT;

	Z_NOOT_state[30] = GameTimer.GetFPS() * 63.4;
	Z_NOOT_pos[30] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[30] = Z_NOOT_RIGHT;

	Z_NOOT_state[31] = GameTimer.GetFPS() * 63.8;
	Z_NOOT_pos[31] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[31] = Z_NOOT_LEFT;

	Z_NOOT_state[32] = GameTimer.GetFPS() * 64.2;
	Z_NOOT_pos[32] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[32] = Z_NOOT_RIGHT;

	Z_NOOT_state[33] = GameTimer.GetFPS() * 64.6;
	Z_NOOT_pos[33] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[33] = Z_NOOT_LEFT;

	Z_NOOT_state[34] = GameTimer.GetFPS() * 65.0;
	Z_NOOT_pos[34] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[34] = Z_NOOT_RIGHT;

	Z_NOOT_state[35] = GameTimer.GetFPS() * 65.4;
	Z_NOOT_pos[35] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[35] = Z_NOOT_LEFT;

	Z_NOOT_state[36] = GameTimer.GetFPS() * 65.8;
	Z_NOOT_pos[36] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[36] = Z_NOOT_RIGHT;

	Z_NOOT_state[37] = GameTimer.GetFPS() * 66.2;
	Z_NOOT_pos[37] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[37] = Z_NOOT_LEFT;

	Z_NOOT_state[38] = GameTimer.GetFPS() * 66.6;
	Z_NOOT_pos[38] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[38] = Z_NOOT_RIGHT;

	Z_NOOT_state[39] = GameTimer.GetFPS() * 67.0;
	Z_NOOT_pos[39] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[39] = Z_NOOT_LEFT;

	Z_NOOT_state[40] = GameTimer.GetFPS() * 67.4;
	Z_NOOT_pos[40] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[40] = Z_NOOT_RIGHT;

	Z_NOOT_state[41] = GameTimer.GetFPS() * 67.8;
	Z_NOOT_pos[41] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[41] = Z_NOOT_LEFT;

	Z_NOOT_state[42] = GameTimer.GetFPS() * 68.2;
	Z_NOOT_pos[42] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[42] = Z_NOOT_RIGHT;

	Z_NOOT_state[43] = GameTimer.GetFPS() * 68.6;
	Z_NOOT_pos[43] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[43] = Z_NOOT_LEFT;

	Z_NOOT_state[44] = GameTimer.GetFPS() * 69.0;
	Z_NOOT_pos[44] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[44] = Z_NOOT_RIGHT;

	Z_NOOT_state[45] = GameTimer.GetFPS() * 69.4;
	Z_NOOT_pos[45] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[45] = Z_NOOT_LEFT;

	Z_NOOT_state[46] = GameTimer.GetFPS() * 69.8;
	Z_NOOT_pos[46] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[46] = Z_NOOT_RIGHT;

	Z_NOOT_state[47] = GameTimer.GetFPS() * 70.2;
	Z_NOOT_pos[47] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[47] = Z_NOOT_LEFT;

	Z_NOOT_state[48] = GameTimer.GetFPS() * 73.0;
	Z_NOOT_pos[48] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[48] = Z_NOOT_RIGHT;

	Z_NOOT_state[49] = GameTimer.GetFPS() * 73.4;
	Z_NOOT_pos[49] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[49] = Z_NOOT_LEFT;

	Z_NOOT_state[50] = GameTimer.GetFPS() * 73.8;
	Z_NOOT_pos[50] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[50] = Z_NOOT_RIGHT;

	Z_NOOT_state[51] = GameTimer.GetFPS() * 74.2;
	Z_NOOT_pos[51] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[51] = Z_NOOT_LEFT;

	Z_NOOT_state[52] = GameTimer.GetFPS() * 74.6;
	Z_NOOT_pos[52] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[52] = Z_NOOT_RIGHT;

	Z_NOOT_state[53] = GameTimer.GetFPS() * 75.0;
	Z_NOOT_pos[53] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[53] = Z_NOOT_LEFT;

	Z_NOOT_state[54] = GameTimer.GetFPS() * 77.4;
	Z_NOOT_pos[54] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[54] = Z_NOOT_RIGHT;

	Z_NOOT_state[55] = GameTimer.GetFPS() * 77.8;
	Z_NOOT_pos[55] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[55] = Z_NOOT_RIGHT;

	Z_NOOT_state[56] = GameTimer.GetFPS() * 78.2;
	Z_NOOT_pos[56] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[56] = Z_NOOT_LEFT;

	Z_NOOT_state[57] = GameTimer.GetFPS() * 78.6;
	Z_NOOT_pos[57] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[57] = Z_NOOT_RIGHT;

	Z_NOOT_state[58] = GameTimer.GetFPS() * 79.0;
	Z_NOOT_pos[58] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[58] = Z_NOOT_LEFT;

	Z_NOOT_state[59] = GameTimer.GetFPS() * 81.8;
	Z_NOOT_pos[59] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[59] = Z_NOOT_RIGHT;

	Z_NOOT_state[60] = GameTimer.GetFPS() * 82.2;
	Z_NOOT_pos[60] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[60] = Z_NOOT_LEFT;

	Z_NOOT_state[61] = GameTimer.GetFPS() * 82.4;
	Z_NOOT_pos[61] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[61] = Z_NOOT_RIGHT;

	Z_NOOT_state[62] = GameTimer.GetFPS() * 82.6;
	Z_NOOT_pos[62] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[62] = Z_NOOT_LEFT;

	Z_NOOT_state[63] = GameTimer.GetFPS() * 85.0;
	Z_NOOT_pos[63] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[63] = Z_NOOT_LEFT;

	Z_NOOT_state[64] = GameTimer.GetFPS() * 86.0;
	Z_NOOT_pos[64] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[64] = Z_NOOT_LEFT;

	Z_NOOT_state[65] = GameTimer.GetFPS() * 86.3;
	Z_NOOT_pos[65] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[65] = Z_NOOT_RIGHT;

	//Z_RIGHT

	Z_NOOT_state[100] = GameTimer.GetFPS() * 10.0;
	Z_NOOT_pos[100] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[100] = Z_NOOT_RIGHT;

	Z_NOOT_state[101] = GameTimer.GetFPS() * 10.3;
	Z_NOOT_pos[101] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[101] = Z_NOOT_LEFT;

	Z_NOOT_state[102] = GameTimer.GetFPS() * 10.7;
	Z_NOOT_pos[102] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[102] = Z_NOOT_RIGHT;

	Z_NOOT_state[103] = GameTimer.GetFPS() * 11.2;
	Z_NOOT_pos[103] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[103] = Z_NOOT_LEFT;

	Z_NOOT_state[104] = GameTimer.GetFPS() * 39.0;
	Z_NOOT_pos[104] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[104] = Z_NOOT_RIGHT;

	Z_NOOT_state[105] = GameTimer.GetFPS() * 39.9;
	Z_NOOT_pos[105] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[105] = Z_NOOT_LEFT;

	Z_NOOT_state[106] = GameTimer.GetFPS() * 40.8;
	Z_NOOT_pos[106] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[106] = Z_NOOT_RIGHT;

	Z_NOOT_state[107] = GameTimer.GetFPS() * 41.6;
	Z_NOOT_pos[107] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[107] = Z_NOOT_LEFT;

	Z_NOOT_state[108] = GameTimer.GetFPS() * 42.4;
	Z_NOOT_pos[108] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[108] = Z_NOOT_RIGHT;

	Z_NOOT_state[109] = GameTimer.GetFPS() * 43.2;
	Z_NOOT_pos[109] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[109] = Z_NOOT_LEFT;

	Z_NOOT_state[110] = GameTimer.GetFPS() * 44.0;
	Z_NOOT_pos[110] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[110] = Z_NOOT_RIGHT;

	Z_NOOT_state[111] = GameTimer.GetFPS() * 44.8;
	Z_NOOT_pos[111] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[111] = Z_NOOT_LEFT;

	Z_NOOT_state[112] = GameTimer.GetFPS() * 45.6;
	Z_NOOT_pos[112] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[112] = Z_NOOT_RIGHT;

	Z_NOOT_state[113] = GameTimer.GetFPS() * 46.5;
	Z_NOOT_pos[113] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[113] = Z_NOOT_LEFT;

	Z_NOOT_state[114] = GameTimer.GetFPS() * 47.4;
	Z_NOOT_pos[114] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[114] = Z_NOOT_RIGHT;

	Z_NOOT_state[115] = GameTimer.GetFPS() * 48.3;
	Z_NOOT_pos[115] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[115] = Z_NOOT_LEFT;

	Z_NOOT_state[116] = GameTimer.GetFPS() * 49.2;
	Z_NOOT_pos[116] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[116] = Z_NOOT_RIGHT;

	Z_NOOT_state[115] = GameTimer.GetFPS() * 48.3;
	Z_NOOT_pos[115] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[115] = Z_NOOT_LEFT;

	Z_NOOT_state[116] = GameTimer.GetFPS() * 49.2;
	Z_NOOT_pos[116] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[116] = Z_NOOT_RIGHT;

	Z_NOOT_state[117] = GameTimer.GetFPS() * 50.0;
	Z_NOOT_pos[117] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[117] = Z_NOOT_LEFT;

	Z_NOOT_state[118] = GameTimer.GetFPS() * 50.4;
	Z_NOOT_pos[118] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[118] = Z_NOOT_RIGHT;

	Z_NOOT_state[119] = GameTimer.GetFPS() * 50.8;
	Z_NOOT_pos[119] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[119] = Z_NOOT_RIGHT;

	Z_NOOT_state[120] = GameTimer.GetFPS() * 51.2;
	Z_NOOT_pos[120] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[120] = Z_NOOT_LEFT;

	Z_NOOT_state[121] = GameTimer.GetFPS() * 54.0;
	Z_NOOT_pos[121] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[121] = Z_NOOT_RIGHT;

	Z_NOOT_state[122] = GameTimer.GetFPS() * 54.4;
	Z_NOOT_pos[122] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[122] = Z_NOOT_LEFT;

	Z_NOOT_state[123] = GameTimer.GetFPS() * 54.8;
	Z_NOOT_pos[123] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[123] = Z_NOOT_RIGHT;

	Z_NOOT_state[124] = GameTimer.GetFPS() * 55.2;
	Z_NOOT_pos[124] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[124] = Z_NOOT_LEFT;

	Z_NOOT_state[125] = GameTimer.GetFPS() * 55.6;
	Z_NOOT_pos[125] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[125] = Z_NOOT_RIGHT;

	Z_NOOT_state[126] = GameTimer.GetFPS() * 56.0;
	Z_NOOT_pos[126] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[126] = Z_NOOT_LEFT;

	Z_NOOT_state[127] = GameTimer.GetFPS() * 56.4;
	Z_NOOT_pos[127] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[127] = Z_NOOT_RIGHT;

	Z_NOOT_state[128] = GameTimer.GetFPS() * 56.8;
	Z_NOOT_pos[128] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[128] = Z_NOOT_LEFT;

	Z_NOOT_state[129] = GameTimer.GetFPS() * 57.2;
	Z_NOOT_pos[129] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[129] = Z_NOOT_RIGHT;

	Z_NOOT_state[130] = GameTimer.GetFPS() * 57.6;
	Z_NOOT_pos[130] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[130] = Z_NOOT_LEFT;

	Z_NOOT_state[129] = GameTimer.GetFPS() * 58.0;
	Z_NOOT_pos[129] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[129] = Z_NOOT_RIGHT;

	Z_NOOT_state[130] = GameTimer.GetFPS() * 58.4;
	Z_NOOT_pos[130] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[130] = Z_NOOT_LEFT;

	Z_NOOT_state[131] = GameTimer.GetFPS() * 58.8;
	Z_NOOT_pos[131] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[131] = Z_NOOT_RIGHT;

	Z_NOOT_state[132] = GameTimer.GetFPS() * 59.2;
	Z_NOOT_pos[132] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[132] = Z_NOOT_LEFT;

	Z_NOOT_state[133] = GameTimer.GetFPS() * 59.6;
	Z_NOOT_pos[133] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[133] = Z_NOOT_RIGHT;

	Z_NOOT_state[134] = GameTimer.GetFPS() * 60.0;
	Z_NOOT_pos[134]= Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[134] = Z_NOOT_LEFT;

	Z_NOOT_state[135] = GameTimer.GetFPS() * 60.4;
	Z_NOOT_pos[135] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[135] = Z_NOOT_RIGHT;

	Z_NOOT_state[136] = GameTimer.GetFPS() * 60.8;
	Z_NOOT_pos[136] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[136] = Z_NOOT_LEFT;

	Z_NOOT_state[137] = GameTimer.GetFPS() * 61.2;
	Z_NOOT_pos[137] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[137] = Z_NOOT_RIGHT;

	Z_NOOT_state[138] = GameTimer.GetFPS() * 61.6;
	Z_NOOT_pos[138] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[138] = Z_NOOT_LEFT;

	Z_NOOT_state[139] = GameTimer.GetFPS() * 62.0;
	Z_NOOT_pos[139] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[139] = Z_NOOT_RIGHT;

	Z_NOOT_state[140] = GameTimer.GetFPS() * 62.4;
	Z_NOOT_pos[140] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[140] = Z_NOOT_LEFT;

	Z_NOOT_state[141] = GameTimer.GetFPS() * 62.8;
	Z_NOOT_pos[141] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[141] = Z_NOOT_RIGHT;

	Z_NOOT_state[142] = GameTimer.GetFPS() * 63.2;
	Z_NOOT_pos[142] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[142] = Z_NOOT_LEFT;

	Z_NOOT_state[143] = GameTimer.GetFPS() * 70.6;
	Z_NOOT_pos[143] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[143] = Z_NOOT_RIGHT;

	Z_NOOT_state[144] = GameTimer.GetFPS() * 71.0;
	Z_NOOT_pos[144] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[144] = Z_NOOT_LEFT;

	Z_NOOT_state[145] = GameTimer.GetFPS() * 71.4;
	Z_NOOT_pos[145] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[145] = Z_NOOT_RIGHT;

	Z_NOOT_state[146] = GameTimer.GetFPS() * 71.8;
	Z_NOOT_pos[146] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[146] = Z_NOOT_LEFT;

	Z_NOOT_state[147] = GameTimer.GetFPS() * 72.2;
	Z_NOOT_pos[147] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[147] = Z_NOOT_RIGHT;

	Z_NOOT_state[148] = GameTimer.GetFPS() * 72.6;
	Z_NOOT_pos[148] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[148] = Z_NOOT_LEFT;

	Z_NOOT_state[149] = GameTimer.GetFPS() * 75.4;
	Z_NOOT_pos[149] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[149] = Z_NOOT_RIGHT;

	Z_NOOT_state[150] = GameTimer.GetFPS() * 75.8;
	Z_NOOT_pos[150] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[150] = Z_NOOT_LEFT;

	Z_NOOT_state[151] = GameTimer.GetFPS() * 76.2;
	Z_NOOT_pos[151] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[151] = Z_NOOT_RIGHT;

	Z_NOOT_state[152] = GameTimer.GetFPS() * 76.6;
	Z_NOOT_pos[152] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[152] = Z_NOOT_LEFT;

	Z_NOOT_state[153] = GameTimer.GetFPS() * 77.0;
	Z_NOOT_pos[153] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[153] = Z_NOOT_RIGHT;

	Z_NOOT_state[154] = GameTimer.GetFPS() * 79.4;
	Z_NOOT_pos[154] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[154] = Z_NOOT_RIGHT;

	Z_NOOT_state[155] = GameTimer.GetFPS() * 79.8;
	Z_NOOT_pos[155] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[155] = Z_NOOT_RIGHT;

	Z_NOOT_state[156] = GameTimer.GetFPS() * 80.2;
	Z_NOOT_pos[156] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[156] = Z_NOOT_LEFT;

	Z_NOOT_state[157] = GameTimer.GetFPS() * 80.6;
	Z_NOOT_pos[157] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[157] = Z_NOOT_RIGHT;

	Z_NOOT_state[158] = GameTimer.GetFPS() * 81.0;
	Z_NOOT_pos[158] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[158] = Z_NOOT_RIGHT;

	Z_NOOT_state[159] = GameTimer.GetFPS() * 81.4;
	Z_NOOT_pos[159] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[159] = Z_NOOT_LEFT;

	Z_NOOT_state[160] = GameTimer.GetFPS() * 82.8;
	Z_NOOT_pos[160] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[160] = Z_NOOT_RIGHT;

	Z_NOOT_state[161] = GameTimer.GetFPS() * 83.2;
	Z_NOOT_pos[161] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[161] = Z_NOOT_LEFT;

	Z_NOOT_state[162] = GameTimer.GetFPS() * 83.6;
	Z_NOOT_pos[162] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[162] = Z_NOOT_RIGHT;

	Z_NOOT_state[163] = GameTimer.GetFPS() * 84.0;
	Z_NOOT_pos[163] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[163] = Z_NOOT_LEFT;

	Z_NOOT_state[164] = GameTimer.GetFPS() * 84.4;
	Z_NOOT_pos[164] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[164] = Z_NOOT_RIGHT;

	Z_NOOT_state[165] = GameTimer.GetFPS() * 85.8;
	Z_NOOT_pos[165] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[165] = Z_NOOT_LEFT;

	Z_NOOT_state[166] = GameTimer.GetFPS() * 86.1;
	Z_NOOT_pos[166] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[166] = Z_NOOT_RIGHT;


	/*Z_NOOT_state[119] = GameTimer.GetFPS() * 57.0;
	Z_NOOT_pos[119] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
	Z_NOOT_type[119] = Z_NOOT_RIGHT;*/

	
	//長押しNOOT

	for (int i = 0; i < 200; i++) {
		Loll_state[i] = -1;
		Loll_length_[i] = 316;
	}

	///////////LEFT;
	Loll_state[0] = GameTimer.GetFPS() * 14.7;
	Loll_pos[0] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[1] = GameTimer.GetFPS() * 18.0;
	Loll_pos[1] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[2] = GameTimer.GetFPS() * 24.0;
	Loll_pos[2] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[3] = GameTimer.GetFPS() * 27.5;
	Loll_pos[3] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[4] = GameTimer.GetFPS() * 30.0;
	Loll_pos[4] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[5] = GameTimer.GetFPS() * 35.0;
	Loll_pos[5] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[6] = GameTimer.GetFPS() * 38.5;
	Loll_pos[6] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[7] = GameTimer.GetFPS() * 53.0;
	Loll_pos[7] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[8] = GameTimer.GetFPS() * 58.0;
	Loll_pos[8] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[9] = GameTimer.GetFPS() * 65.0;
	Loll_pos[9] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	Loll_state[10] = GameTimer.GetFPS() * 88.0;
	Loll_pos[10] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

	////RIGHT;
	Loll_state[100] = GameTimer.GetFPS() * 19.0;
	Loll_pos[100] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

	Loll_state[101] = GameTimer.GetFPS() * 21.5;
	Loll_pos[101] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

	Loll_state[102] = GameTimer.GetFPS() * 59.6;
	Loll_pos[102] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

	Loll_state[103] = GameTimer.GetFPS() * 61.8;
	Loll_pos[103] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

	Loll_state[104] = GameTimer.GetFPS() * 63.4;
	Loll_pos[104] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

	Loll_state[105] = GameTimer.GetFPS() * 88.0;
	Loll_pos[105] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

	count1234 = 0;

	perfect_count_1 = 0;
	miss_count_1 = 0;
	good_count_1 = 0;
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

	GamePadState  pad_state = GamePad(0)->GetState();
	GamePadBuffer pad_buffer = GamePad(0)->GetBuffer();
	if (game_scene_ == 0) {
		count1++;
		if (count1 % 6 == 0) {
			start_ -= 1;
			if (start_ <= 0.0) {
				start_ += 0.1;
			}
			else if (start_ >= 1.0) {
				start_ -= 0.1;
			}
		}
	}
	

	if (game_scene_ == 0) {
		if (pad_buffer.IsPressed(GamePad_Button11)) {
			game_scene_ = 1;
			
		}
	}

	else if (game_scene_ == 1) {
		if (pad_buffer.IsPressed(GamePad_Button11)) {
			game_scene_ = 2;
			BGM->Play();
			movie_->Play();

			perfect_count_1 = 0;
			miss_count_1 = 0;
			good_count_1 = 0;

			good_count = 0;
			perfect_count = 0;
			miss_count = 0;
			total_count = 0;

			METER_POWER = 0;
			meter_state = 0;
			a = 1.0;


			//LEFT
			noot_state[0] = GameTimer.GetFPS() * 0.001;
			noot_pos[0] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[1] = GameTimer.GetFPS() * 13.8;
			noot_pos[1] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[2] = GameTimer.GetFPS() * 14.3;
			noot_pos[2] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[3] = GameTimer.GetFPS() * 16.5;
			noot_pos[3] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[4] = GameTimer.GetFPS() * 17.3;
			noot_pos[4] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[5] = GameTimer.GetFPS() * 20.4;
			noot_pos[5] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[6] = GameTimer.GetFPS() * 21.1;
			noot_pos[6] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[7] = GameTimer.GetFPS() * 23.5;
			noot_pos[7] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[8] = GameTimer.GetFPS() * 27.2;
			noot_pos[8] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[9] = GameTimer.GetFPS() * 29.1;
			noot_pos[9] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[10] = GameTimer.GetFPS() * 32.0;
			noot_pos[10] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[11] = GameTimer.GetFPS() * 34.0;
			noot_pos[11] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[12] = GameTimer.GetFPS() * 34.7;
			noot_pos[12] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[13] = GameTimer.GetFPS() * 37.3;
			noot_pos[13] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[14] = GameTimer.GetFPS() * 38.1;
			noot_pos[14] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[15] = GameTimer.GetFPS() * 54.5;
			noot_pos[15] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);

			noot_state[16] = GameTimer.GetFPS() * 54.9;
			noot_pos[16] = Vector3(NOOT_POS_LEFT, NOOT_INIT_Y, 0);



			//RIGHT
			noot_state[100] = GameTimer.GetFPS() * 0.001;
			noot_pos[100] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[101] = GameTimer.GetFPS() * 13.5;
			noot_pos[101] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[102] = GameTimer.GetFPS() * 16.0;
			noot_pos[102] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[103] = GameTimer.GetFPS() * 16.9;
			noot_pos[103] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[104] = GameTimer.GetFPS() * 17.8;
			noot_pos[104] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[105] = GameTimer.GetFPS() * 20.7;
			noot_pos[105] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[106] = GameTimer.GetFPS() * 24.0;
			noot_pos[106] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[107] = GameTimer.GetFPS() * 25.0;
			noot_pos[107] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[108] = GameTimer.GetFPS() * 27.6;
			noot_pos[108] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[109] = GameTimer.GetFPS() * 28.6;
			noot_pos[109] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[110] = GameTimer.GetFPS() * 30.0;
			noot_pos[110] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[111] = GameTimer.GetFPS() * 31.5;
			noot_pos[111] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[112] = GameTimer.GetFPS() * 33.0;
			noot_pos[112] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[113] = GameTimer.GetFPS() * 34.3;
			noot_pos[113] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[114] = GameTimer.GetFPS() * 35.0;
			noot_pos[114] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[115] = GameTimer.GetFPS() * 37.7;
			noot_pos[115] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			noot_state[116] = GameTimer.GetFPS() * 38.5;
			noot_pos[116] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			/*noot_state[117] = GameTimer.GetFPS() * 38.6;
			noot_pos[117] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);*/

			noot_state[118] = GameTimer.GetFPS() * 54.9;
			noot_pos[118] = Vector3(NOOT_POS_RIGHT, NOOT_INIT_Y, 0);

			//Z_LEFT
			Z_NOOT_state[0] = GameTimer.GetFPS() * 10.0;
			Z_NOOT_pos[0] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[0] = Z_NOOT_LEFT;

			Z_NOOT_state[1] = GameTimer.GetFPS() * 10.3;
			Z_NOOT_pos[1] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[1] = Z_NOOT_RIGHT;

			Z_NOOT_state[2] = GameTimer.GetFPS() * 10.7;
			Z_NOOT_pos[2] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[2] = Z_NOOT_LEFT;

			Z_NOOT_state[3] = GameTimer.GetFPS() * 11.2;
			Z_NOOT_pos[3] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[3] = Z_NOOT_RIGHT;

			Z_NOOT_state[4] = GameTimer.GetFPS() * 39.0;
			Z_NOOT_pos[4] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[4] = Z_NOOT_RIGHT;

			Z_NOOT_state[5] = GameTimer.GetFPS() * 39.9;
			Z_NOOT_pos[5] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[5] = Z_NOOT_LEFT;

			Z_NOOT_state[6] = GameTimer.GetFPS() * 40.8;
			Z_NOOT_pos[6] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[6] = Z_NOOT_RIGHT;

			Z_NOOT_state[7] = GameTimer.GetFPS() * 41.6;
			Z_NOOT_pos[7] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[7] = Z_NOOT_LEFT;

			Z_NOOT_state[8] = GameTimer.GetFPS() * 42.4;
			Z_NOOT_pos[8] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[8] = Z_NOOT_RIGHT;

			Z_NOOT_state[9] = GameTimer.GetFPS() * 43.2;
			Z_NOOT_pos[9] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[9] = Z_NOOT_LEFT;

			Z_NOOT_state[10] = GameTimer.GetFPS() * 44.0;
			Z_NOOT_pos[10] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[10] = Z_NOOT_RIGHT;

			Z_NOOT_state[11] = GameTimer.GetFPS() * 44.8;
			Z_NOOT_pos[11] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[11] = Z_NOOT_LEFT;

			Z_NOOT_state[12] = GameTimer.GetFPS() * 45.6;
			Z_NOOT_pos[12] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[12] = Z_NOOT_RIGHT;

			Z_NOOT_state[13] = GameTimer.GetFPS() * 46.5;
			Z_NOOT_pos[13] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[13] = Z_NOOT_LEFT;

			Z_NOOT_state[14] = GameTimer.GetFPS() * 47.4;
			Z_NOOT_pos[14] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[14] = Z_NOOT_RIGHT;

			Z_NOOT_state[15] = GameTimer.GetFPS() * 48.3;
			Z_NOOT_pos[15] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[15] = Z_NOOT_LEFT;

			Z_NOOT_state[16] = GameTimer.GetFPS() * 49.2;
			Z_NOOT_pos[16] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[16] = Z_NOOT_RIGHT;

			Z_NOOT_state[17] = GameTimer.GetFPS() * 49.6;
			Z_NOOT_pos[17] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[17] = Z_NOOT_RIGHT;

			Z_NOOT_state[18] = GameTimer.GetFPS() * 50.0;
			Z_NOOT_pos[18] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[18] = Z_NOOT_LEFT;

			Z_NOOT_state[19] = GameTimer.GetFPS() * 50.4;
			Z_NOOT_pos[19] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[19] = Z_NOOT_LEFT;

			Z_NOOT_state[20] = GameTimer.GetFPS() * 54.0;
			Z_NOOT_pos[20] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[20] = Z_NOOT_RIGHT;

			Z_NOOT_state[21] = GameTimer.GetFPS() * 54.4;
			Z_NOOT_pos[21] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[21] = Z_NOOT_LEFT;

			Z_NOOT_state[22] = GameTimer.GetFPS() * 54.8;
			Z_NOOT_pos[22] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[22] = Z_NOOT_RIGHT;

			Z_NOOT_state[23] = GameTimer.GetFPS() * 55.2;
			Z_NOOT_pos[23] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[23] = Z_NOOT_LEFT;

			Z_NOOT_state[24] = GameTimer.GetFPS() * 55.6;
			Z_NOOT_pos[24] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[24] = Z_NOOT_RIGHT;

			Z_NOOT_state[25] = GameTimer.GetFPS() * 56.0;
			Z_NOOT_pos[25] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[25] = Z_NOOT_LEFT;

			Z_NOOT_state[26] = GameTimer.GetFPS() * 56.4;
			Z_NOOT_pos[26] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[26] = Z_NOOT_RIGHT;

			Z_NOOT_state[27] = GameTimer.GetFPS() * 56.8;
			Z_NOOT_pos[27] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[27] = Z_NOOT_LEFT;

			Z_NOOT_state[28] = GameTimer.GetFPS() * 57.2;
			Z_NOOT_pos[28] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[28] = Z_NOOT_RIGHT;

			Z_NOOT_state[29] = GameTimer.GetFPS() * 57.6;
			Z_NOOT_pos[29] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[29] = Z_NOOT_LEFT;

			Z_NOOT_state[30] = GameTimer.GetFPS() * 63.4;
			Z_NOOT_pos[30] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[30] = Z_NOOT_RIGHT;

			Z_NOOT_state[31] = GameTimer.GetFPS() * 63.8;
			Z_NOOT_pos[31] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[31] = Z_NOOT_LEFT;

			Z_NOOT_state[32] = GameTimer.GetFPS() * 64.2;
			Z_NOOT_pos[32] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[32] = Z_NOOT_RIGHT;

			Z_NOOT_state[33] = GameTimer.GetFPS() * 64.6;
			Z_NOOT_pos[33] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[33] = Z_NOOT_LEFT;

			Z_NOOT_state[34] = GameTimer.GetFPS() * 65.0;
			Z_NOOT_pos[34] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[34] = Z_NOOT_RIGHT;

			Z_NOOT_state[35] = GameTimer.GetFPS() * 65.4;
			Z_NOOT_pos[35] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[35] = Z_NOOT_LEFT;

			Z_NOOT_state[36] = GameTimer.GetFPS() * 65.8;
			Z_NOOT_pos[36] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[36] = Z_NOOT_RIGHT;

			Z_NOOT_state[37] = GameTimer.GetFPS() * 66.2;
			Z_NOOT_pos[37] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[37] = Z_NOOT_LEFT;

			Z_NOOT_state[38] = GameTimer.GetFPS() * 66.6;
			Z_NOOT_pos[38] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[38] = Z_NOOT_RIGHT;

			Z_NOOT_state[39] = GameTimer.GetFPS() * 67.0;
			Z_NOOT_pos[39] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[39] = Z_NOOT_LEFT;

			Z_NOOT_state[40] = GameTimer.GetFPS() * 67.4;
			Z_NOOT_pos[40] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[40] = Z_NOOT_RIGHT;

			Z_NOOT_state[41] = GameTimer.GetFPS() * 67.8;
			Z_NOOT_pos[41] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[41] = Z_NOOT_LEFT;

			Z_NOOT_state[42] = GameTimer.GetFPS() * 68.2;
			Z_NOOT_pos[42] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[42] = Z_NOOT_RIGHT;

			Z_NOOT_state[43] = GameTimer.GetFPS() * 68.6;
			Z_NOOT_pos[43] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[43] = Z_NOOT_LEFT;

			Z_NOOT_state[44] = GameTimer.GetFPS() * 69.0;
			Z_NOOT_pos[44] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[44] = Z_NOOT_RIGHT;

			Z_NOOT_state[45] = GameTimer.GetFPS() * 69.4;
			Z_NOOT_pos[45] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[45] = Z_NOOT_LEFT;

			Z_NOOT_state[46] = GameTimer.GetFPS() * 69.8;
			Z_NOOT_pos[46] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[46] = Z_NOOT_RIGHT;

			Z_NOOT_state[47] = GameTimer.GetFPS() * 70.2;
			Z_NOOT_pos[47] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[47] = Z_NOOT_LEFT;

			Z_NOOT_state[48] = GameTimer.GetFPS() * 73.0;
			Z_NOOT_pos[48] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[48] = Z_NOOT_RIGHT;

			Z_NOOT_state[49] = GameTimer.GetFPS() * 73.4;
			Z_NOOT_pos[49] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[49] = Z_NOOT_LEFT;

			Z_NOOT_state[50] = GameTimer.GetFPS() * 73.8;
			Z_NOOT_pos[50] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[50] = Z_NOOT_RIGHT;

			Z_NOOT_state[51] = GameTimer.GetFPS() * 74.2;
			Z_NOOT_pos[51] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[51] = Z_NOOT_LEFT;

			Z_NOOT_state[52] = GameTimer.GetFPS() * 74.6;
			Z_NOOT_pos[52] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[52] = Z_NOOT_RIGHT;

			Z_NOOT_state[53] = GameTimer.GetFPS() * 75.0;
			Z_NOOT_pos[53] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[53] = Z_NOOT_LEFT;

			Z_NOOT_state[54] = GameTimer.GetFPS() * 77.4;
			Z_NOOT_pos[54] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[54] = Z_NOOT_RIGHT;

			Z_NOOT_state[55] = GameTimer.GetFPS() * 77.8;
			Z_NOOT_pos[55] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[55] = Z_NOOT_RIGHT;

			Z_NOOT_state[56] = GameTimer.GetFPS() * 78.2;
			Z_NOOT_pos[56] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[56] = Z_NOOT_LEFT;

			Z_NOOT_state[57] = GameTimer.GetFPS() * 78.6;
			Z_NOOT_pos[57] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[57] = Z_NOOT_RIGHT;

			Z_NOOT_state[58] = GameTimer.GetFPS() * 79.0;
			Z_NOOT_pos[58] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[58] = Z_NOOT_LEFT;

			Z_NOOT_state[59] = GameTimer.GetFPS() * 81.8;
			Z_NOOT_pos[59] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[59] = Z_NOOT_RIGHT;

			Z_NOOT_state[60] = GameTimer.GetFPS() * 82.2;
			Z_NOOT_pos[60] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[60] = Z_NOOT_LEFT;

			Z_NOOT_state[61] = GameTimer.GetFPS() * 82.4;
			Z_NOOT_pos[61] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[61] = Z_NOOT_RIGHT;

			Z_NOOT_state[62] = GameTimer.GetFPS() * 82.6;
			Z_NOOT_pos[62] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[62] = Z_NOOT_LEFT;

			Z_NOOT_state[63] = GameTimer.GetFPS() * 85.0;
			Z_NOOT_pos[63] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[63] = Z_NOOT_LEFT;

			Z_NOOT_state[64] = GameTimer.GetFPS() * 86.0;
			Z_NOOT_pos[64] = Vector3(Z_NOOT_POS_LEFT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[64] = Z_NOOT_LEFT;

			Z_NOOT_state[65] = GameTimer.GetFPS() * 86.3;
			Z_NOOT_pos[65] = Vector3(Z_NOOT_POS_RIGHT, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[65] = Z_NOOT_RIGHT;

			//Z_RIGHT

			Z_NOOT_state[100] = GameTimer.GetFPS() * 10.0;
			Z_NOOT_pos[100] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[100] = Z_NOOT_RIGHT;

			Z_NOOT_state[101] = GameTimer.GetFPS() * 10.3;
			Z_NOOT_pos[101] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[101] = Z_NOOT_LEFT;

			Z_NOOT_state[102] = GameTimer.GetFPS() * 10.7;
			Z_NOOT_pos[102] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[102] = Z_NOOT_RIGHT;

			Z_NOOT_state[103] = GameTimer.GetFPS() * 11.2;
			Z_NOOT_pos[103] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[103] = Z_NOOT_LEFT;

			Z_NOOT_state[104] = GameTimer.GetFPS() * 39.0;
			Z_NOOT_pos[104] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[104] = Z_NOOT_RIGHT;

			Z_NOOT_state[105] = GameTimer.GetFPS() * 39.9;
			Z_NOOT_pos[105] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[105] = Z_NOOT_LEFT;

			Z_NOOT_state[106] = GameTimer.GetFPS() * 40.8;
			Z_NOOT_pos[106] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[106] = Z_NOOT_RIGHT;

			Z_NOOT_state[107] = GameTimer.GetFPS() * 41.6;
			Z_NOOT_pos[107] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[107] = Z_NOOT_LEFT;

			Z_NOOT_state[108] = GameTimer.GetFPS() * 42.4;
			Z_NOOT_pos[108] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[108] = Z_NOOT_RIGHT;

			Z_NOOT_state[109] = GameTimer.GetFPS() * 43.2;
			Z_NOOT_pos[109] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[109] = Z_NOOT_LEFT;

			Z_NOOT_state[110] = GameTimer.GetFPS() * 44.0;
			Z_NOOT_pos[110] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[110] = Z_NOOT_RIGHT;

			Z_NOOT_state[111] = GameTimer.GetFPS() * 44.8;
			Z_NOOT_pos[111] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[111] = Z_NOOT_LEFT;

			Z_NOOT_state[112] = GameTimer.GetFPS() * 45.6;
			Z_NOOT_pos[112] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[112] = Z_NOOT_RIGHT;

			Z_NOOT_state[113] = GameTimer.GetFPS() * 46.5;
			Z_NOOT_pos[113] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[113] = Z_NOOT_LEFT;

			Z_NOOT_state[114] = GameTimer.GetFPS() * 47.4;
			Z_NOOT_pos[114] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[114] = Z_NOOT_RIGHT;

			Z_NOOT_state[115] = GameTimer.GetFPS() * 48.3;
			Z_NOOT_pos[115] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[115] = Z_NOOT_LEFT;

			Z_NOOT_state[116] = GameTimer.GetFPS() * 49.2;
			Z_NOOT_pos[116] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[116] = Z_NOOT_RIGHT;

			Z_NOOT_state[115] = GameTimer.GetFPS() * 48.3;
			Z_NOOT_pos[115] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[115] = Z_NOOT_LEFT;

			Z_NOOT_state[116] = GameTimer.GetFPS() * 49.2;
			Z_NOOT_pos[116] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[116] = Z_NOOT_RIGHT;

			Z_NOOT_state[117] = GameTimer.GetFPS() * 50.0;
			Z_NOOT_pos[117] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[117] = Z_NOOT_LEFT;

			Z_NOOT_state[118] = GameTimer.GetFPS() * 50.4;
			Z_NOOT_pos[118] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[118] = Z_NOOT_RIGHT;

			Z_NOOT_state[119] = GameTimer.GetFPS() * 50.8;
			Z_NOOT_pos[119] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[119] = Z_NOOT_RIGHT;

			Z_NOOT_state[120] = GameTimer.GetFPS() * 51.2;
			Z_NOOT_pos[120] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[120] = Z_NOOT_LEFT;

			Z_NOOT_state[121] = GameTimer.GetFPS() * 54.0;
			Z_NOOT_pos[121] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[121] = Z_NOOT_RIGHT;

			Z_NOOT_state[122] = GameTimer.GetFPS() * 54.4;
			Z_NOOT_pos[122] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[122] = Z_NOOT_LEFT;

			Z_NOOT_state[123] = GameTimer.GetFPS() * 54.8;
			Z_NOOT_pos[123] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[123] = Z_NOOT_RIGHT;

			Z_NOOT_state[124] = GameTimer.GetFPS() * 55.2;
			Z_NOOT_pos[124] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[124] = Z_NOOT_LEFT;

			Z_NOOT_state[125] = GameTimer.GetFPS() * 55.6;
			Z_NOOT_pos[125] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[125] = Z_NOOT_RIGHT;

			Z_NOOT_state[126] = GameTimer.GetFPS() * 56.0;
			Z_NOOT_pos[126] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[126] = Z_NOOT_LEFT;

			Z_NOOT_state[127] = GameTimer.GetFPS() * 56.4;
			Z_NOOT_pos[127] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[127] = Z_NOOT_RIGHT;

			Z_NOOT_state[128] = GameTimer.GetFPS() * 56.8;
			Z_NOOT_pos[128] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[128] = Z_NOOT_LEFT;

			Z_NOOT_state[129] = GameTimer.GetFPS() * 57.2;
			Z_NOOT_pos[129] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[129] = Z_NOOT_RIGHT;

			Z_NOOT_state[130] = GameTimer.GetFPS() * 57.6;
			Z_NOOT_pos[130] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[130] = Z_NOOT_LEFT;

			Z_NOOT_state[129] = GameTimer.GetFPS() * 58.0;
			Z_NOOT_pos[129] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[129] = Z_NOOT_RIGHT;

			Z_NOOT_state[130] = GameTimer.GetFPS() * 58.4;
			Z_NOOT_pos[130] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[130] = Z_NOOT_LEFT;

			Z_NOOT_state[131] = GameTimer.GetFPS() * 58.8;
			Z_NOOT_pos[131] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[131] = Z_NOOT_RIGHT;

			Z_NOOT_state[132] = GameTimer.GetFPS() * 59.2;
			Z_NOOT_pos[132] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[132] = Z_NOOT_LEFT;

			Z_NOOT_state[133] = GameTimer.GetFPS() * 59.6;
			Z_NOOT_pos[133] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[133] = Z_NOOT_RIGHT;

			Z_NOOT_state[134] = GameTimer.GetFPS() * 60.0;
			Z_NOOT_pos[134] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[134] = Z_NOOT_LEFT;

			Z_NOOT_state[135] = GameTimer.GetFPS() * 60.4;
			Z_NOOT_pos[135] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[135] = Z_NOOT_RIGHT;

			Z_NOOT_state[136] = GameTimer.GetFPS() * 60.8;
			Z_NOOT_pos[136] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[136] = Z_NOOT_LEFT;

			Z_NOOT_state[137] = GameTimer.GetFPS() * 61.2;
			Z_NOOT_pos[137] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[137] = Z_NOOT_RIGHT;

			Z_NOOT_state[138] = GameTimer.GetFPS() * 61.6;
			Z_NOOT_pos[138] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[138] = Z_NOOT_LEFT;

			Z_NOOT_state[139] = GameTimer.GetFPS() * 62.0;
			Z_NOOT_pos[139] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[139] = Z_NOOT_RIGHT;

			Z_NOOT_state[140] = GameTimer.GetFPS() * 62.4;
			Z_NOOT_pos[140] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[140] = Z_NOOT_LEFT;

			Z_NOOT_state[141] = GameTimer.GetFPS() * 62.8;
			Z_NOOT_pos[141] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[141] = Z_NOOT_RIGHT;

			Z_NOOT_state[142] = GameTimer.GetFPS() * 63.2;
			Z_NOOT_pos[142] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[142] = Z_NOOT_LEFT;

			Z_NOOT_state[143] = GameTimer.GetFPS() * 70.6;
			Z_NOOT_pos[143] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[143] = Z_NOOT_RIGHT;

			Z_NOOT_state[144] = GameTimer.GetFPS() * 71.0;
			Z_NOOT_pos[144] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[144] = Z_NOOT_LEFT;

			Z_NOOT_state[145] = GameTimer.GetFPS() * 71.4;
			Z_NOOT_pos[145] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[145] = Z_NOOT_RIGHT;

			Z_NOOT_state[146] = GameTimer.GetFPS() * 71.8;
			Z_NOOT_pos[146] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[146] = Z_NOOT_LEFT;

			Z_NOOT_state[147] = GameTimer.GetFPS() * 72.2;
			Z_NOOT_pos[147] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[147] = Z_NOOT_RIGHT;

			Z_NOOT_state[148] = GameTimer.GetFPS() * 72.6;
			Z_NOOT_pos[148] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[148] = Z_NOOT_LEFT;

			Z_NOOT_state[149] = GameTimer.GetFPS() * 75.4;
			Z_NOOT_pos[149] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[149] = Z_NOOT_RIGHT;

			Z_NOOT_state[150] = GameTimer.GetFPS() * 75.8;
			Z_NOOT_pos[150] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[150] = Z_NOOT_LEFT;

			Z_NOOT_state[151] = GameTimer.GetFPS() * 76.2;
			Z_NOOT_pos[151] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[151] = Z_NOOT_RIGHT;

			Z_NOOT_state[152] = GameTimer.GetFPS() * 76.6;
			Z_NOOT_pos[152] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[152] = Z_NOOT_LEFT;

			Z_NOOT_state[153] = GameTimer.GetFPS() * 77.0;
			Z_NOOT_pos[153] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[153] = Z_NOOT_RIGHT;

			Z_NOOT_state[154] = GameTimer.GetFPS() * 79.4;
			Z_NOOT_pos[154] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[154] = Z_NOOT_RIGHT;

			Z_NOOT_state[155] = GameTimer.GetFPS() * 79.8;
			Z_NOOT_pos[155] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[155] = Z_NOOT_RIGHT;

			Z_NOOT_state[156] = GameTimer.GetFPS() * 80.2;
			Z_NOOT_pos[156] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[156] = Z_NOOT_LEFT;

			Z_NOOT_state[157] = GameTimer.GetFPS() * 80.6;
			Z_NOOT_pos[157] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[157] = Z_NOOT_RIGHT;

			Z_NOOT_state[158] = GameTimer.GetFPS() * 81.0;
			Z_NOOT_pos[158] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[158] = Z_NOOT_RIGHT;

			Z_NOOT_state[159] = GameTimer.GetFPS() * 81.4;
			Z_NOOT_pos[159] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[159] = Z_NOOT_LEFT;

			Z_NOOT_state[160] = GameTimer.GetFPS() * 82.8;
			Z_NOOT_pos[160] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[160] = Z_NOOT_RIGHT;

			Z_NOOT_state[161] = GameTimer.GetFPS() * 83.2;
			Z_NOOT_pos[161] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[161] = Z_NOOT_LEFT;

			Z_NOOT_state[162] = GameTimer.GetFPS() * 83.6;
			Z_NOOT_pos[162] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[162] = Z_NOOT_RIGHT;

			Z_NOOT_state[163] = GameTimer.GetFPS() * 84.0;
			Z_NOOT_pos[163] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[163] = Z_NOOT_LEFT;

			Z_NOOT_state[164] = GameTimer.GetFPS() * 84.4;
			Z_NOOT_pos[164] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[164] = Z_NOOT_RIGHT;

			Z_NOOT_state[165] = GameTimer.GetFPS() * 85.8;
			Z_NOOT_pos[165] = Vector3(Z_NOOT_POS_LEFT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[165] = Z_NOOT_LEFT;

			Z_NOOT_state[166] = GameTimer.GetFPS() * 86.1;
			Z_NOOT_pos[166] = Vector3(Z_NOOT_POS_RIGHT2, Z_NOOT_INIT_Y, 0);
			Z_NOOT_type[166] = Z_NOOT_RIGHT;

			///////////LEFT;
			Loll_state[0] = GameTimer.GetFPS() * 14.7;
			Loll_pos[0] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[1] = GameTimer.GetFPS() * 18.0;
			Loll_pos[1] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[2] = GameTimer.GetFPS() * 24.0;
			Loll_pos[2] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[3] = GameTimer.GetFPS() * 27.5;
			Loll_pos[3] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[4] = GameTimer.GetFPS() * 30.0;
			Loll_pos[4] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[5] = GameTimer.GetFPS() * 35.0;
			Loll_pos[5] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[6] = GameTimer.GetFPS() * 38.5;
			Loll_pos[6] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[7] = GameTimer.GetFPS() * 53.0;
			Loll_pos[7] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[8] = GameTimer.GetFPS() * 58.0;
			Loll_pos[8] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[9] = GameTimer.GetFPS() * 65.0;
			Loll_pos[9] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			Loll_state[10] = GameTimer.GetFPS() * 88.0;
			Loll_pos[10] = Vector3(Loll_X_LEFT, LOll_Y_, 0);

			////RIGHT;
			Loll_state[100] = GameTimer.GetFPS() * 19.0;
			Loll_pos[100] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

			Loll_state[101] = GameTimer.GetFPS() * 21.5;
			Loll_pos[101] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

			Loll_state[102] = GameTimer.GetFPS() * 59.6;
			Loll_pos[102] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

			Loll_state[103] = GameTimer.GetFPS() * 61.8;
			Loll_pos[103] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

			Loll_state[104] = GameTimer.GetFPS() * 63.4;
			Loll_pos[104] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

			Loll_state[105] = GameTimer.GetFPS() * 88.0;
			Loll_pos[105] = Vector3(Loll_X_RIGHT, LOll_Y_, 0);

			for (int i = 0; i < 200; i++) {
				Loll_length_[i] = 316;
			}


		}
	}

	if (game_scene_ == 3) {
		if (pad_buffer.IsPressed(GamePad_Button12)) {
			timer = 0;
			game_scene_ = 0;
			BGM->Stop();
			METER_POWER = 0;
			movie_->Replay();
			movie_EF->Replay();
		}
	}

	
	
	
	else if (game_scene_ == 2) {

		movie_->Play();

		
		if (pad_state.X == Axis_Center && pad_state.Y == Axis_Center)
				psyllium_.rotation.z = 0.0f;
		else
			psyllium_.rotation.z = MathHelper_Atan2(pad_state.Y, pad_state.X) + 90.0f;
		

		if (pad_state.X2 == Axis_Center && pad_state.Y3 == Axis_Center)
			psyllium_2.rotation.z = 0.0f;
		else

			psyllium_2.rotation.z = MathHelper_Atan2(pad_state.Y3, pad_state.X2) + 90.0f;

		///////////////////////////////

		for (int i = 0; i < 200; i++) {
			if (noot_state[i] == 0) {
				noot_pos[i].y += 6.1f;
				if (noot_pos[i].y >= 720.0f) {
					noot_state[i] = -2;
					miss_count -= 100;
					total_count -= 100;
					miss_count_1 += 1;
				}
			}
			else if (noot_state[i] > 0) {
				noot_state[i]--;

			}
		}

		for (int i = 0; i < 200; i++) {
			if (Z_state[i] == 0) {
				Z_pos[i].y += 1.8f;
				if (Z_pos[i].y >= 600.0f) {
					Z_state[i] = -2;
					
				}
			}
			else if (Z_state[i] > 0) {
				Z_state[i]--;

			}
		}

		for (int i = 0; i < 200; i++) {
			if (Z_NOOT_state[i] == 0) {
				Z_NOOT_pos[i].y += 3.1f;
				if (Z_NOOT_pos[i].y >= 720.0f) {
					Z_NOOT_state[i] = -2;
					miss_count -= 100;
					total_count -= 100;
					miss_count_1 += 1;
				}
			}
			else if (Z_NOOT_state[i] > 0) {
				Z_NOOT_state[i]--;

			}
		}

		for (int i = 0; i < 200; i++) {
			if (Loll_state[i] == 0) {
				Loll_pos[i].y += 5.8f;
				if (Loll_pos[i].y >= 1300.0f) {
					Loll_state[i] = -1;
					miss_count_1 += 1;
				}
			}
			else if (Loll_state[i] > 0) {
				Loll_state[i]--;

			}
		}

		//////////////////////////////////////

		//評価



		if (good_state_ == 1) {
			count2++;
			if (count2 >= 5) {
				good_state_ = 0;
			}
		}
		if (good_state_ == 0) {
			count2 = 0;
		}

		if (perfect_state_ == 1) {
			count3++;
			if (count3 >= 5) {
				perfect_state_ = 0;
			}
		}
		if (perfect_state_ == 0) {
			count3 = 0;
		}

		if (BAD_state_ == 1) {
			count4++;
			if (count4 >= 5) {
				BAD_state_ = 0;
			}
		}
		if (BAD_state_ == 0) {
			count4 = 0;
		}










		//当たり判定

		if (pad_state.Buttons[4] != 0) {
			RectWH bar_rect(-10, 580, 400, 7);
			for (int i = 0; i < 200; i++) {
				if (Loll_state[i] < 0)
					continue;
				RectWH loll_rect(Loll_pos[i].x + 0, Loll_pos[i].y + 0, 84, 416);
				if (loll_rect.Intersect(bar_rect)) {
					Loll_length_[i] = bar_rect.bottom - Loll_pos[i].y;
					good_count += 5;
					total_count += 5;
					good_state_ = 1;
					EFLoll_state = 1;
				}
				
			}
		}

		if (pad_state.Buttons[5] != 0) {
			RectWH bar2_rect(930, 580, 400, 7);
			for (int i = 0; i < 200; i++) {
				if (Loll_state[i] < 0)
					continue;
				RectWH loll2_rect(Loll_pos[i].x + 0, Loll_pos[i].y + 0, 84, 416);
				if (bar2_rect.Intersect(loll2_rect)) {
					Loll_length_[i] = bar2_rect.bottom - Loll_pos[i].y;
					good_state_ = 1;
					good_count += 5;
					total_count += 5;
					EFLoll_2_state = 1;
				}

			}
		}

		//長押しの判定


		if (pad_buffer.IsPressed(GamePad_Button5)) {
			EF_state = 1;
			SE->Play();
			RectWH perfect_rect(-10, 580, 400, 7);
			RectWH good_rect(-10, 570, 400, 10);
			RectWH good_rectDown(-10, 585, 400, 10);
			RectWH miss_rect(-10, 560, 400, 10);
			RectWH miss_rectDown(-10, 593, 400, 10);
			for (int i = 0; i < 200; i++) {
				if (noot_state[i] < 0)
					continue;


				RectWH  note_rect(noot_pos[i].x + 17, noot_pos[i].y + 57, 90, 8);
				if (note_rect.Intersect(perfect_rect)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					perfect_state_ = 1;
					METER_POWER += 7;
					perfect_count += 1000;
					total_count += 1000;
					perfect_count_1 += 1;
					break;
				}

				else if (note_rect.Intersect(good_rect)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					good_state_ = 1;
					METER_POWER += 5;
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
					break;
				}

				else if (note_rect.Intersect(good_rectDown)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					good_state_ = 1;
					METER_POWER += 5;
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
					break;
				}


				else if (note_rect.Intersect(miss_rect)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					BAD_state_ = 1;
					METER_POWER -= 10;
					HP_POWER -= 100;
					miss_count -= 100;
					total_count -= 100;
					miss_count_1 += 1;
					break;
				}



				else if (note_rect.Intersect(miss_rectDown)) {
					noot_state[i] = -1;
					BAD_state_ = 1;
					NOOT_frame[i] = 0;
					METER_POWER -= 10;
					HP_POWER -= 100;
					miss_count -= 100;
					total_count -= 100;
					miss_count_1 += 1;
					break;
				}
			}


		}


		if (pad_buffer.IsPressed(GamePad_Button6)) {
			EF2_state = 1;
			SE->Play();
			RectWH perfect_rect(930, 580, 400, 7);
			RectWH good_rect(930, 570, 400, 10);
			RectWH good_rectDown(930, 585, 400, 10);
			RectWH miss_rect(930, 560, 400, 10);
			RectWH miss_rectDown(930, 593, 400, 10);
			for (int i = 0; i < 200; i++) {
				if (noot_state[i] < 0)
					continue;

				RectWH  note2_rect(noot_pos[i].x + 17, noot_pos[i].y + 57, 90, 8);
				if (note2_rect.Intersect(perfect_rect)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					perfect_state_ = 1;
					METER_POWER += 7;
					perfect_count += 1000;
					total_count += 1000;
					perfect_count_1 += 1;
					break;
				}

				else if (note2_rect.Intersect(good_rect)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					good_state_ = 1;
					METER_POWER += 5;
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
					break;
				}

				else if (note2_rect.Intersect(good_rectDown)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					good_state_ = 1;
					METER_POWER += 5;
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
					break;
				}

				else if (note2_rect.Intersect(miss_rect)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					BAD_state_ = 1;
					METER_POWER -= 10;
					HP_POWER -= 100;
					miss_count -= 100;
					total_count -= 100;
					miss_count_1 += 1;
					break;
				}

				else if (note2_rect.Intersect(miss_rectDown)) {
					noot_state[i] = -1;
					NOOT_frame[i] = 0;
					BAD_state_ = 1;
					METER_POWER -= 10;
					HP_POWER -= 100;
					miss_count -= 100;
					total_count -= 100;
					miss_count_1 += 1;
					break;
				}

			}
		}


		RectWH good_LEFT(420, 573, 122, 20);
		RectWH good_RIGHT(542, 573, 100, 20);
		for (int i = 0; i < 200; i++) {
			if (Z_NOOT_state[i] != 0 || psyllium_.rotation.z == 0)
				continue;
			RectWH  note_Z_LEFT(Z_NOOT_pos[i].x + 16, Z_NOOT_pos[i].y + 57, 90, 8);
			if (psyllium_.rotation.z >= 10 && psyllium_.rotation.z <= 90) {
				if (note_Z_LEFT.Intersect(good_RIGHT)) {
					Z_NOOT_state[i] = -1;
					good_state_ = 1;
					Z_NOOT_frame[i] = 0;
					METER_POWER += 8;
					SE_2->Play();
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
				}
			}

			else if (psyllium_.rotation.z >= -90 && psyllium_.rotation.z <= -10) {
				if (note_Z_LEFT.Intersect(good_LEFT)) {
					Z_NOOT_state[i] = -1;
					good_state_ = 1;
					Z_NOOT_frame[i] = 0;
					METER_POWER += 3.5;
					SE_2->Play();
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
				}
			}


		}

		RectWH good2_LEFT(642, 573, 100, 20);
		RectWH good2_RIGHT(742, 573, 100, 20);
		for (int i = 0; i < 200; i++) {
			if (Z_NOOT_state[i] != 0 || psyllium_2.rotation.z == 0)
				continue;
			RectWH  note2_Z_LEFT(Z_NOOT_pos[i].x + 16, Z_NOOT_pos[i].y + 60, 90, 8);
			if (psyllium_2.rotation.z >= 10 && psyllium_2.rotation.z <= 90) {
				if (note2_Z_LEFT.Intersect(good2_RIGHT)) {
					Z_NOOT_state[i] = -1;
					good_state_ = 1;
					Z_NOOT_frame[i] = 0;
					METER_POWER += 2;
					SE_2->Play();
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
				}
			}

			else if (psyllium_2.rotation.z >= -90 && psyllium_2.rotation.z <= -10) {
				if (note2_Z_LEFT.Intersect(good2_LEFT)) {
					Z_NOOT_state[i] = -1;
					good_state_ = 1;
					Z_NOOT_frame[i] = 0;
					METER_POWER += 2;
					SE_2->Play();
					good_count += 100;
					total_count += 100;
					good_count_1 += 1;
				}
			}
		}


		// ノーツアニメーション
		for (int i = 0; i < 200; i++) {
			if (Z_NOOT_state[i] == -1) {
				Z_NOOT_frame[i] = Z_NOOT_frame[i] + 122;
				if (Z_NOOT_frame[i] >= 3600)
					Z_NOOT_state[i] = -2;
			}
			if (noot_state[i] == -1) {
				NOOT_frame[i] = NOOT_frame[i] + 122;
				if (NOOT_frame[i] >= 3600)
					noot_state[i] = -2;
			}
		}

		if (pad_state.Buttons[6] != 0) {
			EFLoll_state = 1;
		
		}



		//タップアニメーション
		if (EF_state == 1) {
			EF_frame = EF_frame + 290;
			if (EF_frame >= 4350) {
				EF_state = 0;
				EF_frame = 0;
			}
		}

		if (EF2_state == 1) {
			EF2_frame = EF2_frame + 290;
			if (EF2_frame >= 4350) {
				EF2_state = 0;
				EF2_frame = 0;
			}
		}

		if (EFLoll_state == 1) {
			EFLoll_frame = EFLoll_frame + 290;
			if (EFLoll_frame >= 2030) {
				EFLoll_state = 0;
				EFLoll_frame = 0;
			}
		}

		if (EFLoll_2_state == 1) {
			EFLoll_2_frame = EFLoll_2_frame + 290;
			if (EFLoll_2_frame >= 2030) {
				EFLoll_2_state = 0;
				EFLoll_2_frame = 0;
			}
		}
		///////////////////////////////////

		//METER
		/*if (METER_POWER >= 360) {
			movie_EF->Play();
		}*/
		//HP

		if (HP_POWER <= 200) {
			HP_state = 1;
		}

		if (HP_POWER <= 100) {
			HP_state = 2;
		}

		if (HP_POWER <= 20) {
			HP_state = 3;
		}

		if (HP_POWER <= 0) {
			HP_state = 0;
		}



		//メーター
		count++;
		if (count % 60 == 0) {
			timer++;
			count = 0;
		}

		if (METER_POWER >= 365) {
			a--;

			if (count1234 % 5 == 0) {

				if (a <= 0) {
					a += 0.1;
				}
				else if (a >= 1.0) {
					a -= 0.1;
				}

			}

		}

		if (METER_POWER <= 0) {
			METER_POWER = 0;
		}
	}

	if (timer >= 105) {
		game_scene_ = 3;
		BGM->Stop();
	}

	
	count_frame++;
	if(count_frame >= 60){
		count_frame = 0;
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
		SpriteBatch.Draw(*title, Vector3(title_x_, title_y_, 0.0f));
		SpriteBatch.Draw(*game_start, Vector3(game_start_x_, game_start_y_, 0.0f), start_);

	}

	else if (game_scene_ == 1) {
		SpriteBatch.Draw(*select, Vector3(select_x_, select_y_, 0.0f));
	}
	

	else if (game_scene_ == 2) {
		//サイリウム
		SpriteBatch.Draw(psyllium_);
		SpriteBatch.Draw(psyllium_2);
		///////////////////////////////////
		//メーター
		SpriteBatch.Draw(*GAGE, Vector3(GAGE_x_, GAGE_y_, 0.0f));
		SpriteBatch.Draw(*gagemeter, Vector3(gagemeter_x_, gagemeter_y_, 0.0f), RectWH(0, 0, METER_POWER, 68), a);
		///////////////////////////////////

		SpriteBatch.Draw(*WAKU, Vector3(WAKU_x_, WAKU_y_, 500.0f));
		SpriteBatch.Draw(*movie_, Vector3(0.0f, 0.0f, 1000.0f), 1.0f);

		for (int i = 0; i < 200; i++) {
			SpriteBatch.Draw(*Loll, Loll_pos[i], RectWH(0, 0, 84, Loll_length_[i]));
		}


		//HP　////////////////////////////

		/*if (HP_state == 0) {
			SpriteBatch.Draw(*HPfull, Vector3(HPfull_x_, HPfull_y_, 0.0f));
		}

		if (HP_state == 1) {
			SpriteBatch.Draw(*HP, Vector3(HP_x_, HP_y_, 0.0f));
		}

		if (HP_state == 2) {
			SpriteBatch.Draw(*HP2, Vector3(HP2_x_, HP2_y_, 0.0f));
		}

		if (HP_state == 3) {
			SpriteBatch.Draw(*HP3, Vector3(HP3_x_, HP3_y_, 0.0f));
		}*/

		//判定
		if (good_state_ == 1) {
			SpriteBatch.Draw(*good, Vector3(good_x_, good_y_, 0.0f));
		}

		if (perfect_state_ == 1) {
			SpriteBatch.Draw(*perfect, Vector3(perfect_x_, perfect_y_, 0.0f));
		}

		if (BAD_state_ == 1) {
			SpriteBatch.Draw(*BAD, Vector3(BAD_x_, BAD_y_, 0.0f));
		}
		//ノーツ、Z、Zノーツ
		for (int i = 0; i < 200; i++) {
			if (noot_state[i] == 0) {
				SpriteBatch.Draw(*noot_spr, noot_pos[i], RectWH(0, 0, 122, 122));
			}
			else if (noot_state[i] == -1) {
				SpriteBatch.Draw(*noot_spr, noot_pos[i], RectWH(NOOT_frame[i], 0, 122, 122));
			}
		}

		for (int i = 0; i < 200; i++) {
			if (Z_state[i] == 0) {
				SpriteBatch.Draw(*Z_spr[Z_type[i]], Z_pos[i]);
			}

		}

		for (int i = 0; i < 200; i++) {
			if (Z_NOOT_state[i] == 0) {
				SpriteBatch.Draw(*Z_NOOT_spr[Z_NOOT_type[i]], Z_NOOT_pos[i], RectWH(0, 0, 122, 122));
			}
			else if (Z_NOOT_state[i] == -1) {
				SpriteBatch.Draw(*Z_NOOT_spr[Z_NOOT_type[i]], Z_NOOT_pos[i], RectWH(Z_NOOT_frame[i], 0, 122, 122));
			}
		}

		///////////////////

		//エフェクト
		if (EF_state == 1) {
			SpriteBatch.Draw(*EF, Vector3(EF_x_, EF_y_, 0.0f), RectWH(EF_frame, 0, 290, 95));
		}

		if (EF2_state == 1) {
			SpriteBatch.Draw(*EF2, Vector3(EF2_x_, EF2_y_, 0.0f), RectWH(EF2_frame, 0, 290, 95));
		}

		if (EFLoll_state == 1) {
			SpriteBatch.Draw(*EFLoll, Vector3(EFLoll_x_, EFLoll_y_, 0.0f), RectWH(EFLoll_frame, 0, 290, 100));
		}

		if (EFLoll_2_state == 1) {
			SpriteBatch.Draw(*EFLoll_2, Vector3(EFLoll_2_x_, EFLoll_2_y_, 0.0f), RectWH(EFLoll_2_frame, 0, 290, 100));
		}



		
	}
	else if (game_scene_ == 3) {
		SpriteBatch.Draw(*RIZALT, Vector3(RIZALT_x_, RIZALT_y_, 0.0f));
		SpriteBatch.DrawString(moji2, Vector2(839.0f, 270.0f), Color(255, 0, 255), _T("100"));
		SpriteBatch.DrawString(moji2, Vector2(800.0f, 190.0f), Color(255, 255, 0), _T("1000"));
		SpriteBatch.DrawString(moji2, Vector2(811.0f, 350.0f), Color(0, 0, 205), _T("-100"));
		SpriteBatch.DrawString(moji3, Vector2(800.0f, 480.0f), Color(255, 0, 0), _T("%d"), total_count);

		SpriteBatch.DrawString(moji2, Vector2(600.0f, 270.0f), Color(255, 0, 255), _T("%4d"), good_count_1);
		SpriteBatch.DrawString(moji2, Vector2(600.0f, 190.0f), Color(255, 255, 0), _T("%4d"), perfect_count_1);
		SpriteBatch.DrawString(moji2, Vector2(600.0f, 350.0f), Color(0, 0, 205), _T("%4d"), miss_count_1);

		SpriteBatch.DrawString(moji2, Vector2(730.0f, 270.0f), Color(255, 0, 255), _T("x"), good_count_1);
		SpriteBatch.DrawString(moji2, Vector2(730.0f, 190.0f), Color(255, 255, 0), _T("x"), perfect_count_1);
		SpriteBatch.DrawString(moji2, Vector2(730.0f, 350.0f), Color(0, 0, 205), _T("x"), miss_count_1);
	}

	

    SpriteBatch.End();
		//365
	if (METER_POWER >= 360) {
		movie_EF->Play();
		SpriteBatch.Begin();
		GraphicsDevice.SetBlendMode(BlendMode_Add);
		SpriteBatch.Draw(*movie_EF, Vector3(0.0f, 0.0f, 0.0f), 1.0f);
		SpriteBatch.End();

	}
		//////////////////
	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;

	/*paint.SetPaintColor(Color(255, 255, 255));
	for (int i = 0; i < 200; i++) {
		if (noot_state[i] == 0) {
			canvas.DrawRect(RectWH(noot_pos[i].x + 16, noot_pos[i].y + 57, 90, 8), paint);
		}
	}*/
	
	/*for (int i = 0; i < 200; i++) {
		if (Loll_state[i] == 0) {
			paint.SetPaintColor(Color(255, 255, 0));
			canvas.DrawRect(RectWH(Loll_pos[i].x + 0, Loll_pos[i].y + 0, 57, 3), paint);
		}
	}
*/
	
	////////////////////左パーフェクト
	//paint.SetPaintColor(Color(255, 255, 255));
	//canvas.DrawRect(RectWH(-10, 580, 400, 7), paint);

	///////////////////左グット上
	//paint.SetPaintColor(Color(0, 0, 255));
	//canvas.DrawRect(RectWH(-10, 570, 400, 10), paint);

	///////////////////左グット下
	//paint.SetPaintColor(Color(0, 0, 255));
	//canvas.DrawRect(RectWH(-10, 585, 400, 10), paint);

 //   ///////////////////左ミス上
	//paint.SetPaintColor(Color(255, 0, 0));
	//canvas.DrawRect(RectWH(-10, 560, 400, 10), paint);
	//
	///////////////左ミス
	//paint.SetPaintColor(Color(255, 0, 0));
	//canvas.DrawRect(RectWH(-10, 593, 400, 10), paint);




	///////////////右パーフェクト
	//paint.SetPaintColor(Color(255, 255, 255));
	//canvas.DrawRect(RectWH(930, 580, 400, 7), paint);

	//////////////右グット上
	//paint.SetPaintColor(Color(0, 0, 255));
	//canvas.DrawRect(RectWH(930, 570, 400, 10), paint);

	//////////右グット下
	//paint.SetPaintColor(Color(0, 0, 255));
	//canvas.DrawRect(RectWH(930, 585, 400, 10), paint);

	/////////////右ミス上
	//paint.SetPaintColor(Color(255, 0, 0));
	//canvas.DrawRect(RectWH(930, 560, 400, 10), paint);

	/////////////////右ミス下
	//paint.SetPaintColor(Color(255, 0, 0));
	//canvas.DrawRect(RectWH(930, 593, 400, 10), paint);
	//

	//////////////////Zノーツ
	///*paint.SetPaintColor(Color(255, 0, 0));
	//canvas.DrawRect(RectWH(400, 580, 530, 7), paint);*/

	//if (psyllium_.rotation.z >= 30 && psyllium_.rotation.z <= 60) {
	//	paint.SetPaintColor(Color(255, 0, 0));
	//	canvas.DrawRect(RectWH(542, 573, 100, 20), paint);
	//}
	//else if (psyllium_.rotation.z >= -60 && psyllium_.rotation.z <= -10) {
	//	paint.SetPaintColor(Color(255, 0, 255));
	//	canvas.DrawRect(RectWH(420, 573, 122, 20), paint);
	//}

	//paint.SetPaintColor(Color(255, 0, 0));
	//canvas.DrawRect(RectWH(642, 573, 100, 20), paint);
	//
	//paint.SetPaintColor(Color(255, 0, 0));
	//canvas.DrawRect(RectWH(742, 573, 100, 20), paint);

	paint.SetPaintColor(Color(255, 0, 0));
	canvas.DrawRect(RectWH(0, 0, HP_POWER, 0), paint);

	GraphicsDevice.UnlockCanvas();
	
}
