#pragma once
#include "../../ESGLib.h"
#include "../C_OBJECT/Object.h"

enum OBJECT_TYPE
{
	OBJECT_WALL,
	OBJECT_L,
	OBJECT_R,
	OBJECT_BROCK,
	OBJECT_ITEM,
	OBJECT_GATE,
	OBJECT__ZATE,
	OBJECT_TYPE_MAX,
};

class CharactorManager
{
public:

	CharactorManager();
   ~CharactorManager() { };

    void CharactorTagPreference(char _tag, ...);

	void CharactorManager::PosObjectPreference(char _map_tag, Vector3 _position);

	void CharactorManager::PosObjectPreference2(char _map_tag, Vector3 _position);

	std::vector<std::vector<Vector3>> GetCharacterPosition() const { return this->charactor_position_manager; };
private:

	std::vector<char> charactor_tag_manager;
	std::vector<std::vector<Vector3>> charactor_position_manager;

protected:
};

class PlacementManager : public Object
{
public:

	PlacementManager() {};
   ~PlacementManager() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override { return; };

	std::vector<std::vector<Vector3>> GetCharacterPos() const { return character_mng->GetCharacterPosition(); };
private:

	std::vector<cstring>  mapdata;
	std::shared_ptr<CharactorManager>   character_mng;


	void MapdataTagsPos();

protected:
	
};