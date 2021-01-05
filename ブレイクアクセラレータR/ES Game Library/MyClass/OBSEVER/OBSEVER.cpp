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
void OBSERVER::IsCollision(std::string collsion_tag)
{
	// �Փ˔��肵�����Ƃ��ϑ��҂ɒʒm 
	for (auto listener : listeners_){listener->OnCollision(collsion_tag);}
}


