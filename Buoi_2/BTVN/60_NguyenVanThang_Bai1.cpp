#include<iostream>
#include<math.h>
using namespace std;

class ptbac2{
	private:
		float a;
		float b;
		float c;
	public:
		void Nhap();
		void Xuat();
		void Giai();
		ptbac2();
		ptbac2(float a, float b, float c);
		~ptbac2(){};
};

ptbac2::ptbac2(){
	a = 0;
	b = 0; 
	c = 0;
}
ptbac2::ptbac2(float aNew, float bNew, float cNew){
	a = aNew;
	b = bNew;
	c = cNew;
}
void ptbac2::Nhap(){
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
	cout << "Nhap c: ";
	cin >> c;
}
void ptbac2::Xuat(){
	cout << a << "x^2 + " << b << "x + " << c << " = 0." << endl;
}
void ptbac2::Giai(){
	float delta = b*b - 4*a*c;
	if(delta < 0){
		cout << "Phuong trinh vo nghiem." << endl;
	}
	else if(delta == 0){
		float x = (-b) / 2*a;
		cout << "Phuong trinh co nghiem kep." << endl;
		cout << "x1 = x2 = " << x << endl;
	}
	else {
		float x1 = (-b + sqrt(delta)) / (2*a);
		float x2 = (-b - sqrt(delta)) / (2*a);
		cout << "Phuong trinh co hai nghiem phan biet." << endl;
		cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	}
}

int main(){
	ptbac2 P(1, 5, 4);
	cout << "Phuong trinh P: ";
	P.Xuat();
	cout << "Giai phuong trinh P: "<< endl;
	P.Giai();
	
	ptbac2 Q;
	cout << endl << "Nhap phuong trinh Q." << endl;
	Q.Nhap();
	cout << "Phuong trinh Q: ";
	Q.Xuat();
	cout << "Giai phuong trinh Q: "<< endl;
	Q.Giai();
	
	return 0;
}
