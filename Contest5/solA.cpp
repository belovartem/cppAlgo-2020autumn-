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
#include <string>

int main(){
	std::stack<int> stack_of_integer;
	int a;
	int b;
	char c;
	std::string s;

	while (true){
		std::cin >> s;
		if (0 == s.length()){break;}
		if (1 == s.length()){
			switch(s[0]){
				case '*':
					a = stack_of_integer.top();
					stack_of_integer.pop();
					b = stack_of_integer.top();
					stack_of_integer.pop();
					stack_of_integer.push(a*b);
					break;
				case '+':
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
				default:
					stack_of_integer.push(stoi(s));
			}
		}else{stack_of_integer.push(stoi(s));}
	}

	std::cout << stack_of_integer.top();
	return 0;
}
