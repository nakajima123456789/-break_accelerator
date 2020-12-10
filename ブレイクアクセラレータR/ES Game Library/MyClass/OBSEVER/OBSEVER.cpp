#include "OBSEVER.h"
std::list<OBSERVERLISTENER*> OBSERVER::listeners_ = {};

void OBSERVER::addListener(OBSERVERLISTENER* listener)
{
	listeners_.push_back(listener);
};

void OBSERVER::removeListener(OBSERVERLISTENER* listener) {
	listeners_.remove(listener);
};

// 衝突判定した
void OBSERVER::IsCollisionDamage()
{
	// 衝突判定したことを観測者に通知 
	for (auto listener : listeners_)
	{
		listener->OnCollisionDamage();
	}
}

void OBSERVER::IsCollisionClear()
{
	// 衝突判定したことを観測者に通知 
	for (auto listener : listeners_)
	{
		listener->OnCollisionClear();
	}
}

void OBSERVER::IsCollisionGage()
{
	// 衝突判定したことを観測者に通知 
	for (auto listener : listeners_)
	{
		listener->OnCollisionGage();
	}
}

void OBSERVER::IsCollisionDoor()
{
	// 衝突判定したことを観測者に通知 
	for (auto listener : listeners_)
	{
		listener->OnCollisionDoor();
	}
}
