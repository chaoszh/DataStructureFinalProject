#include "Family.h"

Family::Family()
{
	Begin();
	Struction();

}

Family::~Family()
{
	deleteAll();
}

void Family::Begin()
{
	cout << "**               家谱管理系统                  **" << endl;
	cout << "=================================================" << endl;
	cout << "**             请选择要执行的操作：            **" << endl;
	cout << "**             A --- 完善家谱                  **" << endl;
	cout << "**             B --- 添加家庭成员              **" << endl;
	cout << "**             C --- 解散局部家庭              **" << endl;
	cout << "**             D --- 更改家庭成员姓名          **" << endl;
	cout << "**             E --- 退出程序                  **" << endl;

	string name;
	cout << "首先建立一个家谱！" << endl;
	cout << "请输入祖先的姓名：";
	cin >> name;
	Member*tree = new Member(name);
	forest.push_back(tree);
	cout << "此家谱的祖先是：" << name << endl << endl;
}

void Family::Struction()
{
	char order;

	while (true)
	{
		cout << "请选择要执行的操作：";
		cin >> order;

		if (order == 'A')
		{
			string name;
			cout << "请输入要建立家庭的人的姓名：";
			cin >> name;
			Member* father = find(name);
			if (father == nullptr)
			{
				father = new Member(name);
				forest.push_back(father);
			}
			int number;
			cout << "请输入" << name << "的儿女人数：";
			cin >> number;
			cout << "请依次输入" << name << "的儿女的姓名：";
			for (int i = 0; i < number; i++)
			{
				string childname;
				cin >> childname;
				Member* child = new Member(childname);
				father->appendChild(child);
			}
			cout << name << "的第一代子孙是：";
			Member*ptr = father->child;
			while (ptr!=nullptr)
			{
				cout << ptr->name << " ";
				ptr = ptr->neighbor;
			}
			cout << endl << endl;
		}
		else if (order == 'B')
		{
			string fatherName;
			cout << "请输入要添加的儿子（或女儿）的人的姓名：";
			cin >> fatherName;
			Member* father = find(fatherName);
			string childName;
			cout << "请输入" << fatherName << "新添加的儿子（或女儿）的姓名：";
			cin >> childName;
			Member* child = findTree(childName);
			if (child == nullptr)child = new Member(childName);
			father->appendChild(child);
			cout << fatherName << "的第一代子孙是：";
			child = father->child;
			while (child != nullptr)
			{
				cout << child->name << ' ';
				child = child->neighbor;
			}
			cout << endl << endl << endl;
		}
		else if (order == 'C')
		{
			string fatherName;
			cout << "请输入要解散家庭的人的姓名：";
			cin >> fatherName;
			cout << "要解散家庭的人是：" << fatherName << endl << endl;
			Member* father = find(fatherName);
			deleteMember(father);
		}
		else if (order == 'D')
		{
			string name;
			string nameAlter;
			cout << "请输入要更改姓名的人的目前姓名：";
			cin >> name;
			cout << "请输入更改后的姓名：";
			cin >> nameAlter;
			find(name)->name = nameAlter;
			cout << name << "已更名为" << nameAlter << endl << endl;
		}
		else if (order == 'E')
		{
			break;
		}
		else
		{
			cout << "找不到该执行的操作，请重新输入。" << endl << endl;
		}
	}
}

Member* Family::find(string name)
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		stack<Member*> node;
		node.push(*iter);
		while (node.size() != 0)
		{
			Member* ptr = node.top();
			node.pop();
			//judge ptr
			if (ptr->name == name)
			{
				return ptr;
			}
			//update stack
			if (ptr->child != nullptr)node.push(ptr->child);
			if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
		}
		iter++;
	}
	return nullptr;
}

Member* Family::findUpper(string name)
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		stack<Member*> node;
		node.push(*iter);
		while (node.size() != 0)
		{
			Member* ptr = node.top();
			node.pop();
			//judge ptr
			if (ptr->child->name == name || ptr->neighbor->name == name)
			{
				return ptr;
			}
			//update stack
			if (ptr->child != nullptr)node.push(ptr->child);
			if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
		}
		iter++;
	}
	return nullptr;
}

Member* Family::findUpper(Member* member)
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		stack<Member*> node;
		node.push(*iter);
		while (node.size() != 0)
		{
			Member* ptr = node.top();
			node.pop();
			//judge ptr
			if (ptr->child == member || ptr->neighbor == member)
			{
				return ptr;
			}
			//update stack
			if (ptr->child != nullptr)node.push(ptr->child);
			if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
		}
		iter++;
	}
	return nullptr;
}

Member* Family::findTree(string name)
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		if ((*iter)->name == name)
		{
			Member* temp = *iter;
			forest.erase(iter);
			return temp;
		}
		iter++;
	}
	return nullptr;
}

void Family::deleteAll()
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		deleteMember(*iter);
		iter++;
	}
}

void Family::deleteMember(Member* member)
{
	Member*m = member;
	Member* upperNode = findUpper(member);
	if (upperNode != nullptr)
	{
		if (upperNode->child == member)upperNode->child = member->neighbor;
		else if (upperNode->neighbor == member)upperNode->neighbor = member->neighbor;
		member->neighbor = nullptr;
	}
	stack<Member*> node;
	node.push(m);
	while (node.size() != 0)
	{
		Member* ptr = node.top();
		node.pop();
		//judge ptr
		if (ptr->child != nullptr)
		{
			node.push(ptr->child);
		}
		if (ptr->neighbor != nullptr)
		{
			node.push(ptr->neighbor);
		}
		delete(ptr);
	}
}