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

	GraphicsDevice.SetRenderState(NormalizeNormals_Enable);
	GraphicsDevice.SetRenderState(Specular_Enable);

	/*camera_->SetView(Vector3(0,50,-50), Vector3(45,0,0));
	camera_->SetPerspectiveFieldOfView(45.0, 16.0f / 9.0f, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera_);
*/
	SimpleShape shape;
	shape.Type = Shape_Box;
	shape.Width = 5;
	shape.Height = 5;
	shape.Depth = 5;

	box = GraphicsDevice.CreateModelFromSimpleShape(shape);
//	box->SetDirection(0.0f, 0.0f, 0.0f);//Œü‚«
	Material mtrl;
	mtrl.Diffuse = Color(0.0f, 1.0f, 0.0f);
	box->SetMaterial(mtrl);

	SimpleShape shape_enemy;
	shape_enemy.Type = Shape_Box;
	shape_enemy.Width = 5;
	shape_enemy.Height = 5;
	shape_enemy.Depth = 5;

	enemy_box = GraphicsDevice.CreateModelFromSimpleShape(shape_enemy);
	enemy_box->SetDirection(0.0f, 0.0f, 0.0f);//Œü‚«
	Material mtrl_;
	mtrl_.Diffuse = Color(255.0f, 1.0f, 0.0f);
	enemy_box->SetMaterial(mtrl_);

	Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3_Down + Vector3_Forward;
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);

	New_Town = GraphicsDevice.CreateModelFromFile(_T("MODEL/Ground/ground.x"));

	player_ = GraphicsDevice.CreateAnimationModelFromFile(_T("animeshon/all.X"));
	player_->SetTrackEnable(0, FALSE);
	player_->SetTrackEnable(1, FALSE);
	player_->SetTrackEnable(2, FALSE);
	player_->SetTrackEnable(3, FALSE);
	player_->SetTrackEnable(4, FALSE);
	player_->SetTrackEnable(5, FALSE);
	player_->SetTrackEnable(6, FALSE);
	player_->SetTrackEnable(7, FALSE);

	player_->SetScale(0.4f);
	player_->SetPosition(0.0f,0.0f, 0.0f);
//player_->SetTrackLoopMode(RUN,       AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(IDOL,      AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(SLIDING,   AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(ROWLING,   AnimationLoopMode_Once);
//player_->SetTrackLoopMode(JUMP,      AnimationLoopMode_Once);
//player_->SetTrackLoopMode(BACKTEN,   AnimationLoopMode_Once);
//player_->SetTrackLoopMode(STEP,      AnimationLoopMode_Once);
//player_->SetTrackLoopMode(KIRIBARAI, AnimationLoopMode_Once);

