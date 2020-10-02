/*
 * =====================================================================================
 *
 *       Filename:  sol3.cpp
 *
 *    Description: 3rd task on http://cs.mipt.ru/cpp_algo/labs/lab17.html#id13 
 *
 *        Version:  1.0
 *        Created:  18.09.2020 23:40:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (Belov Artem), 
 *   Organization:  MIPT (student)
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>


int main(){
	std::vector<std::string> sequence;

	// R = +1; L = -1;
	
	int ind = 0;
	std::string st = "";
	std::string stroka;
	std::cin >> stroka;
	
	for (auto iter = stroka.begin(); iter < stroka.end(); iter++){
		if (*iter == 'R'){ind++;}else{ind--;}
		st.push_back(*iter);
		if (ind == 0){
			sequence.push_back(st);
			st = "";
		}
	}

	std::cout << sequence.size() << std::endl;
	for (auto it = sequence.begin(); it < sequence.end(); it++){
		std::cout << *it << " ";
	}

}

