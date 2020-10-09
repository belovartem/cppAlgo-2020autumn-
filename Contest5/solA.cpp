/*
 * =====================================================================================
 *
 *       Filename:  solA.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09.10.2020 12:01:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stack>
#include <iterator>
#include <iostream>

int main(){
	std::stack<int> stack_of_integer;
	
	int a;
	int b;
	char c;

	if (std::cin >> a){
		stack_of_integer.push(a);
		}else{
			std::cin.clear();
			std::cin >> c;	
			switch (c)
			{
				case '*':
					a = stack_of_integer.top();
					stack_of_integer.pop();
					b = stack_of_integer.top();
					stack_of_integer.pop();
					stack_of_integer.push(a*b);
					break;
				case '+':
					std::cout << '+';
					a = stack_of_integer.top();
					stack_of_integer.pop();
					b = stack_of_integer.top();
					stack_of_integer.pop();
					stack_of_integer.push(a+b);
					break;
				case '-':
					a = stack_of_integer.top();
					stack_of_integer.pop();
					b = stack_of_integer.top();
					stack_of_integer.pop();
					stack_of_integer.push(a-b);
					break;
				case '/':
					a = stack_of_integer.top();
					stack_of_integer.pop();
					b = stack_of_integer.top();
					stack_of_integer.pop();
					stack_of_integer.push(a/b);
					break;
			}
			
	}


	std::cout << stack_of_integer.top();
	return 0;
}
