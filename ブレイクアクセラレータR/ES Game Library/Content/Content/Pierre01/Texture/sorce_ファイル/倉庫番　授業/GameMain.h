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
	// �ϐ��錾

	SPRITE player_sprite_;
	Vector3 player_position_;

	KeyboardState key_state_;
	KeyboardBuffer key_buffer_;

	SPRITE wall_sprite_;


	SPRITE item;
	SPRITE item_2;

	SPRITE goal;
	Vector3 goal_position;

	cstring map_work_[10];


	bool color;
	bool scene;


	

	//tstring map_data0_; // 0�s�ڂ̃f�[�^(��ԏ�̍s)
	//tstring map_data1_; // 1�s�ڂ̃f�[�^
	//tstring map_data2_; // 2�s�ڂ̃f�[�^
	//tstring map_data3_; // 3�s�ڂ̃f�[�^
	//tstring map_data4_; // 4�s�ڂ̃f�[�^
	//tstring map_data5_; // 5�s�ڂ̃f�[�^
	//tstring map_data6_; // 6�s�ڂ̃f�[�^
	//tstring map_data7_; // 7�s�ڂ̃f�[�^
	//tstring map_data8_; // 8�s�ڂ̃f�[�^


	cstring map_data_[10];
	FILE* file;
	FILE* file_2;

	char buf[40 + 1];
	char buf_2[40 + 1];
	

	SPRITE field_sprite_;

	// �֐��錾

	void loop();

};
