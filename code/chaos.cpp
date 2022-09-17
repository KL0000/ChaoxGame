#include <iostream>
#include<vector>
#include<SFML/Graphics.hpp>

using namespace std;



int main()
{
	//create window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chaos Game");

	//load font 
	sf::Font font;
	if (!font.loadFromFile("fonts/KOMIKAP_.ttf"))
	{
		return EXIT_FAILURE;
	}

	//create dialogue for user
	sf::Text text;
	text.setFont(font);
	text.setString("Click three points on the screen and pick a 4th point to get started");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);

	//create shape
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(1, 1));
	shape.setFillColor(sf::Color::White);

	//vector variables used to create 3 vertices ,position and 
	//hold the last position 
	sf::Vector2i a, b, c, d, e, z, position, lastPos;
	int count = 0;


	while (window.isOpen())
	{
		window.draw(text);

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				position = sf::Mouse::getPosition(window);
				shape.setPosition(position.x, position.y);
				if (count == 0)
				{

					//store the position of the first vertex into vector A
					a.x = position.x;
					a.y = position.y;
					shape.setFillColor(sf::Color::Red);

				}
				if (count == 1)
				{
					//store the position of the second vertex into vector B
					b.x = position.x;
					b.y = position.y;
					shape.setFillColor(sf::Color::Red);


				}
				if (count == 2)
				{
					//store the position of the second vertex into vector C
					c.x = position.x;
					c.y = position.y;


				}
				if (count == 3)
				{
					d.x = position.x;
					d.y = position.y;

				}
				if (count == 4)
				{
					e.x = position.x;
					e.y = position.y;

				}
				if (count == 5)
				{
					//the last vertex  will be stored in the vector lastPos to use in the formula
					lastPos.x = position.x;
					lastPos.y = position.y;
					shape.setFillColor(sf::Color::Green);

				}
				count++;
				break;

			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		//after initializing the requirements to create the triangle 
		//the 4th count or more clicks will trigger the loop to start
		if (count > 6)
		{
			//sets the color to white 
			shape.setFillColor(sf::Color::White);
			int lastRand = -1;
			//in this loop, the size is adjustable
			for (size_t i = 0; i < 9999; i++)
			{
				//genRand grabs a random number from 0,1,2
				int genRand = rand() % 5;
				if (genRand != lastRand)
				{
					if (genRand == 0)
					{
						//used the midpoint formula if genRand == 0
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + a.x) / 2;
						z.y = (lastPos.y + a.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						lastRand = genRand;

					}
					if (genRand == 1)
					{
						//used the midpoint formula if genRand == 1
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + b.x) / 2;
						z.y = (lastPos.y + b.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						lastRand = genRand;
					}
					if (genRand == 2)
					{
						//used the midpoint formula if genRand == 2
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + c.x) / 2;
						z.y = (lastPos.y + c.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						lastRand = genRand;
					}
					if (genRand == 3)
					{
						//used the midpoint formula if genRand == 2
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + d.x) / 2;
						z.y = (lastPos.y + d.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						lastRand = genRand;
					}
					if (genRand == 4)
					{
						//used the midpoint formula if genRand == 2
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + e.x) / 2;
						z.y = (lastPos.y + e.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						lastRand = genRand;
					}
				}
				//after genRand picks a vertex and sets the midpoint, the shape is set in that coordinates
				shape.setPosition(z.x, z.y);

			}
		}


		window.draw(shape);

		window.display();




	}
	return 0;
}