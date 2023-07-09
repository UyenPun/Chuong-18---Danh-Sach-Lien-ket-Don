#include <iostream>
#include <list>
using namespace std;

void InPut(list<int> &l)
{
	// Thêm phần tử vào danh sách liên kết
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	// l.push_back <=> AddTail
	// l.push_front <=> AddHead
}

void OutPut(list<int> l)
{
	// Vòng lặp duyệt danh sách liên kết.
	for(list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << "   ";
	}
}

int TimMax(list<int> l)
{
	l.sort(); // sắp tăng dần
	return l.back(); // lấy số cuối cùng.
}

void LietKeSoChan(list<int> l)
{
	// a = b++
	// a = ++b
	for(list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		if(*it % 2 == 0)
		{
			cout << *it << "   ";
		}
	}
}

int main()
{
	list<int> l; // Khai báo danh sách liên kết
	InPut(l);
	OutPut(l);
	int  Max = TimMax(l);
	cout << "\nMax = " << Max << endl;

	LietKeSoChan(l);
	

	system("pause");
	return 0;
}