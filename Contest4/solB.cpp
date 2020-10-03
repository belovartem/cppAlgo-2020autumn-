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

int64_t GCD(int64_t a, int64_t b) {
	for (int64_t c; b; ) {
		c = a % b;
		a = b;
		b = c;
	}

	if (a>0){return a;}else{return -a;}
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
		uint64_t gcd = GCD(numerator, denominator);
		this->numerator = numerator/gcd; 
		this->denominator = denominator/gcd; 
	}
    
	//  Add operator overloads below

	Fraction operator+(Fraction obj2){
		int64_t g = GCD(this->denominator, obj2.denominator);
		int64_t l = this->denominator/g;
		int64_t r = obj2.denominator/g;

		int64_t auxNumerator = l * obj2.numerator + this->numerator * r;
		uint64_t auxDenominator = g * l * r;
		return Fraction(auxNumerator, auxDenominator);
	}

	Fraction operator*(Fraction obj2){
        int64_t l = GCD(this->numerator, obj2.denominator);
        int64_t r = GCD(obj2.numerator, this->denominator);
		int64_t k_1 = this->numerator/l;
		int64_t k_2 = this->denominator/r;
		int64_t k_3 = obj2.numerator/r;
		int64_t k_4 = obj2.denominator/l;	
		return Fraction(k_1*k_3, k_2*k_4);
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

