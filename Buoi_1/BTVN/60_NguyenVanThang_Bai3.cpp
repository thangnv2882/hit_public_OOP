#include<iostream>
using namespace std;

class CanBo{
	public:	
		char maCB[20];
		char hoTen[30];
		int ngaySinh;
		int soNgayLv;
	
		void Nhap();	
		int TinhLuong();
		void Xuat();
};

void CanBo::Nhap(){
	cout << "Nhap ma can bo: ";
	gets(maCB);
	fflush(stdin);
	cout << "Nhap ho ten: ";
	gets(hoTen);
	fflush(stdin);
	cout << "Ngay sinh: ";
	cin >> ngaySinh;
	cout << "So ngay lam viec trong 1 thang: ";
	cin >> soNgayLv;
}

int CanBo::TinhLuong(){
	return soNgayLv * 250000;
}
void CanBo::Xuat(){
	cout << "Ma can bo: " << maCB << endl;
	cout << "Ho ten: " << hoTen << endl;
	cout << "Ngay sinh: " << ngaySinh << endl;
	cout << "So ngay lam viec trong 1 thang: " << soNgayLv << endl;
	cout << "Luong cua can bo do trong 1 thang la: " << TinhLuong() << endl;
}

int main(){
	CanBo cb1;
	cout << "Nhap thong tin cua can bo. " << endl;
	cb1.Nhap();
	cout << endl << "Thong tin cua can bo vua nhap la: " << endl;
	cb1.Xuat();
	
	return 0;
}








