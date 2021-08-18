#include<iostream>
#include<iomanip>
using namespace std;

class NhaCC {
private:
	char maNCC[10];
	char tenNCC[30];
	char diaChiNCC[50];
	int sdtNCC;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void NhaCC::Nhap() {
	cout << "Nhap ma nha cung cap           : "; fflush(stdin); gets(maNCC);
	cout << "Nhap ten nha cung cap          : "; fflush(stdin); gets(tenNCC);
	cout << "Nhap dia chi nha cung cap      : "; fflush(stdin); gets(diaChiNCC);
	cout << "Nhap so dien thoai nha cung cap: "; cin >> sdtNCC;
} 
void NhaCC::Xuat() {
	cout << "Ma nha cung cap: " << left << setw(32) << this->maNCC << "Ten nha cung cap: " << this->tenNCC << endl;
	cout << "Dia chi: " << left << setw(40) << this->diaChiNCC  << "SDT: " << this->sdtNCC << endl;
}


class SanPham {
private:
	char maSP[10];
	char tenSP[30];
	char tinhTrangSP[20];
	int slSP;
	int donGia;
	int thanhTien;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void SanPham::Nhap() {
	cout << "Nhap ma san pham        : "; fflush(stdin); gets(maSP);
	cout << "Nhap ten san pham       : "; fflush(stdin); gets(tenSP);
	cout << "Nhap tinh trang san pham: "; fflush(stdin); gets(tinhTrangSP);
	cout << "Nhap so luong san pham  : "; cin >> slSP;
	cout << "Nhap don gia            : "; cin >> donGia;
	thanhTien = donGia * slSP;
}
void SanPham::Xuat() {
	cout << left << setw(10) << this->maSP << setw(15) << this->tenSP << setw(15) << this->tinhTrangSP << setw(15) << this->slSP << setw(15) << this->donGia << setw(15) << this->thanhTien << endl;
}


class Phieu {
private:
	char maPhieu[10];
	NhaCC x;
	SanPham *y;
	int n;
public:
	void Nhap();
	void Xuat();
};
void Phieu::Nhap() {
	cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
	x.Nhap();
	cout << "Nhap so san pham: "; cin >> n;
	y = new SanPham[n];
	for(int i = 0; i < n; i++){
		cout << endl << "Nhap thong tin san pham " << i+1 << ": " << endl;
		y[i].Nhap();
	}
}
void Phieu::Xuat() {
	cout << endl << "----------------------------------------------" << endl;
	cout << endl << "Dai hoc Cong Nghiep Ha Noi." << endl;
	cout << "\t\tPHIEU NHAP THIET BI MAY TINH " << endl;
	cout << "Ma phieu: " << maPhieu << endl;
	x.Xuat();
	cout << endl << left << setw(10) << "Ma SP" << setw(15) << "Ten san pham" << setw(15) << "Tinh trang" << setw(15) << "So luong" <<  setw(15) << "Don Gia" << setw(15) << "Thanh Tien" << endl;
	int sumMoney;
	for(int i = 0; i < n; i++) {
		y[i].Xuat();
		sumMoney += y[i].thanhTien;
	}
	cout << endl << "Tong so san pham: " << left << setw(31) << n << "Tong so tien: " << sumMoney << endl;
}

int main() {
	Phieu ph;
	ph.Nhap();
	ph.Xuat();
	
	return 0;
}










