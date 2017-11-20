#ifndef INPUT_H
#define INPUT_H
class Input
{
public:
	Input();
	~Input();

	enum Action
	{
		IDLE,
		JUMP,		//Jump
		LEFT,			//Left movement
		RIGHT,			//Right Movement
		SWORD,			//Sword attack
		HAMMER,			//Hammer
		CLIMB,			//Climb
		SHOVEL			//Shovel
	};

	void setCurrent(Action);
	Action getCurrent();

private:
	Action m_current;
};
#endif