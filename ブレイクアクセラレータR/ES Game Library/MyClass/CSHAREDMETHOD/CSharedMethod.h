#pragma once

#include "../C_HITBOX/HitBox.h"
#include "../CSHAREDMETHOD/CSharedMethod.h"

class CSharedMethod
{
public:
	//ラップアラウンド
	int      wrap(int x, int low, int high);
	//クランプ
	int      clamp(int x, int low, int high);

	//フレーム経過時間を伝える
	bool     FrameTimeObsever(int _index);

	std::unique_ptr<HitBox>     _hitbox;

private:

	int _time;
};
