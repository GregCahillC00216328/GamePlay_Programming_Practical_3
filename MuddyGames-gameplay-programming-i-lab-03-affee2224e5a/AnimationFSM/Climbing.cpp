#include <Climbing.h>
#include <Jumping.h>
#include <Idle.h>
#include "Walking.h"

#include <string>

void Climbing::idle(Animation* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Climbing::jumping(Animation* a)
{
	std::cout << "Climbing -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Climbing::walking(Animation * a)
{
	std::cout << "Climbing -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}
