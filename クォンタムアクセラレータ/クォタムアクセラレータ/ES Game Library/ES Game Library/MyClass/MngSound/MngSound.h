#pragma once

//------------------------------------------------------------------------------
//	インクルードファイル
//------------------------------------------------------------------------------
#include "../../ESGLib.h"
#include <vector>

//------------------------------------------------------------------------------
//	SEManagerクラス定義
//------------------------------------------------------------------------------

class MngSound {
public:
	MngSound() {};
	virtual ~MngSound() {};

	// シングルトンインスタンスの取得
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

	// メンバ変数
	std::vector< std::vector<SOUND> > se;

	MngSound(const MngSound&) = delete;
	MngSound& operator=(const MngSound&) = delete;
	MngSound(MngSound&&) = delete;
	MngSound& operator=(MngSound&&) = delete;
};

//------------------------------------------------------------------------------
//	インライン関数定義
//------------------------------------------------------------------------------
inline MngSound& SNDMgr() { return MngSound::GetInstance(); }
#define SNDMANAGER MngSound::GetInstance()