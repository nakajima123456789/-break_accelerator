#include "GameMastaer.h"

/**
 * @file   CGameMastaer.cpp
 * @brief  �Q�[���}�X�^�[�N���X�\�[�X�t�@�C��
 * @author �����D��N
 * @date   2020/10/1
 */

bool GameMastaer::_fgameClear = false;
bool GameMastaer::_fgameOver  = false;

/**
 * @brief �f�X�g���N�^(���C���V�[�����I������Ώ�����)
 * @param[in] (�Ȃ�)
 * @return    (�Ȃ�)
 */
GameMastaer::~GameMastaer()
{
	_fgameOver  = false;
	_fgameClear = false;
}
