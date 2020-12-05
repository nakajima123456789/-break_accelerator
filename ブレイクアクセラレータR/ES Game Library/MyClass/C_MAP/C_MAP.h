#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include "../CPLAYERDATA/CPlayerData.h"

class C_MAP : public Object
{
public:

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override;
	virtual void Draw2D()      override;

private:

	enum MAP_MODEL
	{
		GROUND,
		LIGHT,
		LIGHT2,
		POLE,
		BUILD,
		MAP_MODEL_SIZE,
	};

	std::vector<MODEL> model;
	std::vector<std::vector<Vector3>> model_position;

	inline void CreateMapPrefarence();

	MEDIA bg;
	MUSIC bgm;

	int ground_model_scene[MAP_MODEL_SIZE];

	//プレイヤーのデータベース
	std::unique_ptr<IPlayerData>   _iplayer_data;
protected:

};