#include<iostream>
#include<iomanip>
using namespace std;

class DATE {
private:
	int day;
	int month;
	int year;
public:
	void Nhap();
	void Xuat();
	friend class NHANSU;
};
void DATE::Nhap() {
	cout << "Nhap ngay sinh : "; cin >> day;
	cout << "Nhap thang sinh: "; cin >> month;
	cout << "Nhap nam sinh  : "; cin >> year;
}
void DATE::Xuat() {
	cout << this->day << "/" << this->month << "/" << this->year;
}


class NHANSU {
private:
	int id;
	char hoTen[30];
	DATE NS;
public:
	NHANSU();
	static int maNS;
	void Nhap();
	void Xuat();
};

int NHANSU::maNS = 1;

NHANSU::NHANSU() {
	this->id = NHANSU::maNS;
	NHANSU::maNS++;
}
void NHANSU::Nhap() {
	cout << "Nhap ho ten: "; fflush(stdin); gets(hoTen);
	NS.Nhap();
}
void NHANSU::Xuat() {
//	maNS++;
	cout << left << setw(12) << this->id << setw(20) << this->hoTen;
	NS.Xuat();
	cout << endl;
}


int main() {
	NHANSU *x;
	int n;
	cout << "Nhap so nhan su: "; cin >> n;
	x = new NHANSU[n];
	for(int i = 0; i < n; i++) {
		cout << endl << "Nhap thong tin nhan su " << i+1 << "." << endl;
		x[i].Nhap();
	}
	cout << endl << "----------------------------------------" << endl;
	cout << left << setw(12) << "Ma nhan su" << setw(20) << "Ho ten" << setw(12) << "Ngay sinh" << endl;
	for(int i = 0; i < n; i++) {
		x[i].Xuat();
	}
	
	return 0;
}
