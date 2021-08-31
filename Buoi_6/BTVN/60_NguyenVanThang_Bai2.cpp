#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class NSX {
private:
	char tenNSX[20];
	char diaChi[50];
public:
	void Nhap();
	void Xuat();
	friend class HANG;
	friend class TIVI;
};
void NSX::Nhap() {
	cout << "Nhap thong tin nha san xuat: " << endl;
	cout << "Nhap ten    : "; fflush(stdin); gets(tenNSX);
	cout << "Nhap dia chi: "; fflush(stdin); gets(diaChi);
}
void NSX::Xuat() {
	cout << "Ten nha san xuat   : " << tenNSX << endl;
	cout << "Dia chi nha san xuat: " << diaChi << endl;
}

class DATE {
private:
	int ngay;
	int thang;
	int nam;
public:
	void Nhap();
	void Xuat();
	friend class TIVI;
};
void DATE::Nhap() {
	cout << "Nhap thoi gian nhap hang: " << endl;
	cout << "Nhap ngay : "; cin >> ngay;
	cout << "Nhap thang: "; cin >> thang;
	cout << "Nhap nam  : "; cin >> nam;
}
void DATE::Xuat() {
	cout << "Thoi gian nhap hang: " << ngay << "/" << thang << "/" << nam << endl;
}

class HANG {
protected:
	char tenHang[20];
	NSX x;
	float donGia;
public:
	HANG();
	void Nhap();
	void Xuat();
};
HANG::HANG() {
	strcpy(tenHang, "");
	strcpy(x.tenNSX, "");
	strcpy(x.diaChi, "");
	donGia = 0;
}
void HANG::Nhap() {
	cout << "Nhap ten hang: "; fflush(stdin); gets(tenHang);
	x.Nhap();
	cout << "Nhap don gia: "; cin >> donGia;
}
void HANG::Xuat() {
	cout << "Ten hang: " << tenHang << endl;
	cout << "Thong tin nha san xuat: " << endl;
	x.Xuat();
	cout << "Don gia: " << fixed << setprecision(5) << donGia << endl;
}

class TIVI : public HANG {
private:
	float kichThuoc;
	DATE ngayNhap;
public:
	TIVI();
	void Nhap();
	void Xuat();
};
TIVI::TIVI() : HANG() {
	kichThuoc = 0;
	ngayNhap.ngay = 0;
	ngayNhap.thang = 0;
	ngayNhap.nam = 0;
}
void TIVI::Nhap() {
	HANG::Nhap();
	cout << "Nhap kich thuoc: "; cin >> kichThuoc;
	ngayNhap.Nhap();
}
void TIVI::Xuat() {
	HANG::Xuat();
	cout << "Kich thuoc: " << fixed << setprecision(5) << kichThuoc << endl;
	ngayNhap.Xuat();
}

int main() {
	TIVI tv;
	tv.Nhap();
	cout << endl << "Thong tin tivi vua nhap." << endl;
	tv.Xuat();
	
	return 0;
}
