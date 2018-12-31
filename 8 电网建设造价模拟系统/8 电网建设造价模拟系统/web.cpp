#include "web.h"



Web::Web()
{
	construction();
}


Web::~Web()
{
}

void Web::construction()
{
	char input;
	bool flag = 1;
	
	while (flag)
	{
		cout << endl << "请选择操作：";
		cin >> input;

		switch (input)
		{
			//输入顶点信息
			case'A':
				cout << "请输入顶点的个数：";
				cin >> n;
				cout << "请依次输入各顶点的名称：" << endl;
				char _name;
				for (int i = 0; i < n; i++)
				{
					cin >> _name;
					Point.push_back(_name);
				}
				break;

			//输入顶点的边的信息
			case'B':
				cout << "输入顶点和边的信息，若要终止输入，输入? ? 0" << endl;
				while (true)
				{
					char a, b;
					int l;
					cout << "请输入两个顶点及边：";
					cin >> a >> b >> l;
					
					if (a == '?'&&b == '?'&&l == 0)
					{
						cout << "边的信息输入完成。" << endl;
						break;
					}
					else
					{
						point* A = findPoint(a);
						A->attach(edge(a, b, l));
						point* B = findPoint(b);
						B->attach(edge(b, a, l));
					}
				}
				break;

			//输入起始顶点并生成Prim最小生成树
			case'C':
				cout << "请输入起始顶点：";
				char start;
				cin >> start;
				buildTree(start);
				cout << "生成Prim最小生成树！" << endl;
				break;
			//显示最小生成树
			case'D':
				showTree();
				break;
			//退出程序
			case'E':
				flag = 0;
				break;
		}
	}
}

point* Web::findPoint(char x)
{
	auto i = Point.begin();
	for (i; i != Point.end(); i++)
	{
		if (i->name == x)
		{
			point* RETURN = &(*i);
			return RETURN;
		}
	}
	assert("WRONG!：函数findPoint()返回了一个空指针！");
	return nullptr;
}

edge* Web::findEdge(point* x, char anotherP)
{
	edge* e = x->bro;
	while (e)
	{
		if (e->target == anotherP)
		{
			return e;
		}
		else
		{
			e = e->bro;
		}
	}

	assert("WRONG!：函数findEdge()返回了一个空指针！");
	return nullptr;
}

void Web::buildTree(char start)
{
	point* x = findPoint(start);
	attachedPoint.push_back(x);

	while (attachedPoint.size() < n)
	{
		//检查attachedPoint，并找出目前的最短边
		//将最短边所连接的点再加入attachedPoint，并把生成树的信息录入到Tree
		auto i = attachedPoint.begin();
		edge* minEdge = (*i)->bro;
		
		//找出attached的最短边
		for (i; i != attachedPoint.end(); i++)
		{

			edge* rival = (*i)->bro;
			while (rival != nullptr)
			{
				//跳过的边-1使用过2回路-靠检查另一个点是不是attachPoint里面来判断
				if (isAttachedPoint(rival->target))continue;
				//变更minEdge
				if (rival->l < minEdge->l)
				{
					minEdge = rival;
				}
				//访问某个点的下一条边；
				rival = rival->bro;
			}
		}

		//attachedPoint、使用过的边、生成树更新
		point* newPoint = findPoint(minEdge->target);
		attachedPoint.push_back(newPoint);

		//minEdge->used = 1;
		//findEdge(newPoint, minEdge->self)->used = 1;
		tree.push_back(minEdge);
	}
}

bool Web::isAttachedPoint(char name)
{
	auto i = attachedPoint.begin();
	while (i != attachedPoint.end())
	{
		if ((*i)->name == name)
		{
			return true;
		}
		i++;
	}
	return false;
}

void Web::showTree()
{
	cout << "最小生成树的顶点及边为：" << endl;
	auto x = tree.begin();
	for (x; x != tree.end(); x++)
	{
		cout << (*x)->self <<"-<"<< (*x)->l <<">->"<< (*x)->target;
		cout << '\t';
	}
	cout << endl;
}