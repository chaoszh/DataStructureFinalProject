#include "Expression.h"

Expression::Expression()
{
	Input();
	Build();
	cout << Digit[0];
}

void Expression::Input()
{
	cout << "请输入表达式：";
	int bracketValue = 0;
	while (true)
	{
		char temp = getchar();

		//判断是不是数字
		if (temp <= '9' && temp >= '0')
		{
			//默认数字不会输错
			char digit[20] = {};
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
			digit[i]=' ';
			Digit.push_back(digit);
		}

		//判断是不是运算符号
		//不用else if：判断是否为数字的时候会多吞一个char
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
		{
			symbol x = temp;
			x.value += bracketValue;
			Symbol.push_back(x);
		}
		//判断是不是括号，改变优先级
		else if (temp == '{' || temp == '[' || temp == '(')
		{
			Bracket.push_back(temp);
			bracketValue += 2;
		}
		else if (temp == '}' || temp == ']' || temp == ')')
		{
			Bracket.pop_back();
			bracketValue -= 2;
		}
		//判断是不是空
		else if(temp=='\n')
		{
			//结束输出
			break;
		}
	}
}

bool Expression::Build()
{
	auto SymbolIter = Symbol.begin();
	auto DigitIter = Digit.begin();
	
	while (true)
	{
		if (Symbol.size()==1)
		{
			string newDigit = "";
			newDigit = *DigitIter + *(DigitIter + 1) + SymbolIter->_symbol + ' ';
			*DigitIter = newDigit;
			DigitIter = Digit.erase(DigitIter + 1);
			break;
		}
		//如果当前指向的运算符优先级最高，归约
		///指向最后一个运算符（运算符优先级已经是从小到大了）||当前运算符优先级大于后面的运算符
		else if (SymbolIter + 1 == Symbol.end() || *SymbolIter >= *(SymbolIter + 1))
		{
			//替换原Digit
			string newDigit = "";
			newDigit = *DigitIter + *(DigitIter + 1) + SymbolIter->_symbol + ' ';
			*DigitIter = newDigit;
			Digit.erase(DigitIter+1);
			if(DigitIter!=Digit.begin())DigitIter--;
			//删除运算符
			if (SymbolIter != Symbol.begin())
			{
				SymbolIter--;
				Symbol.erase(SymbolIter + 1);
			}
			else
			{
				SymbolIter = Symbol.erase(SymbolIter);
			}
		}
		else
		{
			//迭代
			SymbolIter++;
			DigitIter++;
		}
	}
	return true;
}


////other constructions
//float transIntoDigit(char d[])
//{
//	float result = 0;
//	int length = sizeof(d) / sizeof(char);
//	int i = 0;
//	while (d[i] != '.'&&i < length)
//	{
//		result = result * 10 + d[i];
//		i++;
//	}
//	if (d[i] == '.')
//	{
//		int _i = 1;
//		while (i+_i < length)
//		{
//			result = result + d[i + _i] / (10 * _i);
//			_i++;
//		}
//	}
//	return result;
//}