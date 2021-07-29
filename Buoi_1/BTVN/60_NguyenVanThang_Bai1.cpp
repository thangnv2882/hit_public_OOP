#include<iostream>
#include<math.h>
using namespace std;

class HinhTron{
	public:
		float banKinh;
		
		float ChuVi();
		float DienTich();
};

float HinhTron::ChuVi(){
	return 2 * M_PI * banKinh;
}
float HinhTron::DienTich(){
	return M_PI * pow(banKinh, 2);
}

int main(){
	HinhTron ht;
	cout << "Nhap ban kinh: ";
	cin >> ht.banKinh;
	cout << "Chu vi cua hinh tron la: " << ht.ChuVi() << endl;
	cout << "Dien tich cua hinh tron la: " << ht.DienTich() << endl;
	
	return 0;
}

