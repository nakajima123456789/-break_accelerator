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
	// ïœêîêÈåæP
	SPRITE TAITORU;
	SPRITE Fin;
	SPRITE ssss;
	SPRITE yuka;
	SPRITE player;
	SPRITE a;
	SPRITE b;
	SPRITE c;
	SPRITE d;
	SPRITE e;
	SPRITE f;
	SPRITE v;
	SPRITE x;
	SPRITE vv;
	SPRITE xx;
	SPRITE chara;
	SPRITE kyara;
	SPRITE EF;
	SPRITE tate;
	SPRITE w;
	SPRITE ww;
	SOUND se1;
	SOUND se2;
	SOUND se3;
	MUSIC bgm;
	MUSIC bgmgame;
	FONT moji;
	SPRITE l;
	SPRITE ll;
	SPRITE lll;
	float ssss_x_, ssss_y_;
	float TAITORU_x_, TAITORU_y_;
	float Fin_x_, Fin_y_;
	float yuka_x_, yuka_y_;
	float player_x_, player_y_;
	float a_x_, a_y_;
	float b_x_, b_y_;
	float c_x_, c_y_;
	float d_x_, d_y_;
	float e_x_, e_y_;
	float f_x_, f_y_;
	float chara_x_, chara_y_;
	float v_x_, v_y_;
	float x_x_, x_y_;
	float vv_x_, vv_y_;
	float xx_x_, xx_y_;
	float ww_x_, ww_y_;
	float w_x_, w_y_;
	float l_x_, l_y_; 
	float ll_x_, ll_y_;
	float lll_x_, lll_y;
	int v_state_;
	int x_state_;
	int vv_state_;
	int xx_state_;
	int w_state_;
	int l_state_;
	int chara_state_;
	int player_state_;
	int game_scene_;
	int count;
	int timer;
	int gameover_count;
	// ä÷êîêÈåæ

};
