#include <iostream>
#include <string.h>
#include "Student.h"
#include "globals.h"
using namespace std;
int main()
{
	Student a,b;

	a.SetName("Alex");
	b.SetName("Andrei");
	cout << namecomp(a, b) << endl;
	a.SetMath(5);
	b.SetMath(7);
	cout << mathcomp(a, b) << endl;
}