// 20190414_ex1.cpp: 主要專案檔。

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
		cout << name << no << " 物件被建立....\n";
	}
	CAR(string n){
		++iCount;
		speed = 0;  //留意 要給初始值
		name = n;
		no = iCount;
		cout << name << no << " 物件被建立....\n";
	}
	~CAR(){
		cout << name << "物件被消滅....\n";
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
//第一次CAR物件被建立時  執行
int CAR::iCount = 0;
//一般函式
void showCar(const CAR &);

int main()

{
    CAR TOYOTA, BMW("小白");
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
	cout << "第" << c.showno() << "車 : " << c.showName() << " : " << c.showSpeed() << endl;
	static CAR HONDA("小黑");
}
