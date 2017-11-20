#ifndef WALKING
#define WALKING
#include "State.h"
#include "Animation.h"
#include "Idle.h"
class Walking : public State
{
public:
	Walking();
	~Walking();
	void idle(Animation* a);
	void jumping(Animation* a);
	void climbing(Animation* a);
	void shoveling(Animation* a);
	void swording(Animation* a);
	void hammering(Animation* a);
};

#endif //Walking