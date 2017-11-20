#ifndef SHOVELING
#define SHOVELING
#include "State.h"
#include "Animation.h"
#include "Idle.h"
class Shoveling : public State
{
public:
	Shoveling();
	~Shoveling();
	void idle(Animation* a);
	void walking(Animation* a);
};

#endif //HAMMERING