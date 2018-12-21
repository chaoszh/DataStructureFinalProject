#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Member
{
	string name;
	Member* child = nullptr;
	Member* neighbor = nullptr;

//	Member()
	//{

	//}
	Member(string _name)
	{
		name = _name;
	}
	void appendChild(Member*m)
	{
		if (child == nullptr)
		{
			child = m;
		}
		else
		{
			Member*_child = child;
			_child->appendNeighbor(m);
		}
	}
	void appendNeighbor(Member* m)
	{
		Member* ptr = this;
		while (ptr->neighbor != nullptr)
		{
			ptr = ptr->neighbor;
		}
		ptr->neighbor = m;
	}
};

class Family
{
public:
	Family();
	~Family();

	vector<Member*> forest;

private:
	void Begin();
	void Struction();
	void Delete();

	Member* find(string name);
	Member* findUpper(string name);

	void deleteMember(Member* m);
};

