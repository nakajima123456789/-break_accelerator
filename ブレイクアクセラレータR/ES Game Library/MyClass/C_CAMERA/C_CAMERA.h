#pragma once
#include "../../ESGLib.h"
#include "../C_OBJECT/Object.h"
#include "../CPLAYERDATA/CPlayerData.h"

class CCamera_ : public Object
{
public:
	CCamera_() {};
	virtual ~CCamera_() {};
	
	virtual void CCamera_::Init()        override;
	virtual void CCamera_::Update()      override;
	virtual void CCamera_::Draw3D()      override { return; };

	virtual void CCamera_::DrawAlpha3D() override { return; };
	virtual void CCamera_::Draw2D()      override { return; };

	virtual void CCamera_::DrawEnd()     override;

	CAMERA GetCamera() const { return camera; };
	Light  GetLight()  const { return light; };

private:
	CAMERA  camera;
	Light   light;

	//プレイヤーのデータベース
	std::unique_ptr<IPlayerData>   _iplayer_data;
};

