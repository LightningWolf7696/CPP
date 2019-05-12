// 20190414_ex2.cpp: 主要專案檔。

#include "stdafx.h"
#include <iostream>

using namespace std;
class FRACTION{
private:
	int num, den;
public:
	FRACTION():num(n),den(d){}
	//----------------------------
	void setNum(int n){
		num = n;
	}
	void setDen(int d){
		den = d;
	}
	int getNum() const {
		return num;
	}
	int getDen() const {
		return den;
	}
	//-----------------------------
	FRACTION add(const FRACTION &f) const{
		FRACTION tmp;
		tmp.den = this->den * f.den;
		tmp.num = this->num * f.den + f.num * this->den;
		return tmp;
	}
	FRACTION operator+(const FRACTION &f) const {
		FRACTION tmp;
		tmp.den = this->den * f.den;
		tmp.num = this->num * f.den + f.num * this->den;
		return tmp;	
	}
	void showFraction() const{
		cout << this->num << "/" << this->den << endl;
	}
};
ostream& operator<<(ostream&, const FRACTION&);

FRACTION operator-(const FRACTION &, const FRACTION &);
//FRACTION operator-(const int &, const FRACTION &);
int main(array<System::String ^> ^args)
{
    FRACTION a, b(3,2), c(5,4);
	//a = b.add(c);  // b=>this
	//member function
	a = b + c;     // operator+(b,c)    b.operator+(c)
	               // ^一般函式           ^成員函式
	//a = 2 + c; 錯 2不是物件
	//a = b + 2; 可
	a.showFraction();
	//gene function
	a = b - c;
    //a = 2 - c; 可
	//a = b - 2; 可

	//a.showFraction();
	cout << "a = " << a;
	cout << "b = " << b;
	cout << "c = " << c;
	system("pause");
    return 0;
}
FRACTION operator-(const FRACTION &f1, const FRACTION &f2){
	/*
	FRACTION tmp;
	tmp.setDen(f1.getDen() * f2.getDen());
	tmp.setNum(f1.getNum() * f2.getDen() - f1.getDen() * f2.getNum());
	return tmp;
	*/
	return FRACTION(f1.getNum() * f2.getDen() - f1.getDen() * f2.getNum(), f1.getDen() * f2.getDen());
}
ostream& operator<<(ostream& out, const FRACTION& f){
	out << f.getNum() << "/" << f.getDen() << endl;
	return out;
}