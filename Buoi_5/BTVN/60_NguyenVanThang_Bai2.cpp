#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
using namespace std;

class PhieuKK;
class NhanVienKK {
private:
	char hoTen[30];
	char chucVu[30];
public:
	void Nhap();
	void Xuat();
};
void NhanVienKK::Nhap() {
	cout << "Nhap ten    : "; fflush(stdin); gets(hoTen);
	cout << "Nhap chuc vu: "; fflush(stdin); gets(chucVu);
}
void NhanVienKK::Xuat() {
	cout << left << setw(20) << "Nhan vien kiem ke: " << setw(15) << hoTen << setw(15) << "Chuc vu: " << chucVu << endl; 
}

class PhongKK {
private:
	char phong[30];
	char maPhong[10];
	char truongPhong[30];
public:
	void Nhap();
	void Xuat();	
};
void PhongKK::Nhap() {
	cout << "Nhap ten phong       : "; fflush(stdin); gets(phong);
	cout << "Nhap ma phong        : "; fflush(stdin); gets(maPhong);
	cout << "Nhap ten truong phong: "; fflush(stdin); gets(truongPhong);
}
void PhongKK::Xuat() {
	cout << left << setw(20) << "Kiem ke tai phong: " << setw(15) << phong << setw(15) << "Ma phong: " << maPhong << endl; 
	cout << left << setw(15) << "Truong phong: " << truongPhong << endl;
}

class TaiSan {
private:
	char tenTS[20];
	int sl;
	char tinhTrang[20];
public:
	TaiSan();
	TaiSan(char tenTS[20], int sl, char tinhTrang[20]);
	void Nhap();
	void Xuat();
	friend class PhieuKK;
	friend void ChangeSL(PhieuKK ph);
	friend void Insert(PhieuKK &ph, TaiSan x, int vt);
	friend void sx(PhieuKK ph);
};
TaiSan::TaiSan() {
	strcpy(tenTS, "");
	this->sl = 0;
	strcpy(tinhTrang, "");
}
TaiSan::TaiSan(char tenTS[20], int sl, char tinhTrang[20]) {
	strcpy(this->tenTS, tenTS);
	this->sl = sl;
	strcpy(this->tinhTrang, tinhTrang);
}

void TaiSan::Nhap() {
	cout << "Nhap ten tai san: "; fflush(stdin); gets(tenTS);
	cout << "Nhap so luong   : "; cin >> sl;
	cout << "Nhap tinh trang : "; fflush(stdin); gets(tinhTrang);
}
void TaiSan::Xuat() {
	cout << left << setw(25) << tenTS << setw(15) << sl << tinhTrang << endl;
}

class PhieuKK {
private:
	char maPhieu[10];
	char ngayKK[12];
	NhanVienKK nv;
	PhongKK phong;
	TaiSan *ts;
	int n;
public:
	void Nhap();
	void Xuat();
	friend void ChangeSL(PhieuKK ph);
	friend void Insert(PhieuKK &ph, TaiSan x, int vt);
	friend void sx(PhieuKK ph);
};
void PhieuKK::Nhap() {
	cout << "Nhap ma phieu    : "; fflush(stdin); gets(maPhieu);
	cout << "Nhap ngay kiem ke: "; fflush(stdin); gets(ngayKK);
	cout << "Nhap thong tin nhan vien kiem ke." << endl;
	nv.Nhap();
	cout << "Nhap thong tin phong kiem ke." << endl;
	phong.Nhap();
	cout << "\n\tNhap so tai san: "; cin >> n;
	ts = new TaiSan[n];
	for(int i = 0; i < n; i++) {
		cout << "\nNhap thong tin tai san " << i + 1 << endl;
		ts[i].Nhap();
	}
}
void PhieuKK::Xuat() {
	cout << "\t\tPHIEU KIEM KE TAI SAN" << endl;
	cout << left << setw(20) << "Ma phieu: " << setw(15) << maPhieu << setw(15) << "Ngay kiem ke: " << ngayKK << endl; 
	nv.Xuat();
	phong.Xuat();
	cout << left << setw(25) << "Ten tai san" << setw(15) << "So luong" << "Tinh trang" << endl;
	int slAll = 0;
	for(int i = 0; i < n; i++) {
		ts[i].Xuat();
		slAll += ts[i].sl;
	}
	cout << endl << "So tai san da kiem ke: " << left << setw(15) << n << "Tong so luong: " << slAll << endl;
}

