#include "Observer.h"

std::list<Observerlistener*> Observer::listeners_ = {};

void Observer::addListener(Observerlistener* listener)
{ 
	listeners_.push_back(listener);
};

void Observer::removeListener(Observerlistener* listener) {
	listeners_.remove(listener); 
};

// Õ“Ë”»’è‚µ‚½
void Observer::IsCollision(int collsionType)
{
	for (auto listener : listeners_)
	{
		listener->OnCollision(collsionType);
	}
}



