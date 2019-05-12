// 20190324_ex4.cpp: 主要專案檔。

#include "stdafx.h"
#include <iostream>

using namespace std;
class CCOMPLEX{
private:
	double real;
	double image;
public:
	CCOMPLEX();
	CCOMPLEX(double, double);
	CCOMPLEX add(CCOMPLEX &);
	CCOMPLEX sub(CCOMPLEX &);
	CCOMPLEX mul(CCOMPLEX &);
	CCOMPLEX div(CCOMPLEX &);
	void show() const;
};

int main()
{
    CCOMPLEX a(2.0,3.0), b(4.0,5.0);
	a.add(b).show();
	//b.sub(a).show();
	system("pause");
    return 0;
}
CCOMPLEX::CCOMPLEX(){
	real = 0.0;
	image = 0.0;
}
CCOMPLEX::CCOMPLEX(double m, double n){
	real = m;
	image = n;
}
CCOMPLEX CCOMPLEX::add(CCOMPLEX &b){
	CCOMPLEX temp;
	temp.real = this->real + b.real;
	temp.image = this->image +b.image;
	return temp;
}
CCOMPLEX CCOMPLEX::sub(CCOMPLEX &b){
	CCOMPLEX temp;

	return temp;
}
void CCOMPLEX::show() const{
	cout << this->real << '+' << this->image << 'i' << endl;
}