#include "Menu.h"

Menu::Menu(float width, float height, sf::Sprite background)
{
	this->background = background;
	font.loadFromFile("arial.ttf");
	

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Bubble Sort");
	menu[0].setPosition(sf::Vector2f((width / 100) * 2, height / 70));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Insertion Sort");
	menu[1].setPosition(sf::Vector2f((width/100 ) * 25, height / 70));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Selection Sort");
	menu[2].setPosition(sf::Vector2f((width /100) * 52, height / 70));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Heap Sort");
	menu[3].setPosition(sf::Vector2f((width/100 *80  ), height / 70));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Quick Sort");
	menu[4].setPosition(sf::Vector2f((width / 100) * 2, height / 15));

	menu[5].setFont(font);
	menu[5].setFillColor(sf::Color::White);
	menu[5].setString("Merge Sort");
	menu[5].setPosition(sf::Vector2f((width / 100) * 25, height / 15));

	menu[6].setFont(font);
	menu[6].setFillColor(sf::Color::White);
	menu[6].setString("Shell Sort");
	menu[6].setPosition(sf::Vector2f((width / 100) * 52, height /15));

	menu[7].setFont(font);
	menu[7].setFillColor(sf::Color::White);
	menu[7].setString("Exit");
	menu[7].setPosition(sf::Vector2f((width / 100 * 80), height / 15));

	menu[8].setFont(font);
	menu[8].setFillColor(sf::Color::White);
	menu[8].setString("New set of values");
	menu[8].setPosition(sf::Vector2f((width / 100 * 70), height / 8));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& appWindow, bool clear)
{	if(clear == true)
		appWindow.clear();
		appWindow.draw(background);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		appWindow.draw(menu[i]);
	}
	
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}