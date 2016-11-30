#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Collision.h"

int main()
{
	//-----------------------Size of the window-----------------------//
	sf::RenderWindow
	window(sf::VideoMode(500, 500), "My window 500x500 px");

	//-----------------------Shapes Sizes and Positions(X,Y)-----------------------//

	circle* objetCircle = new circle(50, 350, 350); // R , x , y

	Rectangle* objetRectangle = new Rectangle(100, 100, 200, 200); // L , H , x , y

	 //-----------------------Shapes Colors-----------------------//

	objetCircle->Sprite.setFillColor
	(sf::Color(100, 250, 50)); // Green, more sexy

	objetRectangle->Sprite.setFillColor
	(sf::Color(24, 146, 209)); // Blue Sky

	//-----------------------GAME LOOP-----------------------//
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close the Window when the user wants it
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		//-----------------------Arrows keys of the keyboard-----------------------//

		float Speed = 0.08;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our circle
			objetCircle->Sprite.move(-Speed, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// right key is pressed: move our circle
			objetCircle->Sprite.move(Speed, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// Up key is pressed: move our circle
			objetCircle->Sprite.move(0, -Speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// Down key is pressed: move our circle
			objetCircle->Sprite.move(0, Speed);
		}

		//-----------------------The circle is not allowed to go out of the window-----------------------//

		if (objetCircle->Sprite.getPosition().x < 0)
		{
			// define position of Axe "X" to 0 
			objetCircle->Sprite.setPosition(sf::Vector2f(0.f, objetCircle->Sprite.getPosition().y));
		}

		if (objetCircle->Sprite.getPosition().y < 0)
		{
			// define position of Axe "Y" to 0 
			objetCircle->Sprite.setPosition(sf::Vector2f(objetCircle->Sprite.getPosition().x, 0.f));
		}

		if (objetCircle->Sprite.getPosition().x > 400)
		{
			// define position of Axe "X" to 0 
			objetCircle->Sprite.setPosition(sf::Vector2f(400.f, objetCircle->Sprite.getPosition().y));
		}

		if (objetCircle->Sprite.getPosition().y > 400)
		{
			// define position of Axe "Y" to 0 
			objetCircle->Sprite.setPosition(sf::Vector2f(objetCircle->Sprite.getPosition().x, 400.f));
		}

		//-----------------------When the circle and the rectangle collides-----------------------//

		if (objetCircle->isColliding(objetRectangle))
		{
			objetCircle->Sprite.setFillColor
			(sf::Color::Red);

			objetRectangle->Sprite.setFillColor
			(sf::Color::Red);
		}
		else
		{
			objetCircle->Sprite.setFillColor
			(sf::Color(100, 250, 50)); // Green

			objetRectangle->Sprite.setFillColor
			(sf::Color(24, 146, 209)); // Blue 
		}

		// Show the CIRCLE and SQUARE !!!
		window.draw(objetCircle->Sprite);
		window.draw(objetRectangle->Sprite);

		//end of the current frame, display of everything we have drawn
		window.display();
	}

	// Windows specifics
	system("pause");
	return 0;
}