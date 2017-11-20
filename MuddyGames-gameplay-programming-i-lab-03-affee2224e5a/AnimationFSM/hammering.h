#ifndef HAMMERING
#define HAMMERING
#include "State.h"
#include "Animation.h"
#include "Idle.h"
class Hammering : public State
{
public:
	Hammering();
	~Hammering();
	void idle(Animation* a);
	void walking(Animation* a);
};

#endif //HAMMERING