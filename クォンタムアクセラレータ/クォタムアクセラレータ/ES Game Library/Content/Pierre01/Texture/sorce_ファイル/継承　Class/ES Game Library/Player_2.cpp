#include "Player_2.h"

void Player_2::Initialize()
{

	InputDevice.CreateMouse();

	sprite = GraphicsDevice.CreateSpriteFromFile(_T("Brock.png"));
	pos = Vector3_Zero;

}

void Player_2::Update()
{
	MouseState mouse_state = Mouse->GetState();

	pos.x = pos.x + mouse_state.X * 2;

	pos.y = pos.y + mouse_state.Y * 2;

}




