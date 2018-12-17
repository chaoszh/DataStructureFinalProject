#pragma once

#include <iostream>
#include <list>
using namespace std;

template<typename T>
class intersect
{
public:
	intersect();
	~intersect();

	void findIntersection();
	void print();
private:
	list<T>a, b, c;

	//validity()正确返回1 错误返回0
	bool validity();
	//检查1正整数2递增序列 有错返回>=1
	bool numberValidity(T x);
	bool orderValidity(list<T> x);
};





/******************************/
/******************************/
/*         Defination         */
/******************************/
/******************************/

template<typename T>
intersect<T>::intersect()
{
	int input;
	
	bool flag = 1;
	while (flag)
	{
		cout << "输入序列a的内容（空格键隔开各个元素，输入-1结束）：" << endl;
		while (cin >> input && input!=-1)
		{
			a.push_back(input);
		}
		cout << "输入序列b的内容（空格键隔开各个元素，按回车键结束）：" << endl;
		while (cin >> input && input != -1)
		{
			b.push_back(input);
		}

		//检查是否正确
		flag=1-validity();
	}


	findIntersection();
	print();
}

template<typename T>
intersect<T>::~intersect()
{

}

template<typename T>
void intersect<T>::findIntersection()
{
	if (a.size() == 0 || b.size() == 0)return;
	auto iterA = a.begin();
	auto iterB = b.begin();

	while (true)
	{
		int A = *iterA;
		int B = *iterB;

		if (A < B)iterA++;
		else if (A > B)iterB++;
		else if (A == B)
		{
			c.push_back(A);
			iterA++;
			iterB++;
		}
		
		//break conditions
		if (iterA == a.end() || iterB == b.end())
		{
			break;
		}
	}
}

template<typename T>
void intersect<T>::print()
{
	cout << endl << "两序列的交集为：" << endl;
	auto iter = c.begin();
	if (c.size()==0)cout << "NULL";
	else
	{
		cout << *iter;
		iter++;
	}
	while (iter != c.end())
	{
		cout << ' ' << *iter;
		iter++;
	}
	cout << endl;
}

template<typename T>
bool intersect<T>::validity()
{
	int validity = 0;
	validity += orderValidity(a);
	validity += orderValidity(b);
	//正确
	if (validity == 0)
	{
		return 1;
	}
	//错误
	else
	{
		cout << "输入有误，请重新输入。" << endl << endl;
		return 0;
	}
}

template<typename T>
bool intersect<T>::numberValidity(T x)
{
	if (x <= 0)return 1;
	else return 0;
}

template<typename T>
bool intersect<T>::orderValidity(list<T> x)
{
	auto p1 = x.begin();
	auto p2 = p1++;
	while (p1!=x.end())
	{
		//numberValidity
		if (numberValidity(*p1))
		{
			return 1;
		}

		if (*p1 <= *p2)
		{
			p1++;
			p2++;
			continue;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}