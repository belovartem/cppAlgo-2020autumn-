/*
 * =====================================================================================
 *
 *       Filename:  sol4.cpp
 *
 *    Description: 4th task on http://cs.mipt.ru/cpp_algo/labs/lab17.html#id13 
 *
 *        Version:  1.0
 *        Created:  19.09.2020 00:32:25
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
#include <vector>

std::vector<int> method(std::vector<int> taken){
	int aux = 1;
	for (auto iter = --taken.end(); iter >= taken.begin(); iter--){
		int current = *iter + aux;
		taken[iter - taken.begin()] = current % 10;
		aux = current / 10;
	}
	if (aux == 1){taken.insert(taken.begin(),1);}
	return taken;
}


int main(){
	std::vector<int> abc= [1,2,3];
	std::cout << method(abc) << std::endl;
}
