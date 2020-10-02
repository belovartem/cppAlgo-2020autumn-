/*
 * =====================================================================================
 *
 *       Filename:  solB.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.09.2020 11:09:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cmath>


uint64_t GCD(uint64_t a, uint64_t b) {
    uint64_t nod = 1L;
    uint64_t tmp;
    if (a == 0L)
        return b;
    if (b == 0L)
        return a;
    if (a == b)
        return a;
    if (a == 1L || b == 1L)
        return 1L;
    while (a != 0 && b != 0) {
        if (a % 2L == 0L && b % 2L == 0L) {
            nod *= 2L;
            a /= 2L;
            b /= 2L;
            continue;
        }
        if (a % 2L == 0L && b % 2L != 0L) {
            a /= 2L;
            continue;
        }
        if (a % 2L != 0L && b % 2L == 0L) {
            b /= 2L;
            continue;
        }
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        tmp = a;
        a = (b - a) / 2L;
        b = tmp;
    }
    if (a == 0)
        return nod * b;
    else
        return nod * a;
}

class Fraction {
private:
    // Do NOT rename
    int64_t numerator;
    uint64_t denominator;

    // Do NOT delete
    template < class T >
    friend bool operator==(const Fraction& lhs, const T& rhs);

public:
    Fraction() = delete;
    Fraction(const Fraction& rhs) : numerator(rhs.numerator), denominator(rhs.denominator) {}
    Fraction& operator=(const Fraction& rhs){this->numerator = rhs.numerator; this->denominator = rhs.denominator;}

    Fraction(int64_t numerator, uint64_t denominator){
		uint64_t gcd = GCD(abs(numerator), abs(denominator));
		this->numerator = numerator/gcd; 
		this->denominator = denominator/gcd; 
	}
    
	//  Add operator overloads below

	Fraction operator+(Fraction obj2){
		int64_t auxNumerator = this->denominator * obj2.numerator + this->numerator * obj2.denominator;
		uint64_t auxDenominator = this->denominator * obj2.denominator;
		return Fraction(auxNumerator, auxDenominator);
	}

	Fraction operator*(Fraction obj2){
		 return Fraction(this->numerator * obj2.numerator, this->denominator * obj2.denominator);
	}

	Fraction operator-(){
		Fraction result = *this;
		result.numerator = -result.numerator;
		return result;
	}

	Fraction operator-(Fraction obj2){
		return (*this + (-obj2));
	}	

	Fraction operator+=(Fraction obj2){
		return *this = (*this + obj2);
	}

	Fraction operator-=(Fraction obj2){
		return *this = (*this + obj2);
    }

	Fraction operator*=(Fraction obj2){
		return *this = (*this + obj2);
	}
};

