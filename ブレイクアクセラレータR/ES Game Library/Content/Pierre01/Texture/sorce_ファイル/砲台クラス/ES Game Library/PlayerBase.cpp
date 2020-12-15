#include "PlayerBase.h"


void PlayerBase::Initialize(Vector3& position, LPCTSTR filename)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(filename);
	pos = position;

	for (int i = 0; i < 100; i++)
	{
		shot_[i].ini();
	}

}

void PlayerBase::Update(KeyboardState& Key_state, KeyboardBuffer& Key_buffer)
{

	for (int i = 0; i < 100; i++)
	{
		shot_[i].Up();

	}

}

void PlayerBase::Draw()
{
	SpriteBatch.Draw(*sprite, pos);
	for (int i = 0; i < 100; i++)
	{
		shot_[i].Draw();
	}
}

Rect PlayerBase::GetCollision()
{

	Rect collision;
	collision.left = (int)pos.x;
	collision.top = (int)pos.y;
	collision.right = (int)(collision.left + 32);
	collision.bottom = (int)(collision.top + 32);

	return collision;
}

