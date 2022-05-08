#include "Listener.h"


TurtleCore::Listener::~Listener()
{
}

void TurtleCore::Listener::DeleteListener(const Listener* listenerToDelete)
{
	delete listenerToDelete;
}
