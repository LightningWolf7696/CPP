// 20190324_ex2.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include <iostream>  // #include  <stdio.h>

using namespace std;
//�w�q���X�̦h���x�s�h�֤���
const int SIZE = 10;
//�]�w���X�����}�C���x�s���A
enum Status { empty, occupied };
class Set {
private: //tag
	int element[SIZE];// �����}�C
	Status status[SIZE];// ���U�}�C
	int element_no;// �����Ӽ�
public:
	//�غc�l
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
	cout << (insert_element(myData, 5)?"�[�J���\\n":"�[�J����\n");
	cout << (insert_element(myData, 4)?"�[�J���\\n":"�[�J����\n");
	cout << (insert_element(myData, 3)?"�[�J���\\n":"�[�J����\n");
	cout << (insert_element(myData, 2)?"�[�J���\\n":"�[�J����\n");
	cout << (insert_element(myData, 5)?"�[�J���\\n":"�[�J����\n");
	print_set(myData);
	cout << "�R��" << delete_element(myData, 5) << "��"; 
	print_set(myData);
	*/
	Set myData;
	//myData.set_initialization();
	cout << (myData.insert_element(5)?"�[�J���\\n":"�[�J����\n");
	cout << (myData.insert_element(4)?"�[�J���\\n":"�[�J����\n");
	cout << (myData.insert_element(3)?"�[�J���\\n":"�[�J����\n");
	cout << (myData.insert_element(2)?"�[�J���\\n":"�[�J����\n");
	cout << (myData.insert_element(5)?"�[�J���\\n":"�[�J����\n");
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
	cout << "���X��" << element_no << "���� �G" ;
	for( int i = 0 ; i < SIZE ; ++i ){
		if( status[i] == occupied )
			cout << element[i] << ' ';
	}
	cout << endl;
}