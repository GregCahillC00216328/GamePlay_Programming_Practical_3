#include <Jumping.h>
#include <Climbing.h>
#include <Idle.h>
#include "Walking.h"

#include <string>

void Jumping::idle(Animation* a)
{
	std::cout << "Jumping -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Jumping::climbing(Animation* a)
{
	std::cout << "Jumping -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Jumping::walking(Animation * a)
{
	std::cout << "Jumping -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}
