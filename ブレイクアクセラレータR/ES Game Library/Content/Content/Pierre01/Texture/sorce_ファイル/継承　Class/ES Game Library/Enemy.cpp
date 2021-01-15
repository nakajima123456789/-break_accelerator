#include "Enemy.h"



void Enemy::initialize()
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_T("Brock.png"));
	pos = Vector3_Zero;

	state = TRUE;
	
}

void Enemy::Update()
{

	if (pos.x >= 1280.0f)
	{
		state = FALSE;
	}
	else if (pos.x <= 0.0f)
	{
		state = TRUE;
	}

	switch (state)
	{
	case TRUE:
		pos.x += 5.0f;
		break;

	case FALSE:
		pos.x -= 5.0f;
		break;

	}
}