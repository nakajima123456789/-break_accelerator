#pragma once

//------------------------------------------------------------------------------
//	�C���N���[�h�t�@�C��
//------------------------------------------------------------------------------
#include "../../ESGLib.h"
#include <vector>

//------------------------------------------------------------------------------
//	SEManager�N���X��`
//------------------------------------------------------------------------------

class MngSound {
public:
	MngSound() {};
	virtual ~MngSound() {};

	// �V���O���g���C���X�^���X�̎擾
	static MngSound& GetInstance()
	{
		static MngSound theSEManager;
		return theSEManager;
	}
	bool Initialize();

	int  LoadSE(TCHAR* filename, const UINT multiple = 1);
	void PlaySE(int index);

	void LoadBGM(TCHAR* filename) { bgm = SoundDevice.CreateMusicFromFile(filename); };
	bool PlayBGM();

	int  LoadLopeSE(TCHAR* filename);
	void PlayLopeSE(int _number);

	std::vector<SOUND> LopeSE;
private:

	MUSIC bgm;

	// �����o�ϐ�
	std::vector< std::vector<SOUND> > se;

	MngSound(const MngSound&) = delete;
	MngSound& operator=(const MngSound&) = delete;
	MngSound(MngSound&&) = delete;
	MngSound& operator=(MngSound&&) = delete;
};

//------------------------------------------------------------------------------
//	�C�����C���֐���`
//------------------------------------------------------------------------------
inline MngSound& SNDMgr() { return MngSound::GetInstance(); }
#define SNDMANAGER MngSound::GetInstance()