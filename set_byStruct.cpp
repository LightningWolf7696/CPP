// 20190324_ex1.cpp: 主要專案檔。

#include "stdafx.h"
#include <iostream>  // #include  <stdio.h>

using namespace std;
//定義集合最多能儲存多少元素
const int SIZE = 10;
//設定集合元素陣列的儲存狀態
enum Status { empty, occupied };
struct Set {
	int element[SIZE];// 元素陣列
	Status status[SIZE];// 輔助陣列
	int element_no;// 元素個數
};
void set_initialization( Set& );
bool insert_element( Set&, int);
int delete_element( Set&, int);
void print_set( const Set&);
int main()
{
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
	//myData.status[2] = empty;  //會違反規則
	print_set(myData);
	system("pause");
    return 0;
}
void set_initialization( Set& foo ){
	int i ;
	for(i=0 ; i<SIZE ; ++i) foo.status[i] = empty ;
	foo.element_no = 0; 
}
bool insert_element( Set& s , int data ){
	if( s.element_no == SIZE ) return false ;
	for( int i = 0 ; i < SIZE ; ++i ){ 
		if( s.status[i] == empty ){
			s.element[i] = data ;
			s.status[i]  = occupied ;
			++s.element_no ;
			return true ;
		}
	}
}
int delete_element( Set& s , int data ){
	int no_elements_deleted = 0 ;
	for( int i = 0 ; i < SIZE ; ++i ){
		if( s.status[i] == occupied && 
			s.element[i] == data ) {
				s.status[i] = empty ;
				--s.element_no ;
				++no_elements_deleted ;
		}
	}
	return no_elements_deleted;
}
void print_set( const Set& foo ){
	cout << "集合有" << foo.element_no << "元素 ：" ;
	for( int i = 0 ; i < SIZE ; ++i ){
		if( foo.status[i] == occupied )
			cout << foo.element[i] << ' ';
	}
	cout << endl;
}