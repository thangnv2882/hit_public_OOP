#include<iostream>
#include<string.h>
using namespace std;

class SinhVien {
	private:
		char MaSV[10]; // Thuoc tinh
		char HoTen[30];
		int Tuoi;
		float DiemTB;
		int a[];
	public:
		SinhVien(); //Khoi tao khong doi so
		SinhVien(char MaSVNew[10], char HotenNew[30], int TuoiNew, float DiemTBNew); // Khoi tao co doi - day du
		~SinhVien(){
			cout << "Sv da ra truong" << endl;
		} // Ham huy, Tu dong goi
		void an();
		void choi();
		void ngu();
		void Nhap();
		void Xuat();
};
SinhVien::SinhVien(){
	strcpy(MaSV, "");
	strcpy(HoTen, "");
	Tuoi = 0;
	DiemTB = 0;
}
SinhVien::SinhVien(char MaSVNew[10], char HoTenNew[30], int TuoiNew, float DiemTBNew){
	strcpy(MaSV, MaSVNew);
	strcpy(HoTen, HoTenNew);
	Tuoi = TuoiNew;
	DiemTB = DiemTBNew;
}

void SinhVien::Nhap() {
	cout << "Nhap MSV: ";
	gets(MaSV);
	fflush(stdin);
	cout << "Nhap ho ten: ";
	gets(HoTen);
	fflush(stdin);
	cout << "Nhap tuoi: ";
	cin >> Tuoi;
	cout << "Nhap diem TB: ";
	cin >> DiemTB;
}

void SinhVien::Xuat(){
	cout << endl << "Ma SV: " << MaSV << endl;
	cout << "Ho ten: " << HoTen << endl;
	cout << "Tuoi: " << Tuoi << endl;
	cout << "Diem TB: " << DiemTB << endl;
}


class ex {
	private:
		int n;
	public:
		ex(); //Phuong thuc khoi tao khong doi so - khong tham so
		ex(int temp, string str); //Phuong thuc khoi tao doi so - co tham so
		
		~ex();
};

ex::ex(){
	n = 0;
	//str = "";
}
ex::ex(int temp, string strNew){
	n = temp;
	//str = strNew;
}

int main(){
	SinhVien A;
	SinhVien B("m123", "Nguyen Van B", 20, 10);
	A.Nhap();
	cout << endl << "Sinh Vien A: ";
	A.Xuat();
	cout << endl << "Sinh Vien B: ";
	B.Xuat();
	
		
	return 0;
}
