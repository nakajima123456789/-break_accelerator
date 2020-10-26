#include "C_MAP.h"

#include "../INFORMATION/INFORMATION.h"

void C_MAP::Init()
{

	MediaManager.Attach(GraphicsDevice);
    bg = MediaManager.CreateMediaFromFile(_T("SPRITE//BG_v01.wmv"));

	Material mtrl;

	Color _color = Color(1.0f, 1.0f, 1.0f);

	mtrl.Diffuse  = _color;
	mtrl.Ambient  = _color;
	mtrl.Specular = _color;
	mtrl.Emissive = _color;
	mtrl.Power = 1.0f;

	auto&& AddModel = [=](LPCTSTR _filename) { model.push_back(GraphicsDevice.CreateModelFromFile(_filename));
	model[model.size() - 1]->SetScale(transform.scale);
	model[model.size() - 1]->SetMaterial(mtrl);	};

	AddModel(_T("model3D//‰ü’ù”Å//road_3.X"));

	model_position.resize(model.size());

	const unsigned int model_size = 8;

	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();
};

void C_MAP:: Update()
{
	for (int i = 0; i < model_position.size(); ++i)
	{
		if (model_position[i][0].z + 17 >= monostate.player_pos.z)
		{
			Vector3 pos = Vector3(0.0f, 0.0f, model_position[i].back().z + 17);
			model_position[i].erase(model_position[i].begin());
			model_position[i].push_back(pos);
		}
	}

	if (bg->IsComplete()) {bg->Replay();} else { bg->Play(); }
};

void C_MAP::Draw3D()
{
	for (int y = 0; y < model_position.size(); ++y){
		for (int x = 0; x < model_position[y].size(); ++x){
			if (y == PILLAR) {
				if (x % 2 == 0)
					model[y]->SetRotation(Vector3(0.0f, 0.0f, 0.f));
				else
					model[y]->SetRotation(Vector3(0.0f, 180.0f, 0.f));
			}
			else
			{
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
			}
		}
	}

};

void C_MAP::Draw2D() 
{
	//SpriteBatch.Draw(*bg, Vector3(0, 0, SpriteBatch_BottomMost));
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
					 model_position[y][x] =   Vector3( 1.3f, 0.0f,(monostate.player_pos.z - 5) + (x - 1) * 12.f);
				else 
					 model_position[y][x] =   Vector3(-1.3f, 0.0f,(monostate.player_pos.z - 5) + (x - 0) * 12.f);
				continue;   
			} 
			else {
				model_position[y][x] = Vector3(0.0f, 0.f, (monostate.player_pos.z - 5) + (x * 17));
			}
		}
	}
};
