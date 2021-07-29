#include<iostream>
#include<string.h>

using namespace std;
class Person{
	public:
		char ten[30];
		int tuoi;
		char diaChi[50];
		int diemToan;
		int diemLy;
		int diemHoa;
		
		void nhap();
		void xuat();
		int DiemTrungBinh();
};
void Person::nhap(){
	cout << "Nhap ten: ";
	gets(ten);
	fflush(stdin);
	cout << "Nhap tuoi: ";
	cin >> tuoi;
	fflush(stdin);
	cout << "Dia chi: ";
	gets(diaChi);
	fflush(stdin);
	cout << "Diem Toan: "; 
	cin >> diemToan;
	cout << "Diem Ly: ";
	cin >> diemLy;
	cout << "Diem Hoa: ";
	cin >> diemHoa;
	fflush(stdin);
}

void Person::xuat(){
	cout << "Ten: " << ten << endl;
	cout << "Tuoi: " << tuoi << endl;
	cout << "Dia chi: " << diaChi << endl;
	cout << "Diem Toan: " << diemToan << endl; 
	cout << "Diem Ly: " << diemLy << endl;
	cout << "Diem Hoa: " << diemHoa << endl;
}

int Person::DiemTrungBinh(){
	return (diemToan + diemLy + diemHoa) / 3.0;
}
int main(){
	Person dt1, dt2;
	cout << "Nhap doi tuong 1: " << endl;
	dt1.nhap();
	cout << "Nhap doi tuong 2: " << endl;
	dt2.nhap();
	cout << "\nDoi tuong 1: " << endl;
	dt1.xuat();
	cout << "\nDoi tuong 2: " << endl;
	dt2.xuat();
	cout << "Ban co diem trung binh cao hon la: ";
	if(dt1.DiemTrungBinh() > dt2.DiemTrungBinh()){
		cout << dt1.ten << ". Ban do co diem trung binh la: " << dt1.DiemTrungBinh() << " diem.";
	}
	else{
		cout << dt2.ten << ". Ban do co diem trung binh la: " << dt2.DiemTrungBinh() << " diem.";
	}
}


