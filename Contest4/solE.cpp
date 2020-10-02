/*
 * =====================================================================================
 *
 *       Filename:  solE.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02.10.2020 18:21:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <stack>
#include <iostream>

int main(){
	std::stack<int> stck;
	int a;
	do{
		std::cin >> a;
		if (a>0){
			stck.push(a);
		}
		if (a<0){
			if (stck.size()>0){
				if ((-a)>=stck.top()){stck.pop();
				}else{
					int c = stck.top();
					stck.pop();
					stck.push(c+a);}
			}
		}
	}while(a != 0);

	if (stck.size() == 0){std::cout << 0 << ' ' << -1 << std::endl;}
	else{
		std::cout << stck.size() << ' ' << stck.top() << std::endl;
		return 0;
	}

}



