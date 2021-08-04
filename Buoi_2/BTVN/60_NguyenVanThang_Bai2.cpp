#include<iostream>
#include<math.h>
using namespace std;

class PhanSo{
	private:
		int a;
		int b;
	public:
		void Nhap();
		void Xuat();
		void Rut();
		PhanSo();
		PhanSo(int a, int b);
		~PhanSo(){};
};

PhanSo::PhanSo(){
	a = 0;
	b = 0; 
}
PhanSo::PhanSo(int aNew, int bNew){
	a = aNew;
	b = bNew;
}
void PhanSo::Nhap(){
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
}
void PhanSo::Xuat(){
	cout << a << "/" << b << endl;
}
void PhanSo::Rut(){
	int a1 = a;
	int b1 = b;
	while(a1 % b1 != 0){
		int r = a1 % b1;
		a1 = b1;
		b1 = r;
	}
	a = a / b1;
	b = b / b1;
	cout << a << "/" << b;
}

int main(){
	PhanSo P(10, 13);
	cout << "Phan so P: ";
	P.Xuat();
	
	PhanSo Q;
	cout << "Nhap phan so Q." << endl;
	Q.Nhap();
	cout << "Phan so toi gian cua Q la: " ;
	Q.Rut();
	
	
	return 0;
}
