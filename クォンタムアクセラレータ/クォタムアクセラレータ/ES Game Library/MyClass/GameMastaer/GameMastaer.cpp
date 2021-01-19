#include "GameMastaer.h"

/**
 * @file   CGameMastaer.cpp
 * @brief  ゲームマスタークラスソースファイル
 * @author 中島颯一朗
 * @date   2020/10/1
 */

bool GameMastaer::_fgameClear = false;
bool GameMastaer::_fgameOver  = false;

/**
 * @brief デストラクタ(メインシーンが終了すれば初期化)
 * @param[in] (なし)
 * @return    (なし)
 */
GameMastaer::~GameMastaer()
{
	_fgameOver  = false;
	_fgameClear = false;
}
