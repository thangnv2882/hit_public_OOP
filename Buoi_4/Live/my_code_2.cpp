#include<iostream>
#include<iomanip>
using namespace std;

class TaiSan {
private:
	char tenTS[30];
	int sl;
	char tinhTrang[10];
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};

void TaiSan::Nhap() {
	cout << "Nhap ten tai san: "; fflush(stdin); gets(tenTS);
	cout << "Nhap so luong: "; cin >> sl;
	cout < "Nhap tinh trang: "; fflush(stdin); gets(tinhTrang);
}
void TaiSan::Xuat() {
	cout << left << setw(30) << tenTS << setw(12) << sl << setw(12) << tinhTrang << endl;
}


class NhanVien {
private:
	char hoTen[30];
	char chucVu[20];
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};

void NhanVien::Nhap() {
	cout << "Nhap ten nhan vien:" << fflush(stdin); gets(hoTen);
	cout << "Nhap chuc vu nhan vien:" << fflush(stdin); gets(chucVu);
}
void NhanVien::Xuat() {
	cout << left << setw(20) << hoTen << setw(20) << chucVu << endl;
}

class Phong {
private:
	char maPH[12];
	char tenPH[15];
	char tenTP[30];
public:
	void Nhap();
	void Xuat();	
	friend class Phieu;
};
void Phong::Nhap() {
	
}
void Phong::Xuat() {
	cout << "Thong tin phong o day" << endl;
}

class Phieu {
private:
	char maPH[12];
	char ngay[12];
	NhanVien x;
	Phong y;
	TaiSan *z;
	int n;
public:
	void Nhap();
	void Xuat();		
};

void Phieu::Nhap() {
	cout << "Nhap ma phieu: "; fflush(stdin); gets(maPH);
	cout << "Nhap ngay kiem tra: "; fflush(stdin); gets(ngay);
	x.Nhap();
	y.Nhap();
	cout << "Nhap so tai san: "; cin >> n;
	z = new TaiSan[n];
	for(int i = 0; i < n; i++) {
		z[i].Nhap();
	}

}
void Phieu::Xuat() {
	cout << "\t\t\t PHIEU KIEM KE TAI SAN" << endl;
	cout << "Ma phieu: " << this->maPH << endl;
	cout << "Ngay kiem tra: " << this->ngay << endl;
	x.Xuat();
	y.Xuat();
	cout << left << setw(30) << "Ten tai san" << setw(12) << "So luong" << setw(12) << "Tinh trang" << endl;
	int sumTS = 0;
	for(int i = 0; i < n; i++) {
		z[i].Xuat();
		sumTS += z[i].sl;
	}
	cout << left << setw(20) << "So tai san da kiem ke: " << n << setw(15) << "Tong so luong: " << sumTS << endl;
}
int main(){
	Phieu ph;
	ph.Nhap();
	ph.Xuat();
	
	return 0;
}

