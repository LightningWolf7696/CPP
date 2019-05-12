// 20190414_ex3.cpp: 主要專案檔。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#define N 52

using namespace std;

int main()
{
	string sPokerStyle[] = {"S","H","D","C"};
	string sPokerNum[] = {"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
	vector<int> poker(N);
	for(int i = 0; i<N; ++i ){
		poker[i] = i;
	}
	//
	for(int i = 0; i<poker.size(); ++i){
		cout << sPokerStyle[poker[i]/13] << sPokerNum[poker[i]%13] << '\0';
	}
	poker.push_back(99);
	poker.push_back(999);
	cout << "poker : " << poker.size();
	system("pause");
    return 0;
}
