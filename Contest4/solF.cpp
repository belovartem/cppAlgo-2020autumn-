/*
 * =====================================================================================
 *
 *       Filename:  solF.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.09.2020 09:37:38
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
#include <vector>
#include <stack>

int sum(std::stack<int> stck){
	int sum = 0;
	while (stck.size()!=0){
		sum += stck.top();
		stck.pop();
	}
	return sum;
}

int main(){
	int N;
	std::cin >> N;
	std::vector<std::stack<int> > vec(N); 
	for (int i=0;i<N;i++){
		int a,b,c;
		std::cin >> a >> b >> c;
		vec[a].push(c);
	}
	for (int i=0; i<N; i++){
		if (vec[i].size() == 0){continue;}
		std::cout << i <<  ' ' << vec[i].size() << ' ' << sum(vec[i]) << std::endl;
	}
}

