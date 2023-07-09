#include <stdio.h>
#include <conio.h>

// 1: Khai báo cấu trúc dữ liệu danh sách liên kết đơn các số nguyên

struct Node
{
	int Data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

// 2. Khởi tạo danh sách liên kết đơn
void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

// 3. Tạo Node trong danh sách
NODE* GetNode(int x) // x chính là dữ liệu đưa vào Data
{
	// Cấp phát 1 Node
	NODE *p = new NODE;

	if(p == NULL)
	{
		return NULL;
	}
	p->Data = x; // Lưu x vào data
	p ->pNext = NULL; // Khởi tạo mối liên kết
	return p;
}

// 4. Thêm Node (thêm đầu hoặc cuối)

// 1 2 3 4 5 : Thêm cuối
// 5 4 3 2 1 : Thêm đầu

// Thêm Node p vào đầu danh sách
void AddHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL) // Tức là danh sách bị rỗng
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p ->pNext = l.pHead; // p quăng dây để tham gia vào danh sách
		l.pHead = p; // p chính thức đã đứng dầu danh sách
	}
}

// Thêm Node p vào cuối danh sách
void AddTail(LIST &l, NODE *p)
{
	if(l.pHead == NULL) // Tức là danh sách bị rỗng
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail ->pNext = p; // l.pTail quăng dây nối với p
		l.pTail = p;
	}
}

// 5. Nhập dữ liệu cho danh sách
void InPut(LIST &l, int n)
{
	
	Init(l); // Khởi tạo danh sách.
	for(int i = 1; i <= n; i++)
	{
		// Mỗi lần vòng lặp chạy là ta nhập 1 Node
		int x;
		printf("\nNhap vao data: ");
		scanf("%d", &x);

		NODE *p = GetNode(x); // Đưa data vào Node p, tạo ra node p
		AddTail(l, p); // Thêm Node p vào cuối danh sách.
		//AddHead(l, p);
	}
}

void OutPut(LIST l)
{
	// for(int i = 0; i < n; i++)
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		printf("%4d", p ->Data);
	}
}

int TimMax(LIST l)
{
	/*
	int Max = a[0]
	for(int i = 1; i < n; i++)
	{
		if(a[i] > Max)
		{
			Max = a[i];
		}
	}
	*/
	int Max = l.pHead->Data;
	for(NODE *p = l.pHead ->pNext; p != NULL; p = p ->pNext)
	{
		if(p->Data > Max)
		{
			Max = p->Data;
		}
	}
	return Max;
}

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void Sort(LIST &l)
{
	/*
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
	*/
	for(NODE *p = l.pHead; p != l.pTail; p = p ->pNext)
	{
		for(NODE *q = p ->pNext; q != NULL; q = q ->pNext)
		{
			if(p->Data > q->Data)
			{
				HoanVi(p->Data, q->Data);
			}
		}
	}

}

int TinhSum(LIST l)
{
	int sum = 0;
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		sum += p ->Data;
	}
	return sum;
}

// Thêm 1 Node p vào sau 1 Node q
void ThemSau(LIST &l, NODE *p, NODE *q)
{
	for(NODE *k = l.pHead; k != NULL; k = k ->pNext)
	{
		if(k->Data == q->Data) // Tìm thấy q nè
		{
			NODE *g = k ->pNext;
			k ->pNext = p;
			p ->pNext = g;
			return; // Kết thúc
		}
	}
}

/*
xóa đầu
xóa cuối
xóa sau 1 Node bất kỳ
*/

void XoaDau(LIST &l)
{
	NODE *p = l.pHead; // p trỏ vào đầu
	l.pHead = l.pHead ->pNext; // đầu trốn sang bên cạnh
	delete p; // giải phóng p
}

void XoaCuoi(LIST &l)
{
	NODE *p; // p sẽ là Node nằm trước Tail tìm thấy
	for(NODE *k = l.pHead; k != NULL; k = k ->pNext)
	{
		if(k == l.pTail)
		{
			l.pTail = p;
			l.pTail ->pNext = NULL;
			delete k;
			return;
		}
		p = k;
	}
}

// Xóa Node nằm sau Node q trong danh sách
void XoaSauMotNode(LIST &l, NODE *q)
{
	NODE *g; // Node nằm sau q
	for(NODE *k = l.pHead; k != NULL; k = k ->pNext)
	{
		// tìm q
		if(k ->Data == q ->Data) // q bây giờ chính là k nè
		{
			g = k ->pNext;
			k ->pNext = g ->pNext;
			delete g;
			return;
		}
	}
}

void XoaNodeKhoaBatKy(LIST &l, int data)
{
	if(l.pHead->Data == data)
	{
		XoaDau(l);
		return;
	}

	if(l.pTail->Data == data)
	{
		XoaCuoi(l);
		return ;
	}

	NODE *q;
	// Nếu Node cần xóa không phải đầu hoặc cuối
	// Tìm ra Node nằm trước Node có khóa cần xóa => gọi hàm xóa Node sau cái Node vừa tìm thấy
	for(NODE *g = l.pHead; g != NULL; g = g ->pNext)
	{
		if(g ->Data == data)
		{
			XoaSauMotNode(l, q);
			return;
		}
		q = g;
	}
	
}

void GiaiPhong(LIST &l)
{
	NODE *p; // Khai báo Node p.
	while(l.pHead != NULL)
	{
		p = l.pHead; // Cho p trỏ tới Head
		l.pHead = l.pHead ->pNext; // Head trốn sang thằng bên cạnh
		delete p; // giải phóng p (cũng chính là giải phóng Head ban đầu)
	}
}

// Tìm thấy trả về 1, không thấy trả về 0
int TimKiem(LIST l, int data)
{
	for(NODE *q = l.pHead; q != NULL; q = q ->pNext)
	{
		if(q ->Data == data)
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	LIST l;
	int n;
	printf("\nBan muon nhap bao nhieu Node: ");
	scanf("%d", &n);
	InPut(l, n);
	OutPut(l);

	int Max = TimMax(l);
	printf("\nMax la: %d", Max);

	Sort(l);
	printf("\nDanh sach sau khi sap xep la\n");
	OutPut(l);

	int Tong = TinhSum(l);
	float TBC = (float)Tong / n;
	printf("\nTBC la: %f", TBC);

	/*int q, p;
	printf("\nNhap q: ");
	scanf("%d", &q);

	NODE *Q = GetNode(q);

	printf("\nNhap p: ");
	scanf("%d", &p);

	NODE *P = GetNode(p);

	ThemSau(l, P, Q);

	printf("\nDanh sach sau khi them: ");
	OutPut(l);*/

	//XoaDau(l);
	//XoaCuoi(l);

	/*int q;
	printf("\nNhap q: ");
	scanf("%d", &q);

	NODE *Q = GetNode(q);

	

	XoaSauMotNode(l, Q);*/

	/*int data;
	printf("\nNhap khoa bat ky: ");
	scanf("%d", &data);

	XoaNodeKhoaBatKy(l, data);

	printf("\nDanh sach sau khi xoa la\n");
	OutPut(l);*/

	int data;
	printf("\nNhap khoa bat ky: ");
	scanf("%d", &data);

	int Check = TimKiem(l, data);
	if(Check == 1)
	{
		printf("\nTim thay");
	}
	else
	{
		printf("\nKhong tim thay");
	}

	GiaiPhong(l); // giải phóng danh sách.


	getch();
	return 0;
}