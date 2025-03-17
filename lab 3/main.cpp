#include <iostream>
#include "Math.h";
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int main()
{
	int a = 5;
	int b = 7;
	int f = 2;
	double c = 5.3;
	double d = 7.4;
	double e = 2.3;
	Math math;
	cout << math.Add(a, b) << endl;
	cout << math.Add(a,b,f) << endl;
	cout << math.Add(c, d) << endl;
	cout << math.Add(c, d, e) << endl;
	cout << math.Mul(a, b) << endl;
	cout << math.Mul(a,b,f) << endl;
	cout << math.Mul(c, d) << endl;
	cout << math.Mul(c, d, e) << endl;
	cout << math.Add(3, 4, 5, 6)<<endl;
	cout << math.Add("word", "ptr");
}