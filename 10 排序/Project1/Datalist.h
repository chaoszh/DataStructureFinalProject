#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Datalist
{
public:
	Datalist();
	~Datalist();
	Datalist(int _total);
	int total = 0;
	int* data = nullptr;
	void showDatalist();
	void operator=(const Datalist& list);
	int& operator[](int i);
};