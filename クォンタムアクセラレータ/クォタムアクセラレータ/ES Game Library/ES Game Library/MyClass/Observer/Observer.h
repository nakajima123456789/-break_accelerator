#pragma once
#include "../../ESGLib.h"

// 衝突判定 観測者 インターフェース（ 観測 者 を 抽象化） 
class Observerlistener
{
public:
	// 仮想 デストラクタ
	virtual ~Observerlistener() {}
	// 衝突判定した
	virtual void OnCollision(int collsionType)     = 0;
};

// 衝突判定 クラス（ 観測 者 に 通知 する 役）
class Observer
{
public:
	// 観測者の登録 
	void addListener   (Observerlistener* listener);
	void removeListener(Observerlistener* listener);

	// 衝突判定した
	void IsCollision(int collsionType);

private:

	static std::list<Observerlistener*> listeners_;
};