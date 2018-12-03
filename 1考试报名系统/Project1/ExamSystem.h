#ifndef _EXAM_SYSTEM_H_

#include <iostream>
#include <string>
using namespace std;

struct Member
{
	int number;
	string name;
	string sex;
	int age;
	string occupation;
	Member* next;

	Member()
	{

	}

	Member(int _number, string _name, string _sex, int _age, string _occupation)
	{
		number = _number;
		name = _name;
		sex = _sex;
		age = _age;
		occupation = _occupation;
		next = nullptr;
	}

};

class ExamSystem
{
public:
	ExamSystem();
	~ExamSystem();

	//insert member
	void Insert(Member* newNode, int pos);

	//delete member
	void Delete(int number);
	void Delete(string name);

	//find member
	Member* Find(int candidate_number);
	Member* Find(string name);

	//change member information
	void Modify(int candidate_number, Member* newNode);

	//print student's infomation
	void print_stu_ifo(Member* p);
	void print_all();

private:
	Member* first;//表头节点
	int total = 0;

	Member* find(int pos);
	Member* find_pre_withNAME(string name);
	Member* find_pre_withNUMBER(int number);
	
};

#endif

