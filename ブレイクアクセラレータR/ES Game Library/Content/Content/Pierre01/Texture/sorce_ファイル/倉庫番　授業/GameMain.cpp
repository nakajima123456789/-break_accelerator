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
	
	player_sprite_ = GraphicsDevice.CreateSpriteFromFile(_T("player.png"));

	wall_sprite_ = GraphicsDevice.CreateSpriteFromFile(_T("wall.png"));

	field_sprite_ = GraphicsDevice.CreateSpriteFromFile(_T("yuka.png"));

	item = GraphicsDevice.CreateSpriteFromFile(_T("item.png"));
	item_2 = GraphicsDevice.CreateSpriteFromFile(_T("item.png"));


	goal = GraphicsDevice.CreateSpriteFromFile(_T("goal.png"));

	
	FILE* file = fopen("soukoban.txt", "r");

	for (int c = 0; c < 10; c++)
	{
		if (fgets(buf, 40, file) == NULL)
			break;
		map_data_[c] = buf;
	}

	fclose(file);
	


	/*for (int c = 0; c < 10; c++)
	{
		fgets(buf_2, 40, file_2);
		map_data_[c] = buf_2;
	}

	fclose(file);*/
	

	/*map_data_[0] = _T("##########");
	map_data_[1] = _T("#p#  #   #");
	map_data_[2] = _T("#   #  # #");
	map_data_[3] = _T("#  G o   #");
	map_data_[4] = _T("# o   #  #");
	map_data_[5] = _T("#   #    #");
	map_data_[6] = _T("#   #  # #");
	map_data_[7] = _T("#      # #");
	map_data_[8] = _T("# G #  # #");
	map_data_[9] = _T("##########");*/

	for (int y = 0; y < 10; y++)
	{
		map_work_[y] = map_data_[y];
	}

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < map_data_[y].size(); x++)
		{

			if (map_data_[y][x] == 'p')
			{

				player_position_ = Vector3(x * 32.0f, y * 32.0f, 0.0f);

			}
		}
	}

	//loop();

	return true;
}

void GameMain::loop()
{
	/*for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{

			if (map_data_[y][x] == 'p')
			{
				player_position_ = Vector3(x * 32.0f, y * 32.0f, 0.0f);
				return;
			}
		}
	}*/


}


//return ‘O–ß‚é

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

	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	if (key_buffer.IsPressed(Keys_Space))
	{
		FILE* file_2 = fopen("soukoban_2.txt", "r");

		for (int c = 0; c < 10; c++)
		{

			if (fgets(buf_2, 40, file_2) == NULL)
				break;
			map_data_[c] = buf_2;
		}

		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < map_data_[y].size(); x++)
			{

				if (map_data_[y][x] == 'p')
				{

					player_position_ = Vector3(x * 32.0f, y * 32.0f, 0.0f);

				}

			}
		}

		fclose(file_2);

	}

	int mx = (int)(player_position_.x / 32);
	int my = (int)(player_position_.y / 32);

	if (key_buffer.IsPressed(Keys_Left))
	{
		if (map_data_[my][mx - 1] != '#' && map_work_[my][mx - 1] != 'o')
		{

			player_position_.x -= 32.0f;

		}
		else if (map_work_[my][mx - 1] == 'o' && map_work_[my][mx -2] != '#')
		{

			map_work_[my][mx -1] = ' ';
			map_work_[my][mx -2] = 'o';
			player_position_.x -= 32.0f;

		}

	}


	if (key_buffer.IsPressed(Keys_Up))
	{

		if (map_data_[my - 1][mx] != '#'&& map_work_[my -1][mx] != 'o')
		{

			player_position_.y -= 32.0f;

		}
		else if (map_work_[my -1][mx] == 'o' && map_work_[my -2][mx] != '#')
		{

			map_work_[my -1][mx] = ' ';
			map_work_[my -2][mx] = 'o';
			player_position_.y -= 32.0f;
		}
		
		
	}

	if (key_buffer.IsPressed(Keys_Right))
	{
		if (map_data_[my][mx + 1] != '#' && map_work_[my][mx + 1] != 'o')
		{
			player_position_.x += 32.0f;
		}
		else if (map_work_[my][mx +1] == 'o' && map_work_[my][mx +2] != '#')
		{

			map_work_[my][mx +1] = ' ';
			map_work_[my][mx +2] = 'o';
			player_position_.x += 32.0f;
		}

	}

	if (key_buffer.IsPressed(Keys_Down))
	{

		if (map_data_[my +1][mx] != '#'&& map_work_[my +1][mx] != 'o')
		{

			player_position_.y += 32.0f;

		}
		else if (map_work_[my +1][mx] == 'o' && map_work_[my +2][mx] != '#')
		{

			map_work_[my +1][mx] = ' ';
			map_work_[my +2][mx] = 'o';
			player_position_.y += 32.0f;
		}
		
	}

	
	color = false;
	
	return 0;
}


/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	if (color == true)
	{
		GraphicsDevice.Clear(Color_Red);
	}

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();
	SpriteBatch.Draw(*player_sprite_,player_position_);

	/*for (int x = 0; x < 10.0f; x++) 
	{
		SpriteBatch.Draw(*wall_sprite_, Vector3(x * 32 ,0.0f, 0.1f));
	
		SpriteBatch.Draw(*wall_sprite_, Vector3(x * 32, 320.0f, 0.1f));
	
		SpriteBatch.Draw(*wall_sprite_, Vector3(0.0f, x * 32, 0.1f));
	
		SpriteBatch.Draw(*wall_sprite_, Vector3(320.0f, x * 32, 0.1f));
	}*/

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < map_data_[y].size(); x++)
		{

			if (map_data_[y][x] == '#')
			{
				SpriteBatch.Draw(*wall_sprite_, Vector3(x * 32.0f, y * 32.0f, 0.1f));
			}
			else 
			{
				SpriteBatch.Draw(*field_sprite_, Vector3(x * 32.0f, y * 32.0f, 0.1f));
			}

			if (map_data_[y][x] == 'G')
			{
				SpriteBatch.Draw(*goal, Vector3(x * 32.0f, y * 32.0f, 0.1f));
			}			
			
			if (map_data_[y][x] == 'o')
			{
				SpriteBatch.Draw(*item, Vector3(x * 32.0f, y * 32.0f, 0.1f));
			}
		}

	}


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
