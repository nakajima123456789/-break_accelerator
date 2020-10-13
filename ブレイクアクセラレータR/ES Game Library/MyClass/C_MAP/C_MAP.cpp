#include "C_MAP.h"

void C_MAP::Init()
{
	auto&& ModelPrefarence = [this](MODEL& _model, LPCTSTR _filename)->bool{_model = GraphicsDevice.CreateModelFromFile(_filename); 
	_model->SetScale(transform.scale); return model == nullptr ? false : true; };

	ModelPrefarence(model,      _T("model3D//âºëfçﬁ//hashira_01.X"));
	ModelPrefarence(model_road, _T("model3D//ìπòH//road_v01.X"));

	const unsigned int model_size = 5;

	for (int i = 0; i < model_size; ++i)
	{
		if (i <= 3) {
			model_pos.push_back(Vector3(-2, 0, -((i + 1) * 20)));
			model_pos.push_back(Vector3( 2, 0, -((i + 1) * 20)));
		}
		model_road_pos.push_back(Vector3(0, 0, -(i * 12)));
	}
};
void C_MAP:: Update()
{

};
void C_MAP::Draw3D()
{
	auto&& ModelDrawPrefarence = [](MODEL& _model, Vector3& _pos) { _model->SetPosition(Vector3(_pos.x, _pos.y, _pos.z += 0.5f)); _model->Draw(); };

	for (int i = 0; i < model_road_pos.size(); ++i)
	{
		if (model_road_pos[i].z >= 5.0f)model_road_pos[i].z = -45.f;

		ModelDrawPrefarence(model_road, model_road_pos[i]);
	}


	for (int i = 0; i < model_pos.size(); i++)
	{
		if (i % 2 == 0)
			 this->transform.rotation  = Vector3(0.f,180.f,0.f);
		else this->transform.rotation  = Vector3(0.f, 0.f, 0.f);

		this->model->SetRotation(this->transform.rotation);

		if (model_pos[i].z >= 5.0f)model_pos[i].z = -70.f;

		ModelDrawPrefarence(model, model_pos[i]);
	}
};

void C_MAP::Draw2D() 
{
	
};
