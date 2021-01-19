#include "MngSound.h"

/**
 * @file   C_SE.cpp
 * @brief  C_SE�N���X�\�[�X�t�@�C��
 * @author �����D��N
 * @date   2020/10/1
 */

 /**
  * @brief ������(���C�g�̏������A�J�����̐ݒ�)
  * @param[in] (�Ȃ�)
  * @return    (�Ȃ�)
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
  * @brief SE�̓ǂݍ��ݏd���Đ��\
  * @param[in] (filename) SE�t�@�C���̖��O
  * @param[in] (multiple) �d���Đ���
  * @return    �X���b�g�ԍ�
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
  * @brief SE�Đ�
  * @param[in] (index) �Đ��������X���b�g
  * @return    (�Ȃ�)
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
 * @brief BGM�Đ�
 * @param[in] (�Ȃ�)
 * @return    (�Ȃ�)
 */

bool MngSound::PlayBGM()
{
	if (bgm->IsPlaying())return FALSE;
	bgm->Play();
	return TRUE;
}

/**
 * @brief ���[�v�Đ�
 * @param[in] (_number) �X���b�g�ԍ�
 * @return    (�Ȃ�)
 */

void MngSound::PlayLopeSE(int _number)
{
	if (!LopeSE[_number]->IsPlaying()) {
		LopeSE[_number]->Play();
	}
}

/**
 * @brief ���[�vSE�̓ǂݍ���
 * @param[in] (filename) SE�t�@�C���l�[��
 * @return    (�X���b�g�ԍ�)
 */
int MngSound::LoadLopeSE(TCHAR* filename)
{
	LopeSE.push_back(SoundDevice.CreateSoundFromFile(filename));

	return LopeSE.size() - 1;
}

