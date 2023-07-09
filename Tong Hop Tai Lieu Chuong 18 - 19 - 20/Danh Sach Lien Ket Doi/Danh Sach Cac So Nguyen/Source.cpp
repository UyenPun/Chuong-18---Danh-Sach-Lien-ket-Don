/* 
7 bước căn bản luôn phải có trên danh sách liên kết đơn

Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết
Bước 2: Khởi tạo danh sách liên kết
Bước 3: Tạo Node trong danh sách liên kết
Bước 4: Thêm đầu/Thêm cuối trong danh sách liên kết
Bước 5: Viết hàm InPut/OutPut
Bước 6: Những xử lý yêu cầu cần có trên danh sách liên kết
Bước 7: Giải phóng danh sách liên kết

Làm demo trên danh sách liên kết đơn các số nguyên

*/
#include <stdio.h>
#include <conio.h>



/* Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết */
struct Node
{
	int data;
	struct Node *pNext;
	struct Node *pRev; // đây là điều khác biệt với dslk đơn
};
typedef struct Node NODE;

struct List
{
	NODE *pHead, *pTail;
};
typedef struct List LIST;
/* ---------------------------------------------------- */

// Bước 2: Khởi tạo danh sách liên kết
void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

// Bước 3: Tạo Node trong danh sách liên kết
NODE* GetNode(int DATA)
{
	NODE *p = new NODE; // Khởi tạo con trỏ p

	// Nếu trường hợp máy tính hết bộ nhớ.
	if(p == NULL)
	{
		printf("\nKhong du bo nho de cap phat con tro");
		getch();
		return NULL; // trả về rỗng.
	}
	p ->data = DATA; // Đưa data vào trong Node.
	p ->pNext = NULL; // Khởi tạo mối liên kết
	p ->pRev = NULL; // Khởi tạo mối liên kết - đây là điều khác biệt với dslk đơn
	return p; // Trả Node p về.
}

// Bước 4: Thêm Node p vào đầu/Thêm Node p vào cuối trong danh sách liên kết
void AddHead(LIST &l, NODE *p)
{
	// danh sách rỗng.
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // p vừa là đầu vừa là cuối.
	}
	else
	{
		p ->pNext = l.pHead; // Cho p trỏ tới đầu danh sách
		l.pHead ->pRev = p; // đây là điều khác biệt với dslk đơn
		l.pHead = p; // Cập nhật lại đầu danh sách
	}
}

void AddTail(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail ->pNext = p; // pTail trỏ Next tới p
		p ->pRev = l.pTail; // đây là điều khác biệt với dslk đơn
		l.pTail = p; // Cập nhật pTail chính là p
	}
}
/* ------------------------------------------------ */

/* Bước 5: Viết hàm InPut/OutPut */

void InPut(LIST &l)
{
	Init(l); // Khởi tạo danh sách.

	int n;
	printf("\nNhap vao so luong phan tu trong danh sach: ");
	scanf("%d", &n);

	// Vòng lặp chạy n lần, mỗi lần nhập dữ liệu cho 1 Node
	for(int i = 1; i <= n; i++)
	{
		int data;
		printf("\nNhap vao data: ");
		scanf("%d", &data);

		// Đóng gói data vào Node
		NODE *p; // Khai báo
		p = GetNode(data); // Cho con trỏ p trỏ tới Node được tạo ra.
		//AddHead(l, p); // Thêm  Node p vào đầu danh sách
		AddTail(l, p);
	}
}

// 3 4 5 7

void OutPut(LIST l)
{
	// for(int i = 0; i < n; i++)
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	//for(NODE *p = l.pTail; p != NULL; p = p ->pRev)
	{
		printf("%4d", p ->data);
	}
}

/* ------------------------------------------------------ */

/* Bước 6: Những xử lý yêu cầu cần có trên danh sách liên kết */

// Tính tổng danh sách
int TinhTong(LIST l)
{
	// for(int i = 0; i < n; i++)
	int tong = 0;
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		tong += p ->data;
	}
	return tong;
}

