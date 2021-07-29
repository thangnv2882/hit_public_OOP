/*
- Lap trinh thu tuc
- Lap trinh huong doi tuong:
	+ Code de bao tri
	+ Tai su dung
	...
* Class
* Object: Doi tuong

*/

#include<iostream>
#include<string.h>
using namespace std;
class Person{
	public:
		void Sleep(const char *BanBe);
};
// Class co the viet trong ham main()
class Animal{
	public: //access modifier
		// Thuoc tinh
		char name[30];
		int age;
		char address[30];
		
		// Phuong thuc (method) (Nen viet hoa ky tu dau).
		void Sleep(const char *BanBe);
		void Eat();
		int TuoiTho();
	
	
//	void sleep(const char *BanBe){
//		cout << name << " dang ngu voi: " << BanBe << endl;
//	}
//	void eat(){
//		cout << "eatting... " << endl;
//	}
};

void Animal::Sleep(const char *BanBe){
	cout << "Animal dang ngu.";
}
void Person::Sleep(const char *BanBe){
	cout << "Person dang ngu.";
}
void Animal::Eat(){
	cout << "Eatting...";
}
int Animal::TuoiTho(){
	return age + 10;
}


int main(){
	// Animal *cat = new Animal;
	
	Animal dog; // Doi tuong dog
	
	strcpy(dog.name, "Bull"); // Copy chuoi.
	cout << "name: " << dog.name << endl;
	
	strcpy(dog.address, "Zoo"); // 
	cout << "address: " << dog.address << endl;
	
	dog.age = 2;
	cout << "age: " << dog.age << endl;
	
	dog.Sleep("Mun");
	cout << "Sau khi ngu day: " << endl;
	
	int TuoiTho = dog.TuoiTho();
	cout << "Tuoi tho = " << TuoiTho << endl;
	
	
	cout << "Nhap ten: ";
	gets(dog.name);
	fflush(stdin); // Xoa bo nho dem
	cout << "Nhap tuoi: ";
	cin >> dog.age;
	fflush(stdin);
	cout << "Nhap dia chi: ";
	gets(dog.address);
	
	
	return 0;
}

/*
- Tinh dong goi - private
- Tinh ke thua
- Tinh da hinh
- Tinh triu tuong
*/

/*
access modifier
- private
- public
- default
- protected
- 
*/

/*
- Khai bao class Nguoi: ten, tuoi, diachi, diemToan, diemLy, diemHoa;
- Phuong thuc: Nhap(), Xuat(), DiemTrungBinh();
- Yeu cau:
+) Nhap vao 2 doi tuong.
+) Xuat 2 doi tuong vua nhap ra man hinh
+) So sanh diem trung binh -> ai cao hon thi xuat ra man hinh ten va diem
*/
