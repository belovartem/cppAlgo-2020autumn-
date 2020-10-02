/*
 * =====================================================================================
 *
 *       Filename:  sol1.cpp
 *
 *    Description: 1st task on http://cs.mipt.ru/cpp_algo/labs/lab17.html#id3 
 *
 *        Version:  1.0
 *        Created:  18.09.2020 19:43:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (Belov Artem), 
 *   Organization:  MIPT (student)
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <iostream>

int main(){
	std::string st1, st2;	
    st1.reserve(1000);	
    st2.reserve(1000);	
	std::string st_sum;

	std::cin >> st1 >> st2;

	st1.insert(0,"0");
	st2.insert(0,"0");

	while (st1.length()<st2.length()) {st1.insert(0,"0");}
	while (st1.length()>st2.length()) {st2.insert(0,"0");}

	int c = 0;
	int sum_i = 0;

	auto it2 = st2.end();
	auto it1 = st1.end();
	it1--;
	it2--;

	for ( ; it1 >= st1.begin();it1--,it2--){
		int a = *it1 - char('0');
		int b = *it2 - char('0');
		sum_i = (a+b+c)%2;
		c = (a+b+c)/2;
		if (sum_i == 0){st_sum.insert(0,"0");}else{st_sum.insert(0,"1");}
	}

	if (st_sum[0] == '0') {st_sum.erase(0,1);}

	std::cout << st_sum << std::endl;

}


