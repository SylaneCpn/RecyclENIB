
#include "menu.hpp"
#include <iostream>


int Menu::NumberOfItems;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("../Fonts/Freedom-10eM.ttf"))
	{
		std::cout<<"Error , unable to load font";
	}

	 NumberOfItems = 4;



	men.emplace_back(sf::Text());
	men[0].setFont(font);
	men[0].setFillColor(sf::Color::Red);
	men[0].setString("Jouer");
	men[0].setPosition(sf::Vector2f(width / 2, height / ((float)NumberOfItems + 1) * 1));



	men.emplace_back(sf::Text());
	men[1].setFont(font);
	men[1].setFillColor(sf::Color::White);
	men[1].setString("Options");
	men[1].setPosition(sf::Vector2f(width / 2, height / ((float)NumberOfItems + 1) * 2));




	men.emplace_back(sf::Text());
	men[2].setFont(font);
	men[2].setFillColor(sf::Color::White);
	men[2].setString("Regles");
	men[2].setPosition(sf::Vector2f(width / 2, height / ((float)NumberOfItems + 1) * 3));

	men.emplace_back(sf::Text());
	men[3].setFont(font);
	men[3].setFillColor(sf::Color::White);
	men[3].setString("Quitter");
	men[3].setPosition(sf::Vector2f(width / 2, height / ((float)NumberOfItems + 1) * 4));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{


	for (const auto &e : men){
		window.draw(e);
	}
}

void Menu::MoveUp()
{


	if (selectedItemIndex - 1 >= 0)
	{
		men[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		men[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{

	if (selectedItemIndex + 1 < NumberOfItems)
	{
		men[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		men[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


int menu(Window &wind)
{
	//sf::RenderWindow window(sf::VideoMode(1000, 1000), "Recycl'ENIB");
	sf::Texture t;
    t.loadFromFile("../Images/ENIB.png");
    sf::Sprite s(t);
	//s.scale(sf::Vector2f(4,6));
	sf::RenderWindow& window = wind.get_window_();

	Menu menu((float)window.getSize().x,(float) window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				default:
      					{
        			break;}

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						return 0;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						return 1;
						break;
					case 2:
						std::cout << "Rules button has been pressed" << std::endl;
						return 2;
						break;
					case 3:
						return 3;
						break;
					}
					

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;
			default:
      				{
        			break;
					
					}
			}
		
		}

		window.clear();
		window.draw(s);
		menu.draw(window);

		window.display();
	}
	return -1;
}