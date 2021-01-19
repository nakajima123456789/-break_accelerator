#include "GameCamera.h"

void GameCamera::Init()
{
	Effekseer.Attach(GraphicsDevice);

	Color color = (0.5f, 0.5f, 0.5f);

	light.Type      = Light_Directional;
	light.Direction = Vector3_Down + Vector3_Forward;
	light.Diffuse   = color;
	light.Ambient   = color;
	light.Specular  = color;
	light.Position  = Vector3(0, 10, 0);

	camera->SetPerspectiveFieldOfView(40.f, 16.0f / 9.0f, 0.1f, 100.0f);

	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

void GameCamera::Update()
{
	camera->SetLookAt(gameObject->transform.position + Vector3(0.0f,0.5f, - 0.90f),gameObject->transform.position + Vector3(0.0f, -0.56f, 4.5f), Vector3_Up);

	Effekseer.Update();

	GraphicsDevice.SetCamera(camera);
}

void GameCamera::DrawEnd()
{
	GraphicsDevice.SetCamera(camera);

	Effekseer.SetCamera(camera);
	Effekseer.Draw();
};


