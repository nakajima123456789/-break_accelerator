#include "C_MAIN.h"
#include "../SCENEMANAGER/SceneManager.h"

#include "../../C_CAMERA/C_CAMERA.h"

#include "../../ObjectPlacement/ObjectPlacement.h"

#include "../../C_MAP/C_MAP.h"
#include "../../C_UI/CUI.h"

#include "../../C_SHADER/C_SHADER.h"

#include "../../ObstacleManager/ObstacleManager.h"

#include "../../../CMapMove.h"

void C_MAIN::Initialize(){

	auto&& c_mapmove = (new CMapMove());
	_objectroot.AddList((ChildObjRef)c_mapmove);

	GraphicsDevice.SetRenderState(Lighting_Disable);

	auto&& c_camera = (new CCamera_);
	_objectroot.AddList((ChildObjRef)c_camera);

	CShaderAnimation::CameraSetting(*c_camera);

	auto&& c_objectplacement = (new PlacementManager);
	_objectroot.AddList((ChildObjRef)c_objectplacement);

	auto&& c_obstaclemanager = (new ObstacleManager);
	_objectroot.AddList((ChildObjRef)c_obstaclemanager);

	auto&& c_map = new C_MAP;
	_objectroot.AddList((ChildObjRef)c_map);

	auto&& c_se = new CUI();
	_objectroot.AddList((ChildObjRef)c_se);
}

C_MAIN::~C_MAIN()
{

};

void C_MAIN::Update() {
	_objectroot.Update();

	if (Input.GetKeybordInputDown(Keys_Enter)) { SceneManager::ChangeScene(SceneManager::GAME_CLEAR); }
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

