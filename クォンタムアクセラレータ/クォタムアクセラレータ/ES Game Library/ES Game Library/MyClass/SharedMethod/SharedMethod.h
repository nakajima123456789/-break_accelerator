#pragma once
#include "../../ESGLib.h"

class SharedMethod
{
public:

	int  wrap (int x, int low, int high);
	int  clamp(int x, int low, int high);

	bool FrameTimeObsever(int _index);

	Material SharedMethod::SetMaterial();

private:
	int _time;
};
