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
void OBSERVER::IsCollision()
{
	// Õ“Ë”»’è‚µ‚½‚±‚Æ‚ðŠÏ‘ªŽÒ‚É’Ê’m 
	OnCollisionNotify();
	
}


// ŠÏ‘ªŽÒ‚É’Ê’m 
void OBSERVER::OnCollisionNotify()
{
	//  Õ“Ë”»’è‚µ‚½‚±‚Æ‚ðŠÏ‘ªŽÒ‚É’Ê’m 
	for (auto listener : listeners_)
	{
		listener->OnCollision();
	}
}


