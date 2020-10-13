#include "C_MAP.h"

void C_MAP::Init()
{
	model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰¼‘fÞ//hashira_01.X"));
	this->model->SetScale(transform.scale);
	model_road = GraphicsDevice.CreateModelFromFile(_T("model3D//“¹˜H//road_v01.X"));
	this->model_road->SetScale(transform.scale);

	const unsigned int model_size = 5;

	for (int i = 1; i < model_size; ++i)
	{
		model_pos.push_back(Vector3(-2, 0, -(i * 20)));
		model_pos.push_back(Vector3( 2, 0, -(i * 20)));
	}

	for (int i = 0; i < model_size; ++i)
	{
		model_road_pos.push_back(Vector3(0, 0, -(i * 10)));
	}

};
void C_MAP:: Update()
{

};
void C_MAP::Draw3D()
{

	for (int i = 0; i < model_road_pos.size(); ++i)
	{
		if (model_road_pos[i].z >= 5.0f)
			model_road_pos[i].z = -40.f;

		this->model_road->SetPosition(Vector3(model_road_pos[i].x, model_road_pos[i].y, model_road_pos[i].z += 0.5f));
	    this->model_road->Draw();
	}


	for (int i = 0; i < model_pos.size(); i++)
	{
		if (i % 2 == 0)
			 this->transform.rotation  = Vector3(0.f,180.f,0.f);
		else this->transform.rotation  = Vector3(0.f, 0.f, 0.f);

		this->model->SetRotation(this->transform.rotation);

		if (model_pos[i].z >= 5.0f)
			model_pos[i].z = -70.f;

		this->model->SetPosition(Vector3(model_pos[i].x, model_pos[i].y, model_pos[i].z += 0.5f));
	    this->model->Draw();

	}
};
void C_MAP::Draw2D() 
{
	
};
