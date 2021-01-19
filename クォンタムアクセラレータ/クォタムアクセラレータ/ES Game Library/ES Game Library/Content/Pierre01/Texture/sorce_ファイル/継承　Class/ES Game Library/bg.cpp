#include "bg.h"

void bg::Initialize()
{

	sprite = GraphicsDevice.CreateSpriteFromFile(_T("ok.png"));
	pos = Vector3(0,0,10);

}


