/*
 * =====================================================================================
 *
 *       Filename:  demo3.cpp
 *
 *    Description: несколько слов для 3 задачи 
 *	обязательнопростое число
 *	минимальное число 49979687
 *	83886091
 *        Version:  1.0
 *        Created:  10.10.2020 11:24:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

uint64_t first_hash(uint64_t x) {
	return x ^ (x >> 5);
}

uint64_t second_hash(uint64_t x){
	return x ^ (x >> 17);
}

uint64_t third_hash(uint64_t x){
	return x ^ (x >> 13);
}

int main(){
	std::vector<bool> table(4000000000ULL,false);
	std::hash<string> primary_hash;
	std::string s;
	auto hash0 = primary_hash(s);
	auto id_1 = first_hash(hash0);
	auto id_2 = second_hash(hash0);
	auto id_3 = third_hash(hash0);
	
	table[id1] = table[id2] = table[id3] = true;

	table[id1] and table[id2] and table[id3];

	return 0;
}
