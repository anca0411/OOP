#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas canvas(50, 70);
	canvas.DrawCircle(15, 20, 5, '$');
	canvas.Print();
	cout << '\n';
	canvas.DrawRect(5, 7, 10, 13, '*');
	canvas.Print();
	canvas.FillRect(5, 7, 10, 13, '*');
	canvas.Print();
}