// Liệt kê các số chẵn trong danh sách
void LietKeSoChan(LIST l)
{
	printf("\nCac so chan co trong danh sach la: ");
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		if(p ->data % 2 == 0)
		{
			printf("%4d", p ->data);
		}
	}
}

// sắp xếp danh sách liên kết đơn tăng dần/giảm dần
void HoanVi(int &x, int &y)
{
	/*int temp = x;
	x = y;
	y = temp;*/
	x = x + y;
	y = x - y; // y = x
	x = x - y; // x = y
}

void SapXep(LIST &l, char phanloai)
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
			if(phanloai == 't')
			{
				if(p ->data > q ->data)
				{
					HoanVi(p ->data, q ->data);
				}
			}
			else if(phanloai == 'g')
			{
				if(p ->data < q ->data)
				{
					HoanVi(p ->data, q ->data);
				}
			}
		}
	}

}
//
// Thêm Node x vào đằng sau Node q
void ThemVaoSau(LIST &l, NODE *x, NODE *q)
{
	// chạy vòng lặp tìm ra quy
	for(NODE *p = l.pHead; p != l.pTail; p = p ->pNext)
	{
		if(p ->data == q ->data)
		{
			// Tìm thằng nằm đằng sau
			NODE *g = p ->pNext;
			x ->pNext = g;
			g ->pRev = x;
			p ->pNext = x;
			x ->pRev = p;
			return;
		}
	}

	if(l.pTail ->data == q ->data)
	{
		AddTail(l, x);
	}
}

// Thêm x vào đằng sau tất cả các số chẵn
void ThemSauTatCaSoChan(LIST &l, int phantuthemvao)
{
	for(NODE *p = l.pHead; p != l.pTail; p = p ->pNext)
	{
		if(p ->data % 2 == 0)
		{
			NODE *x = GetNode(phantuthemvao); // GetNode ở ngay bên trong để tạo ra Node mới
			
			// Thêm x vào sau p
			NODE *g = p ->pNext;
			x ->pNext = g;
			g ->pRev = x;
			p ->pNext = x;
			x ->pRev = p;
			p = p ->pNext; // bỏ qua không xét phần tử vừa thêm
		}
	}
	if(l.pTail ->data % 2 == 0)
	{
		NODE *x = GetNode(phantuthemvao); // GetNode ở ngay bên trong để tạo ra Node mới
		AddTail(l, x);
	}
}

// 1 2 3 4 5 
// p = 4

// Thêm Node x vào trước Node p
void ThemVaoTruoc(LIST &l, NODE *x, NODE *p)
{
	// Tìm Node nằm trước Node p => gọi là Node q
	NODE *q;
	if(p ->data == l.pHead ->data)
	{
		AddHead(l, x);
		return;
	}
	for(NODE *k = l.pHead; k != NULL; k = k ->pNext)
	{
		if(k ->data == p ->data)
		{
			NODE *q = k ->pRev; // q là node trước k
			x ->pNext = k;
			k ->pRev = x;

			q ->pNext = x;
			x ->pRev = q;
			return;
		}
	}
}
// 1 69 2 3 4 5
void ThemVaoTruocCacSoChan(LIST &l, int phantucanthem)
{
	NODE *q = l.pHead;
	for(NODE *p = l.pHead ->pNext; p != NULL; p = p ->pNext)
	{
		if(p ->data % 2 == 0)
		{
			NODE *q = p ->pRev;

			NODE *x = GetNode(phantucanthem);
			x ->pNext = p;
			p ->pRev = x;
			q ->pNext = x;
			x ->pRev = q;
		}
	}

	// Xét riêng phần tử đầu
	if(l.pHead ->data % 2 == 0)
	{
		NODE *g = GetNode(phantucanthem);
		AddHead(l, g);
	}
}

