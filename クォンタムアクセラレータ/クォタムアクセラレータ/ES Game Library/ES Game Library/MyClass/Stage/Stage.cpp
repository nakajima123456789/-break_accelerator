#include "Stage.h"
#include "../PlayerDataBase/PlayerDataBase.h"

void Stage::Init()
{
	AddModelParametor(_T("model3D//‰ü’ù”Å//road_8.X"),     17, Vector3(0.0f, -0.25f, 0.0f));
	AddModelParametor(_T("model3D//’Œ//kari.X"),           23, Vector3(0.0f,  0.0f,  0.0f));
	AddModelParametor(_T("model3D//bill_side//pro_set.X"), 60, Vector3(0.0f, -8.0f, 0.0f));

};

void Stage:: Update()
{
	Vector3 player_position = PlayerDataBase.GetPlayerPosition();

	for (int y = 0; y < model_position.size(); ++y) 
	{
		Vector3 position = *model_position[y].begin();
		int remove_position = 20;
		if (position.z + remove_position <= player_position.z)
		{
			model_position[y].erase(model_position[y].begin());
			model_position[y].push_back(Vector3(position.x, position.y, (model_position[y].back().z + model_scene[y])));
		}
	}

	return;
};

void Stage::Draw3D()
{
	for (int y = 0; y < model_position.size(); ++y) 
	{
		for (int x = 0; x < model_position[y].size(); ++x)
		{
			model[y]->SetPosition(model_position[y][x]);
			model[y]->Draw();
		}
	}

	return;
};

void Stage::DrawAlpha3D()
{
	return;
};

void Stage::Draw2D() 
{
	
}

void Stage::AddModelParametor(LPCTSTR _filename, int scene, Vector3 position)
{
	Material mtrl;
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);

	model.push_back(GraphicsDevice.CreateModelFromFile(_filename));
	model[model.size() - 1]->SetScale(transform.scale);
	model[model.size() - 1]->SetMaterial(mtrl);

	model_scene.push_back(scene);
	model_position.resize(model.size());

	int model_size = 8;

	for (int i = 0; i < model_size; i++)
	{
		model_position[model.size() - 1].push_back(position + Vector3(0.0f,0.0f,-5 + (i * scene)));
	}
}