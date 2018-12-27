#pragma once
#include "Datalist.h"
class Sort
{
public:
	Datalist datalist;
	Sort();
	~Sort();

	Datalist bubbleSort(const Datalist& List);
	Datalist insertionSort(const Datalist& List);
	

private:



	void instruct();
	char choice();


};

