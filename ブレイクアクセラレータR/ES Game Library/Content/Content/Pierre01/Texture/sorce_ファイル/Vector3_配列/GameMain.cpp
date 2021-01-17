// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate throug h any components and initialize them as well.
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

	SimpleShape shape;
	shape.Type = Shape_Teapot;
	model = GraphicsDevice.CreateModelFromSimpleShape(shape);
	model->SetDirection(0.0f, 0.0f, 0.0f);

	Material mtrl;
	mtrl.Diffuse = Color(255.0f, 0.0f, 0.0f);
	model->SetMaterial(mtrl);

	camera->SetView(Vector3(0, 0, -10), Vector3(0, 0, 0));
	camera->SetPerspectiveFieldOfView(45.0, 16.0f / 9.0f, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera);
	
	
	ZeroMemory(&world, sizeof(world));
	//x
	world._11 = MathHelper_Cos(30);
	world._12 = -MathHelper_Sin(30);
	world._13 = 0;
	//y
	world._21 = MathHelper_Cos(30);
	world._22 = 1;
	world._23 = 0;
	//z
	world._31 = 0;
	world._32 = 0;
	world._33 = 1;

	world._44 = 1;

	GraphicsDevice.SetTransform(D3DTS_WORLD,world);

	a = 0.0f;

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
	a += 2.0f;
	//x
	world._11 = MathHelper_Cos(a);
	world._12 = -MathHelper_Sin(a);
	
	//y
	world._21 = MathHelper_Cos(a);
	world._22 = 0;
	
	GraphicsDevice.SetTransform(D3DTS_WORLD, world);


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

	Material mtrl(model);
	GraphicsDevice.SetMaterial(mtrl);
	model->DrawPure();

	SpriteBatch.Begin();


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
