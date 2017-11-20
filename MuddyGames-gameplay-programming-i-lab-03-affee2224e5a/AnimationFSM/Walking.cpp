#include "Walking.h"
#include "Jumping.h"
#include "Climbing.h"
#include "Swording.h"
#include "Shoveling.h"
#include "hammering.h"

Walking::Walking()
{
}

Walking::~Walking()
{
}

void Walking::idle(Animation * a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Walking::jumping(Animation * a)
{
	std::cout << "Walking -> jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Walking::climbing(Animation * a)
{
	std::cout << "Walking -> climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Walking::shoveling(Animation * a)
{
	std::cout << "Walking -> shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}

void Walking::swording(Animation * a)
{
	std::cout << "Walking -> swording" << std::endl;
	a->setCurrent(new Swording());
	delete this;
}

void Walking::hammering(Animation * a)
{
	std::cout << "Walking -> hammering" << std::endl;
	a->setCurrent(new Hammering());
	delete this;
}
