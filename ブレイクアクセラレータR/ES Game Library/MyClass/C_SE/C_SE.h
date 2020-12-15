#pragma once

//------------------------------------------------------------------------------
//	�C���N���[�h�t�@�C��
//------------------------------------------------------------------------------
#include "../../ESGLib.h"
#include <vector>

//------------------------------------------------------------------------------
//	SEManager�N���X��`
//------------------------------------------------------------------------------

class C_SE 
{
public:
	C_SE() {};
	virtual ~C_SE(){};

	// �V���O���g���C���X�^���X�̎擾
	static C_SE& GetInstance()
	{ 
		static C_SE theSEManager;
		return theSEManager;
	}
	bool Initialize();

	int  LoadSE(TCHAR* filename, const UINT multiple = 1);
	void PlaySE(int index);
	
	void LoadBGM(TCHAR* filename) { bgm = SoundDevice.CreateMusicFromFile(filename); };
	bool PlayBGM();

private:
	
	MUSIC bgm;

	// �����o�ϐ�
	std::vector< std::vector<SOUND> > se;

	C_SE(const C_SE&) = delete;
	C_SE& operator=(const C_SE&) = delete;
	C_SE(C_SE&&) = delete;
	C_SE& operator=(C_SE&&) = delete;
};

//------------------------------------------------------------------------------
//	�C�����C���֐���`
//------------------------------------------------------------------------------
#define SNDMANAGER C_SE::GetInstance()