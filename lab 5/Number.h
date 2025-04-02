#pragma once
class Number
{
private:
	char* val;
	int baza;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	// add operators and copy/move constructor
	Number(Number& ex);
	Number(Number&& ex) noexcept;

	Number(int nr);

	friend Number operator+(const Number& a, const Number& b);
	friend Number operator-(const Number& a, const Number& b);

	char& operator[](int index);

	Number& operator--();  //prefix
	Number operator--(int);//postfix

	void operator=(const Number& a);
	void operator=(int a);
	void operator=(const char* a);

	friend Number operator+=(Number& a, const Number& b);
	friend Number operator-=(Number& a, const Number& b);

	friend bool operator<(const Number& a, const Number& b);
	friend bool operator>(const Number& a, const Number& b);
	friend bool operator<=(const Number& a, const Number& b);
	friend bool operator>=(const Number& a, const Number& b);
	friend bool operator==(const Number& a, const Number& b);
	friend bool operator!=(const Number& a, const Number& b);

	int DetectareBaza(const char* a);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};


