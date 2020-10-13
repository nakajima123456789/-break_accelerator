#include "C_MAP.h"

void C_MAP::Init()
{
	model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰¼‘fÞ//hashira_01.X"));
	this->transform.scale = 10.0f;

	for (int i = 0; i < 5; i++)
	{
		model_pos.push_back(Vector3(0, 0, i * 2000));
	}
};
void C_MAP:: Update()
{
	model_pos;
};
void C_MAP::Draw3D()
{
	this->model->SetRotation(this->transform.rotation);
	this->model->SetScale(this->transform.scale);

	for (int i = 0; i < model_pos.size(); i++)
	{
		this->model->SetPosition(model_pos[i]);
	    this->model->Draw();
	}
};
void C_MAP::Draw2D() 
{
	
};
