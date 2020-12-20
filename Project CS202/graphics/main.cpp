#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(600, 600), "SFML works!");
	//CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	system("dir");
	Texture t;
	
	std::string x = "car.jpg";
	if (!t.loadFromFile(x))
	{
		printf("nono");
	}

	Sprite s(t);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(Color::White);
		window.draw(s);
		window.display();
	}

	return 0;
}