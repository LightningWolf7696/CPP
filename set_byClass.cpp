// 20190324_ex2.cpp: 主要專案檔。

#include "stdafx.h"
#include <iostream>  // #include  <stdio.h>

using namespace std;
//定義集合最多能儲存多少元素
const int SIZE = 10;
//設定集合元素陣列的儲存狀態
enum Status { empty, occupied };
class Set {
private: //tag
	int element[SIZE];// 元素陣列
	Status status[SIZE];// 輔助陣列
	int element_no;// 元素個數
public:
	//建構子
	Set();
	//void set_initialization();
	bool insert_element(int);
	int delete_element(int);
	void print_set() const;
};

int main()
{
    /*
	Set myData;
	set_initialization(myData);
	cout << (insert_element(myData, 5)?"加入成功\n":"加入失敗\n");
	cout << (insert_element(myData, 4)?"加入成功\n":"加入失敗\n");
	cout << (insert_element(myData, 3)?"加入成功\n":"加入失敗\n");
	cout << (insert_element(myData, 2)?"加入成功\n":"加入失敗\n");
	cout << (insert_element(myData, 5)?"加入成功\n":"加入失敗\n");
	print_set(myData);
	cout << "刪除" << delete_element(myData, 5) << "個"; 
	print_set(myData);
	*/
	Set myData;
	//myData.set_initialization();
	cout << (myData.insert_element(5)?"加入成功\n":"加入失敗\n");
	cout << (myData.insert_element(4)?"加入成功\n":"加入失敗\n");
	cout << (myData.insert_element(3)?"加入成功\n":"加入失敗\n");
	cout << (myData.insert_element(2)?"加入成功\n":"加入失敗\n");
	cout << (myData.insert_element(5)?"加入成功\n":"加入失敗\n");
	myData.print_set();
	//myData.status[2] = empty;
	system("pause");
    return 0;
}
//void Set::set_initialization(){
Set::Set(){
	int i ;
	for(i=0 ; i<SIZE ; ++i) status[i] = empty ;
	element_no = 0; 
}
bool Set::insert_element(int data ){
	if( element_no == SIZE ) return false ;
	for( int i = 0 ; i < SIZE ; ++i ){ 
		if( status[i] == empty ){
			element[i] = data ;
			status[i]  = occupied ;
			++element_no ;
			return true ;
		}
	}
}
int Set::delete_element(int data ){
	int no_elements_deleted = 0 ;
	for( int i = 0 ; i < SIZE ; ++i ){
		if( status[i] == occupied && 
			element[i] == data ) {
				status[i] = empty ;
				--element_no ;
				++no_elements_deleted ;
		}
	}
	return no_elements_deleted;
}
void Set::print_set() const {
	cout << "集合有" << element_no << "元素 ：" ;
	for( int i = 0 ; i < SIZE ; ++i ){
		if( status[i] == occupied )
			cout << element[i] << ' ';
	}
	cout << endl;
}