#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

struct edge
{
	char self;
	char target;
	int l;
	bool used = 0;//使用过==1/未使用过==0
	edge* bro = nullptr;

	//构造函数
	edge(char _self, char _target, int _l)
	{
		self = _self;
		target = _target;
		l = _l;
	}
};

struct point
{
	char name;
	edge* bro = nullptr;

	//构造函数
	point(char _name)
	{
		name = _name;
	}

	//给顶点添加相关的边
	void attach(edge e)
	{
		edge* pointer = bro;
		if (!pointer)
		{
			bro = &e;
			return;
		}
		while (true)
		{
			//bro不为空，则循环直到bro为空，并在bro的末尾添加上e，跳出循环。
			if (pointer->bro)
			{
				pointer = pointer->bro;
			}
			else
			{
				pointer->bro = &e;
				return;
			}
		}
	}

};

//struct stick
//{
//	char a, b;
//	int length;
//
//	//构造函数
//	stick(char _a, char _b, int _length)
//	{
//		a = _a;
//		b = _b;
//		length = _length;
//	}
//};

class Web
{
public:
	Web();
	~Web();

	void construction();

	point* findPoint(char x);
	edge* findEdge(point* x, char anotherP);

	//建立最小生成树
	void buildTree(char start);

	//展示最小生成树
	void showTree();

private:
	int n;
	vector<point> Point;
	vector<point*> attachedPoint;
	
	//生成树
	vector<edge*> tree;
};

