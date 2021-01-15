#include "player.h"

void player::Update(KeyboardState& Key_state, KeyboardBuffer& Key_buffer)
{

	if (Key_state.IsKeyDown(Keys_Left))
	{
		pos.x -= 5.0f;
	}

	if (Key_state.IsKeyDown(Keys_Right))
	{
		pos.x += 5.0f;
	}

	if (Key_state.IsKeyDown(Keys_Up))
	{
		pos.y -= 5.0f;
	}

	if (Key_state.IsKeyDown(Keys_Down))
	{
		pos.y += 5.0f;
	}

	PlayerBase::Update(Key_state, Key_buffer);

	if (Key_buffer.IsPressed(Keys_Space))
	{
		for (int i = 0; i < 100; i++)
		{
			if(shot_[i].Fire(pos))
			break;
		}
	}
}


