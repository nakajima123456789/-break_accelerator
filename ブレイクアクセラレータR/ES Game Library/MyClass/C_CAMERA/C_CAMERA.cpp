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

	camera->SetPerspectiveFieldOfView(50.0, 16.0f / 9.0f, 0.1f, 10000.0f);

	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

void CCamera_::Update()
{
	field_of_view_pov = clamp(Input.GetPadInput(5) ? ++field_of_view_pov : --field_of_view_pov, 50, 100);

	camera->SetFieldOfViewY(field_of_view_pov);

	camera->SetLookAt(monostate.player_pos + Vector3(0.0f,0.3f, -0.8f), monostate.player_pos + Vector3(0.0f,0.0f,6.0f), Vector3_Up);

	GraphicsDevice.SetCamera(camera);
}

void CCamera_::DrawEnd()
{
	EffekseerMgr.Draw(camera);
	GraphicsDevice.SetCamera(camera);
};

int CCamera_::clamp(int x, int low, int high)
{
	ASSERT(low <= high && "Å¬’l <= Å‘å’l");
	return min(max(x, low), high);
}


