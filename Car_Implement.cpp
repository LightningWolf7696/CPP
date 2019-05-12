// 20190414_ex1.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
class CAR{
private:
	int no;
	int speed;
	string name;
public:
	static int iCount;
	CAR(){
		++iCount;
		speed = 0;
		name = "";
		no = iCount;
		cout << name << no << " ����Q�إ�....\n";
	}
	CAR(string n){
		++iCount;
		speed = 0;  //�d�N �n����l��
		name = n;
		no = iCount;
		cout << name << no << " ����Q�إ�....\n";
	}
	~CAR(){
		cout << name << "����Q����....\n";
		--iCount;
	}
	void speedup(const int s = 0){
		speed += s;
		//speed = speed + s;
	}
	void speeddown(const int s = 0){
		speed -=s;
	}
	void setBreak(){
		speed = 0;
	}
	int showSpeed() const {
		return speed;
	}
	string showName() const {
		return name;
	}
	int showno() const {
		return no;
	}

};
//�Ĥ@��CAR����Q�إ߮�  ����
int CAR::iCount = 0;
//�@��禡
void showCar(const CAR &);

int main()

{
    CAR TOYOTA, BMW("�p��");
	TOYOTA.speedup(5);
	TOYOTA.speedup(100);
	BMW.speedup(99);
	//cout << TOYOTA.showName() << " : " << TOYOTA.showSpeed() << endl;
	//cout << BMW.showName() << " : " << BMW.showSpeed() << endl;
	showCar(TOYOTA);
	showCar(BMW);


	cout << CAR::iCount << endl;
	system("pause");
    return 0;
}
void showCar(const CAR &c){
	cout << "��" << c.showno() << "�� : " << c.showName() << " : " << c.showSpeed() << endl;
	static CAR HONDA("�p��");
}
