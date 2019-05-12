// 20190324_ex1.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include <iostream>  // #include  <stdio.h>

using namespace std;
//�w�q���X�̦h���x�s�h�֤���
const int SIZE = 10;
//�]�w���X�����}�C���x�s���A
enum Status { empty, occupied };
struct Set {
	int element[SIZE];// �����}�C
	Status status[SIZE];// ���U�}�C
	int element_no;// �����Ӽ�
};
void set_initialization( Set& );
bool insert_element( Set&, int);
int delete_element( Set&, int);
void print_set( const Set&);
int main()
{
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
	//myData.status[2] = empty;  //�|�H�ϳW�h
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
	cout << "���X��" << foo.element_no << "���� �G" ;
	for( int i = 0 ; i < SIZE ; ++i ){
		if( foo.status[i] == occupied )
			cout << foo.element[i] << ' ';
	}
	cout << endl;
}