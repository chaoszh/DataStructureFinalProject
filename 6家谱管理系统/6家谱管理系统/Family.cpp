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
			cout << "请依次输入P0的儿女的姓名：";
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

		}
		else if (order == 'C')
		{

		}
		else if (order == 'D')
		{

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
		//康康头
		if ((*iter)->name == name)
		{
			return *iter;
		}
		//康康子女
		else
		{
			Member* ptr = (*iter)->child;
			while (ptr != nullptr)
			{
				//康康自己
				if (ptr->name == name)return ptr;
				//康康邻居
				else
				{
					                                                                                                 
				}
			}
		}
		iter++;
	}
	return nullptr;
}