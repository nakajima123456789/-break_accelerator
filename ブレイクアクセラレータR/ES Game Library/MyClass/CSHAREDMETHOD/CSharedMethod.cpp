#include "CSharedMethod.h"

int CSharedMethod::wrap(int x, int low, int high)
{
	ASSERT(low < high);
	const int n = (x - low) % (high - low);
	return (n >= 0) ? (n + low) : (n + high);
}

int CSharedMethod::clamp(int x, int low, int high)
{
	ASSERT(low <= high && "�ŏ��l <= �ő�l");
	return min(max(x, low), high);
}

bool CSharedMethod::FrameTimeObsever(int _index)
{
	_time++;
	if (_time % _index == 0) { return true; }
	return false;
}
