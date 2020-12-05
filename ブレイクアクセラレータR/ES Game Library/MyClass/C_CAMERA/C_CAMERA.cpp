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

	camera->SetPerspectiveFieldOfView(50.0, 16.0f / 9.0f, 0.1f, 100.0f);

	_iplayer_data.reset(new IPlayerData);

	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

void CCamera_::Update()
{
	
	Vector3 player_pos = _iplayer_data->GetPlayerPosition("player");

	camera->SetLookAt(player_pos + Vector3(0.0f,0.5f, - 0.65f),player_pos + Vector3(0.0f, -0.56f, 4.0f), Vector3_Up);

	EffekseerMgr.Update();
	GraphicsDevice.SetCamera(camera);

}

void CCamera_::DrawEnd()
{
	GraphicsDevice.SetCamera(camera);
	EffekseerMgr.Draw(camera);
};


