#pragma once

#include<iostream>
#include<vector>
using namespace std;

class Wood
{
public:
	Wood();
	~Wood();

	//排序
	void firstSort();
	//计算
	void calculate();
	//插入新节点
	void insert(int i);

private:
	int n;
	int money = 0;
	vector<int> node;
};

