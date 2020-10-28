#include "C_MAP.h"

void C_MAP::Init()
{
	MediaManager.Attach(GraphicsDevice);
    bg = MediaManager.CreateMediaFromFile(_T("SPRITE//BG_v01.wmv"));

	Material mtrl;

<<<<<<< HEAD
	auto&& ModelPrefarence = [this](MODEL& _model, LPCTSTR _filename){_model = GraphicsDevice.CreateModelFromFile(_filename); 
	_model->SetScale(transform.scale); };
=======
	Color _color = Color(1.0f, 1.0f, 1.0f);
>>>>>>> 中島

	mtrl.Diffuse  = _color;
	mtrl.Ambient  = _color;
	mtrl.Specular = _color;
	mtrl.Emissive = _color;
	mtrl.Power = 1.0f;

	auto&& AddModel = [=](LPCTSTR _filename) { model.push_back(GraphicsDevice.CreateModelFromFile(_filename));
	model[model.size() - 1]->SetScale(transform.scale);
	model[model.size() - 1]->SetMaterial(mtrl);	};

	AddModel(_T("model3D//���H//road_3.X"));
	AddModel(_T("model3D//bill_side//building_V01.X"));
	AddModel(_T("model3D//bill_side//building_V02.X"));
	AddModel(_T("model3D//bill_side//building_V03.X"));
	AddModel(_T("model3D//bill_side//building_V04.X"));
	AddModel(_T("model3D//bill_side//building_V07.X"));


<<<<<<< HEAD
	for (int i = 0; i < model_size; ++i)
	{
		if (i <= 3) {
			model_pos.push_back(Vector3(-3, -0.25, ((i + 1) * 20)));
			model_pos.push_back(Vector3( 3, -0.25, ((i + 1) * 20)));
		}
		model_road_pos.push_back(Vector3(0, 0, (i * 12)));
		model_road->SetPosition(0, 0, -5);
		model_bill_pos.push_back(Vector3(0, 0, (i * 50)));
	}
	model->SetScale(0.05f);
	model_road->SetScale(0.05f);
	model_road->SetPosition(0, -7, 0);
=======
	ground_model_scene[GROUND] = 17;
	ground_model_scene[BILL1] = 100;
	ground_model_scene[BILL2] = 100;
	ground_model_scene[BILL3] = 50;
	ground_model_scene[BILL4] = 40;
	ground_model_scene[BILL5] = 66;

	model_position.resize(model.size());

	const unsigned int model_size = 8;

	for (int i = 0; i < model_position.size(); ++i)
		model_position[i].resize(model_size);

	CreateMapPrefarence();
>>>>>>> 中島
};

void C_MAP:: Update()
{
<<<<<<< HEAD
	bg->Play();
	if (bg->IsComplete()) {
		bg->Replay();
	}
};

void C_MAP::Draw3D()
{
	auto&& ModelDrawPrefarence = [](MODEL& _model, Vector3& _pos) { _model->SetPosition(Vector3(_pos.x, _pos.y, _pos.z - 5.0f)); _model->Draw(); };


	for (int i = 0; i < model_road_pos.size(); ++i)
	{
		
		if (model_road_pos[i].z <= -20.0f)model_road_pos[i].z = +100.f;

		ModelDrawPrefarence(model_road, model_road_pos[i]);
	}


	for (int i = 0; i < model_pos.size(); i++)
=======
	auto&& AddModelProfarence = [this](Vector3 _pos, int y)
>>>>>>> 中島
	{
		Vector3 pos = _pos;
		model_position[y].erase(model_position[y].begin());
		model_position[y].push_back(pos);
	};

	for (int y = 0; y < model_position.size(); ++y) {

<<<<<<< HEAD
		if (model_pos[i].z <= -10.0f)model_pos[i].z = +70.f;

		ModelDrawPrefarence(model, model_pos[i]);
=======
		if (model_position[y][0].z + 17 <= monostate.player_pos.z)
		{
			switch (y)
			{
			case BILL1:
				AddModelProfarence(Vector3(8.0f, -8.0f,   (model_position[y].back().z + 100)), y);
				break;
			case BILL2:
				AddModelProfarence(Vector3(-15.0f, -7.0f, (model_position[y].back().z + 100)), y);
				break;
			case BILL3:
				AddModelProfarence(Vector3(20.0f, -8.0f,  (model_position[y].back().z + 40)), y);
				break;
			case BILL4:
				AddModelProfarence(Vector3(-15.0f, -6.0f, (model_position[y].back().z + 30)), y);
				break;
			case BILL5:
				AddModelProfarence(Vector3(-13.0f, -6.0f, (model_position[y].back().z + 66)), y);
				break;
			default:
				AddModelProfarence(Vector3(0.0f,  0.0f, (model_position[y].back().z + ground_model_scene[GROUND])), y);
				break;
			}
		}
>>>>>>> 中島
	}

	if (bg->IsComplete()) {
		bg->Replay();
	}else { bg->Play(); }
};

void C_MAP::Draw3D()
{
	for (int y = 0; y < model_position.size(); ++y){
		for (int x = 0; x < model_position[y].size(); ++x){
			if (y == BILL1) {
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
			}
			else if (y == BILL2) {
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
			}
			else if (y == BILL3) {
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
			}
			else if (y == BILL4) {
				model[y]->SetPosition(model_position[y][x]);
				model[y]->Draw();
			}
			else if (y == BILL5) {
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
<<<<<<< HEAD
	SpriteBatch.Draw(*bg, Vector3(0, 0, 10000.0f));
	
=======
	SpriteBatch.Draw(*bg, Vector3(0, 0, SpriteBatch_BottomMost));
}

void C_MAP::CreateMapPrefarence()
{
	for (int y = 0; y < model_position.size(); y++)
	{
		for (int x = 0; x < model_position[y].size(); x++)
		{
			if (y == BILL1)
			{
				model_position[y][x] = Vector3(8.0f, -8.0f, (player_pos.z - 5) + (x * ground_model_scene[BILL1]));
			} 
			else if (y == BILL2) {
				model_position[y][x] = Vector3(-15.0f, -7.0f, (player_pos.z - 5) + (x * ground_model_scene[BILL2]));
			}
			else if (y == BILL3) {
				model_position[y][x] = Vector3(20.0f, -8.0f, (player_pos.z - 5) + (x * ground_model_scene[BILL3]));
			}
			else if (y == BILL4) { 
				model_position[y][x] = Vector3(-15.0f, -6.0f, (player_pos.z - 5) + (x * ground_model_scene[BILL4]));
			}
			else if (y == BILL5) {
				model_position[y][x] = Vector3(-13.0f, -6.0f, (player_pos.z - 5) + (x * ground_model_scene[BILL5]));
			}
			else {
				model_position[y][x] = Vector3(0.0f, 0.0f, (player_pos.z - 5) + (x * ground_model_scene[GROUND]));
			}
		}
	}
>>>>>>> 中島
};
