#include "hammering.h"
#include "Walking.h"

Hammering::Hammering()
{
}

Hammering::~Hammering()
{
}

void Hammering::idle(Animation * a)
{
	std::cout << "Hammering -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Hammering::walking(Animation * a)
{
	std::cout << "Hammering-> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}
