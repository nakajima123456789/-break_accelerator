#pragma once
#include "../../ESGLib.h"

#ifdef active_Effekseer

class CEffekseer_
{
public:
	CEffekseer_::CEffekseer_();
	CEffekseer_::~CEffekseer_();
	// シングルトンインスタンスの取得
	static CEffekseer_& GetInstance()
	{
		static CEffekseer_  Effekseer_Manager;
		return              Effekseer_Manager;
	}

	int       CEffekseer_::LoadEffekseer(TCHAR* filename);
	EFFEKSEER CEffekseer_::GetEffekseer(int _number);

	int CEffekseer_::PlayEffekseer(int _number, double _scale, Vector3 _pos);

	void Update();
	void Draw(CAMERA& _camera);
	 
private:
	CEffekseer_(const CEffekseer_&)            = delete;
	CEffekseer_& operator=(const CEffekseer_&) = delete;
	CEffekseer_(CEffekseer_&&)                 = delete;
	CEffekseer_& operator=(CEffekseer_&&)      = delete;

	std::vector<EFFEKSEER> effekseer;

};
#define EffekseerMgr CEffekseer_::GetInstance()
#endif // active_Effekseer