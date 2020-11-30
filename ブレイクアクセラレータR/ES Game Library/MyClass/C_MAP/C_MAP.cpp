#include "C_MAP.h"

#include "../INFORMATION/INFORMATION.h"
void C_MAP::Init()
{
	MediaManager.Attach(GraphicsDevice);
    bg = MediaManager.CreateMediaFromFile(_T("SPRITE//�R���| 1a.wmv"));

	bgm = SoundDevice.CreateMusicFromFile(_T("BGM_SE//bgm.wav"));

	Material mtrl;

	mtrl.Diffuse = Color(0.0f, 0.0f, 0.0f);
	mtrl.Ambient = Color(0.0f, 0.0f, 0.0f);
	mtrl.Specular = Color(0.0f, 0.0f, 0.0f);
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);
	mtrl.Power = 0.0f;

	auto&& AddModel = [=](LPCTSTR _filename) { model.push_back(GraphicsDevice.CreateModelFromFile(_filename));
	model[model.size() - 1]->SetScale(transform.scale);
	model[model.size() - 1]->SetMaterial(mtrl);	};

	AddModel(_T("model3D//������_//road_7.X"));
	AddModel(_T("model3D//��//test_set.X"));
	AddModel(_T("model3D//��//test_set.X"));
	AddModel(_T("model3D//��//test_set.X"));
	AddModel(_T("model3D//��//test3.X"));
	AddModel(_T("model3D//��//hasira.X"));

	model_position.resize(model.size());

	ground_model_scene[GROUND] = 17;
	ground_model_scene[LIGHT] = 55;
	ground_model_scene[LIGHT2] = 55;
	ground_model_scene[LIGHT3] = 55;
	ground_model_scene[LEFT_POLE] = 23;
	ground_model_scene[RIGHT_POLE] = 23;

	const unsigned int model_size = 20;

	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();
	bgm->Play();
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

		if (model_position[y][0].z + 17 <= monostate.player_pos.z)
		{
			switch (y)
			{
			case LIGHT:
				AddModelProfarence(Vector3(-2.5f, -6.5f, (model_position[y].back().z + ground_model_scene[LIGHT])), y);
				break;
			case LIGHT2:
				AddModelProfarence(Vector3(-2.5f, -6.5f, (model_position[y].back().z + ground_model_scene[LIGHT2])), y);
				break;
			case LIGHT3:
				AddModelProfarence(Vector3(-2.5f, -6.5f, (model_position[y].back().z + ground_model_scene[LIGHT3])), y);
				break;
			case RIGHT_POLE:
				AddModelProfarence(Vector3(2.5f, -2.0f, (model_position[y].back().z + ground_model_scene[RIGHT_POLE])), y);
				break;
			case LEFT_POLE:
				AddModelProfarence(Vector3(-5.3f, -2.0f, (model_position[y].back().z + ground_model_scene[LEFT_POLE])), y);
				break;
			default:
				AddModelProfarence(Vector3(0.0f, -0.25f, (model_position[y].back().z + ground_model_scene[GROUND])), y);
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

	for (int y = 0; y < model_position.size(); ++y){
		for (int x = 0; x < model_position[y].size(); ++x){

			switch (y)
			{

			case LIGHT:
			break;
			case LIGHT2:
				break;
			case LIGHT3:
				break;
			case RIGHT_POLE:
				model[y]->SetPosition(model_position[y][x]);
				model[y]->SetRotation(0.0f, 30.0f, 0.0f);
				//model[y]->Draw();
				break;
			case LEFT_POLE:
				model[y]->SetPosition(model_position[y][x]);
				model[y]->SetRotation(0.0f, 30.0f, 0.0f);
				//model[y]->Draw();
				break;
			default:
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
				break;
			}
		}
	}

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
				model[y]->SetScale(0.8f, 0.8f, 1.0f);
				model[y]->DrawAlpha(1.f);
				break;
			case LIGHT3:
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
	SpriteBatch.Draw(*bg, Vector3(0, 0, SpriteBatch_BottomMost));
}

void C_MAP::CreateMapPrefarence()
{
	for (int y = 0; y < model_position.size(); y++)
	{
		for (int x = 0; x < model_position[y].size(); x++)
		{
			switch (y)
			{
			case LIGHT:
				model_position[y][x] = Vector3(-2.5f, -6.5f, (monostate.player_pos.z ) + (x * ground_model_scene[LIGHT]));
				break;
			case LIGHT2:
				model_position[y][x] = Vector3(-2.5f, -6.5f, (monostate.player_pos.z) + (x * ground_model_scene[LIGHT]));
				break;
			case LIGHT3:
				model_position[y][x] = Vector3(-2.5f, -6.5f, (monostate.player_pos.z) + (x * ground_model_scene[LIGHT]));
				break;
			case RIGHT_POLE:
				model_position[y][x] = Vector3(2.5f, -2.0f, (monostate.player_pos.z - 5) + (x * ground_model_scene[RIGHT_POLE]));
				break;
			case LEFT_POLE:
				model_position[y][x] = Vector3(-5.3f, -2.0f, (monostate.player_pos.z - 5) + (x * ground_model_scene[LEFT_POLE]));
				break;
			default:
				model_position[y][x] = Vector3(0.0f, -0.25f, (monostate.player_pos.z - 5) + (x * ground_model_scene[GROUND]));
				break;
			}
		}
	}
};
