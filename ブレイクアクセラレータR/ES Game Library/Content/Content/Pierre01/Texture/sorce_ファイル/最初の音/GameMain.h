#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	// 変数宣言
    MEDIA movie_;
	MUSIC bgm;
	SOUND se;
	

	SPRITE   noot_spr;
	Vector3  noot_pos[200];
	int      noot_state[200];

	SPRITE player;
	FLOAT  player_x_, player_y_;

	SPRITE player1;
	FLOAT  player1_x_, player1_y_;

	SPRITE player2;
	FLOAT  player2_x_, player2_y_;

	SPRITE player3;
	FLOAT  player3_x_, player3_y_;

	SPRITE Line;
	FLOAT  Line_x_, Line_y_;

	FONT moji;
	FONT moji2;
	int count;
	int count22;
	int timer;

	int good;
	int miss;
	int font_state_;

	//フラッシュ
	SPRITE FR;
	int FR_count_;
	int FR_state_;

	SPRITE FR1;
	int FR1_count_;
	int FR1_state_;

	SPRITE FR2;
	int FR2_count_;
	int FR2_state_;

	SPRITE FR3;
	int FR3_count_;
	int FR3_state_;
	//フラッシュ
	SPRITE TITORU;
	SPRITE mein;
	int game_scene_;

	int miss_state_;
	int miss_count_;

	int good_state_;
	int good_count_;



	// 関数宣言

};
