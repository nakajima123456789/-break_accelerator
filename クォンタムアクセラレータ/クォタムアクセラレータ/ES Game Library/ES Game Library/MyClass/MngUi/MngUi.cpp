#include "MngUi.h"

MngUi::MngUi()
{
	//���������X�g�ɓo�^
	observer.addListener(this);
}

MngUi::~MngUi()
{
	//���������X�g����폜
	observer.removeListener(this);
}

void MngUi::Init()
{
	speed_gage = mng_sprite.CreateSpriteFromFileRect(_T("UI/speedgage/sp.png"),    Vector3(0.0f, 0.0f, 0.0f));
	blackOut   = mng_sprite.CreateSprite(Vector2(1280.0f, 720.0f), Color(0, 0, 0), Vector3(0.0f,0.0f, SpriteBatch_TopMost));

	font       = GraphicsDevice.CreateSpriteFont(_T("Thirteen Pixel Fonts"), 90);

	game_timer = MAX_TIMER;
}
 
void MngUi::Update()
{	
	if (game_over_flag || game_timer <= 0) { mng_sprite.BlackOutTrigger(blackOut); };
	if (this->FrameTimeObsever(60))        { game_timer -= 1;};

}

void MngUi::Draw2D()
{
	mng_sprite.SetRectWH(speed_gage, 192 * UiDataBase.GetItemSize(), 0, 192, 192);

	game_timer = this->clamp(game_timer, 0, MAX_TIMER);
	UiDataBase.SetTimerSize(game_timer);
	SpriteBatch.DrawString(font, Vector2(600.0f, 0.0f), Color(255, 255, 255), _T("%d"), game_timer);

	mng_sprite.DrawSprite();
}

void MngUi::OnCollision(int collsionType)
{
	enum { DAMAGE, ITEM, GAMEOVER, RECOVERY};
	switch (collsionType)
	{
	case DAMAGE:
		CollisionTypeDamage();
		break;
	case ITEM:
		CollisionTypeItem();
		break;
	case RECOVERY:
		CollisionTypeRecovery();
		break;
	case GAMEOVER:
		game_over_flag = true;
		break;
	default:
		ASSERT(FALSE && "�Փ˔���̃^�O�����Ⴂ�܂��B");
		break;
	}
}

void MngUi::CollisionTypeDamage()
{
	game_timer -= 2;
}

void MngUi::CollisionTypeItem()
{
	UiDataBase.SetItemSize(2);
}

void MngUi::CollisionTypeRecovery()
{
	game_timer += 2;
}

