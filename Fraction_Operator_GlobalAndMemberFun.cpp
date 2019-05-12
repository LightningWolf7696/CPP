// 20190414_ex5.cpp: 主要專案檔。

#include "stdafx.h"
#include <iostream>
#include <cassert>

using namespace std ;

// 絕對值
int abs( int a ) { return a > 0 ? a : -a ;  }
    
class  Fraction {

  private :

    // 分子與分母  ( 分母 > 0 )
    int  num , den ;  

    // 最大公因數
    int  gcd( int a , int b ) const {
        assert( a > 0 && b > 0 ) ;
        if ( a > b ) 
            return  ( a % b == 0 ? b : gcd( b , a % b ) ) ; 
        else 
            return  ( b % a == 0 ? a : gcd( a , b % a ) ) ; 
    }

  public :

    // 內定建構函式
    Fraction() {};

    // 建構函式 : 分母不等於零
    Fraction( int n , int d = 1 ) : num(n) , den(d) {
        assert( d != 0 ) ;
        if ( den < 0 ) { num *= -1 ; den *= -1 ; }
    }
    
    // 帶分數建構函式 : 分子大於等於零, 分母大於零
    Fraction( int a , int n , int d ) : den(d) {
        assert( d > 0 && n >= 0 ) ;
        num = ( a > 0 ? a * d + n : a * d - n ) ;
    }

    // 送出分子與分母
    int  get_den() const { return den ; }
    int  get_num() const { return num ; }

    // 成員函式 : 負號
    Fraction  operator-() {  return  Fraction(-num,den) ; }

    // 成員函式 : += , -= , *= , /=
    Fraction& operator+= ( const Fraction& a ) ;
    Fraction& operator-= ( const Fraction& a ) ;
    Fraction& operator*= ( const Fraction& a ) ;
    Fraction& operator/= ( const Fraction& a ) ;

    // 輸入運算子  : 接受 分子 / 分母 型式
    friend istream& operator >> ( istream& in , Fraction& foo ) {
        char  slash ;
        in >> foo.num >> slash  >> foo.den ;
        if ( foo.den < 0 ) { foo.num *= -1 ;  foo.den *= -1 ; }
        return in ;
    }
    
    // 輸出運算子  : 輸出約分後分數
    friend ostream& operator << ( ostream& out , 
                                  const Fraction& foo ) {
        int  num = ( foo.num > 0 ? foo.num : -foo.num ) ;
        int  den = foo.den ;
        int  divisor = ( num == 0 ? 1 : foo.gcd(num,den) ) ;
        return  out << foo.num/divisor << "/" << den/divisor ;
    }
    // 夥伴函式 + 
	friend Fraction  operator+ ( const Fraction& a , const Fraction& b ) {
		return  
		  Fraction( a.num*b.den + a.den*b.num ,
					a.den*b.den) ;
	}
} ;

// 全域函式 + 
/*
Fraction  operator+ ( const Fraction& a , const Fraction& b ) {
    return  
      Fraction( a.get_num()*b.get_den() + a.get_den()*b.get_num() ,
                a.get_den()*b.get_den() ) ;
}
*/

// 全域函式 - 
Fraction  operator- ( const Fraction& a , const Fraction& b ) {
    return  
      Fraction( a.get_num()*b.get_den() - a.get_den()*b.get_num() ,
                a.get_den()*b.get_den() ) ;
}

// 全域函式 * 
Fraction  operator* ( const Fraction& a , const Fraction& b ) {
    return  Fraction( a.get_num() * b.get_num() , 
                      a.get_den() * b.get_den() ) ;
}

// 全域函式 /
Fraction  operator/ ( const Fraction& a , const Fraction& b ) {
    return  Fraction( a.get_num() * b.get_den() , 
                      a.get_den() * b.get_num() ) ;
}

// 成員函式 += : 可以利用已有的 operator +
Fraction&  Fraction::operator+= ( const Fraction& a ) { 
    return *this = *this + a ; 
}

// 成員函式 -= : 可以利用已有的 operator -
Fraction&  Fraction::operator-= ( const Fraction& a ) { 
    return *this = *this - a ; 
}

// 成員函式 *= : 或者自行設計
Fraction&  Fraction::operator*= ( const Fraction& a ) { 
    num = num * a.num ;  den = den * a.den ;  
    return *this ;
}

// 成員函式 /= : 或者自行設計
Fraction&  Fraction::operator/= ( const Fraction& a ) { 
    num = num * a.den ;  den = den * a.num ;  
    if ( den < 0 ) { num *= -1 ; den *= -1 ; }
    return *this ;
}

// 全域函式 : 前置遞增
Fraction&  operator++( Fraction& a ) {
    return  a += 1 ;
}

// 全域函式 : 小於
bool  operator< ( const Fraction& a , const Fraction& b ) { 
    return  a.get_num()*b.get_den() < b.get_num()*a.get_den() ;
}
        
int main() {
        
    Fraction  a(2,3) , b(-1,3,2) , c(10,-6) ;
    
    cout << "> a = " << a << " , b = " << b 
         << " , c = " << c << endl ;

    cout << "> 2 + a * -b - c * b / 2 = " 
         << 2 + a * -b - c * b / 2 << "\n\n" ;

    a += b -= c + 2 ;
    cout << "> a += b -= c + 2 : " << '\n' 
         << "  a = " << a << " , b = " << b 
         << " , c = " << c << "\n\n" ;

    for ( Fraction d(0,1) ; d < 5 ; ++d ) cout << d << " " ;
    cout << "\n\n" ;
    
    cout << "> 輸入 分子/分母 形式 : " ;
    cin >> a ;
    cout << "> 輸出 : " << a << endl ;
	system("pause");
    return 0 ;
    
}

