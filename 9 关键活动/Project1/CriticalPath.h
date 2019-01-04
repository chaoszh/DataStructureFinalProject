#pragma once
#include <iostream>
#include <stack>
using namespace std;

class Edge
{
public:
	int name;
	int cost = INT_MAX;
	Edge* next = nullptr;
	Edge(int _neighbor, int _cost)
	{
		name = _neighbor;
		cost = _cost;
	}
};

class Point
{
public:
	int name;
	Edge* adj = nullptr;

	void appendEdge(Edge*e)
	{
		if (adj == nullptr)adj = e;
		else
		{
			Edge* ptr = adj;
			while (ptr->next != nullptr)
			{
				ptr = ptr->next;
			}
			ptr->next = e;
		}
	}
	//Point() {};
	//Point(int _name, int _cost, Point* _dest)
	//{
	//	name = _name;
	//	cost = _cost;
	//	dest = _dest;
	//}
	//void operator=(const Point& p)
	//{
	//	name = p.name;
	//	cost = p.cost;
	//	dest = p.dest;
	//}
};

struct Path
{
	int begin;
	int end;
};

class CriticalPath
{
public:
	CriticalPath();
	~CriticalPath();
private:
	//邻接表存储
	int PointNum; //存储结点个数
	Point* point;
	int* indegree; //存储入度
	int* Vearly;
	int* Vlate;
	stack<Path> criticalPath;

	//拓扑排序
	bool TopologicalSort();

	//输出
	void printPath();

	//大小比较
	int max(int a, int b)
	{
		if (a > b)return a;
		else return b;
	}
	int min(int a, int b)
	{
		if (a < b)return a;
		else return b;
	}
};

