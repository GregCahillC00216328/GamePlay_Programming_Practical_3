#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>
#include "Walking.h"
#include "Jumping.h"
#include "Climbing.h"
#include "Swording.h"
#include "Shoveling.h"
#include "hammering.h"

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_Idle(texture);
	animated_Idle.addFrame(sf::IntRect(3, 3 + (84 * 1), 84, 84));
	animated_Idle.addFrame(sf::IntRect(88, 3 + (84 * 1), 84, 84));
	animated_Idle.addFrame(sf::IntRect(173, 3 + (84 * 1), 84, 84));
	animated_Idle.addFrame(sf::IntRect(258, 3 + (84 * 1), 84, 84));
	animated_Idle.addFrame(sf::IntRect(343, 3 + (84 * 1), 84, 84));
	animated_Idle.addFrame(sf::IntRect(428, 3 + (84 * 1), 84, 84));

	AnimatedSprite animated_Walk(texture);
	animated_Walk.addFrame(sf::IntRect(3, 3 + (84 * 5), 84, 84));
	animated_Walk.addFrame(sf::IntRect(88, 3 + (84 * 5), 84, 84));
	animated_Walk.addFrame(sf::IntRect(173, 3 + (84 * 5), 84, 84));
	animated_Walk.addFrame(sf::IntRect(258, 3 + (84 * 5), 84, 84));

	AnimatedSprite animated_Climb(texture);
	animated_Climb.addFrame(sf::IntRect(3, 3 + (84 * 0), 84, 84));
	animated_Climb.addFrame(sf::IntRect(88, 3 + (84 * 0), 84, 84));
	animated_Climb.addFrame(sf::IntRect(173, 3 + (84 * 0), 84, 84));
	

	AnimatedSprite animated_Hammer(texture);
	animated_Hammer.addFrame(sf::IntRect(258, 3 + (84 * 0), 84, 84));
	animated_Hammer.addFrame(sf::IntRect(343, 3 + (84 * 0), 84, 84));
	animated_Hammer.addFrame(sf::IntRect(428, 3 + (84 * 0), 84, 84));

	AnimatedSprite animated_Jump(texture);
	animated_Jump.addFrame(sf::IntRect(3, 3 + (84 * 2), 84, 84));
	animated_Jump.addFrame(sf::IntRect(88, 3 + (84 * 2), 84, 84));
	animated_Jump.addFrame(sf::IntRect(173, 3 + (84 * 2), 84, 84));
	animated_Jump.addFrame(sf::IntRect(258, 3 + (84 * 2), 84, 84));

	AnimatedSprite animated_Shovel(texture);
	animated_Shovel.addFrame(sf::IntRect(3, 3 + (84 * 3), 84, 84));
	animated_Shovel.addFrame(sf::IntRect(88, 3 + (84 * 3), 84, 84));
	animated_Shovel.addFrame(sf::IntRect(173, 3 + (84 * 3), 84, 84));
	animated_Shovel.addFrame(sf::IntRect(258, 3 + (84 * 3), 84, 84));
	animated_Shovel.addFrame(sf::IntRect(343, 3 + (84 * 3), 84, 84));
	animated_Shovel.addFrame(sf::IntRect(428, 3 + (84 * 3), 84, 84));
	
	AnimatedSprite animated_Sword(texture);
	animated_Sword.addFrame(sf::IntRect(3, 3 + (84 * 4), 84, 84));
	animated_Sword.addFrame(sf::IntRect(88, 3 + (84 * 4), 84, 84));
	animated_Sword.addFrame(sf::IntRect(173, 3 + (84 * 4), 84, 84));

	// Setup the Player
	Player player(animated_Idle);
	
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				input.setCurrent(Input::Action::JUMP);
				player.setAnimatedSprite(animated_Jump);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				input.setCurrent(Input::Action::CLIMB);
				player.setAnimatedSprite(animated_Climb);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				input.setCurrent(Input::Action::SWORD);
				player.setAnimatedSprite(animated_Sword);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				input.setCurrent(Input::Action::HAMMER);
				player.setAnimatedSprite(animated_Hammer);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				input.setCurrent(Input::Action::SHOVEL);
				player.setAnimatedSprite(animated_Shovel);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				input.setCurrent(Input::Action::LEFT);
				player.setAnimatedSprite(animated_Walk);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				input.setCurrent(Input::Action::RIGHT);
				player.setAnimatedSprite(animated_Walk);

			}
			else {
				input.setCurrent(Input::Action::IDLE);
				player.setAnimatedSprite(animated_Idle);
			}
			
			
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
				
			}
		}
		
		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};