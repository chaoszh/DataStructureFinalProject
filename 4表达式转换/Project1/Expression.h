#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

struct symbol
{
	char _symbol;
	int value;

	//initialize
	symbol(char x)
	{
		_symbol = x;
		if (_symbol == '+' || _symbol == '-')
		{
			value = 2;
		}
		else if (_symbol == '*' || _symbol == '/')
		{
			value = 3;
		}
		else if (_symbol == '{' || _symbol == '[' || _symbol == '(' || _symbol == '}' || _symbol == ']' || _symbol == ')')
		{
			value = 1;
		}
	}
	void operator=(char x)
	{
		_symbol = x;
		if (_symbol == '+' || _symbol == '-')
		{
			value = 2;
		}
		else if (_symbol == '*' || _symbol == '/')
		{
			value = 3;
		}
		else if (_symbol == '{' || _symbol == '[' || _symbol == '(' || _symbol == '}' || _symbol == ']' || _symbol == ')')
		{
			value = 1;
		}
	}
	
	//judge value
	bool operator>(symbol x)
	{
		if (value > x.value)
		{
			return true;
		}
		else return false;
	}
	bool operator==(symbol x)
	{
		if (value == x.value)
		{
			return true;
		}
		else return false;
	}
};

class Expression
{
public:
	Expression();
	

private:
	
	char expression[20];

	bool Input();
	vector<int> digit;

};


#endif