#include"web.h"

void hint();

enum Construct
{
	A,
	B,
	C,
	D,
	E
};
int main()
{
	hint();
	Web web;
}

void hint()
{
	cout << "**           电网造价模拟系统             **" << endl;
	cout << "********************************************" << endl;
	cout << "**           A --- 创建电网顶点           **" << endl;
	cout << "**           B --- 添加电网的边           **" << endl;
	cout << "**           C --- 构造最小生成树         **" << endl;
	cout << "**           D --- 显示最小生成树         **" << endl;
	cout << "**           E --- 退出  程序             **" << endl;
	cout << "********************************************" << endl;
}