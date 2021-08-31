#include<iostream>
#include<string.h>
using namespace std;

class ELECTRONIC {
protected:
	float congSuat;
	float dienAp;
public:
	ELECTRONIC(float congSuat, float dienAp);
};
ELECTRONIC::ELECTRONIC(float congSuat, float dienAp) {
	this->congSuat = congSuat;
	this->dienAp = dienAp;
}


class MAYGIAT : public ELECTRONIC {
private:
	float dungTich;
	char loai[20];
public:
	MAYGIAT(float congSuat, float dienAp, float dungTich, char loai[20]);
	void Xuat();
};
MAYGIAT::MAYGIAT(float congSuat, float dienAp, float dungTich, char loai[20]) : ELECTRONIC(congSuat, dienAp) {
	this->dungTich = dungTich;
	strcpy(this->loai, loai);
}
void MAYGIAT::Xuat() {
	cout << "Cong suat: " << congSuat << endl;
	cout << "Dien ap  : " << dienAp <<endl;
	cout << "Dung tich: " << dungTich << " (kg)" << endl;
	cout << "Loai     : " << loai << endl;
}


class TULANH : public ELECTRONIC {
private:
	float dungTich;
	int soNgan;
public:
	TULANH(float congSuat, float dienAp, float dungTich, int soNgan);
	void Xuat();
};
TULANH::TULANH(float congSuat, float dienAp, float dungTich, int soNgan) : ELECTRONIC(congSuat, dienAp) {
	this->dungTich = dungTich;
	this->soNgan = soNgan;
}
void TULANH::Xuat() {
	cout << "Cong suat: " << congSuat << endl;
	cout << "Dien ap  : " << dienAp <<endl;
	cout << "Dung tich: " << dungTich << " (lit)" << endl;
	cout << "So ngan  : " << soNgan << endl;
}

int main() {
	MAYGIAT a(400, 220, 9.2, (char*)"Cua tren");
	TULANH b(300, 220, 100, 4);
	
	cout << "Thong tin may giat. " << endl;
	a.Xuat();
	
	cout << endl << "Thong tin tu lanh." << endl;
	b.Xuat();
	return 0;
}
