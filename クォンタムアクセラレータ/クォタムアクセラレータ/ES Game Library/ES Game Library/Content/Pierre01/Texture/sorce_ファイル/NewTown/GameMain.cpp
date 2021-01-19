// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3_Down;
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);
	number = GraphicsDevice.CreateSpriteFont(_T("MS ƒSƒVƒbƒN"), 100);
	New_Town = GraphicsDevice.CreateModelFromFile(_T("NewTown/Town/kero_town.x"));
	New_Town->SetScale(2);
	SkyDome = GraphicsDevice.CreateModelFromFile(_T("SkyDome/SkyDome.x"));
	SkyDome->SetScale(10.0);

	camera->SetView(Vector3(0, 1.0, 0), Vector3(0, 0, 0));
	camera->SetPerspectiveFieldOfView(45.0, 16.0f / 9.0f, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera);

	C = 0;
	N = Vector3_Zero;

	Effekseer.Attach(GraphicsDevice);
	effect_ = Effekseer.CreateEffectFromFile(_T("Effect//appp.efk"));
	effect_->Play(0.0f, -5.0f, 0.0f);


	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here

	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buf = Keyboard->GetBuffer();
    Vector3 pos = camera->GetPosition();
	Vector3 F = camera->GetFrontVector();
	dist = FLT_MAX;
	N = -F;
	New_Town->IntersectRay(pos, F, &dist, &N);
	C = Vector3_Dot(-F, N);

	if (key.IsKeyDown(Keys_Up))
	{
		/*float dist;
		New_Town->IntersectRay(pos + Vector3(0.0f, 1.0f, 0.0f), camera->GetFrontVector(), &dist);
		if (dist >= 4.0)
		{ 
			camera->Move(0.0f, 0.0f, 0.3f);
		}*/

		/*Vector3 F = camera->GetFrontVector();
		float dist;
*/
		New_Town->IntersectRay(pos, F, &dist, &N);
		C = Vector3_Dot(-F, N);
		if (dist >= 2.0)
		{ 

			camera->Move(0.0f, 0.0f, 0.3f);

		}
	
		
	}else if (key.IsKeyDown(Keys_Down))
	{
		{
			float backdist;
			New_Town->IntersectRay(pos + Vector3(0.0f, 1.0f, 0.0f), -camera->GetFrontVector(), &backdist);
//			if (backdist >= 3.0)
			{
				camera->Move(0.0f, 0.0f, -0.3f);
			}
		}

	}
	 if (key.IsKeyDown(Keys_W))
	{

		camera->Rotation(1.0f, 0.0f, 0.0f);

	}
	 if (key.IsKeyDown(Keys_S))
	{

		camera->Rotation(-1.0f, 0.0f, 0.0f);

	}
	 if (key.IsKeyDown(Keys_Left))
	{

		camera->Rotation(0.0f, -0.8f, 0.0f);

	}
	 if (key.IsKeyDown(Keys_Right))
	{

		camera->Rotation(0.0f, 0.8f, 0.0f);

	}	

	float distance = FLT_MAX;
	float dis = FLT_MAX;
	Vector3 position = camera->GetPosition();

	/*New_Town->IntersectRay(Vector3(position.x, -10.0, position.z), Vector3_Up, &distance);
	camera->SetPosition(position.x, -10.0 + distance + 2.0, position.z);

	New_Town->IntersectRay(Vector3(position.x, 3.0, position.z), Vector3_Down, &dis);
	camera->SetPosition(position.x, 3.0 - dis + 2.0, position.z);*/

	if (New_Town->IntersectRay(Vector3(position.x, position.y, position.z), Vector3_Up, &distance))
		distance += 1.0f;


	/*camera->SetPosition(position.x,distance + 2.0, position.z);*/

	if (New_Town->IntersectRay(Vector3(position.x, position.y, position.z), Vector3_Down, &dis)) {
		dis -= 1.0f;
//		if (dis < 0.0f)
//			dis = 0.0f;
	}
	/*camera->SetPosition(position.x,dis + 2.0, position.z);*/

	if (distance >= dis)
	{
		camera->Move(0.0f, -dis + 1.0, 0.0f);
//		camera->SetPosition(position.x, -1.7 + distance + 1.7, position.z);

	}
	else {
//		camera->SetPosition(position.x, 1.7 - dis + 1.7, position.z);
		camera->Move(0.0f, distance + 1.0, 0.0f);
	}

	GraphicsDevice.SetCamera(camera);

	Effekseer.Update();

	if (key_buf.IsPressed(Keys_Space))
	{
		effect_->Play(0.0f, -5.0f, 0.0f);
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	SkyDome->Draw();

	GraphicsDevice.BeginAlphaBlend();
	New_Town->DrawAlpha(1.0f);
	GraphicsDevice.EndAlphaBlend();

	SpriteBatch.Begin();

	GraphicsDevice.SetRenderState(DepthBufferFunction_Always);
	SpriteBatch.DrawString(number, Vector2(0.0f, 0.0f), Color(255, 255, 255), _T("C:%f"), C);
	SpriteBatch.DrawString(number, Vector2(0.0f, 100.0f), Color(255, 255, 255), _T("N:%f %f %f"), N.x, N.y, N.z);
	SpriteBatch.DrawString(number, Vector2(600.0f, 0.0f), Color(255, 255, 255), _T("C:%f"), dist);

	SpriteBatch.End();
	GraphicsDevice.SetRenderState(DepthBufferFunction_Default);

	Effekseer.Draw();
	Effekseer.SetCamera(camera);

	GraphicsDevice.EndScene();
}
