#include<iostream>
#include<iomanip>
using namespace std;

class Employee {
private:
	char id[15];
	char name[25];
	int age;
	static float salary;
public:
	void Nhap();
	void Xuat();
};

float Employee::salary = 5000000;

void Employee::Nhap() {
	cout << "Nhap ID nhan vien: "; fflush(stdin); gets(id);
	cout << "Nhap ten nhan vien: "; fflush(stdin); gets(name);
	cout << "Nhap tuoi nhan vien: "; cin >> age;
}

void Employee::Xuat(){
	cout << "ID nhan vien: " << id << endl;
	cout << "Ten nhan vien: " << name << endl;
	cout << "Tuoi nhan vien: " << age << endl;
	cout << "Luong nhan vien: " << fixed << setprecision(2) << salary << " VND."<< endl;
}
int main(){
	Employee nv1, nv2;
	cout << "Nhap thong tin nhan vien 1." << endl;
	nv1.Nhap();
	cout << endl << "Nhap thong tin nhan vien 2." << endl;
	nv2.Nhap();
	cout << endl << "Thong tin nhan vien 1. " << endl;
	nv1.Xuat();
	cout << endl << "Thong tin nhan vien 2. " << endl;
	nv2.Xuat();
	
	return 0;
}
