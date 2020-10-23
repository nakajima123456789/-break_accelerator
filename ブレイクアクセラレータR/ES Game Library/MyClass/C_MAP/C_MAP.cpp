#include "C_MAP.h"

#include "../INFORMATION/INFORMATION.h"

void C_MAP::Init()
{
	MediaManager.Attach(GraphicsDevice);
    bg = MediaManager.CreateMediaFromFile(_T("SPRITE//BG_v01.wmv"));
	auto&& AddModel = [this](LPCTSTR _filename) { model.push_back(GraphicsDevice.CreateModelFromFile(_filename)); 
	model[model.size() - 1]->SetScale(transform.scale); };
	AddModel(_T("model3D//ìπòH//road_2.X"));
	AddModel(_T("model3D//âºëfçﬁ//hashira_01.X"));
	//AddModel(_T("model3D//bill_side//building_V01.X"));
	AddModel(_T("model3D//bill_side//billdimg_side02.X"));

	model_position.resize(model.size());

	const unsigned int model_size = 11;

	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();
	
	Light light; 
	Color light_color = Vector3(1.0f, 1.0f, 1.0f);
	light.Type = Light_Directional;
	light.Diffuse = light_color;
	light.Ambient = light_color;
	light.Specular = light_color;
	GraphicsDevice.SetLight(light);


	Material material;
	Color material_color = Vector3(0.5f,0.5f,0.5f);
	material.Diffuse = material_color;
	material.Ambient = material_color;
	material.Specular = material_color;

	auto scale = model[0]->GetScale();
	scale *= (1.0f,1.0f,0.4f);
	model[0]->SetScale(scale);
	model[0]->SetMaterial(material);

	//auto bill_scale = model[2]->GetScale();
	//bill_scale *= (0.2f);
	//model[2]->SetScale(bill_scale);
	//model[2]->SetMaterial(material);


};

void C_MAP:: Update()
{
	player_pos = monostate.player_pos;

	if ((int)player_pos.z % 48 == 0)
		CreateMapPrefarence();

	if (bg->IsComplete()) {
		bg->Replay();
	}else { bg->Play(); }
};

void C_MAP::Draw3D()
{
	//town->Draw();
	for (int y = 0; y < model_position.size(); ++y)
	{
		for (int x = 0; x < model_position[y].size(); ++x)
		{
			if (y == PILLAR)
			{
				if(x % 2 == 0)
				model[y]->SetRotation(Vector3(0.0f, 0.0f, 0.f));
				else 
				model[y]->SetRotation(Vector3(0.0f, 180.0f, 0.f));
			}
			model[y]->SetPosition(model_position[y][x]);
			model[y]->Draw();
		}
	}
	//road->Draw();
};

void C_MAP::Draw2D() 
{
	SpriteBatch.Draw(*bg, Vector3(0, 0, SpriteBatch_BottomMost));
}

void C_MAP::CreateMapPrefarence()
{
	for (int y = 0; y < model_position.size(); y++)
	{
		for (int x = 0; x < model_position[y].size(); x++)
		{
			if (y == PILLAR)
			{
				if (x % 2 == 0)
					 model_position[y][x] =  Vector3( 1.3f, 0.0f,(player_pos.z - 5) + (x - 1) * 12.f);
				else model_position[y][x] =  Vector3(-1.3f, 0.0f,(player_pos.z - 5) + (x - 0) * 12.f);
				continue;
			}
			model_position[y][x] = Vector3(-0.25f, -0.25f, (player_pos.z - 5) + (x * 16));
		}
	}
};
