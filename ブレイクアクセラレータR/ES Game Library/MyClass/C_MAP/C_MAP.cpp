#include "C_MAP.h"

#include "../INFORMATION/INFORMATION.h"
void C_MAP::Init()
{
	//bgm = SoundDevice.CreateMusicFromFile(_T("BGM_SE//bgm.wav"));

	Material mtrl;

	mtrl.Diffuse = Color(0.0f, 0.0f, 0.0f);
	mtrl.Ambient = Color(0.0f, 0.0f, 0.0f);
	mtrl.Specular = Color(0.0f, 0.0f, 0.0f);
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);
	mtrl.Power = 0.0f;

	auto&& AddModel = [=](LPCTSTR _filename) { model.push_back(GraphicsDevice.CreateModelFromFile(_filename));
	model[model.size() - 1]->SetScale(transform.scale);
	model[model.size() - 1]->SetMaterial(mtrl);	};

	AddModel(_T("model3D//‰ü’ù”Å//road_8.X"));
	for (int i = 0; i < 2; i++) {
		AddModel(_T("model3D//Œõ//bg_Vr1_set.X"));
	}
	AddModel(_T("model3D//’Œ//kari.X"));
	AddModel(_T("model3D//bill_side//building_set_pro_3.X"));


	model_position.resize(model.size());

	ground_model_scene[GROUND] = 17;
	ground_model_scene[LIGHT] = 25;
	ground_model_scene[LIGHT2] = 25;
	ground_model_scene[POLE] = 23;
	ground_model_scene[BUILD] = 60;

	const unsigned int model_size = 8;
	
	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();
	//bgm->Play();

	_iplayer_data.reset(new IPlayerData);
};

void C_MAP:: Update()
{
	auto&& AddModelProfarence = [this](Vector3 _pos, int y)
	{
		Vector3 pos = _pos;
		model_position[y].erase(model_position[y].begin());
		model_position[y].push_back(pos);
	};

	Vector3 player_pos = _iplayer_data->GetPlayerPosition("player");

	for (int y = 0; y < model_position.size(); ++y) {

		if (model_position[y][0].z + 17 <= player_pos.z)
		{
			switch (y)
			{
			case LIGHT:
				AddModelProfarence(Vector3(-2.5f, -6.5f, (model_position[y].back().z  + ground_model_scene[LIGHT])), y );
				break;
			case LIGHT2:
				AddModelProfarence(Vector3(-2.5f, -6.5f, (model_position[y].back().z + ground_model_scene[LIGHT2])), y);
				break;
			case POLE:
				AddModelProfarence(Vector3(0.0f,0.0f, (model_position[y].back().z + ground_model_scene[POLE])), y);
				break;
			case BUILD:
				AddModelProfarence(Vector3(0.0f, -8.0f, (model_position[y].back().z + ground_model_scene[BUILD])) , y);
				break;
			default:
				AddModelProfarence(Vector3(0.0f, -0.25f, (model_position[y].back().z + ground_model_scene[GROUND])), y);
				break;
			}

		}
	}

	return;
};

void C_MAP::Draw3D()
{

	for (int y = 0; y < model_position.size(); ++y){
		for (int x = 0; x < model_position[y].size(); ++x){

			switch (y)
			{
			case LIGHT:
			break;
			case LIGHT2:
			break;
			case POLE:
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
				break;
			case BUILD:
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
				break;
			default:
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
				break;
			}
		}
	}
	return;
};

void C_MAP::DrawAlpha3D()
{
	for (int y = 0; y < model_position.size(); ++y) {
		for (int x = 0; x < model_position[y].size(); ++x) {
			switch (y) {
				case LIGHT:
					model[y]->SetPosition(model_position[y][x]);
					model[y]->DrawAlpha(1.f);
					break;
				case LIGHT2:
					model[y]->SetPosition(model_position[y][x]);
					model[y]->SetScale(0.9f, 0.9f, 1.0f);
					model[y]->DrawAlpha(1.f);
					break;
			}
		}
	}
	return;
};

void C_MAP::Draw2D() 
{
	return;
}

void C_MAP::CreateMapPrefarence()
{
	Vector3 player_pos = _iplayer_data->GetPlayerPosition("player");

	for (int y = 0; y < model_position.size(); y++)
	{
		for (int x = 0; x < model_position[y].size(); x++)
		{
			switch (y) 
			{
			case LIGHT:
				model_position[y][x] = Vector3(-2.5f, -6.5f, (player_pos.z - 5) + (x * ground_model_scene[LIGHT]));
				break;										 
			case LIGHT2:									 
				model_position[y][x] = Vector3(-2.5f, -6.5f, (player_pos.z) + (x * ground_model_scene[LIGHT2]));
				break;										 
			case POLE:										 
				model_position[y][x] = Vector3(0.0f, 0.0f,   (player_pos.z - 5) + (x * ground_model_scene[POLE]));
				break;										 
			case BUILD:										 
				model_position[y][x] = Vector3(0.0f, -8.0f,  (player_pos.z - 20) + (x * ground_model_scene[BUILD]));
				break;										  
			default:										  
				model_position[y][x] = Vector3(0.0f, -0.25f, (player_pos.z - 5) + (x * ground_model_scene[GROUND]));
				break;
			}
		}
	}
	return;
};
