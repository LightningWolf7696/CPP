// 20190324_ex5.cpp: 主要專案檔。

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#define N 5

using namespace std;
enum myOperator{add, sub, mul, divi};
class QUESTION{
private:
	int iLeft;
	int iRight;
	int iAnswer;
	myOperator opt;
public:
	QUESTION();
	void show();
	bool veri(int);
	void showAnswer();
};

int main()
{
    srand(unsigned(time(NULL)));
	int iUserInput, iCount = 0;
	QUESTION myExam[N];
	for(int i = 0; i<N; ++i){
		myExam[i].show();
		cin >> iUserInput;
		if (myExam[i].veri(iUserInput)) iCount++;
	}
	cout << "答對 " << iCount << " 題" << endl;
	for(int i = 0; i<N; ++i){
		myExam[i].showAnswer();
	}
	system("pause");
    return 0;
}
QUESTION::QUESTION(){
	iLeft = rand()%100 + 1;
	iRight = rand()%100 + 1;
	int tmp = rand()%3;
	switch(tmp){
	case 0:
		opt = add;
		iAnswer = iLeft + iRight;
		break;
	case 1:
		opt = sub;
		iAnswer = iLeft - iRight;
		break;
	case 2:
		opt = mul;
		iAnswer = iLeft * iRight;
		break;

	}
}
void QUESTION::show(){
	cout << setw(3) <<iLeft;
	switch(opt){
	case add:
		cout << " + ";
		break;
	case sub:
		cout << " - ";
		break;
	case mul:
		cout << " * ";
		break;
	}
	cout << setw(3) << iRight << " = ";
}
bool QUESTION::veri(int answer){
	return this->iAnswer == answer;
}
void QUESTION::showAnswer(){
	cout << setw(3) <<iLeft;
	switch(opt){
	case add:
		cout << " + ";
		break;
	case sub:
		cout << " - ";
		break;
	case mul:
		cout << " * ";
		break;
	}
	cout << setw(3) << iRight << " = " << iAnswer << endl;
}