#include "SharedMethod.h"

int SharedMethod::wrap(int x, int low, int high)
{
	ASSERT(low < high);
	const int n = (x - low) % (high - low);
	return (n >= 0) ? (n + low) : (n + high);
}

int SharedMethod::clamp(int x, int low, int high)
{
	ASSERT(low <= high && "Å¬’l <= Å‘å’l");
	return min(max(x, low), high);
}

bool SharedMethod::FrameTimeObsever(int _index)
{
	_time++;
	if (_time % _index == 0) { return true; }
	return false;
}

Material SharedMethod::SetMaterial()
{
	Material mtrl;

	mtrl.Diffuse  = Color(1.0f, 1.0f, 1.0f);
	mtrl.Ambient  = Color(1.0f, 1.0f, 1.0f);
	mtrl.Specular = Color(1.0f, 1.0f, 1.0f);
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);
	mtrl.Power = 1.0f;

	return Material(mtrl);
}