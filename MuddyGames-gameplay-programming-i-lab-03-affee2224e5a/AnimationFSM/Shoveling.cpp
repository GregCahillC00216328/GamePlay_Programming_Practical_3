#include "Shoveling.h"
#include "Walking.h"

Shoveling::Shoveling()
{
}

Shoveling::~Shoveling()
{
}

void Shoveling::idle(Animation * a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Shoveling::walking(Animation * a)
{
	std::cout << "Shoveling -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

