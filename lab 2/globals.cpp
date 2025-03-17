#include <string.h>
#include "Student.h"
#include <iostream>
using namespace std;
int namecomp(Student a, Student b)
{
	if (strcmp(a.GetName(), b.GetName())==0)
		return 0;
	else if(strcmp(a.GetName(),b.GetName())>0)
		return 1;
	return -1;
}
int mathcomp(Student a, Student b)
{
	if(a.GetMath() == b.GetMath())
		return 0;
	if(a.GetMath()>b.GetMath())
		return 1;
	return -1;
}
int englishcomp(Student a, Student b)
{
	if (a.GetEnglish() == b.GetEnglish())
		return 0;
	if (a.GetEnglish() > b.GetEnglish())
		return 1;
	return -1;
}
int historycomp(Student a, Student b)
{
	if (a.GetHistory() == b.GetHistory())
		return 0;
	if (a.GetHistory() > b.GetHistory())
		return 1;
	return -1;
}
int mediecomp(Student a, Student b)
{
	if (a.Average() == b.Average())
		return 0;
	if (a.Average() > b.Average())
		return 1;
	return -1;
}

