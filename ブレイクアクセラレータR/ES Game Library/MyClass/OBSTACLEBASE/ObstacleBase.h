#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include "../C_HITBOX/HitBox.h"
#include "../CPLAYERDATA/CPlayerData.h"
#include "..//OBSEVER/OBSEVER.h"
#include "../MapPlacementData/MapPlacementData.h"
#include "../UIDATABASE/UiDataBase.h"

class ObstacleBase : public Object
{
public:
	ObstacleBase();
	virtual ~ObstacleBase() {};

	virtual void Init()        override = 0;
	virtual void Update()      override = 0;
	virtual void Draw3D()      override = 0;

	virtual void DrawAlpha3D() override {};
	virtual void Draw2D()      override {};

private:

protected:

	//関数宣言
	void   IsHitObjectsInit(std::string _tags,float scale);
	void   IsHitObjectsDraw(Vector3 _pos);

	bool   RemoveModelDistance(double _distance);
	bool   DistanceTrigger(double _index);
	bool   CollsionTrigger();

	float  PlayerDistance(); 

	Material SetMaterial(Color color);

	//変数宣言
	std::unique_ptr <HitBox> _hitbox;

	OBSERVER observer;
	MODEL                obstacle_model;

	//プレイヤーのデータベース
	std::unique_ptr<IPlayerData>  _iplayer_data;
	std::unique_ptr<IMapData>     _imap_data;
	std::unique_ptr<UiData>       _i_ui_data;

	std::vector<Vector3> obstacle_position;
};

