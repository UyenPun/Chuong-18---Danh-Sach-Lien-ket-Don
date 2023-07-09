/* 
B1: Khai báo cấu trúc dữ liệu
B2: Khởi tạo
B3: Tạo Node
B4: Thêm Node vào cấu trúc
B5: InPut/OutPut
B6: Xử lý gì đó
B7: Giải Phóng
*/
#include <stdio.h>
#include <conio.h>

/* ================== B1: Khai Báo ==================== */
struct Node
{
	int Data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct Stack
{
	NODE *Top;
};
typedef struct Stack STACK;
/* =================================================== */

/* ============= B2: Khởi Tạo ================= */

void Init(STACK &s)
{
	s.Top = NULL;
}

/* =================================================== */

/* ============= B3: Tạo Node ================= */

NODE *GetNode(int DATA)
{
	NODE *p = new NODE();
	if(p == NULL)
	{
		printf("\nKhong du bo nho de cap phat !");
		getch();
		return NULL;
	}
	p ->Data = DATA; // bỏ Data vào trong Node p
	p ->pNext = NULL; // Thiết lập mối liên kết
	return p; // trả Node p về
}
/* =================================================== */


/* 
Cần tạo ra 4 hàm sau đây:
1/ Kiểm tra Stack có rỗng hay không ?
2/ Push => Thêm 1 Node vào (AddHead/AddTail)
3/ Pop => Xóa Node đầu tiên (Giải Phóng)
4/ Top => Xem Node đầu tiên
*/

// if(a > b)

// Nếu Stack rỗng trả về true, ngược lại trả về false
bool KiemTraStackRong(STACK s)
{
	if(s.Top == NULL)
	{
		return true; // rỗng
	}
	return false; // không rỗng
}

// Thêm Node p vào Stack. Thành công trả về true, thất bại trả về false
bool Push(STACK &s, NODE *p)
{
	if(p == NULL)
	{
		return false;
	}

	// trường hợp danh sách không có gì => p là Node duy nhất
	if(s.Top == NULL)
	{
		s.Top = p;
	}
	else
	{
		p ->pNext = s.Top;
		s.Top = p;
	}
	return true; // thành công
}

// Pop (xóa đầu Stack) thành công => trả về true
bool Pop(STACK &s)
{
	NODE *p = s.Top; // Cho 1 con trỏ p trỏ tới s.Top
	s.Top = s.Top ->pNext; // Cập nhật lại s.Top là Node kế tiếp
	delete p; 
	return true;
}

int Top(STACK s)
{
	return s.Top ->Data;
}

void InPut(STACK &s)
{
	Init(s); // Khởi tạo Stack

	int n; // số lượng Node cần nhập
	printf("\nNhap vao so luong Node: ");
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		int DATA;
		printf("\nNhap vao Node thu %d: ", i);
		scanf("%d", &DATA);

		NODE *p = GetNode(DATA); // Bỏ DATA vào trong Node
		Push(s, p); // Bỏ Node p vào trong Stack
	}
}

// OutPut cũng đồng thời giải phóng khi lấy ra từng Node
void OutPut(STACK &s)
{
	// Vòng lặp sẽ lặp liên tục khi mà Stack không bị rỗng
	while(!KiemTraStackRong(s))
	{
		int x = Top(s); // gán data của top sang x
		Pop(s); // Delete top đi
		printf("%4d", x);
	}
}

void DoiHe(STACK &s, int socandoi, int hecandoi)
{
	Init(s);

	while(socandoi != 0)
	{
		int data = socandoi % hecandoi;
		socandoi /= hecandoi;
		NODE *p = GetNode(data);
		Push(s, p);
	}
}

void XuatHe(STACK s)
{
	while(!KiemTraStackRong(s))
	{
		int x = Top(s);
		Pop(s);
		if(x < 10)
		{
			printf("%2d", x);
		}
		else if(x == 10)
		{
			printf(" A ");
		}
		else if(x == 11)
		{
			printf(" B ");
		}
		else if(x == 12)
		{
			printf(" C ");
		}
		else if(x == 13)
		{
			printf(" D ");
		}
		else if(x == 14)
		{
			printf(" E ");
		}
		else if(x == 15)
		{
			printf(" F ");
		}
	}
}

int main()
{
	STACK s;
	//InPut(s);
	//OutPut(s);

	DoiHe(s, 250, 16);
	XuatHe(s);
	



	getch();
	return 0;
}