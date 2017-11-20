#ifndef CLIMBING_H
#define CLIMBING_H

#include "State.h"
#include "Animation.h"
#include "Idle.h"

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
	void jumping(Animation* a);
	void walking(Animation* a);
};

#endif // !IDLE_H