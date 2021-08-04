#include<iostream>
#include<math.h>
#include<string.h>
#include<iomanip>
using namespace std;

class Hang{
	private:
		char maHang[10];
		char tenHang[30];
		char ngayNhap[15];
		char NSX[15];
		
	public:
		float donGia;
		int soLuong;
		void Nhap();
		void Xuat();
		Hang();
		Hang(char maHang[10], char tenHang[30], char ngayNhap[15], char NSX[15], float donGia, int soLuong);
		~Hang(){};
};

Hang::Hang(){
	strcpy(maHang, "");
	strcpy(tenHang, "");
	strcpy(ngayNhap, "");
	strcpy(NSX, "");
	donGia = 0;
	soLuong = 0; 
}
Hang::Hang(char maHangNew[10], char tenHangNew[30], char ngayNhapNew[15], char NSXNew[15], float donGiaNew, int soLuongNew){
	strcpy(maHang, maHangNew);
	strcpy(tenHang, tenHangNew);
	strcpy(ngayNhap, ngayNhapNew);
	strcpy(NSX, NSXNew);
	donGia = donGiaNew;
	soLuong = soLuongNew; 
}
void Hang::Nhap(){
	cout << "Nhap ma hang: ";
	fflush(stdin);
	gets(maHang);
	cout << "Nhap ten hang: ";
	fflush(stdin);
	gets(tenHang);
	cout << "Nhap ngay nhap hang: ";
	fflush(stdin);
	gets(ngayNhap);
	cout << "Nhap ngay san xuat: ";
	fflush(stdin);
	gets(NSX);
	cout << "Nhap don gia: ";
	cin >> donGia;
	cout << "Nhap so luong: ";
	cin >> soLuong;
}
void Hang::Xuat(){
	cout << "Ma hang: " << maHang << endl;
	cout << "Ten hang: " << tenHang << endl;
	cout << "Ngay nhap hang: " << ngayNhap << endl;
	cout << "Ngay san xuat: " << NSX << endl;
	cout << "Don gia: " << donGia << " VND" << endl;
	cout << "So luong: " << soLuong << endl;
	cout << "Thanh tien " << fixed << setprecision(2) << soLuong * donGia << " VND." << endl;

}

int main(){
	Hang P("VN2021", "Vaccine", "02/08/2021", "03/08/2021", 200000, 123);
	cout << "Thong tin mat hang P." << endl;
	P.Xuat();
	
	Hang Q;
	cout << endl << "Nhap thong tin mat hang Q." << endl;
	Q.Nhap();
	cout << endl << "Thong tin mat hang Q." << endl;
	Q.Xuat();
	
	return 0;
}
