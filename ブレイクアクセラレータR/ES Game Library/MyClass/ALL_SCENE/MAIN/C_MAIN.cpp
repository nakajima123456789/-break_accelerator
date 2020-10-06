#include "C_MAIN.h"
#include "../SCENEMANAGER/SceneManager.h"

#include "../../C_PLAYER/C_PLAYER.h"
#include "../../C_CAMERA/C_CAMERA.h"

#include "../../C_INPUT/C_INPUT.h"

void C_MAIN::Initialize(){

	auto c_camera = (new CCamera_);
	_objectroot.AddList((ChildObjRef)c_camera);

	auto&& c_player = (new CPlayer(Vector3_Zero));
	_objectroot.AddList((ChildObjRef)c_player);
	
}

C_MAIN::~C_MAIN()
{

};

void C_MAIN::Update() {
	_objectroot.Update();

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

