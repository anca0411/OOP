#include "Student.h"
#include <string.h>

void Student::SetName(const char* name)
{
	this->student = name;
}
 const char* Student::GetName()
{
	return student;
}
void Student::SetMath(int grade)
{
	if (grade >= 1 && grade <= 10)
		this->mate = grade;
}
int Student::GetMath()
{
	return mate;
}
void Student::SetEnglish(int grade)
{
	if (grade >= 1 && grade <= 10)
		this->engleza = grade;
}
int Student::GetEnglish()
{
	return engleza;
}
void Student::SetHistory(int grade)
{
	if (grade >= 1 && grade <= 10)
		this->istorie = grade;
}
int Student::GetHistory()
{
	return istorie;
}
double Student::Average()
{
	return (double)(this->engleza + this->mate + this->istorie) / 3.0;
}


