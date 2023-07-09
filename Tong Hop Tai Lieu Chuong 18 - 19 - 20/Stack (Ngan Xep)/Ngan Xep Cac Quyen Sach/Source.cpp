/* 
B1: Khai báo cấu trúc dữ liệu
B2: Khởi tạo
B3: Tạo Node
B4: Thêm Node vào cấu trúc
B5: InPut/OutPut
B6: Xử lý gì đó
B7: Giải Phóng
*/

/* STACK CÁC QUYỂN SÁCH */

#include <stdio.h>
#include <conio.h>

/* ================== B1: Khai Báo ==================== */

struct Sach
{
	char TenSach[30];
	char NhaXuatBan[30];
	int GiaBan;
};
typedef struct Sach SACH;

struct Node
{
	SACH Data;
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

NODE *GetNode(SACH DATA)
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

SACH Top(STACK s)
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
		
		SACH DATA;
		printf("\nNhap vao quyen sach thu %d\n", i);
		NhapSach(DATA);

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
		SACH x = Top(s); // gán data của top sang x
		Pop(s); // Delete top đi
		
		XuatSach(x);
	}
}

int main()
{
	STACK s;
	InPut(s);
	OutPut(s);

	getch();
	return 0;
}