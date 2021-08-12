#include<iostream>
#include<string.h>
using namespace std;

class Employee {
private:
	static int countId;
	int id;
	char name[25];
	int age;
public:
	Employee();
	~Employee(){};
	void Input();
	void Output();
};

int Employee::countId = 0;

Employee::Employee(){
	id = 0;
	strcpy(name, "");
	age = 0;
}
void Employee::Input(){
	cout << "Name: "; fflush(stdin); gets(name);
	cout << "Age: "; cin >> age;
}
void Employee::Output(){
	countId++;
	id = countId;
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

int main(){
	int n;
	cout << "Input amount Employee: "; cin >> n;
	Employee e[n+1];
	for(int i = 1; i <= n; i++) {
		cout << "Input employee " << i << ": " << endl;
		e[i].Input();
	}
	cout << endl << "----------------------------------" << endl;
	for(int i = 1; i <= n; i++) {
		cout << "Information Employee " << i << ": " << endl;
		e[i].Output();
	}
}
