#include "maze.h"

int main()
{
	bool flag = 1;
	do
	{
		maze A;
		cout << "是否继续检测下个迷宫？(Y/N)：";
		char order;
		while (cin >> order)
		{
			if (order == 'N')
			{
				cout << "Bye!" << endl << endl;
				flag = 0;
				break;
			}
			else if (order == 'Y')
			{
				break;
			}
			else
			{
				cout << "输入错误，请重新输入：";
			}
		}

	} while (flag);
	
}