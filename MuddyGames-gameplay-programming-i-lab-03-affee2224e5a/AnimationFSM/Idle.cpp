#include <Idle.h>
#include "Walking.h"
#include "Jumping.h"
#include "Climbing.h"
#include "Swording.h"
#include "Shoveling.h"
#include "hammering.h"

#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::shoveling(Animation * a)
{
	std::cout << "Idle -> shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}

void Idle::swording(Animation * a)
{
	std::cout << "Idle -> swording" << std::endl;
	a->setCurrent(new Swording());
	delete this;
}

void Idle::hammering(Animation * a)
{
	std::cout << "Idle -> hammering" << std::endl;
	a->setCurrent(new Hammering());
	delete this;
}

void Idle::walking(Animation * a)
{
	std::cout << "Idle -> walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}
