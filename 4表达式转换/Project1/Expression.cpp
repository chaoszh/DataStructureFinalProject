#include "Expression.h"

Expression::Expression()
{
	Input();
	Build();
	cout << Digit[0];
}

void Expression::Input()
{
	Symbol.push_back(symbol('{'));

	cout << "请输入表达式：";
	int i = 0;
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
			Digit.push_back(digit);
		}

		//判断是不是运算符号
		//不用else if：判断是否为数字的时候会多吞一个char
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
		{
			symbol x = temp;
			Symbol.push_back(x);
		}
		//判断是不是括号
		else if (temp == '{' || temp == '[' || temp == '(')
		{
			symbol x = temp;
			Symbol.push_back(x);
		}
		else if (temp == '}' || temp == ']' || temp == ')')
		{
			symbol x = temp;
			Symbol.push_back(x);
		}

		//判断是不是空
		if(temp=='\n')
		{
			//结束输出
			Symbol.push_back(symbol('}'));
			break;
		}
	}
}

bool Expression::Build()
{
	auto SymbolIterPre = Symbol.begin();
	auto SymbolIter = ++Symbol.begin();
	auto SymbolIterNext = ++(++Symbol.begin());
	auto DigitIter = Digit.begin();
	bool digitFlag = 1;
	
	while (true)
	{
		//对应当前二元运算符的前一个数字/对象
		if (*SymbolIter != '('&&
			*SymbolIter != '['&&
			*SymbolIter != '{'&&
			*SymbolIter != '}'&&
			*SymbolIter != ']'&&
			*SymbolIter != ')')
		{
			if (digitFlag)
			{
				digitFlag = 0;
			}
			else
			{
				DigitIter++;
			}
		}

		//如果当前指向的运算符优先级最高
		if (*SymbolIter > *SymbolIterNext)
		{
			//两边都是括号且是同一朝向,continue
			if ((SymbolIter->value == 1 && SymbolIterNext->value == 1) || (SymbolIter->value == 0 && SymbolIterNext->value == 0))
			{
				SymbolIterPre++;
				SymbolIter++;
				SymbolIterNext++;
				continue;
			}
			//两边是正经运算符或者正经括号,开始归约
			else
			{
				//两边是括号
				if ((SymbolIter->value + SymbolIterNext->value) == 1)
				{
					cout << "come in";
				}
				else
				//两边都是运算符/一边运算符一边括号
				{
					string newDigit = "";
					auto DigitIterNext = DigitIter;
					DigitIterNext++;
					newDigit = *DigitIter + SymbolIter->_symbol + *DigitIterNext;
					//替换原Digit
					*DigitIter = newDigit;
					Digit.erase(DigitIterNext);
					//删除Symbol
					Symbol.erase(SymbolIter);
					SymbolIter = SymbolIterPre;
					SymbolIter++;
					SymbolIterNext++;
				}
			}
		}
		//运算符优先级不够高,检测下一个运算符
		else
		{
			SymbolIterPre++;
			SymbolIter++;
			SymbolIterNext++;
			continue;
		}

		if (Digit.size() == 1)
		{
			break;
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