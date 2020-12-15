#include "OBSEVER.h"
std::list<OBSERVERLISTENER*> OBSERVER::listeners_ = {};

void OBSERVER::addListener(OBSERVERLISTENER* listener)
{
	listeners_.push_back(listener);
};

void OBSERVER::removeListener(OBSERVERLISTENER* listener) 
{
	listeners_.remove(listener);
};

// �Փ˔��肵��
void OBSERVER::IsCollisionDamage()
{
	// �Փ˔��肵�����Ƃ��ϑ��҂ɒʒm 
	for (auto listener : listeners_){listener->OnCollisionDamage();}
}

void OBSERVER::IsCollisionClear()
{
	// �Փ˔��肵�����Ƃ��ϑ��҂ɒʒm 
	for (auto listener : listeners_){listener->OnCollisionClear();}
}

void OBSERVER::IsCollisionEffekseer(PLAYER::PLAYEREFFEKSEERTYPE player_effekseer_type)
{
	for (auto listener : listeners_){listener->OnCollisionEffekseer(player_effekseer_type);}
}
