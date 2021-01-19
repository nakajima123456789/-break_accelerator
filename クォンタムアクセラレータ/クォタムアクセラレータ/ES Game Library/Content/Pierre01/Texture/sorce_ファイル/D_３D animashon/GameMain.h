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
	// ïœêîêÈåæ

	enum PLAYER_STATE {
		BACKTEN,
		STEP,
		KIRIBARAI,
		RUN,
		IDOL,
		SLIDING,
		ROWLING,
		JUMP
	};

	ANIMATIONMODEL player_;
    ANIMATIONMODEL enemy;

	int player_state_;
	int anime_state;
	int jump_count;
	int sliding_count;
	int rowling_count;
	int run_count;
	int kiribarai_count;
	int step_count;
	int backten_count;

	MODEL New_Town;
    MODEL box;
	MODEL enemy_box;
	CAMERA camera;

	EFFEKSEER   effect_;
	
	FONT letter;

	bool Box;

	bool Drw;

	 //ä÷êîêÈåæ
	void SetPlayerState(int new_state);
};
