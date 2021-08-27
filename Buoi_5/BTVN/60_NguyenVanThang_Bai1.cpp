#include<iostream>
#include<string>
using namespace std;

class SinhVien {
private:
	string idSV;
	string name;
	int day;
	int month;
	int year;
	string sex;
	float score;
	string rating;
//	int n;
public:
	SinhVien();
	SinhVien(string idSV, string name, int day, int month, int year, string sex, float score, string rating);
	~SinhVien(){};
	
	string GetId();
	string GetName();
	int GetDay();
	int GetMonth();
	int GetYear();
	string GetSex();
	float GetScore();
	string GetRating();
	
	void SetId(string idSV);
	void SetName(string name);
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void SetSex(string sex);
	void SetScore(float score);
	void SetRating(string rating);
	
	void Nhap();
	void Xuat();
};

SinhVien::SinhVien() {
	this->idSV = "";
	this->name = "";
	this->day = 0;
	this->month = 0;
	this->year = 0;
	this->sex = "";
	this->score = 0;
	this->rating = "";
	
}
SinhVien::SinhVien(string idSV, string name, int day, int month, int year, string sex, float score, string rating) {
	this->idSV = idSV;
	this->name = name;
	this->day = day;
	this->month = month;
	this->year = year;
	this->sex, sex;
	this->score = score;
	this->rating, rating;
}


//Getter
string SinhVien::GetId() {
	return this->idSV;
}
string SinhVien::GetName() {
	return this->name;
}
int SinhVien::GetDay() {
	return this->day;
}
int SinhVien::GetMonth() {
	return this->month;
}
int SinhVien::GetYear() {
	return this->year;
}
string SinhVien::GetSex() {
	return this->sex;
}
float SinhVien::GetScore() {
	return this->score;
}
string SinhVien::GetRating() {
	return this->rating;
}


//Setter
void SinhVien::SetId(string idSV) {
	this->idSV = idSV;
}
void SinhVien::SetName(string name) {
	this->name = name;
}
void SinhVien::SetDay(int day) {
	this->day = day;
}
void SinhVien::SetMonth(int month) {
	this->month = month;
}
void SinhVien::SetYear(int year) {
	this->year = year;
}
void SinhVien::SetSex(string sex) {
	this->sex = sex;
}
void SinhVien::SetScore(float score) {
	this->score = score;
}
void SinhVien::SetRating(string rating) {
	this->rating = rating;
}

void SinhVien::Nhap() {
	string str;
	int temp;
	cout << "Nhap ma sinh vien    : ";	fflush(stdin);	getline(cin, str);	SetId(str);
	cout << "Nhap ten sinh vien   : ";	fflush(stdin);	getline(cin, str);	SetName(str);
	cout << "Nhap ngay sinh       : ";					cin >> temp;		SetDay(temp);
	cout << "Nhap thang sinh      : ";					cin >> temp;		SetMonth(temp);
	cout << "Nhap nam sinh        : ";					cin >> temp;		SetYear(temp);
	cout << "Nhap gioi tinh       : ";	fflush(stdin);	getline(cin, str);	SetSex(str);
	cout << "Nhap diem trung binh : ";					cin >> temp;		SetScore(temp);
	cout << "Nhap xep loai dao duc: ";	fflush(stdin);	getline(cin, str);	SetRating(str);
}
void SinhVien::Xuat() {
	cout << "Ma sinh vien    : " << GetId() << endl;
	cout << "Ten sinh vien   : " << GetName() << endl;
	cout << "Ngay sinh       : " << GetDay() << endl;
	cout << "Thang sinh      : " << GetMonth() << endl;
	cout << "Nam sinh        : " << GetYear() << endl;
	cout << "Gioi tinh       : " << GetSex() << endl;
	cout << "Diem trung binh : " << GetScore() << endl;
	cout << "Xep loai dao duc: " << GetRating() << endl;
}

int main() {
	int n;
	cout << "Nhap so sinh vien: "; cin >> n;
	SinhVien *sv;
	sv = new SinhVien[n];
	
	for(int i = 0; i < n; i++) {
		cout << "\nNhap thong tin sinh vien: " << i+1 << endl;
		sv[i].Nhap();
	}
	cout << "\n\tXuat thong tin sinh vien." << endl;
	for(int i = 0; i < n; i++) {
		cout << "\nThong tin sinh vien: " << i+1 << endl;
		sv[i].Xuat();
	}
	
	int d = 0;
	cout << "\n------------------------------------" << endl;
	cout << "Nhung sinh vien co xep loai dao duc tot la: " << endl;
	for(int i = 0; i < n; i++) {
		if(sv[i].GetRating() == "Tot" || sv[i].GetRating() == "tot" ) {
			sv[i].Xuat();
			d++;
		}
	}
	if(d == 0) {
		cout << "Khong co sinh vien nao xep loai dao duc tot.";
	}
	return 0;
}






