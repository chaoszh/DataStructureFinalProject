#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#define SIZE 7
using namespace std;

struct point
{
	int row;
	int col;
	point* pre;
	point(int a, int b)
	{
		row = a;
		col = b;
	}
	point(int a, int b, point* _pre)
	{
		row = a;
		col = b;
		pre = _pre;
	}
};

class maze
{
public:
	maze();
	~maze();
private:
	//maze situation
	char table[SIZE][SIZE];
	char solution[SIZE][SIZE];
	char block[SIZE][SIZE];
	

	//stack
	stack<point> detect;
	stack<point> detected;
	stack<point> path;

	//direction
	int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

	//funtion
	bool findSolution();
	bool findPath(point p);
	void printSolution();
	void print()
	{
		cout << "行\\列\t第1列\t第2列\t第3列\t第4列\t第5列\t第6列\t第7列" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << "第" << i + 1 << "行" << '\t';
			for (int j = 0; j < SIZE; j++)
			{
				cout << table[i][j] << '\t';
			}
			cout << endl;
		}
	}

};