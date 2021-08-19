#include<iostream>
#include<iomanip>
using namespace std;

class NhaCC {
private:
	char maNCC[10];
	char tenNCC[30];
	char diaChiNCC[50];
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void NhaCC::Nhap() {
	cout << "Nhap ma nha cung cap     : "; fflush(stdin); gets(maNCC);
	cout << "Nhap ten nha cung cap    : "; fflush(stdin); gets(tenNCC);
	cout << "Nhap dia chi nha cung cap: "; fflush(stdin); gets(diaChiNCC);
} 
void NhaCC::Xuat() {
	cout <<left << setw(10) << "Ma NCC: " << left << setw(17) << this->maNCC << "Ten NCC: " << this->tenNCC << endl;
	cout << left << setw(10) << "Dia chi: " << this->diaChiNCC << endl;
}


class Hang {
private:
	char tenHang[20];
	float donGia;
	int sl;
	float thanhTien;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void Hang::Nhap() {
	cout << "Nhap ten hang: "; fflush(stdin); gets(tenHang);
	cout << "Nhap don gia : "; cin >> donGia;
	cout << "Nhap so luong: "; cin >> sl;
	thanhTien = donGia * sl;
}
void Hang::Xuat() {
	cout << left << setw(15) << this->tenHang<< setw(15) << this->donGia << setw(15) << this->sl << setw(15) << this->thanhTien << endl;
}


class Phieu {
private:
	char maPhieu[10];
	char ngayLap[12];
	NhaCC x;
	Hang *y;
	int n;
public:
	void Nhap();
	void Xuat();
};
void Phieu::Nhap() {
	cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
	cout << "Nhap ngay lap: "; fflush(stdin); gets(ngayLap);
	x.Nhap();
	cout << "Nhap so san pham: "; cin >> n;
	y = new Hang[n];
	for(int i = 0; i < n; i++){
		cout << endl << "Nhap thong tin san pham " << i+1 << ": " << endl;
		y[i].Nhap();
	}
}
void Phieu::Xuat() {
	cout << endl << "----------------------------------------------" << endl;
	cout << "\t\tPHIEU NHAP HANG " << endl;
	cout << left << setw(10) << "Ma phieu: " << this->maPhieu << right << setw(26) << "Ngay lap: " << this->ngayLap << endl;
	x.Xuat();
	cout << left << setw(15) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(15) << "Thanh tien" << endl;
	float sumMoney;
	for(int i = 0; i < n; i++) {
		y[i].Xuat();
		sumMoney += y[i].thanhTien;
	}
	cout << endl << setw(45) << right << "Cong thanh tien: " << sumMoney << endl;
}

int main() {
	Phieu ph;
	ph.Nhap();
	ph.Xuat();
	
	return 0;
}