void ChangeSL(PhieuKK ph) {
	for(int i = 0; i < ph.n; i++) {
		if(ph.ts[i].tenTS == "May vi tinh") {
			ph.ts[i].sl = 20;
		}
	}
	for(int i = 0; i < ph.n; i++) {
		if(ph.ts[i].tenTS == "May vi tinh") {
			cout << "\n\nPhieu sau khi sua thong tin so luong." << endl;
			ph.Xuat();
			break;
		}
	}
}

void Insert(PhieuKK &ph, TaiSan x, int vt) {
	realloc(ph.ts, (ph.n+1)*sizeof(TaiSan));
	for(int i=ph.n; i >= vt; i--) {
		ph.ts[i] = ph.ts[i-1];
	}
	ph.ts[vt-1] = x;
	ph.n++;
}


void sx(PhieuKK ph) {
	for(int i = 0; i < ph.n-1; i++) {
		for(int j = i + 1; j < ph.n; j++){
			if(ph.ts[i].sl >= ph.ts[j].sl){
				TaiSan temp = ph.ts[i];
				ph.ts[i] = ph.ts[j];
				ph.ts[j] = temp;
			}
		}
	} 
}

int main() {
	PhieuKK ph;
	ph.Nhap();
	cout << "\n----------------------------------------" << endl;
	ph.Xuat();
	
	//Bonus 1
	ChangeSL(ph);
	
//	Bonus 2 
	cout << "\n----------------------------------------" << endl;
	cout << "Phieu sau khi chen them tai san." << endl;
	TaiSan taisan((char*)"Laptop", 10, (char*)"Tot");
	Insert(ph, taisan, 2);
	ph.Xuat();
	
	//Bonus 3
	cout << "\n----------------------------------------" << endl;
	cout << "Phieu sau khi sap xep." << endl;
	sx(ph);
	ph.Xuat();
	
	
	return 0;
}

