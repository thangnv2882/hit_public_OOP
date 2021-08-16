#include<iostream>
#include<iomanip>
using namespace std;

//class PS {
//private:
//	int TS, MS;
//public:
//	PS();
//	PS(int TSnew, int MSnew);
//	~PS();
//	void Xuat();
//};
//
//PS::PS() {
//	this->TS = 0;
//	this->MS = 1;
//}
//PS::~PS() {
//	this->TS = 0;
//	this->MS = 1;
//}
//PS::PS(int TS, int MS) {
//	this->TS = TS;
//	this->MS = MS;
//}
//void PS::Xuat() {
//	cout << "Ps: " << this->TS << "/" << this->MS << endl; 
//}
//
//int main() {
//	PS ps(3, 2);
//	//PS *p;
//	PS *p = &ps;
//	p->Xuat();
//	ps.Xuat();
//	
//	return 0;
//	
//}
//



class Hang {
private:
	char tenHang[20];
	float donGia;
	int soLuong;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};

class Phieu {
private:
	char maPhieu[10];
	char ngayLap[15];
	Hang *a;
	int n;
public:
	void Nhap();
	void Xuat();
};

void Hang::Nhap(){
	cout << "Nhap ten hang: ";  fflush(stdin); gets(tenHang);
	cout << "Nhap don gia: "; fflush(stdin); cin >> donGia;
	cout << "Nhap so luong: "; cin >> soLuong;
}
void Hang::Xuat(){
	cout << left << setw(12) << tenHang << setw(10) << donGia << setw(10) << soLuong << endl;
}

void Phieu::Nhap(){
	cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
	cout << "Nhap ngay lap: "; fflush(stdin); gets(ngayLap);
	cout << "Nhap so mat hang: "; cin >> n;
	a = new Hang[n];
	for(int i = 0; i < n; i++) {
		a[i].Nhap();
	}
}
void Phieu::Xuat(){
	cout << "Ma phieu: " << maPhieu << endl;
	cout << "Ngay lap: " << ngayLap << endl;
	cout << left << setw(12) << "Ten hang" << setw(10) << "Don gia" << setw(10) << "So luong" << endl;
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}

int main() {
	Phieu ph;
	ph.Nhap();
	cout << endl << "Xuat " << endl;
	ph.Xuat();
}
