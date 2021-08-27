#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class Phieu;
class NhaCC {
private:
	char maNCC[10];
	char tenNCC[30];
	char diaChiNCC[50];
	char sdtNCC[15];
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
	cout << left << setw(17) << "Ma nha cung cap: " << setw(20) << this->maNCC << "Ten nha cung cap: " << this->tenNCC << endl;
	cout << "Dia chi: " << left << setw(28) << this->diaChiNCC  << "SDT: " << this->sdtNCC << endl;
}


class SanPham {
private:
	char maSP[10];
	char tenSP[30];
	int slSP;
	int donGia;
	
public:
	void Nhap();
	void Xuat();
	double GetThanhTien() {
		return slSP * donGia;
	}
	friend class Phieu;
	friend void DoiSP(Phieu ph);
};
void SanPham::Nhap() {
	cout << "Nhap ma san pham        : "; fflush(stdin); gets(maSP);
	cout << "Nhap ten san pham       : "; fflush(stdin); gets(tenSP);
	cout << "Nhap so luong san pham  : "; cin >> slSP;
	cout << "Nhap don gia            : "; cin >> donGia;
}
void SanPham::Xuat() {
	cout << left << setw(10) << this->maSP << setw(15) << this->tenSP << setw(15) << this->slSP << setw(15) << this->donGia << setw(15) << GetThanhTien() << endl;
}

class Phieu {
private:
	char maPhieu[10];
	char ngayLap[15];
	NhaCC x;
	SanPham *y;
	int n;
public:
	void Nhap();
	void Xuat();
	friend void Sx(Phieu ph);
	friend void Chen(Phieu &ph, SanPham x, int vt);
	friend void Xoa(Phieu &ph, int vt);
	friend void DoiSP(Phieu ph);
};
void Phieu::Nhap() {
	cout << "Nhap ma phieu      : "; fflush(stdin); gets(maPhieu);
	cout << "Nhap ngay lap phieu: "; fflush(stdin); gets(ngayLap);
	cout << "\nNhap thong tin nha cung cap: " << endl;
	x.Nhap();
	cout << "Nhap so san pham: "; cin >> n;
	y = new SanPham[n];
	for(int i = 0; i < n; i++){
		cout << endl << "Nhap thong tin san pham " << i+1 << ": " << endl;
		y[i].Nhap();
	}
}

void Phieu::Xuat() {
	cout << endl << "Dai hoc Victory." << endl;
	cout << "\t\tPHIEU NHAP VAN PHONG PHAM " << endl;
	cout <<  left << setw(17) << "Ma phieu: " << setw(20) << left << maPhieu << "Ngay lap: " << setw(10) << ngayLap << endl;
	x.Xuat();
	cout << endl << left << setw(10) << "Ma SP" << setw(15) << "Ten san pham" << setw(15) << "So luong" <<  setw(15) << "Don Gia" << setw(15) << "Thanh Tien" << endl;
	int sumMoney;
	for(int i = 0; i < n; i++) {
		y[i].Xuat();
		sumMoney += y[i].GetThanhTien();
	}
	cout << endl << right << setw(55) << "Tong so tien: " << sumMoney << endl;
	cout << endl << setw(12) << "Hieu truong" << setw(25) << "Phong tai chinh" << setw(23) << "Nguoi lap" << endl;
}
void Sx(Phieu ph) {
	for(int i = 0; i < ph.n-1; i++) {
		for(int j = i + 1; j < ph.n; j++) {
			if(ph.y[i].GetThanhTien() < ph.y[j].GetThanhTien()) {
				SanPham temp = ph.y[i];
				ph.y[i] = ph.y[j];
				ph.y[j] = temp;
			}
		}
	}
}
void Chen(Phieu &ph, SanPham x, int vt) {
	ph.y = (SanPham*)realloc(ph.y, (ph.n+1)*sizeof(SanPham));
	for(int i = ph.n; i >= vt; i--) {
		ph.y[i] = ph.y[i-1];
	}
	ph.y[vt-1] = x;
	ph.n++;
}
void Xoa(Phieu &ph, int vt) {
	//if else vi tri 
	for(int i = vt-1; i < ph.n-1; i++) {
		ph.y[i] = ph.y[i+1];
	}
	ph.y = (SanPham*)realloc(ph.y, (ph.n-1)*sizeof(SanPham));
	ph.n--;
}
void DoiSP(Phieu ph) {
	for(int i = 0; i < ph.n; i++) {
		if(ph.y[i].slSP < 10){
			ph.y[i].slSP = 10;
		}
	}
}

int main() {
	Phieu ph;
	ph.Nhap();
	ph.Xuat();
//	
////	Cau 2
//	Sx(ph);
//	cout << "\nPhieu sau khi sap xep la: " << endl;
//	ph.Xuat();
//	
////	Cau 3
//	cout << "\nNhap san pham can chen: " << endl;
//	SanPham x;
//	x.Nhap();
//	Chen(ph, x, 1);
//	cout << "\nPhieu sau khi chen them san pham la: ";
//	ph.Xuat();
	
//	Cau 4
	int vt;
	cout << "Nhap vi tri can xoa: "; cin >> vt;
	Xoa(ph, vt);
	cout << "\nPhieu sau khi xoa sp la: ";
	ph.Xuat();
	
//	Cau 5
	DoiSP(ph);
	cout << "Phieu sua khi thay doi san pham la." << endl;
	ph.Xuat();
	return 0;
}










