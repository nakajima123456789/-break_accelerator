#include "OBSEVER.h"
std::list<OBSERVERLISTENER*> OBSERVER::listeners_ = {};

void OBSERVER::addListener(OBSERVERLISTENER* listener)
{
	listeners_.push_back(listener);
};

void OBSERVER::removeListener(OBSERVERLISTENER* listener) {
	listeners_.remove(listener);
};

// Õ“Ë”»’è‚µ‚½
void OBSERVER::IsCollisionDamage()
{
	// Õ“Ë”»’è‚µ‚½‚±‚Æ‚ðŠÏ‘ªŽÒ‚É’Ê’m 
	for (auto listener : listeners_)
	{
		listener->OnCollisionDamage();
	}
}

void OBSERVER::IsCollisionClear()
{
	// Õ“Ë”»’è‚µ‚½‚±‚Æ‚ðŠÏ‘ªŽÒ‚É’Ê’m 
	for (auto listener : listeners_)
	{
		listener->OnCollisionClear();
	}
}

void OBSERVER::IsCollisionGage()
{
	// Õ“Ë”»’è‚µ‚½‚±‚Æ‚ðŠÏ‘ªŽÒ‚É’Ê’m 
	for (auto listener : listeners_)
	{
		listener->OnCollisionGage();
	}
}
