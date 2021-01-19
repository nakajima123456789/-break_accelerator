#pragma once
#include "../Object/Object.h"

#include "../HitBox/HitBox.h"
#include "../PlayerDataBase/PlayerDataBase.h"
#include "../CsvPositionDataBase/CsvPositionDataBase.h"

enum {DAMAGE,ITEM,GAMEOVER,RECOVERY};

class ObstacleBase : public Object
{
public:
	ObstacleBase();
	virtual ~ObstacleBase() {};

	virtual void Init()        override = 0;
	virtual void Update()      override = 0;
	virtual void Draw3D()      override = 0;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override { return; };

private:

protected:
	//ä÷êîêÈåæ
	HitBox* p_hitbox;

	const UINT DRAWOBSTACLERANGE   = 90;
	const int  REMOVEOBSTACLERANGE = -1;

	MODEL   model = nullptr;
	std::vector<Vector3> position;

	bool OnCollsion(float distance, Vector3 lerp_position);
	Material SetMaterial();


	UINT AttackType = 0;
};