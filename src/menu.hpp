#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "window.hpp"


class Menu
{
public:
	
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	std::vector<sf::Text> men;
	static int NumberOfItems;

};

int menu(Window &wind);


#endif