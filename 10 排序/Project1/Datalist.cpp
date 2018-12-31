#include "Datalist.h"

Datalist::Datalist()
{
	//cout << endl << "Address=" << this << "无参数构建" << endl;
}

Datalist::~Datalist()
{
	//cout << endl << "Address=" << this << "析构" << endl;
	delete(data);
}

Datalist::Datalist(int _total)
{
	//cout << endl << "Address=" << this << "有参数构建" << endl;
	total = _total;
	data = new int[total];
	srand((unsigned int)(time(NULL)));
	for (int i = 0; i < total; i++)
	{
		data[i] = rand();
	}
}

void Datalist::showDatalist()
{
	for (int i = 0; i < total; i++)
	{
		cout << data[i] << ' ';
	}
	cout << endl;
}

void Datalist::operator=(const Datalist& list)
{
	//cout << endl << "Address=" << this << "copy" << endl;
	total = list.total;
	data = new int[total];
	for (int i = 0; i < total; i++)
	{
		data[i] = list.data[i];
	}
}

int& Datalist::operator[](int i)
{
	return data[i];
}