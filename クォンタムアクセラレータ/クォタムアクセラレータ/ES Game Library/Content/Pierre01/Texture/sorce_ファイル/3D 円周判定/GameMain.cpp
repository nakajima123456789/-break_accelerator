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
	
	SE = SoundDevice.CreateSoundFromFile(_T("se1.wav"));

	SimpleShape shape;
	shape.Type = Shape_Teapot;
	model_ = GraphicsDevice.CreateModelFromSimpleShape(shape);
	model_->SetPosition(0, 5, 0);
	model_->SetDirection(0.0f, 0.0f, 0.0f);

	Material mtrl;
	mtrl.Diffuse = Color(255.0f, 0.0f, 0.0f);
	model_->SetMaterial(mtrl);




	shape.Type = Shape_Torus;
	shape.InnerRadius = 1.0f;//ì‡â~
	shape.OuterRadius = 2.0f;//äOâ~
	shape.Rings = 20;//ífñ 
	shape.Sides = 10;
	model2_ = GraphicsDevice.CreateModelFromSimpleShape(shape);
	Material mtrl2;
	mtrl2.Diffuse = Color(255.0f, 255.0f, 0.0f);
	model2_->SetMaterial(mtrl2);


	shape.Type = Shape_Sphere;
	shape.Slices = 20;
	shape.Stacks = 20;

	Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3_Down;
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);

	HK = GraphicsDevice.CreateSpriteFromFile(_T("090.jpg"));

	UI = GraphicsDevice.CreateSpriteFromFile(_T("bad.png"));
	UI_position_ = Vector3(570.0f, 310.0f, SpriteBatch_TopMost);
	                                         //(-10000.0f)

	ground = GraphicsDevice.CreateModelFromFile(_T("MODEL/Ground/ground.x"));

	player_ = GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Mikoto/mikoto.x"));
	player_->SetScale(0.05f);
	player_->SetPosition(0, 0, 10);

	
	BoundingSphere bs;

	bs = player_->GetBoundingSphere();
	shape.Radius = bs.Radius * 0.5; //ìñÇΩÇËîªíËëÂÇ´Ç≥
	Ball1 = GraphicsDevice.CreateModelFromSimpleShape(shape);
	Material ball1;
	ball1.Diffuse = Color(255.0f,0.0f, 0.0f);
	Ball1->SetMaterial(ball1);

	bs = model_->GetBoundingSphere();
	shape.Radius = bs.Radius * 1;
	Ball2 = GraphicsDevice.CreateModelFromSimpleShape(shape);
	Material ball2;
	ball2.Diffuse = Color(255.0f, 255.0f, 255.0f);
	Ball2->SetMaterial(ball2);

                    //èÍèäÅ@Å@Å@Å@Å@Å@Å@//å¸Ç´
	//camera_->SetView(Vector3(0,100,-120), Vector3(45,0,0));
	camera_->SetLookAt(Vector3(0,25,-50),player_->GetPosition(), Vector3_Up);
	camera_->SetPerspectiveFieldOfView(45.0,16.0f/9.0f,1.0f,10000.0f);
	GraphicsDevice.SetCamera(camera_);

	count = 0;
	get = false;


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
	KeyboardState key_state = Keyboard->GetState();

	//model_->Rotation(0, 0, 0);
	//model_->Move(0.01, 0, 0);

	/*if (key_state.IsKeyDown(Keys_Left))
	{
		model_->Rotation(0, 0, -10);
	}
	if (key_state.IsKeyDown(Keys_Right))
	{
		model_->Rotation(0, 0, 10);
	}
	if (key_state.IsKeyDown(Keys_Up))
	{
		model_->Move(0, 0, 0.1);
	}
	if (key_state.IsKeyDown(Keys_Down))
	{
		model_->Move(0, 0, -0.1);
	}*/

	player_->SetTrackEnable(0, TRUE);
	player_->SetTrackEnable(5, FALSE);

	count++;

	if (count >= 180)
	{
		/*player_->SetTrackEnable(2, FALSE);*/
	}

	if (count >= 180)
	{
		count = 0;
	}

	if (key_state.IsKeyDown(Keys_Up))
	{
		player_->Move(0.0f, 0.0f, 0.5f);
		player_->SetTrackEnable(5, TRUE);
		player_->SetTrackEnable(0, FALSE);
	}

	if (key_state.IsKeyDown(Keys_Down))
	{
		player_->Move(0.0f, 0.0f, -0.5f);
		player_->SetTrackEnable(5, TRUE);
		player_->SetTrackEnable(0, FALSE);
	}

	if (key_state.IsKeyDown(Keys_Up) & key_state.IsKeyDown(Keys_Down))
	{
		/*player_->SetTrackEnable(5, FALSE);
		player_->SetTrackEnable(0, TRUE);*/
	}
	
	if (key_state.IsKeyDown(Keys_Left))
	{
		player_->Rotation(0.0f, -2.0f, 0.0f);
	}

	if (key_state.IsKeyDown(Keys_Right))
	{
		player_->Rotation(0.0f, 2.0f, 0.0f);
	}

	BoundingSphere bs1 = player_->GetBoundingSphere();
	BoundingSphere bs2 = model_->GetBoundingSphere();
	
	

	bs1.Center = player_->GetPosition();
	bs1.Center += player_->GetUpVector() * bs1.Radius;
	bs2.Center = model_->GetPosition();

	Ball1->SetPosition(bs1.Center);
	Ball2->SetPosition(bs2.Center);

	float bs_dist = Vector3_Distance(bs1.Center,bs2.Center);
	float bs_radius = bs1.Radius + bs2.Radius;

	if (bs_dist < bs_radius)
	{
		get = true;
		SE->Play();
	}

	float distance;
	Vector3 pos = player_->GetPosition();

	ground->IntersectRay(Vector3(pos.x, 100.0f, pos.z), Vector3_Down, &distance);
	player_->SetPosition(pos.x,100.0f - distance,pos.z);
	//-player_->GetFrontVector()îwíÜ
	camera_->SetLookAt(pos + -player_->GetFrontVector() * 50 + Vector3(0,20,0),pos + Vector3(0, 5, 0) , Vector3_Up);

	GraphicsDevice.SetCamera(camera_);
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
	if (get == false)
	{
		model_->Draw();
	}
	
	model2_->Draw();

	/*Ball1->DrawAlpha(0.5f);
	Ball2->DrawAlpha(0.5f);*/
	
	player_->AdvanceTime(1.0 / 60.0);
	player_->Rotation(0.0,180,0.0);
	player_->Draw();
	player_->Rotation(0.0,180,0.0);

	float camera_ground_dist = FLT_MAX;

	ground->IntersectRay(camera_->GetPosition(), camera_->GetFrontVector(), &camera_ground_dist);

	float camera_player_dist = Vector3_Distance(camera_->GetPosition(),player_->GetPosition());

	if (camera_ground_dist > camera_player_dist)
	{
		ground->Draw();
	}
	else {
		GraphicsDevice.BeginAlphaBlend();	
		ground->DrawAlpha(0.5f);

		GraphicsDevice.BeginAlphaBlend();
	}

	GraphicsDevice.BeginShadowRendering();

	Matrix mat = Matrix_CreateShadow(Light_Directional, Vector3(-1.0f, -1.0f, 1.0f),
		player_->GetPosition(), Vector3(0.0f, 0.1f, 0.0f), Vector3_Up);

	player_->DrawShadow(mat, 0.75f);

	GraphicsDevice.EndShadowRendering();

	GraphicsDevice.BeginAlphaBlend();
	/*if (get == false)
	{
		Ball2->DrawAlpha(0.5f);
	}

	Ball1->DrawAlpha(0.5f);*/
	GraphicsDevice.BeginAlphaBlend();



	SpriteBatch.Begin();

	//SpriteBatch.Draw(*HK,Vector3(0.0f,0.0f,SpriteBatch_BottomMost));
	                                       //Å™àÍî‘âú(10000.0f) Å@Å{âúÅ@Å|éËëO
	//SpriteBatch.Draw(*UI, UI_position_);

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}

