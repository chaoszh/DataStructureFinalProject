#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include <iostream>
#include <string>
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
		else if (_symbol == '{' || _symbol == '[' || _symbol == '(' )
		{
			value = 1;
		}
		else if (_symbol == '}' || _symbol == ']' || _symbol == ')')
		{
			value = 0;
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

	bool operator!=(char x)
	{
		if (_symbol != x)
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
	vector<symbol> Symbol;
	vector<string> Digit;

	void Input();
	bool Build();

};


#endif