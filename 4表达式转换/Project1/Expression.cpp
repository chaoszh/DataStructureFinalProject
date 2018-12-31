#include "Expression.h"

Expression::Expression()
{
	Input();
	Build();
	Digit[0].pop_back();
	cout << Digit[0];
}

void Expression::Input()
{
	cout << "请输入表达式：";
	int bracketValue = 0;
	char str[30] = {};
	
	char temp;
	str[0] = '(';
	int i = 1;
	while (temp=getchar())
	{
		if (temp == '\n')break;
		else if (temp == ' ')continue;
		else
		{
			str[i] = temp;
			i++;
		}
	}

	int x = 0;
	int length = sizeof(str) / sizeof(char);
	while (true)
	{
		//判断是不是空
		if (x==length)
		{
			//结束输出
			break;
		}
		//判断是不是运算符号
		else if (str[x] == '+' || str[x] == '-' || str[x] == '*' || str[x] == '/')
		{
			char temp = str[x];
			symbol x = temp;
			x.value += bracketValue;
			Symbol.push_back(x);
		}
		//判断是不是括号，改变优先级
		else if (str[x] == '{' || str[x] == '[' || str[x] == '(')
		{
			Bracket.push_back(str[x]);
			bracketValue += 2;

			if (str[x + 1] == '-' || str[x + 1] == '+')//带符号数
			{
				//默认数字不会输错
				char digit[20] = {};
				x+=2;
				digit[0] = str[x + 1];
				digit[1] = str[x];
				int i = 2;
				while (str[x + 1] <= '9' && str[x + 1] >= '0' || str[x + 1] == '.')
				{
					x++;
					digit[i] = str[x];
					i++;
				}
				//把字符数组转成数字
				//transIntoDigit(digit);
				//用string保存该数字
				digit[i] = ' ';
				Digit.push_back(digit);
			}
		}
		//判断是不是数字
		else if (str[x] <= '9' && str[x] >= '0')
		{
			//默认数字不会输错
			char digit[20] = {};
			digit[0] = str[x];
			int i = 1;
			while (str[x+1] <= '9' && str[x+1] >= '0' || str[x+1] == '.')
			{
				x++;
				digit[i] = str[x];
				i++;
			}
			//把字符数组转成数字
			//transIntoDigit(digit);
			//用string保存该数字
			digit[i] = ' ';
			Digit.push_back(digit);
		}
		else if (str[x] == '}' || str[x] == ']' || str[x] == ')')
		{
			Bracket.pop_back();
			bracketValue -= 2;
		}

		x++;
	}
}

bool Expression::Build()
{
	auto SymbolIter = Symbol.begin();
	auto DigitIter = Digit.begin();
	
	while (true)
	{
		if (Symbol.size() == 0)return true;
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