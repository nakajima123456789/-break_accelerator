#pragma once

class GameMastaer
{
public:
	//コンストラクタ
	GameMastaer() {};
	//デストラクタ
	~GameMastaer();

	//ゲームオーバーのフラグ　TRUEだと画面遷移
	static bool _fgameOver;
	//ゲームクリアのフラグ　TRUEだと画面遷移
	static bool _fgameClear;

private:

};

