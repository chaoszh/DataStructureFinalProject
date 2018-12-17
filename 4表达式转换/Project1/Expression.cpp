#include "Expression.h"

Expression::Expression()
{
	Input();
}

bool Expression::Input()
{
	stack<symbol> Symbol;
	vector<string> Digit;
	Symbol.push(symbol('('));

	cout << "请输入表达式：";
	int i = 0;
	while (true)
	{
		char temp = getchar();

		//判断是不是数字
		if (temp <= '9' && temp >= '0')
		{
			//默认数字不会输错
			char digit[20];
			int i = 0;
			while (temp <= '9' && temp >= '0' || temp == '.')
			{
				digit[i] = temp;
				i++;
				temp = getchar();
			}
			//把字符数组转成数字
			//transIntoDigit(digit);
			//用string保存该数字
			Digit.push_back(digit);
		}
		//判断是不是运算符号
		//不用else if：判断是否为数字的时候会多吞一个char
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
		{
			symbol x = temp;
			Symbol.push(x);
		}
		//判断是不是括号
		else if (temp == '{' || temp == '[' || temp == '(')
		{
			symbol x = temp;
			Symbol.push(x);
		}
		else if (temp == '}' || temp == ']' || temp == ')')
		{
			Symbol.pop();
		}
		//判断是不是空
		else if(temp=='\n')
		{
			//结束输出
			break;
		}
	}
}

//other constructions
float transIntoDigit(char d[])
{
	float result = 0;
	int length = sizeof(d) / sizeof(char);
	int i = 0;
	while (d[i] != '.'&&i < length)
	{
		result = result * 10 + d[i];
		i++;
	}
	if (d[i] == '.')
	{
		int _i = 1;
		while (i+_i < length)
		{
			result = result + d[i + _i] / (10 * _i);
			_i++;
		}
	}
	return result;
}