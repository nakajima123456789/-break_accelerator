#pragma once
#include "base.h"
class Enemy : public base
{
public:
	
	void initialize();
	void Update();

private:
	bool state;
	int count;
};

