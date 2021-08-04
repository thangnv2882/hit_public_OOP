//Anh Huan

#include<iostream>
#include<string.h>

using namespace std;
/*
  access modifier: ph?m vi truy c?p
  private:
  protected: K? th?a
  public: 
  Hàm b?n, l?p b?n: 
*/
class Person {
private: 
  int sdt;
public:
  char hoTen[30];
};
class SinhVien {
private: //dóng gói d? li?u
  int maSV;
  char hoTen[30];
  int tuoi;
  double diemTB;
  bool gioiTinh; //true: nam  || false: n?
public: 
  SinhVien(); //Hàm kh?i t?o không d?i
  // SinhVien(int maSVNew);
  // SinhVien(int maSVNew, char hoTenNew[]);
  // SinhVien(int maSVNew, char hoTenNew[], int tuoiNew);
  SinhVien(int maSVNew, char hoTenNew[], double diemTBNNew);
  SinhVien(int maSVNew, char hoTenNew[], int tuoiNew, double diemTBNew, bool gioiTinhNew);//Hàm kh?i t?o có d?i - Ð?y d?
  ~SinhVien() {
    cout << "Sinh vien da ra truong" << endl;

  }; //t? d?ng g?i
  void Nhap();
  void Xuat();
};

SinhVien::SinhVien() {
  maSV = 0;
  strcpy(hoTen, "");
  tuoi = 0;
  diemTB = 0;
}

// SinhVien::SinhVien(int maSVNew, char hoTenNew[], int tuoiNew){
//   maSV = maSVNew;
//   strcpy(hoTen, hoTenNew);
//   tuoi = tuoiNew;
// }

SinhVien::SinhVien(int maSVNew, char hoTenNew[], int tuoiNew = 19, double diemTBNew = 0, bool gioiTinhNew = true){
  maSV = maSVNew;
  strcpy(hoTen, hoTenNew);
  tuoi = tuoiNew;
  diemTB = diemTBNew;
  gioiTinh = gioiTinhNew;
}

void SinhVien::Nhap() {
  cout << "Nhap ma sinh vien  : "; cin >> maSV;
  cout << "Nhap ten sinh vien : "; fflush(stdin);  gets(hoTen);
  cout << "Nhap tuoi sinh vien: "; cin >> tuoi;
  cout << "Nhap diem sinh vien: "; cin >> diemTB;
}

void SinhVien::Xuat() {
  cout << "Ma sinh vien: " << maSV << endl;
  cout << "Ten sinh vien: " << hoTen << endl;
  cout << "Tuoi: " << tuoi << endl;
  cout << "Diem trung binh: " << diemTB << endl;
}

int main() {
  SinhVien svA;


  return 0;
}




// Anh Trung
#include <bits/stdc++.h>
using namespace std;

class SinhVien
{
private:
    char MaSV[10]; //Thuoc tinh
    char HoTen[30];
    int Tuoi;
    float DiemTB;
    int n;
    int *a;

public:
    SinhVien();         // phuong thuc khoi tao khong doi so(khong co tham so)
    SinhVien( char MaSVNew[10], char HoTenNew[30],int TuoiNew, float DiemTBNew);	// phuong thuc khoi tao co doi(co tham so)
    ~SinhVien();	// phuong thuc huy
    void Nhap();	// phuong thuc nhap
    void Xuat();	// phuong thuc xuat
};

SinhVien::SinhVien()
{
    strcpy(MaSV, "");
    strcpy(HoTen, "");
    Tuoi = 0;
    DiemTB =0;
}

SinhVien::SinhVien(char MaSVNew[10], char HoTenNew[30],int TuoiNew, float DiemTBNew)
{
    strcpy(MaSV, MaSVNew);
    strcpy(HoTen, HoTenNew);
    Tuoi = TuoiNew;
    DiemTB = DiemTBNew;
}

SinhVien::~SinhVien()
{
    strcpy(MaSV, "");
    strcpy(HoTen, "");
    Tuoi = 0;
    DiemTB =0;
}


void SinhVien::Nhap()
{
    cout<<"Nhap MSV: ";         fflush(stdin);      gets(MaSV);       //  fflush(stdin)  - Xoa bo nho dem
    cout<<"Nhap ho ten: ";      fflush(stdin);      gets(HoTen); 
    cout<<"Nhap tuoi: ";        cin>>Tuoi;
    cout<<"Nhap diem TB: ";     cin>>DiemTB;
}

void SinhVien::Xuat()
{
    cout<<"MSV: "<<MaSV; 
    cout<<"\nHo ten: "<<HoTen;
    cout<<"\nTuoi: "<<Tuoi;
    cout<<"\nDiem TB: "<<DiemTB;
}


int main()
{
    SinhVien A;     // Khong doi
    SinhVien B( "123", " Nguyen Van A", 21, 10);    // co doi
//    A.Nhap();
    cout<<"Sinh Vien A: "<<endl;
    A.Xuat();

    cout<<"\nSinh Vien B: "<<endl;
    B.Xuat();
    return 0;
}

