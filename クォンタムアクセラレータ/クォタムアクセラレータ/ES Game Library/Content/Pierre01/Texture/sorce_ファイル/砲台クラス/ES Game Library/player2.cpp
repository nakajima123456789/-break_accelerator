#include "player2.h"

void player2::Update(KeyboardState& Key_state, KeyboardBuffer& Key_buffer)
{

	if (Key_state.IsKeyDown(Keys_A))
	{
		pos.x -= 5.0f;
	}

	if (Key_state.IsKeyDown(Keys_D))
	{
		pos.x += 5.0f;
	}

	if (Key_state.IsKeyDown(Keys_W))
	{
		pos.y -= 5.0f;
	}

	if (Key_state.IsKeyDown(Keys_S))
	{
		pos.y += 5.0f;
	}

	PlayerBase::Update(Key_state, Key_buffer);

	if (Key_state.IsKeyDown(Keys_Enter))
	{
		for (int i = 0; i < 100; i++)
		{
			if (shot_[i].Fire(pos))
			break;
		}
	}

}

