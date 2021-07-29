#include<iostream>
using namespace std;

class SinhVien{
	public:
		char MaSV[20];
		char HoTen[30];
		int ngaySinh;
		int thangSinh;
		int namSinh;
		char gioiTinh[10];
		float diemTB;
		char xepLoai[20];
	
		void Nhap();
		void Xuat();
};

void SinhVien::Nhap(){
	cout << "Nhap ma sinh vien: ";
	gets(MaSV);
	fflush(stdin);
	cout << "Nhap ten: ";
	gets(HoTen);
	fflush(stdin);
	cout << "Ngay sinh: ";
	cin >> ngaySinh;
	cout << "Thang sinh: ";
	cin >> thangSinh;
	cout << "Nam sinh: ";
	cin >> namSinh;
	fflush(stdin);
	cout << "Gioi tinh: ";
	gets(gioiTinh);
	fflush(stdin);
	cout << "Nhap diem TB: ";
	cin >> diemTB;
	fflush(stdin);
	cout << "Xep loai dao duc: ";
	gets(xepLoai);
	fflush(stdin);
}
void SinhVien::Xuat(){
	cout << "Ma sinh vien: " << MaSV << endl;
	cout << "Nhap ten: " << HoTen << endl;
	cout << "Ngay sinh: " << ngaySinh << endl;
	cout << "Thang sinh: " << thangSinh << endl;
	cout << "Nam sinh: " << namSinh << endl;
	cout << "Gioi tinh: " << gioiTinh << endl;
	cout << "Diem TB: " << diemTB << endl;
	cout << "Xep loai dao duc: " << xepLoai << endl;
}

int main(){
	SinhVien SVDiemCao, SVDiemThap;
	cout << endl << "Nhap thong tin sinh vien 1." << endl;
	SVDiemCao.Nhap();
	cout << endl << "Nhap thong tin sinh vien 2." << endl;
	SVDiemThap.Nhap();
	if(SVDiemCao.diemTB < SVDiemThap.diemTB){
		SinhVien tg = SVDiemCao;
		SVDiemCao = SVDiemThap;
		SVDiemThap = tg;
	}
	cout << "\n--------------------------------------" << endl;
	cout << "Sinh vien diem cao la: " << endl;
	SVDiemCao.Xuat();
	cout << "\nSinh vien diem thap la: " << endl;
	SVDiemThap.Xuat();
	
	return 0;
}

//Cach 2
//#include<iostream>
//using namespace std;
//
//class SinhVien{
//	public:
//		char MaSV[20];
//		char HoTen[30];
//		int ngaySinh;
//		int thangSinh;
//		int namSinh;
//		char gioiTinh[10];
//		float diemTB;
//		char xepLoai[20];
//	
//		void Nhap();
//		void Xuat();
//		void HoanDoi(SinhVien &a, SinhVien &b);
//};
//
//void SinhVien::Nhap(){
//	cout << "Nhap ma sinh vien: ";
//	gets(MaSV);
//	fflush(stdin);
//	cout << "Nhap ten: ";
//	gets(HoTen);
//	fflush(stdin);
//	cout << "Ngay sinh: ";
//	cin >> ngaySinh;
//	cout << "Thang sinh: ";
//	cin >> thangSinh;
//	cout << "Nam sinh: ";
//	cin >> namSinh;
//	fflush(stdin);
//	cout << "Gioi tinh: ";
//	gets(gioiTinh);
//	fflush(stdin);
//	cout << "Nhap diem TB: ";
//	cin >> diemTB;
//	fflush(stdin);
//	cout << "Xep loai dao duc: ";
//	gets(xepLoai);
//	fflush(stdin);
//}
//void SinhVien::Xuat(){
//	cout << "Ma sinh vien: " << MaSV << endl;
//	cout << "Nhap ten: " << HoTen << endl;
//	cout << "Ngay sinh: " << ngaySinh << endl;
//	cout << "Thang sinh: " << thangSinh << endl;
//	cout << "Nam sinh: " << namSinh << endl;
//	cout << "Gioi tinh: " << gioiTinh << endl;
//	cout << "Diem TB: " << diemTB << endl;
//	cout << "Xep loai dao duc: " << xepLoai << endl;
//}
//void SinhVien::HoanDoi(SinhVien &a, SinhVien &b){
//	if(a.diemTB < b.diemTB){
//		SinhVien tg = a;
//		a = b;
//		b = tg;
//	}
//}
//
//int main(){
//	SinhVien SVDiemCao, SVDiemThap, SV;
//	cout << endl << "Nhap thong tin sinh vien 1." << endl;
//	SVDiemCao.Nhap();
//	cout << endl << "Nhap thong tin sinh vien 2." << endl;
//	SVDiemThap.Nhap();
//	SV.HoanDoi(SVDiemCao, SVDiemThap);
//	cout << "\n--------------------------------------" << endl;
//	cout << "Sinh vien diem cao la: " << endl;
//	SVDiemCao.Xuat();
//	cout << "\nSinh vien diem thap la: " << endl;
//	SVDiemThap.Xuat();
//	
//	return 0;
//}
//

