#include "Player_3.h"

void Player_3::Initialize()
{
	InputDevice.CreateGamePad(1);

	sprite = GraphicsDevice.CreateSpriteFromFile(_T("Brock.png"));
	pos = Vector3_Zero;

}

void Player_3::Update()
{
	GamePadState pad_state = GamePad(0)->GetState();

	if (pad_state.X > Axis_Center)
	{
		pos.x += 5.0f;
	}

	if (pad_state.X < Axis_Center)
	{
		pos.x -= 5.0f;
		
	}

}


