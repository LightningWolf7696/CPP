// 20190324_ex3.cpp: 璶盡郎

#include "stdafx.h"
#include <iostream>

using namespace std;
class FRACTION{
private:
	int num;
	int den;
public:
	//FRACTION();
	FRACTION(int m = 0, int n = 1); //ノ把计箇砞 搭ぶ更级糶
	FRACTION add(FRACTION &);
	FRACTION sub(FRACTION &);
	FRACTION mul(FRACTION &);
	FRACTION div(FRACTION &);
	void show();
};

int main()
{
    FRACTION a(1,2), b(2,3), c, d(5);
	a.add(b).show();
	b.sub(a).show();
	system("pause");
    return 0;
}
/*  炊
FRACTION::FRACTION(){
	num = 0;
	den = 1;//ㄢ ﹚笲衡
}
*/
//FRACTION::FRACTION():num(0),den(1){} //ㄎ  纔
FRACTION::FRACTION(int m, int n){
	num = m;
	den = n;
}
FRACTION FRACTION::add(FRACTION &b){
	FRACTION temp;
	temp.den = this->den * b.den;
	temp.num = this->num * b.den + b.num * this->den;
	return temp;
}
FRACTION FRACTION::sub(FRACTION &b){
	FRACTION temp;
	temp.den = this->den * b.den;
	temp.num = this->num * b.den - b.num * this->den;
	return temp;
}
void FRACTION::show(){
	cout << this->num << '/' << this->den << endl;
}