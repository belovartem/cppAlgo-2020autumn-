/*
 * =====================================================================================
 *
 *       Filename:  solB.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09.10.2020 16:30:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <map>
#include <utility>
#include <iostream>

int main(){
	int N;
	std::map<std::pair<int, char>, std::pair<int, char> > map_of_pair;
	std::cin >> N;
	N *= 4;
	for (int i = 0; i<N; i++){
		int a, a_1;
		char c, c_1;
		std::cin >> a_1 >> c >> a >> c_1;

		auto p = std::make_pair(a, c);
		auto p_1 = std::make_pair(a_1, c_1);
		map_of_pair.insert(make_pair(p_1, p));
	}

	char c;
	int state = 1;
	while (std::cin >> c){
		auto pr = map_of_pair[std::make_pair(state, c)];
		state = std::get<0>(pr);
		std::cout << std::get<1>(pr);
	}
}

