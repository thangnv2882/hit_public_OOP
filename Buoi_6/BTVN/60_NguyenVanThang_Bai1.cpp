#include<iostream>
#include<iomanip>
using namespace std;

class VEHICLE {
protected:
	char nhanHieu[30];
	int namSX;
	char hang[30];
public:
	void Nhap();
	void Xuat();
};
void VEHICLE::Nhap() {
	cout << "Nhap ten nhan hieu   : "; fflush(stdin); gets(nhanHieu);
	cout << "Nhap ten nam san xuat: "; cin >> namSX;
	cout << "Nhap ten hang        : "; fflush(stdin); gets(hang);
}
void VEHICLE::Xuat() {
	cout << "Ten nhan hieu   : " << nhanHieu << endl;
	cout << "Ten nam san xuat: " << namSX << endl;
	cout << "Ten hang        : " << hang << endl;
}

class OTO : public VEHICLE {
private:
	int soCho;
	float dungTich;
public:
	void Nhap();
	void Xuat();
};
void OTO::Nhap() {
	VEHICLE::Nhap();
	cout << "Nhap so cho ngoi: "; cin >> soCho;
	cout << "Nhap dung tich  : "; cin >> dungTich;
}
void OTO::Xuat() {
	VEHICLE::Xuat();
	cout << "So cho ngoi: " << soCho << endl;
	cout << "Dung tich  : " << fixed << setprecision(5) << dungTich << endl;
}

class MOTO : public VEHICLE {
private:
	float phanKhoi;
public:
	void Nhap();
	void Xuat();
};
void MOTO::Nhap() {
	VEHICLE::Nhap();
	cout << "Nhap phan khoi: "; cin >> phanKhoi;
}
void MOTO::Xuat() {
	VEHICLE::Xuat();
	cout << "Phan khoi: " << fixed << setprecision(5) << phanKhoi << endl;
}

int main() {
	OTO oto;
	MOTO moto;
	
	cout <<"Nhap thong tin xe oto: " << endl;
	oto.Nhap();
	cout << endl << "Nhap thong tin xe moto: " << endl;
	moto.Nhap();
	
	cout << endl << "Thong tin hai xe vua nhap la." << endl;

	cout << endl << "Oto" << endl;
	oto.Xuat();
	cout << endl << "Moto" << endl;
	moto.Xuat();
	
	return 0;
}
