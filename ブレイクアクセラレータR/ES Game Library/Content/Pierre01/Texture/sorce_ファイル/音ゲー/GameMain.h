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
	SpriteElement psyllium_;
	SpriteElement psyllium_2;

	SPRITE title;
	FLOAT title_x_, title_y_;

	SPRITE game_start;
	FLOAT game_start_x_, game_start_y_;

	SPRITE select;
	FLOAT select_x_, select_y_;

	SPRITE RIZALT;
	FLOAT RIZALT_x_, RIZALT_y_;

	float start_;
	int count1;

	//エフェクト
	SPRITE EF;
	FLOAT EF_x_, EF_y_;
	int EF_frame;
	int EF_state;


	SPRITE EF2;
	FLOAT EF2_x_, EF2_y_;
	int EF2_frame;
	int EF2_state;

	//

	//ゲージ
	SPRITE GAGE;
	FLOAT GAGE_x_, GAGE_y_;

	SPRITE gagemeter;
	float gagemeter_x_, gagemeter_y_;
	float a;
	int count1234;

	int METER_POWER;
	int meter_state;

	//HP
	int HP_POWER;
	SPRITE HPfull;
	FLOAT HPfull_x_, HPfull_y_;

	SPRITE HP;
	FLOAT HP_x_, HP_y_;

	SPRITE HP2;
	FLOAT HP2_x_, HP2_y_;

	SPRITE HP3;
	FLOAT HP3_x_, HP3_y_;

	int HP_state;

	//

	FONT moji2;

	SPRITE WAKU;
	FLOAT WAKU_x_,WAKU_y_;
	MEDIA movie_;
	MEDIA movie_EF;
	
	MUSIC BGM;
	SOUND SE;
	SOUND SE_2;
	SOUND SE_3;

	int NOOT_frame[200];
	

	//判定
	int count2;
	SPRITE good;
	FLOAT good_x_, good_y_;
	int good_state_;

	int count3;
	SPRITE perfect;
	FLOAT perfect_x_, perfect_y_;
	int perfect_state_;

	int count4;
	SPRITE BAD;
	FLOAT BAD_x_, BAD_y_;
	int BAD_state_;

	//NOOT_LOll
	SPRITE Loll;
	int  Loll_state[200];
	Vector3 Loll_pos[200];
    int  Loll_length_[200];
	
	FLOAT Loll_X_LEFT = 315;
	FLOAT Loll_X_RIGHT = 947;
	FLOAT LOll_Y_ = -416;



	//NOOT
	SPRITE   noot_spr;
	Vector3  noot_pos[200];
	int      noot_state[200];
	

	float   NOOT_POS_LEFT = 280.0f;
	float   NOOT_POS_RIGHT = 920.0f;
	float   NOOT_INIT_Y = -50.0f;





	//Z
	SPRITE   Z_spr[2];
	Vector3  Z_pos[200];
	int      Z_state[200];
	int      Z_type[200];

	float   Z_POS_RIGHT = 680.0f;
	float   Z_POS_LEFT = 440.0f;
	float   Z_INIT_Y = -55.0f;

	enum z_type {
		Z_LEFT,
		Z_RIGHT,
	};



	//Z_NOOT
	SPRITE   Z_NOOT_spr[2];
	Vector3  Z_NOOT_pos[200];
	int      Z_NOOT_state[200];
	int      Z_NOOT_type[200];
	int      Z_NOOT_frame[200];
	//サイリウム１
	float   Z_NOOT_POS_LEFT = 430.0f;
	float   Z_NOOT_POS_RIGHT = 530.0f;
	//サイリウム２
	float   Z_NOOT_POS_LEFT2 = 630.0f;
	float   Z_NOOT_POS_RIGHT2 = 750.0f;

	float   Z_NOOT_INIT_Y = -55.0f;


	enum z_noot_type {
		Z_NOOT_LEFT,
		Z_NOOT_RIGHT,
	};
		
	int count;
	int timer;
	int count_frame;

	int game_scene_;

	int good_count;
	int perfect_count;
	int miss_count;
	int total_count;

	int perfect_count_1;
	int miss_count_1;
	int good_count_1;

	SPRITE EFLoll;
	FLOAT EFLoll_x_, EFLoll_y_;
	int EFLoll_state;
	int EFLoll_frame;

	SPRITE EFLoll_2;
	FLOAT EFLoll_2_x_, EFLoll_2_y_;
	int EFLoll_2_state;
	int EFLoll_2_frame;
		

	FONT moji3;


	

	// 関数宣言

	

};
