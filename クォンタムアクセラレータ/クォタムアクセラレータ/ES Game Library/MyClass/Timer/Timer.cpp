#include "Timer.h"

void Time::Init()
{
	this->font = GraphicsDevice.CreateSpriteFont(_T("Thirteen Pixel Fonts"), 90);

	this->timer = this->MAX_TIME;
}

void Time::Update()
{
	if (this->FrameTimeObsever(60)) { this->timer--; };
}

void Time::Draw2D()
{
	this->timer = this->clamp(this->timer, 0, this->MAX_TIME);

	UiDataBase.SetTimerSize(this->timer);

	SpriteBatch.DrawString(font, Vector2(600.0f, 0.0f), Color(255, 255, 255), _T("%d"), this->timer);
}