void XoaDau(LIST &l)
{
	if(l.pHead != NULL)
	{
		NODE *p = l.pHead;
		l.pHead = l.pHead ->pNext;
		delete p;

		if(l.pHead != NULL)
		{
			l.pHead ->pRev = NULL;
		}
	}
}
//
// Xóa Node nằm sau q
void XoaSauMotNode(LIST &l, NODE *q)
{
	for(NODE *p = l.pHead; p != l.pTail; p = p ->pNext)
	{
		if(p ->data == q ->data)
		{
			// NODE cần xóa gọi là k
			NODE *k = p ->pNext;

			p ->pNext = k ->pNext;
			k ->pNext ->pRev = p;
			delete k;
			return;
		}
	}
}

void XoaCuoi(LIST &l)
{
	if(l.pHead ->pNext == NULL)
	{
		XoaDau(l);
		return;
	}
	NODE *p = l.pTail;
	(p ->pRev) ->pNext = NULL;
	l.pTail = p ->pRev;
	delete p;
}

//// 2   7 8
void XoaHetTatCaSoChan(LIST &l)
{
	NODE *truoc = l.pHead; // Node nằm trước
	for(NODE *p = l.pHead ->pNext; p != l.pTail; p = p ->pNext)
	{
		if(p ->data % 2 == 0)
		{
			truoc = p ->pRev;

			// Xóa p
			// tìm Node nằm trước p và cho nó trỏ tới Node nằm sau p
			NODE *sau;
			sau = p ->pNext;
			p ->pRev = sau;
			truoc ->pNext = sau;
			sau ->pRev = truoc;
			delete p;
			p = truoc;

		}
	}

	if(l.pHead ->data % 2 == 0)
	{
		XoaDau(l);
	}

	if(l.pTail ->data % 2 == 0)
	{
		XoaCuoi(l);
	}
}
//
// sửa tất cả các số chẵn trong danh sách thành số 69
void SuaCacSoChan(LIST &l, int sothaythe)
{
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		if(p ->data % 2 == 0)
		{
			p ->data = sothaythe;
		}
	}
}


// Bước 7: Giải phóng danh sách liên kết
void GiaiPhong(LIST &l)
{
	NODE *p;
	while(l.pHead != NULL)
	{
		p = l.pHead; // Cho con trỏ p trỏ vào pHead
		l.pHead = l.pHead ->pNext; // pHead được trỏ sang Node bên cạnh
		delete p; // giải phóng con trỏ
	}
}

int main()
{
	LIST l; // Khai báo danh sách.
	InPut(l);
	OutPut(l);

	/*int tong = TinhTong(l);
	printf("\nTong = %d", tong);

	LietKeSoChan(l);

	printf("\nDanh sach sau khi sap xep tang la: ");
	SapXep(l, 't');
	OutPut(l);

	printf("\nDanh sach sau khi sap xep giam la: ");
	SapXep(l, 'g');
	OutPut(l);*/

	// Thêm 69 vào đằng sau 2
	/*NODE *q, *x;
	q = GetNode(2);
	x = GetNode(69);*/
	/*
	printf("\nThem 69 vao dang truoc 2: ");
	ThemVaoTruoc(l, x, q);
	OutPut(l);*/

	/*printf("\nThem x vao truoc tat ca so chan: ");
	ThemVaoTruocCacSoChan(l, 69);
	OutPut(l);*/

	/*printf("\nXoa cuoi danh sach: ");
	XoaCuoi(l);
	OutPut(l);*/

	/*printf("\nXoa Node nam sau 2: ");
	XoaSauMotNode(l, q);
	OutPut(l);*/

	/*printf("\nXoa het tat ca so chan: ");
	XoaHetTatCaSoChan(l);
	OutPut(l);*/

	/*printf("\nSua cac so chan thanh so 69: ");
	SuaCacSoChan(l, 69);
	OutPut(l);*/




	GiaiPhong(l); // Giải phóng danh sách
	// printf("\npTail = %d", l.pTail ->data);

	getch();
	return 0;
}