#include "EffekseerMng.h"
#include "../ResouceManager/ResouceManager.h"


int EffekseerMng::LoadEffekseer(TCHAR* filename)
{
	EFFEKSEER _effekseer;
	_effekseer = ResouceManager::Instance().LordEffekseerFile(filename);

	effekseer.   push_back(_effekseer);
	effekseer_id.push_back(INT_MAX);

	return effekseer.size() - 1;
}

EFFEKSEER EffekseerMng::GetEffekseer(int _number)
{
    return effekseer[_number];
}

int EffekseerMng::PlayEffekseer(int _number)
{
	effekseer_id[_number] = effekseer[_number]->Play(this->gameObject->transform.position);

	Vector3 front_vectol = gameObject->transform.position + Vector3_Forward;

	return effekseer.size() - 1;
}

void EffekseerMng::Update()
{
	for (int effekseer_idr = 0; effekseer_idr < effekseer_id.size(); effekseer_idr++)
	{
		effekseer[effekseer_idr]->SetPosition(effekseer_id[effekseer_idr], this->gameObject->transform.position + Vector3(0.0f, 0.5f, 0.5f));
		effekseer[effekseer_idr]->SetScale(effekseer_id[effekseer_idr], this->transform.scale);
	}
}

