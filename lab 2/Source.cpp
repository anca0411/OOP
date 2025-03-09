#include "NumberList.h"
#include <iostream>

using namespace std;

int main()
{
	NumberList list;
		list.Add(7);
	    list.Add(2)
		list.Add(12);
	    list.Add(5);
		list.Sort();
		cout << "Lista dupa sortare este:" << endl;
		list.Print();

}
