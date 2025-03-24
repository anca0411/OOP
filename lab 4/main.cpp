#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
    Sort s1(10, 1, 100); // Vector cu 10 elemente între 1 ?i 100

    std::cout << "Vectorul initial: ";
    s1.Print();

    // Testare InsertSort crescator
    s1.InsertSort(true);
    std::cout << "\nVector sortat crescator cu InsertSort: ";
    s1.Print();

    // Testare QuickSort descrescator
    s1.QuickSort(false);
    std::cout << "\nVector sortat descrescator cu QuickSort: ";
    s1.Print();

    // Testare BubbleSort crescator
    s1.BubbleSort(true);
    std::cout << "\nVector sortat crescator cu BubbleSort: ";
    s1.Print();

    // Testare BubbleSort descrescator
    s1.BubbleSort(false);
    std::cout << "\nVector sortat descrescator cu BubbleSort: ";
    s1.Print();

    return 0;
}
