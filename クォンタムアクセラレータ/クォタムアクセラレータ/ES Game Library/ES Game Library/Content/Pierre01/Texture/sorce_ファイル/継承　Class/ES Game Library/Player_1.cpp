#include "Player_1.h"

void Player_1::Initialize()
{

	sprite = GraphicsDevice.CreateSpriteFromFile(_T("Brock.png"));
	pos = Vector3_Zero;

}

void Player_1::Update()
{
	KeyboardState Key_state = Keyboard->GetState();

	if (Key_state.IsKeyDown(Keys_Down))
	{
		pos.y += 5.0f;
	}

	if (Key_state.IsKeyDown(Keys_Up))
	{
		pos.y -= 5.0f;
	}

}

