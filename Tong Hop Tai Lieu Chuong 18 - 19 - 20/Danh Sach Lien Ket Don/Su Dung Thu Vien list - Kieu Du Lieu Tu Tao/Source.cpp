/* 
nhập xuất danh sách các học sinh trong lớp
và tìm ra học sinh có điểm trung bình lớn nhất lớp

biết thông tin mỗi học sinh gồm:
- mã số
- họ tên
- điểm toán, lý, hóa
*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

struct HocSinh
{
	string MaSo, HoTen;
	double DiemToan, DiemLy, DiemHoa;
};
typedef struct HocSinh HOCSINH;

void NhapHocSinh(HOCSINH &hs)
{
	fflush(stdin); // xóa bộ nhớ đệm.
	cout << "\nNhap vao ho ten: ";
	getline(cin, hs.HoTen);

	cout << "\nNhap diem toan: ";
	cin >> hs.DiemToan;

	cout << "\nNhap diem ly: ";
	cin >> hs.DiemLy;

	cout << "\nNhap diem hoa: ";
	cin >> hs.DiemHoa;
}

void XuatHocSinh(HOCSINH hs)
{
	cout << "\nMa so: " << hs.MaSo;
	cout << "\nHo ten: " << hs.HoTen;
	cout << "\nDiem toan = " << hs.DiemToan;
	cout << "\nDiem ly = " << hs.DiemLy;
	cout << "\nDiem hoa = " << hs.DiemHoa;
}

double TinhDiemTrungBinh(HOCSINH hs)
{
	return (hs.DiemToan + hs.DiemLy + hs.DiemHoa) / 3;
}

void NhapDanhSach(list<HOCSINH> &l, int n)
{
	for(int i = 1; i <= n; i++)
	{
		HOCSINH hs;
		bool Check;
		do{
			Check = true;
			fflush(stdin); // xóa bộ nhớ đệm.
			cout << "\nNhap vao ma so: ";
			getline(cin, hs.MaSo);

			// kiểm tra xem trước đó có bị trùng hay không ?
			for(list<HOCSINH> ::iterator it = l.begin(); it != l.end(); ++it)
			{
				// bị trùng
				if((*it).MaSo == hs.MaSo)
				{
					Check = false;
					break;
				}
			}
			if(Check == false)
			{
				cout << "\nMa so da bi trung. Xin kiem tra lai !";
			}
		}while(Check == false);

		NhapHocSinh(hs); // nhập học sinh

		l.push_back(hs); // đưa học sinh vào danh sách
	}
}

void XuatDanhSach(list<HOCSINH> l)
{
	int dem = 1;
	for(list<HOCSINH>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << "\nThong tin hoc sinh thu " << dem++;
		XuatHocSinh(*it);
	}
}

double TimDiemTrungBinhLonNhat(list<HOCSINH> l)
{
	list<HOCSINH>::iterator it;
	it = l.begin();
	double DiemMax = TinhDiemTrungBinh(*it);
	
	for(it++; it != l.end(); ++it)
	{
		double diem = TinhDiemTrungBinh(*it);
		if(diem > DiemMax)
		{
			DiemMax = diem;
		}
	}
	return DiemMax;
}

void LietKeTatCaHocSinhDiemCaoNhatLop(list<HOCSINH> l)
{
	double DiemMax = TimDiemTrungBinhLonNhat(l);

	for(list<HOCSINH>::iterator it = l.begin(); it != l.end(); ++it)
	{
		if(TinhDiemTrungBinh(*it) == DiemMax)
		{
			XuatHocSinh(*it);
			cout << "\n\n";
		}
	}
}



int main()
{
	int n;
	cout << "\nNhap vao so luong hoc sinh: ";
	cin >> n;

	list<HOCSINH> l;
	NhapDanhSach(l, n);
	XuatDanhSach(l);

	double DiemMax = TimDiemTrungBinhLonNhat(l);
	cout << "\nDiem max = " << DiemMax;

	cout << "\n\nDanh sach cac hoc sinh co diem lon nhat lop la\n";
	LietKeTatCaHocSinhDiemCaoNhatLop(l);

	system("pause");
	return 0;
}



