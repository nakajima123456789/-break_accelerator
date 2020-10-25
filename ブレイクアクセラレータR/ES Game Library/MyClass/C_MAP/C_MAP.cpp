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


	AddModel(_T("model3D//âºëfçﬁ//road_2.X"));
	AddModel(_T("model3D//bill_side//building_V01.X"));
	AddModel(_T("model3D//bill_side//building_V02.X"));
	//AddModel(_T("model3D//bill_side//building_V03.X"));
	//AddModel(_T("model3D//bill_side//building_V04.X"));
	//AddModel(_T("model3D//bill_side//building_V05.X"));
	//AddModel(_T("model3D//bill_side//building_V06.X"));
	//AddModel(_T("model3D//bill_side//building_V07.X"));


	model_position.resize(model.size());

	const unsigned int model_size = 4;

	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();
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
	for (int y = 0; y < model_position.size(); ++y){
		for (int x = 0; x < model_position[y].size(); ++x){
			if (y == PILLAR) {
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
			}
			if (y == PILLAR + 1) {
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
				model_position[y][x] = Vector3(5.0f, -7.0f, (player_pos.z - 5) + (x * 44)); 
			} 
			else	if (y == PILLAR + 1) {
				model_position[y][x] = Vector3(-5.0f, -7.0f, (player_pos.z - 5) + (x * 44));
			}
			else {
				model_position[y][x] = Vector3(0.0f, -0.5f, (player_pos.z - 5) + (x * 44));
			}
		}
	}
};
