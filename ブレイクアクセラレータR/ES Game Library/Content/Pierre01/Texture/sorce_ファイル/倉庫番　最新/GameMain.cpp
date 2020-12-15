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


	player_sprite_ = GraphicsDevice.CreateSpriteFromFile(_T("6053568i.png"));
	player_position_ = Vector3(32.0f, 32.0f, 0.0f);

	
	wall_sprite_ = GraphicsDevice.CreateSpriteFromFile(_T("ñºèÃñ¢ê›íË 1.png"));

	move_position_ = Vector3_Zero;
	map_data.push_back(_T("########################################"));
	map_data.push_back(_T("#                                      #"));
	map_data.push_back(_T("#                                    # #"));
	map_data.push_back(_T("#                           #  # # #   #"));
	map_data.push_back(_T("#                                      #"));
	map_data.push_back(_T("#                #  #  # #  #          #"));
	map_data.push_back(_T("#                                      #"));
	map_data.push_back(_T("#     #   #   #                        #"));
	map_data.push_back(_T("#                                      #"));
	map_data.push_back(_T("# p                                    #"));
	map_data.push_back(_T("########################################"));
	map_data.push_back(_T("########################################"));

	for (int y = 0; y < map_data.size(); y++)
	{
		for (int x = 0; x < map_data[y].size(); x++)
		{
			if (map_data[y][x] == 'p') {
				player_position_ = Vector3(x * 32.0f, y * 32.0f, 0);
			}
		}
	}

	player_state = 0;
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
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	int PLAYER_X = (int)player_position_.x;
	int PLAYER_Y = (int)player_position_.y;

	int MAP_X = PLAYER_X / 32;
	int MAP_Y = PLAYER_Y / 32;

	if (key_state.IsKeyDown(Keys_Left))
	{
		if (PLAYER_Y % 32 == 0) {
			if (PLAYER_X % 32 == 0) {
				if (map_data[MAP_Y][MAP_X - 1] != '#')
					player_position_.x -= 2.0f;
			}
			else {
				if (map_data[MAP_Y][MAP_X] != '#')
					player_position_.x -= 2.0f;
				else {
					player_position_.x = MAP_X * 32.0f + 32.0f;
				}
			}
		}
		else {
			if (PLAYER_X % 32 == 0) {
				if (map_data[MAP_Y][MAP_X - 1] != '#' && map_data[MAP_Y + 1][MAP_X - 1] != '#')
					player_position_.x -= 2.0f;
			}
			else {
				if (map_data[MAP_Y][MAP_X] != '#' && map_data[MAP_Y + 1][MAP_X] != '#')
					player_position_.x -= 2.0f;
				else {
					player_position_.x = MAP_X * 32.0f + 32;
				}
			}
		}
	}

	if (key_state.IsKeyDown(Keys_Right))
	{
		if (PLAYER_Y % 32 == 0) {
			if (PLAYER_X % 32 == 0) {
				if (map_data[MAP_Y][MAP_X + 1] != '#')
					player_position_.x += 2.0f;
			}
			else {
				if (map_data[MAP_Y][MAP_X + 1] != '#')
					player_position_.x += 2.0f;
				else
					player_position_.x = MAP_X * 32.0f;
			}
		}
		else {
			if (PLAYER_X % 32 == 0) {
				if (map_data[MAP_Y][MAP_X + 1] != '#' && map_data[MAP_Y + 1][MAP_X + 1] != '#')
					player_position_.x += 2.0f;
			}
			else {
				if (map_data[MAP_Y][MAP_X + 1] != '#' && map_data[MAP_Y + 1][MAP_X + 1] != '#')
					player_position_.x += 2.0f;
				else {
					player_position_.x = MAP_X * 32.0f;
				}
			}
		}

	}

	if (player_state == 0) 
	{
		if (key_buffer.IsPressed(Keys_Space)) {
			junp_power = 15;
			player_state = 1;			
		}
	}
	else if (player_state == 1) 
	{
		player_position_.y = player_position_.y - junp_power;

		int PLAYER_X = (int)player_position_.x;
		int PLAYER_Y = (int)player_position_.y;

		int MAP_X = PLAYER_X / 32;
		int MAP_Y = PLAYER_Y / 32;
		if (junp_power > 0)
		{
			if (PLAYER_X % 32 == 0) {
				if (PLAYER_Y % 32 == 0) {
					if (map_data[MAP_Y - 1][MAP_X] != '#')
						player_position_.y -= 2.0f;
				}
				else {
					if (map_data[MAP_Y][MAP_X] != '#')
						player_position_.y -= 2.0f;
					else
						player_position_.y = MAP_Y * 32.0f+32;
				}
			}
			else {
				if (PLAYER_Y % 32 == 0) {
					if (map_data[MAP_Y - 1][MAP_X] != '#' && map_data[MAP_Y - 1][MAP_X + 1] != '#')
						player_position_.y -= 2.0f;
				}
				else {
					if (map_data[MAP_Y][MAP_X] != '#' && map_data[MAP_Y][MAP_X + 1] != '#')
						player_position_.y -= 2.0f;
					else {
						player_position_.y = MAP_Y * 32.0f + 32;
					}
				}
			}
		}
		else if (junp_power < 0)
		{
			if (PLAYER_X % 32 == 0) {
				if (PLAYER_Y % 32 == 0) {
					if (map_data[MAP_Y + 1][MAP_X] != '#')
						player_position_.y += 2.0f;
				}
				else {
					if (map_data[MAP_Y + 1][MAP_X] != '#')
						player_position_.y += 2.0f;					
					else {
						player_position_.y = MAP_Y * 32.0f;
						player_state = 0;
					}
				}
			}
			else {
				if (PLAYER_Y % 32 == 0) {
					if (map_data[MAP_Y + 1][MAP_X] != '#' && map_data[MAP_Y + 1][MAP_X + 1] != '#')
						player_position_.y += 2.0f;
				}
				else {
					if (map_data[MAP_Y + 1][MAP_X] != '#' && map_data[MAP_Y + 1][MAP_X + 1] != '#')
						player_position_.y += 2.0f;
					else {
						player_position_.y = MAP_Y * 32.0f;
						player_state = 0;
					}
				}
					
			}
		}
		
		junp_power = junp_power - 1.0;
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


	SpriteBatch.Begin();

	SpriteBatch.Draw(*player_sprite_, player_position_);

	for (int y = 0; y < map_data.size(); y++)
	{
		for (int x = 0; x < map_data[y].size(); x++)
		{
			if (map_data[y][x] == '#')
				SpriteBatch.Draw(*wall_sprite_, Vector3(x * 32.0f, y * 32.0f, 1));
		}
	}


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
