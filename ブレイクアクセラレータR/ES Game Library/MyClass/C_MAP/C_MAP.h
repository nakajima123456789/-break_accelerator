#pragma once
#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include "../CPLAYERDATA/CPlayerData.h"

class MAPOBJECTS
{
public:
	MAPOBJECTS();
	~MAPOBJECTS() {};

	void Draw();

	void SetScenePosition(double num) { scene_position = num; };


private:

	enum 
	{
		_PILLAR,
		_BILL,
	};

	double scene_position = 0.0f;

	std::vector<MODEL> models;

	std::vector<MODEL> model_graund;

	//プレイヤーのデータベース
	std::unique_ptr<IPlayerData>   _iplayer_data;
};

class C_MAP : public Object
{
public:

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override;
	virtual void Draw2D()      override;

private:

	MAPOBJECTS mapobject[3];

protected:

};