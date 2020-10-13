#include "C_MAIN.h"
#include "../SCENEMANAGER/SceneManager.h"

#include "../../C_PLAYER/C_PLAYER.h"
#include "../../C_CAMERA/C_CAMERA.h"

#include "../../C_INPUT/C_INPUT.h"
#include "../../ObjectPlacement/ObjectPlacement.h"

#include "../../OBSTACLEFACTORY/ObstacleFactory.h"

#include "../../C_MAP/C_MAP.h"

void C_MAIN::Initialize(){

	auto c_camera = (new CCamera_);
	_objectroot.AddList((ChildObjRef)c_camera);

	auto&& c_player = (new CPlayer(Vector3_Zero));
	_objectroot.AddList((ChildObjRef)c_player);
	
	auto&& c_objectplacement = (new PlacementManager);
	_objectroot.AddList((ChildObjRef)c_objectplacement);

	auto&& c_map = new C_MAP;
	_objectroot.AddList((ChildObjRef)c_map);



	ObstacleFactory* Obstacle_factory = new ObstacleStationeryFactory();

	for (int i = 0; i < c_objectplacement->GetCharacterPos()[OBJECT_WALL].size(); i++)
	{
		Vector3 pos = c_objectplacement->GetCharacterPos()[OBJECT_WALL][i];
		Object* Obstacle_book = Obstacle_factory->Create("•ÇáŠQ•¨", c_objectplacement->GetCharacterPos()[OBJECT_WALL][i]);
		_objectroot.AddList((ChildObjRef)Obstacle_book);
	}

	delete Obstacle_factory;
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

