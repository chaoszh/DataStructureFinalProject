#pragma once
#include "Datalist.h"
class Sort
{
public:

	Datalist datalist;
	Sort();
	~Sort();

	void bubbleSort(Datalist& list, unsigned long long& t);
	void selectSort(Datalist& list, unsigned long long& t);
	void insertionSort(Datalist& list, unsigned long long& t);
	void shellSort(Datalist& list, unsigned long long& t);
	void quickSort(Datalist& list, int start, int end, unsigned long long& t);
	void heapSort(Datalist& list, unsigned long long& t);
	void mergeSort(Datalist& list, unsigned long long& t);
	void radixSort(Datalist& list);

private:
	void instruct();
	char choice();

	void swap(int&a, int&b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	struct node {
		int value;
		node* next = nullptr;
		node()
		{
		};
		node(int _value)
		{
			value = _value;
		}
	};
	void radixSort(node* &P, int baseNum);
	int findMaxBase(Datalist& list);

	void heapAdjust(Datalist& list, int i, int size, unsigned long long& t);
};

