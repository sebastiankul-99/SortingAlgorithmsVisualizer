#include "ArrayToSort.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include    <ctime>
#include <algorithm>
#include <cstdlib>

ArrayToSort::ArrayToSort(int size, sf::Sprite background)
{
   
    this->background = background;
	arrayOfPointsToSort.resize(size);
    srand(time(NULL));
    for (int i = 0; i < arrayOfPointsToSort.size(); i++) {
        arrayOfPointsToSort[i].first = i;
        arrayOfPointsToSort[i].second = 1 + rand() % (400);


    }
}
void ArrayToSort::NewArray(sf::RenderWindow& appWindow)
{
    appWindow.clear(sf::Color::Black);
    int n = this->arrayOfPointsToSort.size();
   this->arrayOfPointsToSort.resize(0);
   this->arrayOfPointsToSort.resize(n);
    srand(time(NULL));
    for (int i = 0; i < arrayOfPointsToSort.size(); i++) {
        this->arrayOfPointsToSort[i].first = i;
        this->arrayOfPointsToSort[i].second = 1 + rand() % (400); 


    }
 
}

void ArrayToSort::Draw( sf::RenderWindow & appWindow, bool clear, int iterator, int a , int b ,int c ) {
    sf::RectangleShape rectangle(sf::Vector2f(2, 2));
    if(clear == true)
    appWindow.clear(sf::Color::Black);
    if (clear == true)
        appWindow.draw(background);
    rectangle.setFillColor(sf::Color(235, 149, 13));
    for (int i = 0; i < arrayOfPointsToSort.size(); i++) {
        if (a != -1 || b != -1 || c != -1)
        {   
        
            if ((a != -1 && b != -1) && c != -1)
            {
                if (i < b&& i >c)
                    rectangle.setFillColor(sf::Color(63, 167, 147));
                 else
                    rectangle.setFillColor(sf::Color(235, 170, 62));

            }
       
            
        else if (a != -1&&b!=-1)
            {
            if (i > b)
                rectangle.setFillColor(sf::Color(235, 170, 62));
            else
                rectangle.setFillColor(sf::Color(63, 167, 147));
            
            }
        else if (a != -1)
        {
            if (i < a)
                rectangle.setFillColor(sf::Color(235, 170, 62));
            else
                rectangle.setFillColor(sf::Color(63, 167, 147));
        }
            
            if (i == iterator)rectangle.setFillColor(sf::Color(255, 0, 0));


            rectangle.setPosition(arrayOfPointsToSort[i].first, 600);
            rectangle.setSize(sf::Vector2f(2, arrayOfPointsToSort[i].second));
            rectangle.setRotation(180);
            appWindow.draw(rectangle);
        }
        else
        {
            rectangle.setFillColor(sf::Color(235, 170, 62));
            if (i == iterator)rectangle.setFillColor(sf::Color(255, 0, 0));
            rectangle.setPosition(arrayOfPointsToSort[i].first, 600);
            rectangle.setSize(sf::Vector2f(2, arrayOfPointsToSort[i].second));
            rectangle.setRotation(180);
            appWindow.draw(rectangle);
        }
    }
    appWindow.display();
   
}
void ArrayToSort::BubbleSort(sf::RenderWindow& appWindow) {
    for (int i = 0; i < arrayOfPointsToSort.size(); i++)
    {
     
        for (int j = 0; j < arrayOfPointsToSort.size() - i - 1; j++)
        {
            if (arrayOfPointsToSort[j].second > arrayOfPointsToSort[j + 1].second)
            {
                auto temp = arrayOfPointsToSort[j].second;
                arrayOfPointsToSort[j].second = arrayOfPointsToSort[j + 1].second;
                arrayOfPointsToSort[j + 1].second = temp;
                if (j != 0 && (arrayOfPointsToSort.size() % j >= 0 && arrayOfPointsToSort.size() % j <= 7))
                this->Draw(appWindow, true,j, arrayOfPointsToSort.size() - i - 1);
            }
           
        }
       
    }
    this->Draw(appWindow,true, 0,1);
}
void ArrayToSort::InsertionSort(sf::RenderWindow& appWindow) {
    int key, j;
    for (int i = 1; i < arrayOfPointsToSort.size(); i++) {
        key = arrayOfPointsToSort[i].second;//take value
        j = i;
        while (j > 0 && arrayOfPointsToSort[j - 1].second > key) {
            arrayOfPointsToSort[j].second = arrayOfPointsToSort[j - 1].second;
            j--;
            if (j != 0 && (arrayOfPointsToSort.size() % j >= 0 && arrayOfPointsToSort.size() % j <= 7))
            this->Draw(appWindow,true, j,0,i);
        }
       
        arrayOfPointsToSort[j].second = key;   
       
    }
    this->Draw(appWindow,true, 0,0);
}
void ArrayToSort::SelectionSort(sf::RenderWindow& appWindow) {
    int i, j, min_idx;

    
    for (i = 0; i < arrayOfPointsToSort.size() - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < arrayOfPointsToSort.size(); j++)
        {
            if (arrayOfPointsToSort[j].second < arrayOfPointsToSort[min_idx].second)
            {
                min_idx = j;
                this->Draw(appWindow,true, min_idx,0,i);
            }
            
        }
      
        auto temp = arrayOfPointsToSort[i].second;
        arrayOfPointsToSort[i].second = arrayOfPointsToSort[min_idx].second;
        arrayOfPointsToSort[min_idx].second = temp;
        
    }
    this->Draw(appWindow,true, 0, 0,0);
}
void ArrayToSort::heapify(sf::RenderWindow& appWindow, int n,int i, int d)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;

    if (l < n && arrayOfPointsToSort[l].second > arrayOfPointsToSort[largest].second)
        largest = l;


    if (r < n && arrayOfPointsToSort[r].second > arrayOfPointsToSort[largest].second)
        largest = r;

 
    if (largest != i) {
        
        auto temp = arrayOfPointsToSort[i].second;
        arrayOfPointsToSort[i].second = arrayOfPointsToSort[largest].second;
        arrayOfPointsToSort[largest].second = temp;
        
        
        this->heapify( appWindow,n, largest,d);
        this->Draw(appWindow,true, largest,d);
    }
}
void ArrayToSort::HeapSort(sf::RenderWindow& appWindow) {

    for (int i = arrayOfPointsToSort.size() / 2 - 1; i >= 0; i--)
       this->heapify(appWindow, arrayOfPointsToSort.size(), i);

 
    for (int i = arrayOfPointsToSort.size() - 1; i > 0; i--) {
        
            auto temp = arrayOfPointsToSort[i].second;
            arrayOfPointsToSort[i].second = arrayOfPointsToSort[0].second;
            arrayOfPointsToSort[0].second = temp;
           
        

       this->heapify(appWindow,i, 0,i);
    }
    this->Draw(appWindow,true, 0,0);
}
int ArrayToSort::partition(sf::RenderWindow& appWindow, int low, int high) {

    int pivot = arrayOfPointsToSort[high].second;
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
      
        if (arrayOfPointsToSort[j].second < pivot)
        {
            i++;  
            
            auto temp = arrayOfPointsToSort[i].second;
            arrayOfPointsToSort[i].second = arrayOfPointsToSort[j].second;
            arrayOfPointsToSort[j].second = temp;
        }
        this->Draw(appWindow, true,j,0,low);
    }
    auto temp = arrayOfPointsToSort[i+1].second;
    arrayOfPointsToSort[i+1].second = arrayOfPointsToSort[high].second;
    arrayOfPointsToSort[high].second = temp;
   
    return (i + 1);
}
void ArrayToSort::quickSort(sf::RenderWindow& appWindow, int low, int high) {
   

    if (low < high)
    {
       
        int pi = this->partition(appWindow, low, high);
        this->quickSort(appWindow, low, pi - 1);
        this->quickSort(appWindow, pi + 1, high);
        
    }
    
}
void ArrayToSort::QuickSort(sf::RenderWindow& appWindow) {
    this->quickSort( appWindow,0, arrayOfPointsToSort.size()-1);
    this->Draw(appWindow,true, 0, 0);
}

