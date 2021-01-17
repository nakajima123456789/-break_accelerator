#pragma once
#include "shot.h"

class PlayerBase
{

public:
	void Initialize(Vector3& position,LPCTSTR filename);
	void Update(KeyboardState& Key_state, KeyboardBuffer& Key_buffer);
	void Draw();

	Vector3 GetPosition() { return pos; }
	Rect GetCollision();


protected:
	SPRITE sprite;
	Vector3 pos;

	shot shot_[100];


};


