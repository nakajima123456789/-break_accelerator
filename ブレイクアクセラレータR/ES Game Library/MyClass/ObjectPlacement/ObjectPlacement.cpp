#include "ObjectPlacement.h"
#include"../C_UI/CUI.h"

CharactorManager::CharactorManager()
{
	CharactorTagPreference(OBJECT_TYPE_MAX , 'O','L','R','B','I','G','Z');
};

void CharactorManager::CharactorTagPreference(char _tag, ...) {
	va_list arguments;
	va_start(arguments, _tag);

	for (char x = 0; x < _tag; x++)
	{
		charactor_tag_manager.push_back(va_arg(arguments, char));
	}
	charactor_position_manager.resize(charactor_tag_manager.size());
}

void CharactorManager::PosObjectPreference(char _map_tag, Vector3 _position)
{
	for (int i = 0; i < charactor_tag_manager.size(); i++)
	{
		char tag = charactor_tag_manager[i];
		if (_map_tag == tag)
		{
			if (tag == 'G')
				charactor_position_manager[i].push_back(Vector3(-3.0f, -0.3f, _position.z));
			else if (tag == 'Z')
				charactor_position_manager[i].push_back(Vector3(3.0f, -0.3f, _position.z));
			else
				charactor_position_manager[i].push_back(_position);
		}
	}
}





void PlacementManager::Init()
{
	character_mng.reset(new CharactorManager);

	FILE* fp = fopen("オブジェクト配置.csv", "r");

	char load_char[99999 + 1];
	gate_x = 0.0f;
	gate2_x = 0.0f;
	
	while (fgets(load_char, sizeof load_char - 1, fp) != NULL)
	{
		std::string a = load_char;
		std::string b = ",";

		std::string c = b + a;

		mapdata.push_back(c);
	}


	for (int y = 0; y < mapdata.size(); y++)
	{

		for (int x = 0; x < mapdata[y].size(); x++)
		{

			if (mapdata[y][x] == ',' && mapdata[y][x + 1] == ',')
			{ 
				mapdata[y][x] = ' ';
			}

			if (mapdata[y][x] == ',') 
			{ 
				mapdata[y].erase(mapdata[y].begin() + x); 
			}
		}


		if (mapdata[y][mapdata[y].size()] == ','){ mapdata[y][mapdata[y].size()] = ' '; }
	}
	fclose(fp);

	MapdataTagsPos();
}



void PlacementManager::Update()
{

}

void PlacementManager::Draw3D()
{

}

void PlacementManager::MapdataTagsPos()
{
	const float   sense    = 0.38f;
	const Vector3 lear_pos = Vector3(-1.33f, -0.25f, 50.0f);

	for (int z = 0; z < mapdata.size(); z++)
	{
		for (int x = 0; x < mapdata[z].size(); x++)
		{
			Vector3 position = Vector3((1 * sense) * x, (0 * sense), ((1 * sense) * z));

			character_mng->PosObjectPreference(mapdata[z][x], position + lear_pos);
		}
	}
}
