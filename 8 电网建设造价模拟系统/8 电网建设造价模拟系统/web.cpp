#include "web.h"
Web::Web()
{
    construction();
}


Web::~Web()
{
    delete[]nodeList;
    delete[]nearVec;
    delete[]lowCost;
    for (int i = 0; i < nodeNum; i++)
    {
        delete[]cost[i];
    }
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
            cin >> nodeNum;
            nodeList = new Node[nodeNum];
            cout << "请依次输入各顶点的名称：" << endl;
            char _name;
            //创建顶点和相关信息
            for (int i = 0; i < nodeNum; i++)
            {
                cin >> _name;
                nodeList[i].setName(_name);
                nodeList[i].setIndex(i);
            }
            //初始化
            nearVec = new bool[nodeNum];
            lowCost = new int[nodeNum];
            cost = new int*[nodeNum];
            for (int i = 0; i < nodeNum; i++)
            {
                nearVec[i] = 0;
                lowCost[i] = INT_MAX;
                cost[i] = new int[nodeNum];
                for (int j = 0; j < nodeNum; j++)
                {
                    cost[i][j] = INT_MAX;
                }
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
                    int indexA = getIndex(a);
                    int indexB = getIndex(b);
                    cost[indexA][indexB] = cost[indexB][indexA] = l;
                }
            }
            break;

            //输入起始顶点并生成Prim最小生成树
        case'C':
            cout << "请输入起始顶点：";
            char start;
            cin >> start;
            nearVec[getIndex(start)] = 1;
            count++;
            buildTree();
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

int Web::getIndex(char name)
{
    for (int i = 0; i < nodeNum; i++)
    {
        if (nodeList[i].getName() == name)
        {
            return nodeList[i].getIndex();
        }
    }
    return -1;
}

char Web::getName(int index)
{
    for (int i = 0; i < nodeNum; i++)
    {
        if (nodeList[i].getIndex() == index)
        {
            return nodeList[i].getName();
        }

    }
    return 0;
}

void Web::buildTree()
{
    //存储离未知点i最小距离的已知点j
    int* lowCostNode = new int[nodeNum];
    //update lowCost
    //找未知点i到已知点j的最小距离
    for (int i = 0; i < nodeNum; i++)
    {
        if (nearVec[i] == 1)continue;
        for (int j = 0; j < nodeNum; j++)
        {
            if (nearVec[j] != 1)continue;
            if (cost[i][j] <= lowCost[i])
            {
                lowCost[i] = cost[i][j];
                lowCostNode[i] = j;
            }
        }
    }

    //根据lowCost选择新加入的点
    int addNode = 0;
    int minCost = lowCost[0];
    for (int i = 1; i < nodeNum; i++)
    {
        if (nearVec[i] == 1)continue;
        if (minCost > lowCost[i])
        {
            minCost = lowCost[i];
            addNode = i;
        }
    }

    //update nearVec
    nearVec[addNode] = 1;
    count++;

    //加入边到已选边数组edge里
    Edge edgeTemp(lowCost[addNode], getName(addNode), getName(lowCostNode[addNode]));
    edge.push_back(edgeTemp);
    if (count != nodeNum)buildTree();
    return;
}

void Web::showTree()
{
    auto iter = edge.begin();
    while (iter != edge.end())
    {
        cout << iter->start << "-<" << iter->length << ">->" << iter->end << '\t';
        iter++;
    }
    return;
}