#include<iostream>
#include<string.h>
using namespace std;

class Date {
private:
  int day, month, year;
public:
  void Xuat();
  //h�m b?n
  friend void Nhap(Date &ngaySinh);
};
void Date::Xuat() {
  cout << day << "/" << month << "/" << year << endl;
}

void Nhap(Date &ngaySinh) {
  cout << "Nhap ngay sinh: "; cin >> ngaySinh.day;
  cout << "Nhap thang sinh: "; cin >> ngaySinh.month;
  cout << "Nhap nam sinh: "; cin >> ngaySinh.year;
}

int main () {
  Date date;
  Nhap(date);

  date.Xuat();
  
  return 0;
}
/*
  - Nhap(Date &ngaySinh) y�u c?u truy xu?t d?n c�c thu?c t�nh c?a Date
  -> Cho Nhap(Date &ngaySinh) l�m b?n c?a class Date
*/