//String bi loi kho chiu
//#include<iostream>
//#include<iomanip>
//#include<string.h>
//#include<stdlib.h>
//using namespace std;
//
//class PhieuKK;
//class NhanVienKK {
//private:
//	string hoTen;
//	string chucVu;
//public:
//	void Nhap();
//	void Xuat();
//};
//void NhanVienKK::Nhap() {
//	cout << "Nhap ten    : "; fflush(stdin); getline(cin, hoTen);
//	cout << "Nhap chuc vu: "; fflush(stdin); getline(cin, chucVu);
//}
//void NhanVienKK::Xuat() {
//	cout << left << setw(20) << "Nhan vien kiem ke: " << setw(15) << hoTen << setw(15) << "Chuc vu: " << chucVu << endl; 
//}
//
//class PhongKK {
//private:
//	string phong;
//	string maPhong;
//	string truongPhong;
//public:
//	void Nhap();
//	void Xuat();	
//};
//void PhongKK::Nhap() {
//	cout << "Nhap ten phong       : "; fflush(stdin); getline(cin, phong);
//	cout << "Nhap ma phong        : "; fflush(stdin); getline(cin, maPhong);
//	cout << "Nhap ten truong phong: "; fflush(stdin); getline(cin, truongPhong);
//}
//void PhongKK::Xuat() {
//	cout << left << setw(20) << "Kiem ke tai phong: " << setw(15) << phong << setw(15) << "Ma phong: " << maPhong << endl; 
//	cout << left << setw(15) << "Truong phong: " << truongPhong << endl;
//}
//
//class TaiSan {
//private:
//	string tenTS;
//	int sl;
//	string tinhTrang;
//public:
//	TaiSan();
//	TaiSan(string tenTS, int sl, string tinhTrang);
//	void Nhap();
//	void Xuat();
//	friend class PhieuKK;
//	friend void ChangeSL(PhieuKK ph);
//	friend void Insert(PhieuKK &ph, TaiSan x, int vt);
//	friend void sx(PhieuKK ph);
//};
//TaiSan::TaiSan() {
//	this->tenTS = "";
//	this->sl = 0;
//	this->tinhTrang = "";
//}
//TaiSan::TaiSan(string tenTS, int sl, string tinhTrang) {
//	this->tenTS = tenTS;
//	this->sl = sl;
//	this->tinhTrang = tinhTrang;
//}
//
//void TaiSan::Nhap() {
//	cout << "Nhap ten tai san: "; fflush(stdin); getline(cin, tenTS);
//	cout << "Nhap so luong   : "; cin >> sl;
//	cout << "Nhap tinh trang : "; fflush(stdin); getline(cin, tinhTrang);
//}
//void TaiSan::Xuat() {
//	cout << left << setw(25) << tenTS << setw(15) << sl << tinhTrang << endl;
//}
//
//class PhieuKK {
//private:
//	string maPhieu;
//	string ngayKK;
//	NhanVienKK nv;
//	PhongKK phong;
//	TaiSan *ts;
//	int n;
//public:
//	void Nhap();
//	void Xuat();
//	friend void ChangeSL(PhieuKK ph);
//	friend void Insert(PhieuKK &ph, TaiSan x, int vt);
//	friend void sx(PhieuKK ph);
//};
//void PhieuKK::Nhap() {
//	cout << "Nhap ma phieu    : "; fflush(stdin); getline(cin, maPhieu);
//	cout << "Nhap ngay kiem ke: "; fflush(stdin); getline(cin, ngayKK);
//	cout << "Nhap thong tin nhan vien kiem ke." << endl;
//	nv.Nhap();
//	cout << "Nhap thong tin phong kiem ke." << endl;
//	phong.Nhap();
//	cout << "\n\tNhap so tai san: "; cin >> n;
//	ts = new TaiSan[n];
//	for(int i = 0; i < n; i++) {
//		cout << "\nNhap thong tin tai san " << i + 1 << endl;
//		ts[i].Nhap();
//	}
//}
//void PhieuKK::Xuat() {
//	cout << "\t\tPHIEU KIEM KE TAI SAN" << endl;
//	cout << left << setw(20) << "Ma phieu: " << setw(15) << maPhieu << setw(15) << "Ngay kiem ke: " << ngayKK << endl; 
//	nv.Xuat();
//	phong.Xuat();
//	cout << left << setw(25) << "Ten tai san" << setw(15) << "So luong" << "Tinh trang" << endl;
//	int slAll = 0;
//	for(int i = 0; i < n; i++) {
//		ts[i].Xuat();
//		slAll += ts[i].sl;
//	}
//	cout << endl << "So tai san da kiem ke: " << left << setw(15) << n << "Tong so luong: " << slAll << endl;
//}
//
//void ChangeSL(PhieuKK ph) {
//	for(int i = 0; i < ph.n; i++) {
//		if(ph.ts[i].tenTS == "May vi tinh") {
//			ph.ts[i].sl = 20;
//		}
//	}
//	for(int i = 0; i < ph.n; i++) {
//		if(ph.ts[i].tenTS == "May vi tinh") {
//			cout << "\n\nPhieu sau khi sua thong tin so luong." << endl;
//			ph.Xuat();
//			break;
//		}
//	}
//}
//
//void Insert(PhieuKK &ph, TaiSan x, int vt) {
//	realloc(ph.ts, (ph.n+1)*sizeof(TaiSan));
//	for(int i=ph.n; i >= vt; i--) {
//		ph.ts[i] = ph.ts[i-1];
//	}
//	ph.ts[vt-1] = x;
//	ph.n++;
//}
//
//
//void sx(PhieuKK ph) {
//	for(int i = 0; i < ph.n-1; i++) {
//		for(int j = i + 1; j < ph.n; j++){
//			if(ph.ts[i].sl >= ph.ts[j].sl){
//				TaiSan temp = ph.ts[i];
//				ph.ts[i] = ph.ts[j];
//				ph.ts[j] = temp;
//			}
//		}
//	} 
//}
//
//int main() {
//	PhieuKK ph;
//	ph.Nhap();
//	cout << "\n----------------------------------------" << endl;
//	ph.Xuat();
//	
//	//Bonus 1
//	ChangeSL(ph);
//	
////	Bonus 2 (Bi loi)
//	cout << "\n----------------------------------------" << endl;
//	cout << "Phieu sau khi chen them tai san." << endl;
//	TaiSan taisan("Laptop", 10, "Tot");
//	Insert(ph, taisan, 2);
//	ph.Xuat();
//	
//	//Bonus 3
//	cout << "\n----------------------------------------" << endl;
//	cout << "Phieu sau khi sap xep." << endl;
//	sx(ph);
//	ph.Xuat();
//	
//	
//	return 0;
//}
