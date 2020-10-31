#include "C_MAP.h"

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

	AddModel(_T("model3D//“¹˜H//miti_03.X"));
	AddModel(_T("model3D//bill_side//test.X"));
	//AddModel(_T("model3D//bill_side//building_V02.X"));
	//AddModel(_T("model3D//bill_side//building_V03.X"));
	//AddModel(_T("model3D//bill_side//building_V04.X"));
	//AddModel(_T("model3D//bill_side//building_V07.X"));

	ground_model_scene[GROUND] = 17;
	ground_model_scene[BILL] = 100;


	const unsigned int model_size = 8;

	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();

};

void C_MAP:: Update()
{

	auto&& AddModelProfarence = [this](Vector3 _pos, int y)
	{
		Vector3 pos = _pos;
		model_position[y].erase(model_position[y].begin());
		model_position[y].push_back(pos);
	};

	for (int y = 0; y < model_position.size(); ++y) {

		if (model_position[y][y].z + 17 <= monostate.player_pos.z)
		{
			switch (y)
			{
			case BILL:
				AddModelProfarence(Vector3(-200.0f, -20.0f, (model_position[y].back().z - 10)), y);
				break;
			default:
				AddModelProfarence(Vector3(0.0f, 0.0f, (model_position[y].back().z + ground_model_scene[GROUND])), y);
				break;
			}

		}
	}

		if (bg->IsComplete()) {
			bg->Replay();
		}
		else { bg->Play(); }

	bg->Play();
	if (bg->IsComplete()) {
		bg->Replay();
	}
};

void C_MAP::Draw3D()
{
	//town->Draw();
	//town2->Draw();
	//town3->Draw();
	//town4->Draw();
	for (int y = 0; y < model_position.size(); ++y){
		for (int x = 0; x < model_position[y].size(); ++x){
			if (y == BILL) {
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
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
			if (y == BILL)
			{
				model_position[y][x] = Vector3(-20.0f, -20.0f,   (monostate.player_pos.z - 5) + (x * ground_model_scene[BILL]));
			} 
			else {
				model_position[y][x] = Vector3(0.0f, 0.0f,    (monostate.player_pos.z - 5) + (x * ground_model_scene[GROUND]));
			}
		}
	}
};
