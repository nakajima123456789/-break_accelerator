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

	AddModel(_T("model3D//������//road_3.X"));

	model_position.resize(model.size());

	const unsigned int model_size = 4;

	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();

};

void C_MAP:: Update()
{

	for (int y = 0; y < model_position.size(); ++y) {
		if (model_position[y][0].z + ground_model_scene <= monostate.player_pos.z)
		{
			Vector3 pos = Vector3(0.0f,0.0f, (model_position[y].back().z + ground_model_scene));
			model_position[y].erase(model_position[y].begin());
			model_position[y].push_back(pos);
		}
	}

	if (bg->IsComplete()) {bg->Replay();} else { bg->Play(); }
};

void C_MAP::Draw3D()
{
	for (int y = 0; y < model_position.size(); ++y) {
		for (int x = 0; x < model_position[y].size(); ++x) 
		{
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
		}
	}
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
			model_position[y][x] = Vector3(0.0f, 0.f, (monostate.player_pos.z - 5) + (x * ground_model_scene));
		}
	}
};
