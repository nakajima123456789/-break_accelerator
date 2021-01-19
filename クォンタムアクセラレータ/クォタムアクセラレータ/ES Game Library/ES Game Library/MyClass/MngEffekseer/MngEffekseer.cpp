#include "MngEffekseer.h"

int MngEffekseer::LoadEffekseer(TCHAR* filename)
{
	EFFEKSEER _effekseer;
	_effekseer = Effekseer.CreateEffectFromFile(filename);

	effekseer.push_back(_effekseer);
	effekseer_id.push_back(0);

	return effekseer.size() - 1;
}

EFFEKSEER MngEffekseer::GetEffekseer(int _number)
{
	return effekseer[_number];
}

int MngEffekseer::PlayEffekseer(int _number)
{
	effekseer_id[_number] = effekseer[_number]->Play(this->gameObject->transform.position);

	Vector3 front_vectol = gameObject->transform.position + Vector3_Forward;

	return effekseer.size() - 1;
}

void MngEffekseer::PlayEffekseerAngle(int _number)
{
	effekseer_id[_number] = effekseer[_number]->Play(this->gameObject->transform.position);
	Vector3 front_vectol = gameObject->transform.position + Vector3_Forward;

	Vector3 forward     = Vector3_Forward;
	Vector3 effect_dir_ = Vector3_Zero;
	effect_dir_.y = MathHelper_ToRadians(-MathHelper_Atan2(forward.z, forward.x));

	effekseer[_number]->SetRotation(effekseer_id[_number], effect_dir_);
}

void MngEffekseer::Init()
{

}

void MngEffekseer::Update()
{
	for (int effekseer_idr = 0; effekseer_idr < effekseer_id.size(); effekseer_idr++)
	{
		effekseer[effekseer_idr]->SetPosition(effekseer_id[effekseer_idr], this->gameObject->transform.position + Vector3(0.0f, 0.0f, 0.5f));
		effekseer[effekseer_idr]->SetScale(effekseer_id[effekseer_idr], this->transform.scale);
	}
}