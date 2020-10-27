#include "ObjectPlacement.h"

CharactorManager::CharactorManager()
{
	CharactorTagPreference(OBJECT_TYPE_MAX , 'o','L','R','b','i');
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
		if (_map_tag == charactor_tag_manager[i])
		{
			charactor_position_manager[i].push_back(_position);
		}
	}
}

void PlacementManager::Init()
{
	character_mng.reset(new CharactorManager);

	FILE* fp = fopen("オブジェクト配置.txt", "r");
	// マップデータを読み込む
	char load_char[99999 + 1];

	while (fgets(load_char, sizeof load_char - 1, fp) != NULL)
	{
		mapdata.push_back(load_char);
	}

	// ファイルを閉じる
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
	const float sense = 0.17f;

	for (int z = 0; z < mapdata.size(); z++) 
	{
		for (int x = 0; x < mapdata[z].size(); x++)
		{
			Vector3 position = Vector3((1 * sense) * x, (0 * sense), ((1 * sense) * z));

			character_mng->PosObjectPreference(mapdata[z][x], position + Vector3(-0.85f,0.13f,20.0f));
		}
	}
}
