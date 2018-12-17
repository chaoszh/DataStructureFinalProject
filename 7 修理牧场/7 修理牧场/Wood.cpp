#include "Wood.h"



Wood::Wood()
{
	cout << "木头将要被锯成几块？：";
	cin >> n;
	cout << "输入每块木头的长度（空格键分隔，回车键结束输入）：" << endl;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		node.push_back(temp);
	}
	firstSort();
	calculate();

	cout << "将木头锯成" << n << "块的最小花费是" << money << "元。" << endl;
}

void Wood::calculate()
{
	while (true)
	{	
		auto a = node.begin();
		auto b = node.begin() + 1;
		if (b == node.end())break;

		int newNode = *a + *b;
		money += newNode;
		node.erase(node.begin());
		node.erase(node.begin());
		insert(newNode);

	}
}

void Wood::firstSort()
{
	int a = 0;
	for (a; a < node.size() - 1; a++)
	{
		for (auto point = node.begin(); point != node.end() - a - 1; point++)
		{
			auto point_after = point + 1;
			int temp;
			//从小到大排列
			if (*point > *point_after)
			{
				temp = *point_after;
				*point_after = *point;
				*point = temp;
			}
		}
	}

}

void Wood::insert(int i)
{
	auto a = node.begin();
	while (true)
	{
		if (a == node.end())
		{
			node.insert(a, i);
			break;
		}
		else if (*a > i)
		{
			node.insert(a,i);
			break;
		}
		else
		{
			a++;
		}
	}
}

Wood::~Wood()
{
}
