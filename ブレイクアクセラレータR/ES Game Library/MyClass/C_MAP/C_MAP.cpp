#include "C_MAP.h"

void C_MAP::Init()
{
	
	mapobject[0].SetScenePosition(0);
	mapobject[1].SetScenePosition((17 * 3));
};

void C_MAP:: Update()
{



};

void C_MAP::Draw3D()
{

	mapobject[0].Draw();
	mapobject[1].Draw();
};

void C_MAP::DrawAlpha3D()
{
	
	return;
};

void C_MAP::Draw2D() 
{
	
}

MAPOBJECTS::MAPOBJECTS()
{
	Color    color = Color(1.f, 1.f, 1.f);
	Material mtrl;

	mtrl.Diffuse  = color;
	mtrl.Ambient  = color;
	mtrl.Specular = color;
	mtrl.Emissive = color;
	mtrl.Power = 1.0f;

	models.push_back(GraphicsDevice.CreateModelFromFile(_T("‰ü’ù//kari.X")));
	models.push_back(GraphicsDevice.CreateModelFromFile(_T("building_set_WB4.fbm//WB4.X")));

	model_graund.push_back(GraphicsDevice.CreateModelFromFile(_T("‰ü’ù//road_8.X")));
	model_graund.push_back(GraphicsDevice.CreateModelFromFile(_T("‰ü’ù//road_8.X")));
	model_graund.push_back(GraphicsDevice.CreateModelFromFile(_T("‰ü’ù//road_8.X")));

	for (int i = 0; i < (int)models.size(); i++) { models[i]->SetMaterial(mtrl); };

	for (int i = 0; i < (int)model_graund.size(); i++) { model_graund[i]->SetMaterial(mtrl); };

	_iplayer_data.reset(new IPlayerData);
}

void MAPOBJECTS::Draw()
{

	Vector3 player_position = _iplayer_data->GetPlayerPosition("player");

	if (player_position.z >= scene_position + (17 * 3))
	{
		scene_position += (17 * 3) * 2;
	}

	for (int i = 0; i < (int)model_graund.size(); i++)
	{
		model_graund[i]->SetPosition(Vector3(0.0f, -0.3f, scene_position + (i * 17)));
		model_graund[i]->Draw();
	}

	for (int i = 0; i < (int)models.size(); i++)
	{
		if (i == _PILLAR)
		{
			for (int g = 0; g < (int)models.size(); g++)
			{
				models[_PILLAR]->SetPosition(Vector3(0.0f, -0.3f, scene_position  + (-10 + (g * 19))));
				models[_PILLAR]->Draw();
			}
		}
		if (i == _BILL)
		{
			models[_BILL]->SetScale(0.8);
			models[_BILL]->SetPosition(Vector3(0.0f, -5.0f, scene_position + 25.0f));
			models[_BILL]->Draw();
		}
	}
}
