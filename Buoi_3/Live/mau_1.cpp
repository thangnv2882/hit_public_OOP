#include<iostream>

using namespace std;

class Student;

class Date {
private:
  int day, month, year;
public:
  Date();
  Date(int d, int m , int y);
  void Xuat();
  friend class Student;
};

Date::Date() {
  day = month = year = 0;
}

Date::Date(int d, int m , int y) {
  day = d;
  month = m;
  year = y;
}

Date getDate() {
  return Date(1, 2, 2001);
}

// void Date::Nhap() {
//   cout << "Nhap ngay : "; cin >> day;
//   cout << "Nhap thang: "; cin >> month;
//   cout << "Nhap nam  : "; cin >> year;
// }

void Date::Xuat() {
  cout << day << "/" << month << "/" << year << endl;
}

class Student {
private:
  char maSV[30], hoTen[30];
  // char ngaySinh[30];//01/01/2001
  Date ngaySinh;
public: 
  void Nhap();
  void Xuat();
};

void Student::Nhap() {
  cout << "Nhap ma sinh vien : "; fflush(stdin); gets(maSV);
  cout << "Nhap ten sinh vien: "; fflush(stdin); gets(hoTen);
  cout << "Nhap ngay sinh: "; cin >> ngaySinh.day;
  cout << "Nhap thang sinh: "; cin >> ngaySinh.month;
  cout << "Nhap nam sinh: "; cin >> ngaySinh.year;
}

void Student::Xuat() {
  cout << "Ma sinh vien : " << maSV << endl;
  cout << "Ten sinh vien: " << hoTen << endl;
  cout << "Ngay sinh    : ";
  ngaySinh.Xuat();
}

// int main() {
//   Student svA;
//   svA.Nhap();
//   cout << "\nThong tin sinh vien: " << endl;
//   svA.Xuat();

//   return 0;
// }

/*
  class Date {
    friend class Student;
  }
  class Student {
  }
  -> Student l� b?n c?a Date: c� th? truy xu?t d?n c�c thu?c t�nh c?a Date
  -> Date kh�ng ph?i l� b?n c?a Student: kh�ng th? truy xu?t d?n c�c thu?c t�nh c?a Student
  T�m T?t(friend class): Khi ngaySinh c?a Student y�u c?u truy c?p d?n thu?c t�nh c?a ngaySinh 
          -> �? c�c thu?c t�nh c?a ngaySinh l� public
          -> Khai b�o Student l� b?n c?a class Date
  T�m T?t(friend function): Khi 1 function m� y�u c?u truy c?p d?n thu?c t�nh c?a d?i tu?ng n�o d�
          -> �?i tu?ng d?y ph?i chuy?n access modifier th�nh public
          -> Khai b�o h�m l� b?n c?a class d?y -> truy c?p du?c
*/
