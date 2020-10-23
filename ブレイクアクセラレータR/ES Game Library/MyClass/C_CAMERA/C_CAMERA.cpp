#include "C_CAMERA.h"
#include "../C_Effekseer/CEffekseer_.h"
#include "../C_INPUT/C_INPUT.h"


void CCamera_::Init()
{
	Color color = (0.5f, 0.5f, 0.5f);

	light.Type      = Light_Directional;
	light.Direction = Vector3_Down + Vector3_Forward;
	light.Diffuse   = color;
	light.Ambient   = color;
	light.Specular  = color;
	light.Position  = Vector3(0, 10, 0);


	camera->SetLookAt(Vector3(0,1, -5),Vector3(0,0,0), Vector3_Up);
	camera->SetPerspectiveFieldOfView(45.0, 16.0f / 9.0f, 1.0f, 10000.0f);

	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

void CCamera_::Update()
{

	Vector3 player_pos = monostate.player_pos;

	camera->SetLookAt(player_pos + Vector3(0,1, -2), player_pos + Vector3(0,0,2), Vector3_Up);
	GraphicsDevice.SetCamera(camera);
}

void CCamera_::DrawEnd()
{
	EffekseerMgr.Draw(camera);
	GraphicsDevice.SetCamera(camera);
};



