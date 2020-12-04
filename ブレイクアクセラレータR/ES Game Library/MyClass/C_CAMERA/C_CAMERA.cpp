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

	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

void CCamera_::Update()
{
	//field_of_view_pov = clamp(Input.GetPadInput(5) ? field_of_view_pov += 0.5f : field_of_view_pov -= 0.5f, 50.0f, 500.0f);

	camera->SetFieldOfViewY(field_of_view_pov);

	camera->SetLookAt(monostate.player_pos + Vector3(0.0f,0.5f, - 0.65f), monostate.player_pos + Vector3(0.0f, -0.56f, 4.0f), Vector3_Up);
//	camera->SetLookAt(monostate.player_pos + Vector3(0.0f, 0.69f, -0.65f), monostate.player_pos + Vector3(0.0f, -0.56f,4.0f), Vector3_Up);

	EffekseerMgr.Update();
	GraphicsDevice.SetCamera(camera);

}

void CCamera_::DrawEnd()
{
	GraphicsDevice.SetCamera(camera);
	EffekseerMgr.Draw(camera);
};

double CCamera_::clamp(double x, double low, double high)
{
	ASSERT(low <= high && "Å¬’l <= Å‘å’l");
	return min(max(x, low), high);
}


