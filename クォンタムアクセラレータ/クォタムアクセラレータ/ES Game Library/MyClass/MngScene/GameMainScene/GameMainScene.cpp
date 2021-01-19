#include "GameMainScene.h"
#include "../SCENEMANAGER/SceneManager.h"

#include "../../Player/Player.h"
#include "../../Stage/Stage.h"
#include "../../MngUi/MngUi.h"

#include "../../ObstacleB/ObstacleB.h"
#include "../../ObstacleP/ObstacleP.h"
#include "../../ItemObstacle/ItemObstacle.h"
#include "../../ObstacleLeft/ObstacleLeft.h"
#include "../../ObstacleRight/ObstacleRight.h"
#include "../../ObstacleGate/ObstacleGate.h"

void GameMainScene::Initialize(){

	SNDMANAGER.LoadBGM(_T("BGM_SE//bgm.wav"));

	auto&& player = (new Player(Vector3_Zero));
	_objectroot.AddList((ChildObjRef)player);

	auto&& stage = (new Stage());
	_objectroot.AddList((ChildObjRef)stage);

	auto&& mngui = (new MngUi());
	_objectroot.AddList((ChildObjRef)mngui);
	player->SetUgui(mngui);

	auto&& obstacleb = (new ObstacleB());
	_objectroot.AddList((ChildObjRef)obstacleb);

	auto&& obstaclep = (new ObstacleP());
	_objectroot.AddList((ChildObjRef)obstaclep);

	auto&& item_obstacle = (new ItemObstacle());
	_objectroot.AddList((ChildObjRef)item_obstacle);

	auto&& left_obstacle = (new ObstacleLeft());
	_objectroot.AddList((ChildObjRef)left_obstacle);

	auto&& right_obstacle = (new ObstacleRight());
	_objectroot.AddList((ChildObjRef)right_obstacle);

	auto&& gate_obstacle = (new ObstacleGate());
	_objectroot.AddList((ChildObjRef)gate_obstacle);
}

GameMainScene::~GameMainScene()
{



};

void GameMainScene::Update(){
	_objectroot.Update();

	SNDMANAGER.PlayBGM();

	if (_gameMastaer._fgameOver  == true)  { SceneManager::ChangeScene(SceneManager::GAME_OVER);  };
	if (_gameMastaer._fgameClear == true)  { SceneManager::ChangeScene(SceneManager::RESULT);     };

}
void GameMainScene::Draw3D()
{
	_objectroot.Draw3D();
}
void GameMainScene::Draw2D()
{
	_objectroot.Draw2D();
}
void GameMainScene::DrawAlpha3D() 
{
	GraphicsDevice.BeginAlphaBlend();
	_objectroot.DrawAlpha3D();
	GraphicsDevice.EndAlphaBlend();
};

void GameMainScene::DrawEnd()
{
	_objectroot.DrawEnd();
}

