#include <iostream>
#include <stack>
using namespace std;

struct Sach
{
	char TenSach[30];
	char NhaXuatBan[30];
	int GiaBan;
};
typedef struct Sach SACH;

void NhapSach(SACH &sach)
{
	fflush(stdin);
	printf("\nNhap vao ten sach: ");
	gets(sach.TenSach);

	fflush(stdin);
	printf("\nNhap vao ten nha xuat ban: ");
	gets(sach.NhaXuatBan);

	printf("\nNhap vao gia ban: ");
	scanf("%d", &sach.GiaBan);
}

void XuatSach(SACH sach)
{
	printf("\nTen sach: %s", sach.TenSach);
	printf("\nNha xuat ban: %s", sach.NhaXuatBan);
	printf("\nGia ban: %d", sach.GiaBan);
}

void InPut(stack<SACH> &s)
{
	SACH a, b;
	NhapSach(a);
	NhapSach(b);

	s.push(a);
	s.push(b);
}

void OutPut(stack<SACH> &s)
{
	while(!s.empty())
	{
		SACH x = s.top();
		XuatSach(x);
		s.pop();
	}
}

int main()
{
	stack<SACH> s;
	InPut(s);
	OutPut(s);

	system("pause");
	return 0;
}