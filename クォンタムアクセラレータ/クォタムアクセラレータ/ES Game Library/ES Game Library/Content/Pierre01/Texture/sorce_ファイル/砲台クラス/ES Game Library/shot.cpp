#include "shot.h"

SPRITE shot::sprite = nullptr;
void shot::ini()
{
	if (sprite == nullptr)
	{
		sprite = GraphicsDevice.CreateSpriteFromFile(_T("6053568i.png"));
	}

	state = 0;

	sprite_pos = Vector3_Zero;

}



void shot::Up()
{

//	KeyboardBuffer Key_buf = Keyboard->GetBuffer();

	
	/*if (state == 0)
	{

		sprite_pos.x = start_pos.x;
		sprite_pos.y = start_pos.y;
		sprite_pos = Vector3(sprite_pos.x, sprite_pos.y, 0);
		
	}*/
	
	if (state == 1)
	{
		sprite_pos.y -= 2.0f;
		if (sprite_pos.y <= 0)
		{
			state = 0;
		}
	}



}

bool shot::Fire(Vector3& start_pos)
{

	if (state == 1)
	{
		return false;

	}

	if (state == 0)
	{

		sprite_pos.x = start_pos.x;
		sprite_pos.y = start_pos.y;
		state = 1;

	}

	return true;

}

void shot::Reload()
{

}


void shot::Draw()
{


	if (state == 1)
	{
		SpriteBatch.Draw(*sprite, sprite_pos);
	}

}

