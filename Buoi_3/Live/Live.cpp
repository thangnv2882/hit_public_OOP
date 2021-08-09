#include<iostream>
using namespace std;

//Quan he ket tap: Date ngay sinh la 1 thuoc tinh cua Student.
// Class Date ket tap vao Student

class Date {
private:
	int day, month, year;
public:
	Date();
	Date(int d, int m, int y);
	void Xuat();
	void Nhap();
};

Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}

void Date::Nhap() {
	cout << "Nhap ngay: "; cin >> day;
	cout << "Nhap thang: "; cin >> month;
	cout << "Nhap nam: "; cin >> year;
}
void Date::Xuat() {
	cout << day << "/" << month << "/" << year << endl;
}

class Student {
private:
	char maSV[30];
	char hoTen[30];
	Date ngaySinh;
public:
	void Xuat();
	void Nhap();
};

void Student::Nhap() {
	cout << "Nhap ma sinh vien: "; fflush(stdin); gets(maSV);
	cout << "Nhap ten sinh vien: "; fflush(stdin); gets(hoTen);
	ngaySinh.Nhap();
}

void Student::Xuat() {
	cout << "Ma sinh vien: " << maSV << endl;
	cout << "Ten sinh vien: " << hoTen << endl;
	cout << "Ngay sinh: ";
	ngaySinh.Xuat();
}
int main(){
	Student svA;
	svA.Nhap();
	cout << "Thong tin sinh vien A la." << endl;
	svA.Xuat();
	
	return 0;
}


