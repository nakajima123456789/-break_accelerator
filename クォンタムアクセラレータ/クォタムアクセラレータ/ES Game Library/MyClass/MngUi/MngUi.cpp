#include "MngUi.h"

#include "../CsvPositionDataBase/CsvPositionDataBase.h"
#include "../PlayerDataBase/PlayerDataBase.h"

MngUi::MngUi()
{
	//Ž©•ª‚ðƒŠƒXƒg‚É“o˜^
	observer.addListener(this);
}

MngUi::~MngUi()
{
	//Ž©•ª‚ðƒŠƒXƒg‚©‚çíœ
	observer.removeListener(this);
}

void MngUi::Init()
{
	mng_sprite = new MngSprite();
	this->ChildObj_AddList((ChildObjRef)mng_sprite);

	timer = new Time();
	this->ChildObj_AddList((ChildObjRef)timer);

	sprite[SPEED]    = mng_sprite->CreateSpriteFromFileRect(_T("UI/speedgage/sp.png"),   Vector3(0.0f, 0.0f, 0.0f));
	sprite[BLACK]    = mng_sprite->CreateSprite(Vector2(1280.0f, 720.0f), Color(0, 0, 0),Vector3(0.0f,0.0f, SpriteBatch_TopMost));
	sprite[SPEED_UP] = mng_sprite->CreateSpriteFromFileAlpha(_T("SPRITE/spu.png"),       Vector3(650.0f, 320.0f, 0.0f));

	mng_sprite->CreateSpriteFromFile(_T("SPRITE/aka.png"), Vector3(0.0f, 0.0f, SpriteBatch_BottomMost));
}
 
void MngUi::Update()
{	
	if (speed_up_flag){ speed_up_flag = mng_sprite->RoopDrawOutTrigger(sprite[SPEED_UP]); }

	Vector3 goal_position = *CsvPoitionDataBase.GetCsvPosition('G').begin();

	if (gameoverFlag || timer->IsTimer())                        { gameMastaer._fgameOver  = mng_sprite->BlackOutTrigger(sprite[BLACK]); };
	if (PlayerDataBase.GetPlayerPosition().z >= goal_position.z) { gameMastaer._fgameClear = mng_sprite->BlackOutTrigger(sprite[BLACK]); };
}

void MngUi::Draw2D()
{
	mng_sprite->SetRectWH(sprite[SPEED], 192 * UiDataBase.GetItemSize(), 0, 192, 192);
}

void MngUi::OnCollision(int collsionType)
{
	enum { DAMAGE, ITEM, GAMEOVER, RECOVERY};
	if (collsionType == DAMAGE)     { CollisionTypeDamage();   }
	if (collsionType == ITEM)       { CollisionTypeItem();     }
	if (collsionType == RECOVERY)   { CollisionTypeRecovery(); }
	if (collsionType == GAMEOVER)   { gameoverFlag = true;     }
}

void MngUi::OnAddTiemr(int add_timer){ timer->AddTimer(add_timer);}

void MngUi::CollisionTypeDamage(){
	
}

void MngUi::CollisionTypeItem() {
	UiDataBase.SetItemSize(add_item_point *  2);
}

void MngUi::CollisionTypeRecovery(){

}

void MngUi::PlayerSpeedUp(){
	UiDataBase.SetItemSize(add_item_point * -3);
	speed_up_flag = true;
}
