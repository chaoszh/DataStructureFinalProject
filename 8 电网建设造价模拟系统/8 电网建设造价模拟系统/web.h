#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Node
{
private:
    char name;
    int index;
public:
    Node() {};
    Node(char _name, int _index)
    {
        name = _name;
        index = _index;
    }
    char getName()
    {
        return name;
    }
    int getIndex()
    {
        return index;
    }
    void setName(char _name)
    {
        name = _name;
    }
    void setIndex(int _index)
    {
        index = _index;
    }
};

class Edge
{
public:
    int length;
    char start;
    char end;
    Edge(int _length, char _start, char _end)
    {
        length = _length;
        start = _start;
        end = _end;
    }
};

class Web
{
public:
    Web();
    ~Web();

    void construction();

    //建立最小生成树
    void buildTree();

    //展示最小生成树
    void showTree();

private:
    int nodeNum;
    Node* nodeList;
    vector<Edge> edge;

    int** cost;
    bool* nearVec;//选中1 未选0
    int* lowCost;
    int count = 0;

    int getIndex(char name);
    char getName(int index);
    int min(int a, int b)
    {
        if (a < b)return a;
        else return b;
    }
};

