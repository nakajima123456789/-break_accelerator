#include "C_MAP.h"

#include "../INFORMATION/INFORMATION.h"

void C_MAP::Init()
{

	MediaManager.Attach(GraphicsDevice);
    bg = MediaManager.CreateMediaFromFile(_T("SPRITE//BG_v01.wmv"));

	auto&& AddModel = [this](LPCTSTR _filename) { model.push_back(GraphicsDevice.CreateModelFromFile(_filename)); 
	model[model.size() - 1]->SetScale(transform.scale); };

	AddModel(_T("model3D//ìπòH//road_v01.X"));
	AddModel(_T("model3D//âºëfçﬁ//hashira_01.X"));
	AddModel(_T("model3D//bill_side//billdimg_side02.X"));

	model_position.resize(model.size());

	const unsigned int model_size = 11;

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
			if (y == PILLAR){
				if(x % 2 == 0)
				model[y]->SetRotation(Vector3(0.0f, 0.0f, 0.f));
				else 
				model[y]->SetRotation(Vector3(0.0f, 180.0f, 0.f)); }
			else {
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
	for (int y = 0; y < model_position.size(); y++){
		for (int x = 0; x < model_position[y].size(); x++){
			if (y == PILLAR){
				if (x % 2 == 0)
					 model_position[y][x] =  Vector3( 1.3f, 0.0f,(player_pos.z - 5) + (x - 1) * 12.f);
				else model_position[y][x] =  Vector3(-1.3f, 0.0f,(player_pos.z - 5) + (x - 0) * 12.f);
				continue;    } else 
			model_position[y][x] = Vector3(0.0f,0.0f,(player_pos.z - 5) + (x * 12));
		}
	}
};
