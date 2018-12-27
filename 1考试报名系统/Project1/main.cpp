#include "ExamSystem.h"

using namespace std;

int menu();
Member* create();
enum 
{
	CANCEL,		//取消操作
	INSERT,		//插入
	DELETE,		//删除
	SEARCH,		//查找
	MODIFY,		//修改
	CALCULATE	//统计
};

int main()
{
	ExamSystem System;

	//initial the system
	int number;
	cout << "首先请建立考生信息系统！\n"
		<< "请输入考生人数:";
	cin >> number;
	cout << "请依次输入要插入的考生的考号，姓名，性别，年龄，及报考类别！\n";
	for (int i = 0; i < number; i++)
	{
		Member* newNode = create();
		System.Insert(newNode, i);
	}

	//construction
	bool flag = 1;
	while (flag)
	{
		int Construction = menu();
		switch (Construction)
		{
		case(CANCEL):
		{
			cout << "感谢使用本系统！";
			flag = 0;
			break;
		}
		case(INSERT):
		{
			int number;
			cout << "请输入你要插入的考生的位置：";
			cin >> number;
			cout << "请依次输入要插入的考生的考号，姓名，性别，年龄，及报考类别！\n";
			Member* temp = create();
			System.Insert(temp, number - 1);
			break;
		}
		case(DELETE):
		{
			int candidate_number;
			cout << "请输入要删除的考生的考号：";
			cin >> candidate_number;
			System.Delete(candidate_number);
			break;
		}
		case(SEARCH):
		{
			int candidate_number;
			cout << "请输入要查找的考生的考号：";
			cin >> candidate_number;
			cout << "考号\t姓名\t性别\t年龄\t报考类别\t\n";
			System.print_stu_ifo(System.Find(candidate_number));
			break;
		}
		case(CALCULATE):
		{
			System.print_all();
			break;
		}
		case(MODIFY):
		{
			int candidate_number3;
			cout << "请输入要修改的考生的考号：";
			cin >> candidate_number3;
			cout << "请依次输入要修改的考生的考号，姓名，性别，年龄，及报考类别！\n";
			Member* newNode = create();
			System.Modify(candidate_number3, newNode);
			break;
		}
		}
	}

	system("pause");
	return 0;
}

int menu()
{
	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）\n";
	cout << "请选择您要进行的操作：";
	int s;
	cin >> s;
	return s;
}

Member* create()
{
	int number;
	string name;
	string sex;
	int age;
	string occupation;

	cin >> number >> name >> sex >> age >> occupation;

	Member* newNode = new Member(number,name,sex,age,occupation);

	//格式检查
	bool isAccurate = 1;
	if (sex != "男"&&sex != "女")
	{
		isAccurate = 0;
		cout << "错误！学生性别信息输入格式有误！\n";
		cout << newNode->number << '\t'
			<< newNode->name << '\t'
			<< newNode->sex << '\t'
			<< newNode->age << '\t'
			<< newNode->occupation << '\n';
	}

	if (!isAccurate)return nullptr;
	else return newNode;
}