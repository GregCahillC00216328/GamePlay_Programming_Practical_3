#include <iostream>
#include <Player.h>
#include <Idle.h>
#include "Debug.h"


Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::setAnimatedSprite(AnimatedSprite & t_animated_Sprite)
{
	
	//m_animated_sprite.clearFrames();
	m_animated_sprite = t_animated_Sprite;
	
}



void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_animation.idle();
		break;
	case Input::Action::JUMP:
		//std::cout << "Player jumping" << std::endl;
		m_animation.jumping();
		break;
	case Input::Action::LEFT:
		//std::cout << "Player Left" << std::endl;
		m_animation.walking();
		break;
	case Input::Action::RIGHT:
		//std::cout << "Player Right" << std::endl;
		m_animation.walking();
		break;
	case Input::Action::CLIMB:
		//std::cout << "Player Climb" << std::endl;
		m_animation.climbing();
		break;
	case Input::Action::SWORD:
		//std::cout << "Player Sword" << std::endl;
		m_animation.swording();
		break;
	case Input::Action::HAMMER:
		//std::cout << "Player Hammer" << std::endl;
		m_animation.hammering();
		break;
	case Input::Action::SHOVEL:
		//std::cout << "Player Shovel" << std::endl;
		m_animation.shoveling();
		break;
	default:
		break;
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
}