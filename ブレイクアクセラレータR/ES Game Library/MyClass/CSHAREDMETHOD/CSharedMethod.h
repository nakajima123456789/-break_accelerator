#pragma once

#include "../C_HITBOX/HitBox.h"
#include "../CSHAREDMETHOD/CSharedMethod.h"
#include "../OBSEVER/OBSEVER.h"

class CSharedMethod
{
public:
	//���b�v�A���E���h
	int         wrap(int x, int low, int high);
	//�N�����v
	double      clamp(double x, double low, double high);

	//�t���[���o�ߎ��Ԃ�`����
	bool     FrameTimeObsever(int _index);

	int a = 5;

private:

	int _time;
};
