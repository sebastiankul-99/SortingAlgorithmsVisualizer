#pragma once
#include "SFML/Graphics.hpp"
#include <array>
#define MAX_NUMBER_OF_ITEMS 9

class Menu
{
public:
	//Menu();
	Menu(float width, float height, sf::Sprite background);
	~Menu();
	//Menu(const Menu& p1);
	//Menu& operator= (const Menu& T);
	void draw(sf::RenderWindow& window, bool clear = true);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	
	sf::Sprite background;
	std::array<sf::Text, MAX_NUMBER_OF_ITEMS> menu;
	int selectedItemIndex;
	sf::Font font;
	

};