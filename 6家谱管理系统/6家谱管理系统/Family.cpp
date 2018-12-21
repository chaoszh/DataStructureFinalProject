#include "Family.h"

Family::Family()
{
	Begin();
	Struction();

}


Family::~Family()
{
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
			bool flagnew = 0;
			if (father == nullptr)
			{
				flagnew = 1;
				father = new Member(name);
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
			if (flagnew == 1)forest.push_back(father);
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
			Member* child = new Member(childName);
			father->appendChild(child);
			cout << fatherName << "的第一代子孙是：";
			child = father->child;
			while (child != nullptr)
			{
				cout << child->name;
				child = child->neighbor;
			}
			cout << endl << endl << endl;
		}
		else if (order == 'C')
		{
			string fatherName;
			cout << "请输入要解散家庭的人的姓名：";
			cin >> fatherName;
			cout << "要解散家庭的人是：" << fatherName << endl;
			Member* fatherUpper = findUpper(fatherName);
			if (fatherUpper->child->name == fatherName)
			{
				deleteMember(fatherUpper->child);
				fatherUpper->child == nullptr;
			}
			else if (fatherUpper->neighbor->name == fatherName)
			{
				deleteMember(fatherUpper->neighbor);
				fatherUpper->neighbor == nullptr;
			}

		}
		else if (order == 'D')
		{
			string name;
			string nameAlter;
			cout << "请输入要更改姓名的人的目前姓名：";
			cin >> name;
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
	}
	return nullptr;
}

void Family::deleteMember(Member* m)
{
	//Member*iter = m;
	//stack<Member*> node;
	//node.push(iter);
	//while (node.size() != 0)
	//{
	//	Member* ptr = node.top();
	//	//judge ptr
	//	if (ptr->child == nullptr && ptr->neighbor == nullptr)
	//	{
	//		delete ptr;
	//	}
	//	else
	//	{
	//		//update stack
	//		if (ptr->child != nullptr)node.push(ptr->child);
	//		if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
	//	}
	//}
}