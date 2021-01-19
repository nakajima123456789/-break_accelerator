#include "ESGLib.h"
#pragma once
class shot
{
public:
	void ini();
	void Up();
	void Draw();

	bool Fire(Vector3& start_pos);
	void Reload();
	

private:
	static SPRITE sprite;
	Vector3 sprite_pos;
	int state;

	//SPRITE canon;
	//Vector3 canon_pos;

};

