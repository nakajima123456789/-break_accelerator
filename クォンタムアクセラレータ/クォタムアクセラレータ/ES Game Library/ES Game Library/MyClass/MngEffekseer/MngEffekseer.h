#pragma once
#include "../Object/Object.h"

class MngEffekseer : public Object
{
public:
	MngEffekseer::MngEffekseer()  {};
	MngEffekseer::~MngEffekseer() {};

	int       MngEffekseer::LoadEffekseer(TCHAR* filename);
	EFFEKSEER MngEffekseer::GetEffekseer(int _number);

	int MngEffekseer::PlayEffekseer(int _number);

	void MngEffekseer::PlayEffekseerAngle(int _number);

	virtual void Init()   override;
	virtual void Update() override;

private:

	std::vector<EFFEKSEER> effekseer;
	std::vector<int>       effekseer_id;
};
