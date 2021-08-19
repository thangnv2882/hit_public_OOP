#include<iostream>
#include<iomanip>
using namespace std;

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
	Hang *y;
	int n;
public:
	void Nhap();
	void Xuat();
};
void Phieu::Nhap() {
	cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
	cout << "Nhap ngay lap: "; fflush(stdin); gets(ngayLap);
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
	cout << "Ma phieu: " << this->maPhieu << setw(20) << "Ngay lap: " << this->ngayLap << endl;
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










