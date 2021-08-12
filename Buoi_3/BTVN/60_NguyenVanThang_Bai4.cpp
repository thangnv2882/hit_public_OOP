#include<iostream>
#include<string.h>
using namespace std;

class SCHOOL {
private:
	char Name[25];
	char Date[25];
	friend class FACULTY;	
};

class FACULTY {
private:
	char Name[25];
	char Date[25];
	SCHOOL x;
public:
	void input();
	void output();
};

class STUDENT {
private:
	FACULTY y;
	char Class[25];
	float Score;
public:
	void input();
	void output();
	STUDENT();
};

void FACULTY::input(){
	cout << "Faculty name: "; fflush(stdin); gets(Name);
	cout << "Faculty date: "; fflush(stdin); gets(Date);
	cout << "School name: "; fflush(stdin); gets(x.Name);
	cout << "School date: "; fflush(stdin); gets(x.Date);
}
void FACULTY::output(){
	cout << "Faculty name: " << Name << endl;
	cout << "Faculty date: " << Date << endl;
	cout << "School name: " << x.Name << endl;
	cout << "School date: " << x.Date << endl;
}

STUDENT::STUDENT(){
	strcpy(Class, "");
	Score = 0;
}
void STUDENT::input(){
	y.input();
	cout << "Class: "; fflush(stdin); gets(Class);
	cout << "Score: "; cin >> Score;
}
void STUDENT::output(){
	y.output();
	cout << "Class: " << Class << endl;
	cout << "Score: " << Score << endl;
}

int main(){
	int n;
	cout << "Nhap so sinh vien: "; cin >> n; 
	STUDENT s[n+1];
	
	for(int i = 1; i <= n; i++){
		cout << endl << "Nhap thong tin sinh vien " << i << endl;
		s[i].input();
	}
	cout << "------------------------------" << endl;
	for(int i = 1; i <= n; i++){
		cout << endl << "Thong tin sinh vien " << i << endl;
		s[i].output();
	}	
	
	return 0;
}
