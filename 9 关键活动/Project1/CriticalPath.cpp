#include "CriticalPath.h"

CriticalPath::CriticalPath()
{
    int TaskNum;
    cout << "输入关键活动的任务交接点数量N和任务数量M：";
    cin >> PointNum >> TaskNum;

    //初始化邻接表
    point = new Point[PointNum];
    indegree = new int[PointNum];
    Vearly = new int[PointNum];
    Vlate = new int[PointNum];
    for (int i = 0; i < PointNum; i++)
    {
        point[i].name = i;
        indegree[i] = 0;
        Vearly[i] = 0;
        Vlate[i] = INT_MAX;
    }

    cout << "下面各行依次输入（任务开始交接点、任务完成交接点、完成任务所需时间）：" << endl;
    for (int i = 0; i < TaskNum; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        //添加到邻接表中
        point[a - 1].appendEdge(new Edge(b - 1, cost));
        indegree[b - 1]++;
    }

    if (TopologicalSort())
    {
        printPath();
    }
    else
    {
        cout << "不可行的方案测试。" << endl;
    }
}


CriticalPath::~CriticalPath()
{
    //删除point的edges
    for (int i = 0; i < PointNum; i++)
    {
        Edge* e = point[i].adj;
        while (e != nullptr)
        {
            Edge*_e = e;
            e = e->next;
            delete _e;
        }
    }

    //删除
    delete[] point;
    delete[] indegree;
    delete[] Vearly;
    delete[] Vlate;
}

bool CriticalPath::TopologicalSort()
{
    int top = -1;	//栈顶指针
    int* topologicalPath = new int[PointNum];	//拓扑序列
    for (int i = 0; i < PointNum; i++)
    {
        if (indegree[i] == 0)
        {
            indegree[i] = top;
            top = i;
        }
    }

    int topoIndex = 0;
    while (top != -1)	//栈不为空
    {
        int lastTop = top;		//存下刚刚加入拓扑序列的点序号
        top = indegree[top];	//退栈

        Edge* edge = point[lastTop].adj;	//Top点的所有邻边
        topologicalPath[topoIndex] = lastTop;	//输出拓扑序列
        topoIndex++;

        while (edge != nullptr)
        {
            indegree[edge->name]--;
            Vearly[edge->name] = max(Vearly[edge->name], Vearly[lastTop] + edge->cost);		//更新Vearly数组
            if (indegree[edge->name] == 0)
            {
                indegree[edge->name] = top;
                top = edge->name;
            }
            edge = edge->next;
        }
    }

    if (topoIndex < PointNum)return false;	//拓扑序列不涵盖活动网络图中所有结点，说明有回路。

    //倒序更新Vlate，顺便计算关键路径
    Vlate[topoIndex - 1] = Vearly[topoIndex - 1];
    for (int i = topoIndex - 2; i > -1; i--)
    {
        Edge* edge = point[i].adj;
        while (edge != nullptr)
        {
            Vlate[i] = min(Vlate[edge->name] - edge->cost, Vlate[i]);	//计算Vlate;
            edge = edge->next;
        }
        //计算当前点是否有关键路径
        edge = point[i].adj;
        while (edge != nullptr)
        {
            if (Vlate[edge->name] - edge->cost == Vearly[i])
            {
                Path p;
                p.begin = i;
                p.end = edge->name;
                criticalPath.push(p);
            }
            edge = edge->next;
        }
    }

    delete[]topologicalPath;
    return true;
}

void CriticalPath::printPath()
{
    cout << endl;
    cout << "完成整个项目所需时长：" << Vearly[PointNum - 1] << endl;
    cout << "关键路径：" << endl;
    while (criticalPath.size() != 0)
    {
        auto p = criticalPath.top();
        cout << p.begin + 1 << "->" << p.end + 1 << endl;
        criticalPath.pop();
    }
    return;
}
