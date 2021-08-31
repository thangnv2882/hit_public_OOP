//#include<iostream>
//using namespace std;
//
//class ConNguoi {
//private:
//	char hoTen[30];
//	char ngaySinh[10];
//	char queQuan[50];
//public:
//	void NhapA();
//	void XuatA();
//	void An() {
//		cout << "An." << endl;
//	}
//};
//void ConNguoi::NhapA() {
//	cout << "Nhap ho ten   : "; fflush(stdin); gets(hoTen);
//	cout << "Nhap ngay sinh: "; fflush(stdin); gets(ngaySinh);
//	cout << "Nhap que quan : "; fflush(stdin); gets(queQuan);
//}
//void ConNguoi::XuatA() {
//	cout << "Ho ten   : " << hoTen <<endl;
//	cout << "Ngay sinh: " << ngaySinh <<endl;
//	cout << "Que quan : " << queQuan <<endl;
//}
//class SinhVien : public ConNguoi {
//private:
//	char tenTruong[50];
//	char chuyenNganh[30];
//	char maSV[15];
//public:
//	void Nhap();
//	void Xuat();
//};
//void SinhVien::Nhap() {
//	ConNguoi::NhapA();
//	cout << "Nhap ten truong  : "; fflush(stdin); gets(tenTruong);
//	cout << "Nhap chuyen nganh: "; fflush(stdin); gets(chuyenNganh);
//	cout << "Nhap ma sinh vien: "; fflush(stdin); gets(maSV);
//}
//void SinhVien::Xuat() {
//	ConNguoi::XuatA();
//	cout << "Ten truong  : " << tenTruong <<endl;
//	cout << "Chuyen nganh: " << chuyenNganh <<endl;
//	cout << "Ma sinh vien: " << maSV <<endl;
//}
//int main() {
//	SinhVien sv;
//	sv.Nhap();
//	cout << "\nThong tin sinh vien. " << endl;
//	sv.Xuat();
//
//	return 0;
//}



//VD2
#include<iostream>
#include<string.h>
using namespace std;

class Hinh {
protected:
	char vien[15];
	char mauSac[10];
public:
	Hinh(char vien[15], char mauSac[10]) {
		strcpy(this->vien, vien);
		strcpy(this->mauSac, mauSac);
	}
	~Hinh() {};
};

class HinhTron : public Hinh {
private:
	float bk;
public:
	HinhTron();
	HinhTron(float bk, char vien[15], char mauSac[10]);
	~HinhTron(){};
	void Xuat();
};
HinhTron::HinhTron(float bk, char vien[15], char mauSac[10]) : Hinh(vien, mauSac) {
	this->bk = bk;
}
void HinhTron::Xuat() {
	cout << "Ban kinh: " << bk << endl;
	cout << "Vien: " << vien << endl;
	cout << "Mau sac: " << mauSac << endl;
}
int main() {
	HinhTron ht(5.1, (char*)"lien", (char*)"do");
	ht.Xuat();
	return 0;
}
