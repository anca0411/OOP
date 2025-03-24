#pragma once
class Sort
{
private:
    int* vector;
    int size;
public:
    Sort(int nr, int minx, int maxx);
    Sort();
    Sort(int* v, int nr);
    Sort(int count, ...);
    Sort(char* c);
    void InsertSort(bool ascendent = false);
    int partitie(int mini, int maxi, bool ascendent);
    void QuickSort1(int mini, int maxi, bool ascendent);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

