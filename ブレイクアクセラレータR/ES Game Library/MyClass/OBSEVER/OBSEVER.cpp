#include "OBSEVER.h"
std::list<OBSERVERLISTENER*> OBSERVER::listeners_ = {};

void OBSERVER::addListener(OBSERVERLISTENER* listener)
{
	listeners_.push_back(listener);
};

void OBSERVER::removeListener(OBSERVERLISTENER* listener) {
	listeners_.remove(listener);
};

// �Փ˔��肵��
void OBSERVER::IsCollisionDamage()
{
	// �Փ˔��肵�����Ƃ��ϑ��҂ɒʒm 
	for (auto listener : listeners_)
	{
		listener->OnCollisionDamage();
	}
}

void OBSERVER::IsCollisionClear()
{
	// �Փ˔��肵�����Ƃ��ϑ��҂ɒʒm 
	for (auto listener : listeners_)
	{
		listener->OnCollisionClear();
	}
}

void OBSERVER::IsCollisionGage()
{
	// �Փ˔��肵�����Ƃ��ϑ��҂ɒʒm 
	for (auto listener : listeners_)
	{
		listener->OnCollisionGage();
	}
}

void OBSERVER::IsCollisionGate()
{
	// �Փ˔��肵�����Ƃ��ϑ��҂ɒʒm 
	auto it = listeners_.begin();
	while (it != listeners_.end()) {
		(*it)->OnCollisionGate();
		it++;
	}
	//for (auto listener : listeners_)
	//{
	//	listener->OnCollisionGate();
	//}

}


