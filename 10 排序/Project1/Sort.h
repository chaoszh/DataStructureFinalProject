#pragma once
#include "Datalist.h"
class Sort
{
public:

	Datalist datalist;
	Sort();
	~Sort();

	void bubbleSort(Datalist& list);
	void selectSort(Datalist& list);
	void insertionSort(Datalist& list);
	void shellSort(Datalist& list);
	void quickSort(Datalist& list, int start, int end);
	void heapSort(Datalist& list);
	void mergeSort(Datalist& list);
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

	void heapAdjust(Datalist& list, int i, int size);
};

