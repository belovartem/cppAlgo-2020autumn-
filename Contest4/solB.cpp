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

int GCD(int n1, int n2)
{
  int div;
  if (n1 == n2){return n1;}
  int d = n1 - n2;
  if (d < 0)       
  {
    d = -d;     
    div = GCD(n1, d);
  }
  else      
  {
    div = GCD(n2, d);
  }
  return div;
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
    Fraction& operator=(const Fraction& rhs){return rhs;}
    Fraction(int64_t numerator, uint64_t denominator){
		int gcd = GCD(abs(numerator), abs(denominator));
		this->numerator = numerator/gcd; 
		this->denominator = denominator/gcd; 
	}
    
	//  Add operator overloads below

	Fraction operator+(Fraction obj2){
		int auxNumerator = this->denominator * obj2.numerator + this->numerator * obj2.denominator;
		int auxDenominator = this->denominator * obj2.denominator;
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

