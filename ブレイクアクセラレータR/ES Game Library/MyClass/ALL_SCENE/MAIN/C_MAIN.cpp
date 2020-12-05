#include "C_MAIN.h"
#include "../SCENEMANAGER/SceneManager.h"

#include "../../C_PLAYER/C_PLAYER.h"
#include "../../C_CAMERA/C_CAMERA.h"

#include "../../C_INPUT/C_INPUT.h"
#include "../../ObjectPlacement/ObjectPlacement.h"

#include "../../C_OBSTACLE/C_Obstacle.h"
#include "../../C_OBSTACLEL/CObstacleL.h"

#include "../../C_OBSTACLER/CObstacleR.h"

#include "../../CBROCKOBSTACLE/CBrockObstacle.h"

#include "../../C_ITEMOBSTACLE/CItemOBstacle.h"

#include "../../CGATEOBSTACLE/CGateObstacle.h"

#include"../../C_GATEOBSTATCLE/R_GATEOBSTATCLE.h"

#include "../../C_EFFEKSEER/CEffekseer_.h"

#include "../../C_MAP/C_MAP.h"
#include "../../C_UI/CUI.h"

#include "../../C_SHADER/C_SHADER.h"

void C_MAIN::Initialize(){

	GraphicsDevice.SetRenderState(Lighting_Disable);

	auto&& c_camera = (new CCamera_);
	_objectroot.AddList((ChildObjRef)c_camera);

	CShaderAnimation::CameraSetting(*c_camera);

	auto&& c_player = (new CPlayer(Vector3_Zero));
	_objectroot.AddList((ChildObjRef)c_player);

	auto&& c_objectplacement = (new PlacementManager);
	_objectroot.AddList((ChildObjRef)c_objectplacement);

	auto&& c_map = new C_MAP;
	_objectroot.AddList((ChildObjRef)c_map);

	auto&& c_obstacle = new CObstacle();
	_objectroot.AddList((ChildObjRef)c_obstacle);

	auto&& c_obstacleL = new CObstacleL();
	_objectroot.AddList((ChildObjRef)c_obstacleL);

	auto&& c_obstacleR = new CObstacleR();
	_objectroot.AddList((ChildObjRef)c_obstacleR);

	auto&& c_brockobstacle = new CBrockObstacle();
	_objectroot.AddList((ChildObjRef)c_brockobstacle);

	auto&& c_itemobstacle = new CItemObstacle();
	_objectroot.AddList((ChildObjRef)c_itemobstacle);

	auto&& c_gateobstacle = new CGateObstacle();
	_objectroot.AddList((ChildObjRef)c_gateobstacle);

	auto&& c_gateobstatcle = new R_GATEOBSTATCLE();
	_objectroot.AddList((ChildObjRef)c_gateobstatcle);

	auto&& c_se = new CUI();
	_objectroot.AddList((ChildObjRef)c_se);
}

C_MAIN::~C_MAIN()
{

};

void C_MAIN::Update() {
	_objectroot.Update();

	if (Input.GetKeyInputDown(Keys_Enter)) { SceneManager::ChangeScene(SceneManager::GAME_CLEAR); }

	EffekseerMgr.Update();
}

void C_MAIN::Draw3D()
{
	_objectroot.Draw3D();
}
void C_MAIN::Draw2D()
{
	_objectroot.Draw2D();
}
void C_MAIN::DrawAlpha3D() 
{
	GraphicsDevice.BeginAlphaBlend();

	_objectroot.DrawAlpha3D();

	GraphicsDevice.EndAlphaBlend();
};

void C_MAIN::DrawEnd()
{
	_objectroot.DrawEnd();
}

