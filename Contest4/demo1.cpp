/*
 * =====================================================================================
 *
 *       Filename:  demo1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.09.2020 09:13:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <algorithm>

int main(){
	unsigned N;
	std::cin >> N;
	std::istream_iterator<int> cin_it(std::cin);
	std::vector<int> vec;
	
	for (unsigned counter = 0; counter != N; ++counter){
		int tmp;
		std::cin >> tmp;
		vec.push_back(tmp);
		//аналогично

		vec.push_back(*cin_it);
	}	


	std::ostream_iterator<int> cout_it(std::cout, ' ');
	std::copy(vec.begin(), vec.end(), cout_it);
	std::cout << std::endl;

	std::set<int> int_set;
	int_set.insert(vec[0]);

	for (auto &x : vec)
		in_set.insert(x);

	for (auto it = )

	std::cout << int_set.size();


	return 0;
}

 
