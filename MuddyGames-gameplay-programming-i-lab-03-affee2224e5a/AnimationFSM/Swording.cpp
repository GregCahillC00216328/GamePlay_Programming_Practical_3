#include "Swording.h"
#include "Walking.h"

Swording::Swording()
{

}

Swording::~Swording()
{

}

void Swording::idle(Animation * a)
{
	std::cout << "Swording -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Swording::walking(Animation * a)
{
	std::cout << "Swording -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}
