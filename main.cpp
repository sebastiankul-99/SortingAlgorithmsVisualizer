#include <SFML/Graphics.hpp>
#include <thread>
#include "ArrayToSort.h"
#include "Menu.h"
#include<iostream>
using namespace sf;


int main() {
   
    
    RenderWindow appWindow(VideoMode(800, 600), "Sorting algorthm visualizer");

	Texture Background;
	Background.loadFromFile("background.jpg");
	Sprite background(Background);

    Menu menu(appWindow.getSize().x, appWindow.getSize().y,background);
  
    ArrayToSort test(800, background);
    int draw = 1;
    int sort = 1;
	int sortType = 0;
	int newSetOfValues = 0;
	bool clear = true;
    while (appWindow.isOpen()) {
		Event appEvent;
		while (appWindow.pollEvent(appEvent))
		{
			switch (appEvent.type)
			{
			case sf::Event::KeyReleased:
				switch (appEvent.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						sort = 0;
						sortType = 0;
						break;
					case 1:
						sort = 0;
						sortType = 1;
						break;
					case 2:
						sort = 0;
						sortType = 2;
						break;
					case 3:
						sort = 0;
						sortType = 3;
						break;
					case 4:
						sort = 0;
						sortType = 4;
						break;
					case 5:
						sort = 0;
						sortType = 5;
						break;
					case 6:
						sort = 0;
						sortType = 6;
						break;
					case 7:
						appWindow.close();
						break;
					case 8:
						newSetOfValues = 1;
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				appWindow.close();

				break;

			}
		}
		

		 menu.draw(appWindow,false);
		
		 if (newSetOfValues == 1)
		 {
			 test.NewArray(appWindow);
			 menu.draw(appWindow, true);
			 test.Draw(appWindow, false);
			 test.Draw(appWindow, true);
			 newSetOfValues = 0;
		 }
       
            
		if(draw==1)
		test.Draw(appWindow,false);
            
		if (draw == 0)
		{
			test.Draw(appWindow, true);
			draw = 1;
		}
        if (sort == 0)
        {
			draw = 1;
            sort = 1;
			switch (sortType)
					{
					case 0:
						test.BubbleSort(appWindow);
						break;
					case 1:
						test.InsertionSort(appWindow);
						break;
					case 2:
						test.SelectionSort(appWindow);
						break;
					case 3:
						test.HeapSort(appWindow);
						break;
					case 4:
						test.QuickSort(appWindow);
						break;
					case 5:
						test.MergeSort(appWindow);
						break;
					case 6:
						test.ShellSort(appWindow);
						break;
		
					}
              
        }
           
    }
    return 0;
}
