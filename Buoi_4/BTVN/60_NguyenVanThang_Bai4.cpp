#include<iostream>
#include<iomanip>
using namespace std;

class DiaChi {
private:
	char soNha[10];
	char ngo[20];
	char pho[20];
	char phuong[20];
	char quan[20];
	char thanhPho[20];
public:
	void Nhap();
	void Xuat();
	friend class NguoiDiCho;
};
void DiaChi::Nhap() {
	cout << "Nhap so nha   : "; fflush(stdin); gets(soNha);
	cout << "Nhap ngo      : "; fflush(stdin); gets(ngo);
	cout << "Nhap pho      : "; fflush(stdin); gets(pho);
	cout << "Nhap phuong   : "; fflush(stdin); gets(phuong);
	cout << "Nhap quan     : "; fflush(stdin); gets(quan);
	cout << "Nhap thanh pho: "; fflush(stdin); gets(thanhPho);
}
void DiaChi::Xuat() {
	cout << "Dia chi: So " << this->soNha << ", ngo " << this->ngo << ", pho " << this->pho << ", phuong " << this->phuong << endl;
	cout << "quan " << this->quan << ", Thanh Pho " << this->thanhPho << "." << endl;
}


class NguoiDiCho {
private:
	char hoTen[30];
	char sdt[15];
	DiaChi dc;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void NguoiDiCho::Nhap() {
	cout << "Nhap ho ten nguoi di cho: "; fflush(stdin); gets(hoTen);
	cout << "Nhap so dien thoai: "; fflush(stdin); gets(sdt);
	dc.Nhap();
}
void NguoiDiCho::Xuat() {
	cout << "Ho va ten nguoi di cho: " << this->hoTen << endl;
	cout << "So dien thoai: " << this->sdt << endl;
	dc.Xuat();
}


class Hang {
private:
	char tenHang[10];
	int donGia;
	int soLuong;
	int thanhTien;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void Hang::Nhap() {
	cout << "Nhap ten hang: "; fflush(stdin); gets(tenHang);
	cout << "Don gia: "; cin >> donGia;
	cout << "So luong: "; cin >> soLuong;
	thanhTien = donGia * soLuong;
}
void Hang::Xuat() {
	cout << left << setw(15) << this->tenHang << setw(12) << this->donGia << setw(12) << this->soLuong << setw(12) << this->thanhTien << endl;
}

class Phieu {
private:
	char maPhieu[10];
	char ngay[12];
	NguoiDiCho x;
	Hang *y;
	int n;
public:
	void Nhap();
	void Xuat();
};
void Phieu::Nhap() {
	cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
	cout << "Nhap ngay: "; fflush(stdin); gets(ngay);
	x.Nhap();
	cout << "Nhap so mat hang: "; cin >> n;
	y = new Hang[n];
	for(int i = 0; i < n; i++) {
		cout << endl << "Nhap thong tin mat hang " << i+1 << endl;
		y[i].Nhap();
	}
}
void Phieu::Xuat() {
	cout << endl << "----------------------------------------------" << endl;
	cout << endl << "\t\tPHIEU DI CHO" << endl;
	cout << "Ma Phieu: " << maPhieu << setw(30) << "Ngay: " << ngay << endl;
	x.Xuat();
	int sum;
	cout << left << setw(15) << "Ten hang" << setw(12) << "Don gia" << setw(12) << "So luong" << setw(12) << "Thanh tien" << endl;
	for(int i = 0; i < n; i++) {
		y[i].Xuat();
		sum += y[i].thanhTien;
	}
	cout << right << setw(39) << "Cong thanh tien: " << sum << endl;
	cout << "Luu y: Phieu chi co tac dung trong BTVN buoi 4 cua lop OOP 2021.";
}
int main() {
	Phieu ph;
	ph.Nhap();
	ph.Xuat();
	
	return 0;
}
