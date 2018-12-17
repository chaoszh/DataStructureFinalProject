#pragma once
#include <vector>
#include <iostream>
using namespace std;

class bank
{
public:
	bank();
	~bank();

private:
	int n;

	//A窗口队列
	vector<int> A;
	//B窗口队列
	vector<int> B;

};

