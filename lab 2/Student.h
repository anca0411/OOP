#pragma once
class Student
{
private:
	const char* student;
	int mate, istorie, engleza;

public:
	void SetName(const char* name);
	const char* GetName();
	void SetMath(int grade);
	int  GetMath();
	void SetEnglish(int grade);
	int GetEnglish();
	void SetHistory(int grade);
	int GetHistory();
	double Average();
};

