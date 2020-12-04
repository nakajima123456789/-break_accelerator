#pragma once

#include "../C_HITBOX/HitBox.h"
#include "../CSHAREDMETHOD/CSharedMethod.h"

class CSharedMethod
{
public:
	//���b�v�A���E���h
	int      wrap(int x, int low, int high);
	//�N�����v
	int      clamp(int x, int low, int high);

	//�t���[���o�ߎ��Ԃ�`����
	bool     FrameTimeObsever(int _index);

	std::unique_ptr<HitBox>     _hitbox;

private:

	int _time;
};
