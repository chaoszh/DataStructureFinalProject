#include "Sort.h"



Sort::Sort()
{
	instruct();

	int i;
	cout << "请输入要产生的随机数的个数：";
	cin >> i;
	datalist = Datalist(i);
	datalist.showDatalist();	//debug

	bool flag = true;
	while (flag)
	{
		char Choice = choice();
		switch (Choice) 
		{
		case '1':	//bubble
		{
			
			break;
		}
		case '2':	//
		{

		}
		case '3':	//insertionSort
		{
			Datalist* p= &insertionSort(datalist);
			cout << endl << "Address=" << p << " RETURN " << endl;

			p->showDatalist();
			cout << endl;
			datalist.showDatalist();
			break;
		}
		case '4':
		{

		}
		case '5':
		{

		}
		case '6':
		{

		}
		case '7':
		{

		}
		case '8':
		{

		}
		case '9':
		{
			flag = false;
		}
		}
	}
}


Sort::~Sort()
{
}

Datalist Sort::bubbleSort(const Datalist& List)
{
	Datalist list;
	list = List;

	return list;
}

Datalist Sort::insertionSort(const Datalist& List)
{
	Datalist list = List;
	for (int t = 1; t < list.total; t++)
	{
		int temp = list[t];
		int i = t - 1;
		while (temp < list[i] && i >= 0)
		{
			list[i + 1] = list[i];
			i--;
		}
		list[i + 1] = temp;
	}
	return list;
}

void Sort::instruct()
{
	cout << "**            排序算法比较              **" << endl;
	cout << "==========================================" << endl;
	cout << "**            1 --- 冒泡排序            **" << endl;
	cout << "**            2 --- 选择排序            **" << endl;
	cout << "**            3 --- 直接插入排序        **" << endl;
	cout << "**            4 --- 希尔排序            **" << endl;
	cout << "**            5 --- 快速排序            **" << endl;
	cout << "**            6 --- 堆排序              **" << endl;
	cout << "**            7 --- 归并排序            **" << endl;
	cout << "**            8 --- 基数排序            **" << endl;
	cout << "**            9 --- 退出程序            **" << endl << endl;
}

char Sort::choice()
{
	char in;
	cout << endl << "请选择排序算法：";
	cin >> in;
	return in;
}