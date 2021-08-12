#include<iostream>
using namespace std;

class NSX {
private:
	char Mansx[20];
	char Tennsx[50];
	char Dcnsx[50];
public:
	void NHAP();
	void XUAT();
};

class HANG {
private:
	char Mahang[20];
	char Tenhang[20];
	NSX x;
public:
	void NHAP();
	void XUAT(); 
};



void NSX::NHAP(){
	cout << "Nhap ma nsx: "; fflush(stdin); gets(Mansx);
	cout << "Nhap ten nsx: "; fflush(stdin); gets(Tennsx);
	cout << "Nhap dia chi nsx: "; fflush(stdin); gets(Dcnsx); 
}
void NSX::XUAT(){
	cout << "Ma nsx: " << Mansx << endl;
	cout << "Ten nsx: " << Tennsx << endl;
	cout << "Dia chi nsx: " << Dcnsx << endl;
}

void HANG::NHAP(){
	cout << "Nhap ma hang: "; fflush(stdin); gets(Mahang);
	cout << "Nhap ten hang: "; fflush(stdin); gets(Tenhang);
	cout << "Nhap thong tin nha san xuat mat hang nay." << endl;
	x.NHAP();
}
void HANG::XUAT(){
	cout << "Ma hang: " << Mahang << endl;
	cout << "Ten hang: " << Tenhang << endl;
	cout << "Thong tin nha san xuat mat hang nay." << endl;
	x.XUAT();
}

int main(){
	int n;
	cout << "So mat hang can nhap: ";
	cin >> n;
	HANG h[n+1];
	
	for(int i = 1; i <= n; i++){
		cout << endl << "Nhap thong tin mat hang " << i << "." << endl;
		h[i].NHAP();
	}
	cout << "----------------------------------------" << endl;
	for(int i = 1; i <= n; i++){
		cout << endl << "Thong tin mat hang " << i << " la:" << endl;
		h[i].XUAT();
	}
	
	return 0;
}
