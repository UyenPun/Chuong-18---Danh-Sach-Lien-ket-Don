#include <iostream>
#include <stack>
using namespace std;

// "Nam Son" => noS maN

void InPut(stack<int> &s)
{
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
}

void OutPut(stack<int> &s)
{
	while(!s.empty())
	{
		int x = s.top();
		s.pop();
		printf("%4d", x);
	}
}

int main()
{
	stack<int> s;
	
	InPut(s);
	OutPut(s);
	
	system("pause");
	return 0;
}