void ArrayToSort::merge(sf::RenderWindow& appWindow, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

 
    std::vector<std::pair<int, int>> L, R;
    L.resize(n1);
    R.resize(n2);

    
    for (int i = 0; i < n1; i++)
        L[i] = arrayOfPointsToSort[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arrayOfPointsToSort[m + 1 + j];

    int i = 0;

    int j = 0;

    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].second <= R[j].second) {
            arrayOfPointsToSort[k].second = L[i].second;
            i++;
           
        }
        else {
            arrayOfPointsToSort[k].second = R[j].second;
           
            j++;
        }
        this->Draw(appWindow, true,l,0,r+1,l);
        k++;
    }


    while (i < n1) {
        arrayOfPointsToSort[k].second = L[i].second;
        i++;
        this->Draw(appWindow,true, k,0,r+1,l);
        k++;
    }

    while (j < n2) {
        arrayOfPointsToSort[k].second = R[j].second;
       this->Draw(appWindow, true,k,0,r+1,l);
        j++;
        k++;
    }

}
void ArrayToSort::mergeSort(sf::RenderWindow& appWindow, int l, int r) {
   
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    this->mergeSort(appWindow, l, m);
    this->mergeSort(appWindow, m + 1, r);
    this->merge(appWindow, l, m, r);
    this->Draw(appWindow, true,0,0,r+1,l);
}

void ArrayToSort::MergeSort(sf::RenderWindow& appWindow) {
    this->mergeSort(appWindow, 0, arrayOfPointsToSort.size() - 1);
    this->Draw(appWindow,true, 0, 0);
}


void ArrayToSort::ShellSort(sf::RenderWindow& appWindow)
{
   
    for (int gap = arrayOfPointsToSort.size() / 2; gap > 0; gap /= 2)
    {
       
        for (int i = gap; i < arrayOfPointsToSort.size(); i += 1)
        {
           
            int temp = arrayOfPointsToSort[i].second;

            int j;
            for (j = i; j >= gap && arrayOfPointsToSort[j - gap].second > temp; j -= gap)
            {
                arrayOfPointsToSort[j].second = arrayOfPointsToSort[j - gap].second;
               
                if (gap == 1)
                    this->Draw(appWindow, true,j, 0, j);
                else
                    this->Draw(appWindow,true, j);
            }
     
            arrayOfPointsToSort[j].second = temp;
        }
    }
    this->Draw(appWindow, true,0,0);
}