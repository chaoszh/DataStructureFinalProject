#include "Sort.h"



Sort::Sort()
{
	instruct();

	int i;
	cout << "请输入要产生的随机数的个数：";
	cin >> i;
	datalist = Datalist(i);
	//datalist.showDatalist();	//debug

	bool flag = true;
	while (flag)
	{
		Datalist list;
		list = datalist;
		char Choice = choice();

		float timeBegin = clock();
		unsigned long long exchangeCount = 0;
		switch (Choice) 
		{
		case '1':	//bubbleSort
		{
			bubbleSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "冒泡排序所用时间：\t" << duration << "ms" << endl;
			cout << "冒泡排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '2':	//selectSort
		{
			selectSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "选择排序所用时间：\t" << duration << "ms" << endl;
			cout << "选择排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '3':	//insertionSort
		{
			insertionSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "直接插入排序所用时间：\t" << duration << "ms" << endl;
			cout << "直接插入排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '4':	//shellSort
		{
			shellSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "希尔排序所用时间：\t" << duration << "ms" << endl;
			cout << "希尔排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '5':	//quickSort
		{
			quickSort(list, 0, list.total - 1, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "快速排序所用时间：\t" << duration << "ms" << endl;
			cout << "快速排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '6':	//heapSort
		{
			heapSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "堆排序所用时间：\t" << duration << "ms" << endl;
			cout << "堆排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '7':	//mergeSort
		{
			mergeSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "归并排序所用时间：\t" << duration << "ms" << endl;
			cout << "归并排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '8':	//radixSort
		{
			radixSort(list);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "基数排序所用时间：\t" << duration << "ms" << endl;
			cout << "基数排序交换次数：\t" << exchangeCount << endl;
			break;
		}
		case '9':
		{
			flag = false;
		}
		}

		//list.showDatalist();
		cout << endl;
		//datalist.showDatalist();
	}
}

Sort::~Sort()
{
}

void Sort::bubbleSort(Datalist& list, unsigned long long& t)
{
	for (int i = 0; i < list.total - 1; i++)
	{
		for (int j = 0; j < list.total - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
				t+=3;
			}
		}
	}
}

void Sort::selectSort(Datalist& list, unsigned long long& t)
{
	for (int i = 0; i < list.total - 1; i++)
	{
		int min_index = i;
		for (int j = i; j < list.total; j++)
		{
			if (list[min_index] > list[j])
			{
				min_index = j;
				t++;
			}
		}
		int temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
		t+=3;
	}
}

void Sort::insertionSort(Datalist& list, unsigned long long& time)
{
	for (int t = 1; t < list.total; t++)
	{
		int temp = list[t];
		int i = t - 1;
		while (temp < list[i] && i>=0)
		{
			list[i + 1] = list[i];
			time++;
			i--;
		}
		list[i + 1] = temp;
		time++;
	}
}

void Sort::shellSort(Datalist& list, unsigned long long& time)
{
	int gap = 7;
	while (gap >= 1)
	{
		//gap==N时的几个子序列都排好序
		int start = gap - 1;
		while (start >= 0)
		{
			for (int t = start + gap; t < list.total; t += gap)
			{
				int temp = list[t];
				int i = t - gap;
				while (temp < list[i] && i >= 0)
				{
					list[i + gap] = list[i];
					i -= gap;
					time++;
				}
				list[i + gap] = temp;
				time++;
			}
			start--;

			//debug
			//cout << "(gap,start)==" << gap << ',' << start << ": ";
			//list.showDatalist();
			//cout << endl;
		}
		if (gap == 1)
		{
			break;
		}
		gap /= 2;
	}
}

void Sort::quickSort(Datalist& list, int start, int end, unsigned long long& t)
{
	if (end <= start)
	{
		return;
	}
	else
	{
		int mid = start;
		for (int i = start; i <= end; i++)
		{
			if (list[i] < list[mid])
			{
				int temp = list[mid];
				list[mid] = list[i];
				list[i] = list[mid + 1];
				list[mid + 1] = temp;
				t += 3;
				mid++;
			}
		}
		quickSort(list, start, mid - 1, t);
		quickSort(list, mid + 1, end, t);
	}
}

/*heapSort*/

void Sort::heapSort(Datalist& list, unsigned long long& t)
{
	int i = 1;
	//找到最大树节点
	while (i * 2 - 1 < list.total)
	{
		i *= 2;
	}
	i = i / 2 - 1;
	//构造最大堆
	while (i > -1)
	{
		heapAdjust(list, i, list.total, t);
		i--;
	}
	int size = list.total;
	//交换
	while (size > 1)
	{
		swap(list[0], list[size - 1]);//list最后一个数最大
		size -= 1;
		heapAdjust(list, 0, size, t);
	}
}

void Sort::heapAdjust(Datalist& list, int i, int size, unsigned long long& t)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (right < size)
	{
		if (list[right] > list[i])
		{
			swap(list[i], list[right]);
			t++;
			heapAdjust(list, right, size, t);
		}
	}
	if (left < size)
	{
		if (list[left] > list[i])
		{
			swap(list[i], list[left]);
			t++;
			heapAdjust(list, left, size, t);
		}
	}
	return;
}


void Sort::mergeSort(Datalist& list, unsigned long long& t)
{
	int size = 1;
	while (size < list.total)//size
	{
		int first = 0;
		int second = 0 + size;
		while (first < list.total)//first second
		{
			//compare
			int a = first;
			int b = second;
			int* temp = new int[2 * size];
			int temp_i = 0;
			while (a < second&&b < second + size && b < list.total)//ab不为空
			{
				if (list[a] < list[b])
				{
					temp[temp_i] = list[a];
					temp_i++;
					a++;
					t++;
				}
				else
				{
					temp[temp_i] = list[b];
					temp_i++;
					b++;
					t++;
				}
			}
			while (a < second&&a < list.total)//a不为空
			{
				temp[temp_i] = list[a];
				temp_i++;
				a++;
			}
			while (b < second + size && b < list.total)//b不为空
			{
				temp[temp_i] = list[b];
				temp_i++;
				b++;
			}
			//copy
			int i = 0;
			int j = first;
			while (j < second + size && j < list.total)
			{
				list[j] = temp[i];
				i++;
				j++;
			}
			delete []temp;
			//next 2
			first += 2 * size;
			second += 2 * size;
		}
		size *= 2;
	}
}

/*radixSort*/

void Sort::radixSort(Datalist& list)
{
	int baseNum = findMaxBase(list);
	//list转换成链表first
	node* first = new node(list[0]);
	int i = 1;
	node* p = first;
	while (i <list.total)
	{
		p->next = new node(list[i]);
		p = p->next;
		i++;
	}
	//radixSort
	radixSort(first, baseNum);
	//链表转化成list
	i = 0;
	p = first;
	while (p != nullptr && i < list.total)
	{
		list[i] = p->value;
		i++;
		p = p->next;
	}
}

int Sort::findMaxBase(Datalist& list)
{
	int max = 0;
	int i = 0;
	while (i < list.total)
	{
		if (max < list[i])
		{
			max = list[i];
		}
		i++;
	}
	
	int base = 10;
	while (max%base != max)
	{
		base *= 10;
	}
	base /= 10;
	return base;
}

void Sort::radixSort(node* &P, int baseNum)
{
	//根据当前的baseNum进行重排
	node* ptr = P;	//链表指针
	node* bucket[10];
	for (int i = 0; i < 10; i++)
	{
		bucket[i] = new node(0);
	}

	while (ptr != nullptr)//遍历链表 分配到bucket中
	{
		int key = (ptr->value / baseNum) % 10;
		node* p = bucket[key];
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new node(ptr->value);
		ptr = ptr->next;
	}

	//删除原链表
	ptr = P;
	while (ptr != nullptr)
	{
		node* before = ptr;
		ptr = ptr->next;
		delete before;
	}

	//对10个链表递归
	if (baseNum != 1)//不是最低位
	{
		baseNum /= 10;
		for (int i = 0; i < 10; i++)
		{
			if (bucket[i]->next != nullptr)//有元素的桶
			{
				radixSort(bucket[i]->next, baseNum);
			}
		}
	}

	//连接桶 返回给P
	node* start;
	node* end;
	bool find_start = 0;
	for (int i = 0; i < 10; i++)
	{
		node* ptr = bucket[i];
		if (ptr->next == nullptr)continue;//排除前部分的空桶
		else if(!find_start)
		{
			start = ptr->next;//返回链表的开头
			find_start = 1;//只进来1次
		}
		else
		{
			end->next = ptr->next;
		}

		while (ptr->next != nullptr)//ptr找到桶最后一个元素
		{
			ptr = ptr->next;
		}
		end = ptr;

		//i++;
		//while (i < 10 && bucket[i]->next == nullptr)//下一个有元素的桶
		//{
		//	i += 1;
		//}
		//if (i < 10 && bucket[i]->next != nullptr)
		//{
		//	ptr->next = bucket[i]->next;
		//	i--;//抵消for循环中的++
		//}
	}
	
	//删除桶
	for (int i = 0; i < 10; i++)
	{
		delete bucket[i];
	}

	P = start;
}

/////////////////
/////*OTHER*/////
/////////////////
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
	cout << endl << "请选择排序算法：\t";
	cin >> in;
	return in;
}