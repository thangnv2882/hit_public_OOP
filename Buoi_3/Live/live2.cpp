#include<iostream>
using namespace std;

class Student {
private:
	static int cnt;
	int maSV;
	char hoTen[30];
public:
	void Nhap();
	void Xuat();
	friend void Xuat(Student student);
};

void Student::Nhap() {
	cout << "Nhap cnt: "; cin >> cnt << endl;
	cout << "Ten: "; ci
}

void Xuat(Student student) {
	cout << "cnt: " << student.cnt << endl;
	cout << "Ma SV: " << student.hoTen << endl
}
