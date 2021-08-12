#include<iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	void nhap();
	void xuat();
};

class DiaChi {
private:
	char dienThoai[12];
	char phuong[30];
	char quan[30];
	char thanhPho[30];
public:
	void nhap();
	void xuat();
};

class DoanhNghiep {
private:
	int maDn;
	char tenDn[60];
	Date ngayTl;
	DiaChi diaChi;
	char giamDoc[30];
	long doanhThu;
public:
	void nhap();
	void xuat();
};



void Date::nhap(){
	cout << "Nhap ngay thanh lap: "; cin >> day;
	cout << "Nhap thang thanh lap: "; cin >> month;
	cout << "Nhap nam thanh lap: "; cin >> year;
}
void Date::xuat(){
	cout << "Ngay thanh lap la: " << day << "/" << month << "/" << year << endl;
}

void DiaChi::nhap(){
	cout << "Nhap so dien thoai: "; fflush(stdin); gets(dienThoai);
	cout << "Nhap phuong: "; fflush(stdin); gets(phuong);
	cout << "Nhap quan: "; fflush(stdin); gets(quan);
	cout << "Nhap thanh pho: "; fflush(stdin); gets(thanhPho);	
}
void DiaChi::xuat(){
	cout << "So dien thoai: " << dienThoai << endl;
	cout << "Dia chi cua doanh nghiep: " << "Phuong " << phuong << ", Quan " << quan << ", Thanh Pho " << thanhPho << endl;
} 

void DoanhNghiep::nhap(){
	cout << "Nhap ma doanh nghiep: "; cin >> maDn;
	cout << "Nhap ten doanh nghiep: "; fflush(stdin); gets(tenDn);
	ngayTl.nhap();
	diaChi.nhap();
	cout << "Nhap ten giam doc: "; fflush(stdin); gets(giamDoc);
	cout << "Nhap doanh thu: "; cin >> doanhThu;
}
void DoanhNghiep::xuat(){
	cout << "Ma doanh nghiep la: " << maDn << endl;
	cout << "Ten doanh nghiep la: " << tenDn << endl;
	ngayTl.xuat();
	diaChi.xuat();
	cout << "Giam doc doanh nghiep: " << giamDoc << endl;
	cout << "Doanh thu cua doanh nghiep: " << doanhThu << endl;
}

int main(){
	DoanhNghiep dn;
	cout << "Nhap thong tin doanh nghiep. " << endl;
	dn.nhap();
	cout << endl << "Thong tin doanh nghiep." << endl;
	dn.xuat();
	
	return 0;
}
