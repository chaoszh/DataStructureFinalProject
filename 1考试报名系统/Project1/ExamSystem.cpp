#include "ExamSystem.h"



ExamSystem::ExamSystem()
{
	//初始化
	first = new Member();
	total = 0;
}

ExamSystem::~ExamSystem()
{
	Member* iter = first;
	while (iter->next)
	{
		Member* del = iter;
		iter = iter->next;
		delete del;
	}
	delete iter;

	return;
}

/*********/
/*添加操作*/
/*********/
void ExamSystem::Insert(Member newNode, int pos)
{
	//apointed position is out of range
	if (pos > total + 1 || pos < 0)
	{
		cout << "错误！插入考生的位置超出范围。";
		return;
	}
	//no apointed position
	if (pos == 0) pos = total + 1;

	//insert
	Member* pre = find(pos - 1);
	if(pre->next)newNode.next = pre->next;
	pre->next = &newNode;

	//change the total number
	total++;

	return;
}

/*********/
/*删除操作*/
/*********/
void ExamSystem::Delete(int candidate_number)
{
	Member* preDel = find_pre_withNUMBER(candidate_number);
	Member* del = preDel->next;
	preDel->next = del->next;
	
	//CARVEAT!!!
	cout << "你删除的考生信息是：";
	print_stu_ifo(del);
	
	delete del;

	//change the total number
	total--;
	return;
}

void ExamSystem::Delete(string name)
{
	Member* preDel = find_pre_withNAME(name);
	Member* del = preDel->next;
	preDel->next = del->next;
	delete del;

	//change the total number
	total--;
	return;

}

/*********/
/*查找操作*/
/*********/
Member* ExamSystem::Find(int candidate_number)
{
	//point to ZERO
	Member* iter = first;
	while (iter->next)
	{
		iter = iter->next;
		if (iter->number == candidate_number)
		{
			return iter;
		}
	}
	cout << "错误！未找到指定考号的考生！";
	return nullptr;
}

Member* ExamSystem::Find(string name)
{
	//point to ZERO
	Member* iter = first;
	while (iter->next)
	{
		iter = iter->next;
		if (iter->name == name)
		{
			return iter;
		}
	}
	cout << "错误！未找到指定名称的考生！";
	return nullptr;
}


/*********/
/*修改操作*/
/*********/
void ExamSystem::Modify(int candidate_number, Member* newNode)
{
	Member* pre = find_pre_withNUMBER(candidate_number);
	Member* target = pre->next;
	pre->next = newNode;
	newNode->next = target->next;
	delete target;

	return;
}

/***********************/
/*输出指定/全部学生的信息*/
/***********************/
void ExamSystem::print_stu_ifo(Member* p)
{
	cout << p->number << '\t'
		<< p->name << '\t'
		<< p->sex << '\t'
		<< p->age << '\t'
		<< p->occupation << '\n';
	return;
}

void ExamSystem::print_all()
{
	cout << "考号\t姓名\t性别\t年龄\t报考类别\t\n";
	
	Member* iter = first;
	while (iter->next)
	{
		iter++;
		print_stu_ifo(iter);
	}

	return;
}

/////////////////////////////////////////////////////////////
///////////////////////内部调用的函数/////////////////////////
/////////////////////////////////////////////////////////////



/******************/
/*找到指定序号的学生*/
/******************/
Member* ExamSystem::find(int number)
{
	if (number > total || number < 0)
	{
		cout << "错误！指定序号超出范围！";
		return nullptr;
	}
	
	//point to ZERO
	Member* iter = first;
	int seq = 0;
	while (seq!=number)
	{
		seq++;
		iter = iter->next;
	}
	return iter;
}


/***************************/
/*找到指定名称/学号的学生的前一个人*/
/***************************/
Member* ExamSystem::find_pre_withNAME(string name)
{
	//point to ZERO
	Member* iter = first;
	Member* iter_pre;
	while (iter->next)
	{
		iter_pre = iter;
		iter = iter->next;
		if (iter->name == name)
		{
			return iter_pre;
		}
	}
	cout << "错误！未找到指定名称的考生！";
	return nullptr;
}

Member* ExamSystem::find_pre_withNUMBER(int number)
{
	//point to ZERO
	Member* iter = first;
	Member* iter_pre;
	while (iter->next)
	{
		iter_pre = iter;
		iter = iter->next;
		if (iter->number == number)
		{
			return iter_pre;
		}
	}
	cout << "错误！未找到指定名称的考生！";
	return nullptr;
}
