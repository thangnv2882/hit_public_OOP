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
  -> Student là b?n c?a Date: có th? truy xu?t d?n các thu?c tính c?a Date
  -> Date không ph?i là b?n c?a Student: không th? truy xu?t d?n các thu?c tính c?a Student
  Tóm T?t(friend class): Khi ngaySinh c?a Student yêu c?u truy c?p d?n thu?c tính c?a ngaySinh 
          -> Ð? các thu?c tính c?a ngaySinh là public
          -> Khai báo Student là b?n c?a class Date
  Tóm T?t(friend function): Khi 1 function mà yêu c?u truy c?p d?n thu?c tính c?a d?i tu?ng nào dó
          -> Ð?i tu?ng d?y ph?i chuy?n access modifier thành public
          -> Khai báo hàm là b?n c?a class d?y -> truy c?p du?c
*/
