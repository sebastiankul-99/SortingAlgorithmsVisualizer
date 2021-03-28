#pragma once
#include "Menu.h"
#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>

class ArrayToSort
{
	
	std::vector<std::pair<int, int>>  arrayOfPointsToSort;  // <int x (position of rectagle), int y (height of rectagle) >
	sf::Sprite background;
	//int iterator;
	void heapify(sf::RenderWindow& appWindow, int n,int i, int d =-1);
	void quickSort(sf::RenderWindow& appWindow,int low, int high);
	int partition(sf::RenderWindow& appWindow, int low, int high);
	void mergeSort(sf::RenderWindow& appWindow, int l, int r);
	void merge(sf::RenderWindow& appWindow, int l, int m, int r);
public:
	ArrayToSort();
	ArrayToSort(int size, sf::Sprite background);
	void NewArray(sf::RenderWindow& appWindow);
	void Draw(sf::RenderWindow &appWindow, bool clear = true ,int iterator =0, int a=-1, int b=-1, int c=-1);
	void BubbleSort(sf::RenderWindow& appWindow);
	void InsertionSort(sf::RenderWindow& appWindow);
	void SelectionSort(sf::RenderWindow& appWindow);
	void HeapSort(sf::RenderWindow& appWindow);
	void QuickSort(sf::RenderWindow& appWindow);
	void MergeSort(sf::RenderWindow& appWindow);
	void ShellSort(sf::RenderWindow& appWindow);
	

};