//player_->SetTrackLoopMode(RUN,       AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(IDOL,      AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(SLIDING,   AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(ROWLING,   AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(JUMP,      AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(BACKTEN,   AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(STEP,      AnimationLoopMode_Loop);
//player_->SetTrackLoopMode(KIRIBARAI, AnimationLoopMode_Loop);


	SetPlayerState(IDOL);

	int anime_state = 0;

	enemy = GraphicsDevice.CreateAnimationModelFromFile(_T("animeshon/all.X"));
	enemy->SetScale(0.4f);
	enemy->SetPosition(0.0f, 0.0f, 50.0f);
	enemy->SetTrackEnable(0, FALSE);
	enemy->SetTrackEnable(1, FALSE);
	enemy->SetTrackEnable(2, FALSE);
	enemy->SetTrackEnable(3, FALSE);
	enemy->SetTrackEnable(4, TRUE);
	enemy->SetTrackEnable(5, FALSE);
	enemy->SetTrackEnable(6, FALSE);
	enemy->SetTrackEnable(7, FALSE);

	Material material;
	material.Diffuse = Color(0.925490f,0.305882f, 0.305882f);

  /*  Material mtrl;
	mtrl.Diffuse = Color(255.0f, 255.0f, 255.0f);
	player_->SetMaterial(mtrl);*/

	jump_count = 0;
	sliding_count = 0;
	rowling_count = 0;
	run_count = 0;
	kiribarai_count = 0;
	step_count = 0;
	backten_count = 0;

	//jump_state = 0;
	//sliding_state = 0;
	//rowling_state = 0;

	/*player_->SetTrackEnable(0, FALSE);
	player_->SetTrackEnable(1, FALSE);
	player_->SetTrackEnable(2, FALSE);
	player_->SetTrackEnable(3, FALSE);
	player_->SetTrackEnable(4, FALSE);*/

	//string letter_ = "Arial";

	//letter = GraphicsDevice.CreateSpriteFont(("letter")) + 100;

	anime_state = 0;

	camera->SetLookAt(Vector3(0, 25, -50), /*player_->GetPosition()*/Vector3(0, 0, 0), Vector3_Up);
	camera->SetPerspectiveFieldOfView(45.0, 16.0f / 9.0f, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera);

	Effekseer.Attach(GraphicsDevice);
	effect_ = Effekseer.CreateEffectFromFile(_T("animation//‘O.efk"));

	Box = false;
	Drw = false;

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
/// Scene continued value
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here

	KeyboardBuffer key_buf = Keyboard->GetBuffer();
	KeyboardState key_state = Keyboard->GetState();

	

	Vector3 Animation_pos = player_->GetPosition();

	if (key_buf.IsPressed(Keys_Left))
	{
		player_->Rotation(0.0f, 180.0f, 0.0f);
		
	}
	else if (key_buf.IsPressed(Keys_Right))
	{
		player_->Rotation(0.0f, -180.0f, 0.0f);
	
	}
	else if (key_state.IsKeyDown(Keys_Down))
	{
		player_->Move(0.0f, 0.0f, -0.5f);
		
	}

	if (player_state_ == JUMP)
	{

		if (key_buf.IsPressed(Keys_Left))
		{

			player_->Move(0.0f, -1.0f, 0.0f);

		}
		else if (key_buf.IsPressed(Keys_Right))
		{

			player_->Move(0.0f, 1.0f, -0.5f);

		}

	}

	if (player_state_ == RUN)
	{
		player_->Move(0.0, 0.0, 0.5f);
	}
	else if (player_state_ == JUMP)
	{
		jump_count++;
		player_->Move(0.0, 0.0, 0.2f);
		if (jump_count >= 130) {
			if(key_state.IsKeyDown(Keys_Up))
				SetPlayerState(RUN);
			else
				SetPlayerState(IDOL);
		}
	}
	else if (player_state_ == ROWLING)
	{
		rowling_count++;
		player_->Move(0.0, 0.0, 0.5f);
		if (rowling_count >= 90) {
			if (key_state.IsKeyDown(Keys_Up))
				SetPlayerState(RUN);
			else
				SetPlayerState(IDOL);
		}
	}
	else if (player_state_ == SLIDING)
	{
		sliding_count++;
		player_->Move(0.0, 0.0, 0.5f);
		if (sliding_count >= 50) {
			if (key_state.IsKeyDown(Keys_Up))
				SetPlayerState(RUN);
			else
				SetPlayerState(IDOL);
		}
	}
	else if (player_state_ == STEP)
	{
		player_->Move(0.0, 0.0, 0.2f);
		step_count++;
		if (step_count >= 35) {
			SetPlayerState(IDOL);
		}
	}
	else if (player_state_ == BACKTEN)
	{
		backten_count++;
		if (backten_count >= 50) {
			SetPlayerState(IDOL);
		}
	}
	else if (player_state_ == KIRIBARAI)
	{
		kiribarai_count++;
		if (kiribarai_count >= 30) {
			Box = false;
			SetPlayerState(IDOL);
		}
	}

	if (player_state_ == RUN || player_state_ == IDOL) {
		if (key_buf.IsPressed(Keys_Up))
		{
			SetPlayerState(RUN);
		}
		if (key_buf.IsReleased(Keys_Up))
		{
			SetPlayerState(IDOL);
		}
		if (key_buf.IsPressed(Keys_Q))
		{
			SetPlayerState(JUMP);
			jump_count = 0;
		}
		if (key_buf.IsPressed(Keys_W))
		{
			SetPlayerState(ROWLING);
			rowling_count = 0;
		}
		if (key_buf.IsPressed(Keys_E))
		{
			SetPlayerState(SLIDING);
			sliding_count = 0;
		}
		if (key_buf.IsPressed(Keys_R))
		{
			SetPlayerState(STEP);
			step_count = 0;
		}
		if (key_buf.IsPressed(Keys_T))
		{
			SetPlayerState(BACKTEN);
			backten_count = 0;
		}
		if (key_buf.IsPressed(Keys_Y))
		{
			Box = true;
			SetPlayerState(KIRIBARAI);
			effect_->Play(player_->GetPosition() + player_->GetFrontVector() * 2.0f + Vector3(0.0f, 10.0f, 0.0f));
			kiribarai_count = 0;
			
			box->SetPosition(player_->GetPosition() + player_->GetFrontVector() * 2.0f + Vector3(0.0f, 10.0f, 0.0f));
			box->SetDirection(player_->GetDirectionQuaternion());

			//OrientedBoundingBox  obb1 = box->GetOBB();
			//OrientedBoundingBox  obb2 = enemy_box->GetOBB();

			//if (obb1.Intersects(obb2))
			//{
			//	Drw = true;
			//}
			//else {
			//	Drw = false;
			//}

		}
	}

	Vector3 pos = player_->GetPosition();
	Vector3 enemy_pos = enemy->GetPosition();

	//if (Box == true)
	//{
	//	box->SetPosition(pos.x, pos.y + 5.0f, pos.z + 5.0f);
	//}

	enemy_pos += Vector3_Normalize(pos - enemy_pos) * 0.1f;
	enemy->SetPosition(enemy_pos);

	enemy_box->SetPosition(enemy_pos.x, enemy_pos.y + 10.0f, enemy_pos.z);

	float distance;
	
	New_Town->IntersectRay(Vector3(pos.x, 100.0f, pos.z), Vector3_Down, &distance);
	player_->SetPosition(pos.x, 100.0f - distance, pos.z);

	camera->SetLookAt(pos + -player_->GetFrontVector() * 50 + Vector3(0, 30, 0), pos + Vector3(0, 7, 0), Vector3_Up);
	GraphicsDevice.SetCamera(camera);

	Effekseer.Update();

	Drw = false;
	if (Box) {
		OrientedBoundingBox  obb1 = box->GetOBB();
		OrientedBoundingBox  obb2 = enemy_box->GetOBB();

		if (obb1.Intersects(obb2))
		{
			Drw = true;
		}
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here

	if (Drw == true)
	{
		GraphicsDevice.Clear(Color_Red);
	}
	else if(Drw == false)
	{
		GraphicsDevice.Clear(Color_CornflowerBlue);
	}

	GraphicsDevice.BeginScene();

	if (Box == true)
	{
		box->Draw();
	}

	enemy_box->Draw();
	enemy->Draw();

	player_->AdvanceTime(1.0 / 60.0);
	if (player_state_ == IDOL || player_state_ == RUN || player_state_ == JUMP
		|| player_state_ == ROWLING || player_state_ == SLIDING || player_state_ == STEP) {
		player_->Rotation(0, 180, 0);
		player_->Draw();
		player_->Rotation(0, 180, 0);
	}
	else {
		player_->Draw();
	}


//	New_Town->Draw();

	enemy->Rotation(0, 180, 0);

	enemy->Rotation(0, 180, 0);
	enemy->AdvanceTime(1.0 / 60.0);

	GraphicsDevice.BeginShadowRendering();

	Matrix mat = Matrix_CreateShadow(Light_Directional, Vector3(-1.0f, -1.0f, 1.0f),
							  player_->GetPosition(), Vector3(0.0f, 0.1f, 0.0f), Vector3_Up);

	player_->DrawShadow(mat, 0.75f);

	GraphicsDevice.EndShadowRendering();

//	SpriteBatch.Begin();

//	SpriteBatch.End();

	Effekseer.SetCamera(camera);
	Effekseer.Draw();


	GraphicsDevice.EndScene();
}

void GameMain::SetPlayerState(int new_state)
{

	player_->SetTrackEnable(player_state_, FALSE);
	player_->SetTrackEnable(new_state, TRUE);
	player_->SetTrackPosition(new_state, 0);
//	player_->ChangeAnimation(new_state, 0.5);
	player_state_ = new_state;

}