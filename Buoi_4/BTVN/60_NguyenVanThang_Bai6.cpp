#include<iostream>
#include<iomanip>
using namespace std;

class SinhVien {
private:
	char maSV[15];
	char tenSV[30];
	char lop[50];
	int khoa;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void SinhVien::Nhap() {
	cout << "Nhap ma sinh vien : "; fflush(stdin); gets(maSV);
	cout << "Nhap ten sinh vien: "; fflush(stdin); gets(tenSV);
	cout << "Nhap lop          : "; fflush(stdin); gets(lop);
	cout << "Nhap khoa         : "; cin >> khoa;
} 
void SinhVien::Xuat() {
	cout << left << setw(14) << "Ma sinh vien: " << left << setw(16) << this->maSV << "Ten sinh vien: " << this->tenSV << endl;
	cout << left << setw(14) << "Lop: " << left << setw(16) << this->lop  << "Khoa: " << this->khoa << endl;
}


class Mon {
private:
	char tenMon[20];
	int soTrinh;
	float diem;
public:
	void Nhap();
	void Xuat();
	friend class Phieu;
};
void Mon::Nhap() {
	cout << "Nhap ten mon : "; fflush(stdin); gets(tenMon);
	cout << "Nhap so trinh: "; cin >> soTrinh;
	cout << "Nhap diem    : "; cin >> diem;
}
void Mon::Xuat() {
	cout << left << setw(20) << this->tenMon << setw(15) << this->soTrinh << setw(15) << this->diem << endl;
}


class Phieu {
private:
	SinhVien x;
	Mon *y;
	int n;
public:
	void Nhap();
	void Xuat();
};
void Phieu::Nhap() {
	x.Nhap();
	cout << "Nhap so mon: "; cin >> n;
	y = new Mon[n];
	for(int i = 0; i < n; i++){
		cout << endl << "Nhap thong tin mon " << i+1 << ": " << endl;
		y[i].Nhap();
	}
}
void Phieu::Xuat() {
	cout << endl << "----------------------------------------------" << endl;
	cout << "\t\tPHIEU BAO DIEM " << endl;
	x.Xuat();
	cout << "Bang diem: " << endl;
	cout << left << setw(20) << "Ten mon" << setw(15) << "So trinh" << setw(15) << "Diem" << endl;
	float tongdiem = 0, a = 0;
	int tongtrinh = 0;
	for(int i = 0; i < n; i++) {
		y[i].Xuat();
		a = y[i].diem * y[i].soTrinh;
		tongdiem += a;
		tongtrinh += y[i].soTrinh;
	}
	float tb = tongdiem/tongtrinh;
	cout << endl << right << setw(35) << "Diem trung binh: " << setprecision(3) << tb << endl;
}

int main() {
	Phieu ph;
	ph.Nhap();
	ph.Xuat();
	
	return 0;
}










