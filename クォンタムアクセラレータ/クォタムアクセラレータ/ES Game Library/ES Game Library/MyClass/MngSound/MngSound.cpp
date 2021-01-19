#include "MngSound.h"

/**
 * @file   C_SE.cpp
 * @brief  C_SEクラスソースファイル
 * @author 中島颯一朗
 * @date   2020/10/1
 */

 /**
  * @brief 初期化(ライトの初期化、カメラの設定)
  * @param[in] (なし)
  * @return    (なし)
  */
bool MngSound::Initialize()
{
	se.clear();
	se.reserve(4);

	SoundDevice.ReleaseAllMusics();
	SoundDevice.ReleaseAllSounds();

	return true;
}

 /**
  * @brief SEの読み込み重複再生可能
  * @param[in] (filename) SEファイルの名前
  * @param[in] (multiple) 重複再生個数
  * @return    スロット番号
  */

int MngSound::LoadSE(TCHAR* filename, const UINT multiple)
{
	std::vector<SOUND> se_vec;
	se_vec.assign(multiple, nullptr);

	SoundDevice.CreateSharedSoundFromFile(filename, &se_vec[0], multiple, false);
	se.push_back(se_vec);


	return se.size() - 1;
}

 /**
  * @brief SE再生
  * @param[in] (index) 再生したいスロット
  * @return    (なし)
  */

void MngSound::PlaySE(int index)
{
	if (se[index].size() <= 1) {
		se[index][0]->Play();
		return;
	}

	for (UINT i = 0; i < se[index].size(); i++) {
		if (!se[index][i]->IsPlaying()) {
			se[index][i]->Play();
			return;
		}
	}

	se[index][0]->Play();
}

/**
 * @brief BGM再生
 * @param[in] (なし)
 * @return    (なし)
 */

bool MngSound::PlayBGM()
{
	if (bgm->IsPlaying())return FALSE;
	bgm->Play();
	return TRUE;
}

/**
 * @brief ループ再生
 * @param[in] (_number) スロット番号
 * @return    (なし)
 */

void MngSound::PlayLopeSE(int _number)
{
	if (!LopeSE[_number]->IsPlaying()) {
		LopeSE[_number]->Play();
	}
}

/**
 * @brief ループSEの読み込み
 * @param[in] (filename) SEファイルネーム
 * @return    (スロット番号)
 */
int MngSound::LoadLopeSE(TCHAR* filename)
{
	LopeSE.push_back(SoundDevice.CreateSoundFromFile(filename));

	return LopeSE.size() - 1;
}

