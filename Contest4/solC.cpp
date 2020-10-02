/*
 * =====================================================================================
 *
 *       Filename:  solC.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02.10.2020 14:04:42
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

struct Cell {
	int* value;
	Cell *prev;

};

class MinStack { //ваш код

	private:
	Cell* last;

	public: 
	MinStack() { //ваш код
		Cell nothing;
		nothing.prev = nullptr;
		nothing.value = nullptr;
		this->last = &nothing;
   	}

	~MinStack() { //ваш код
		while(last != nullptr){
			last = last->prev;
		}
		last = nullptr; //the last of us was killed
	}

	void print() { //ваш код
		Cell *printThisCell = last;
		do{
			std::cout << printThisCell->value << std::endl;
			printThisCell = printThisCell->prev;
		}while(printThisCell != nullptr);	
	}

	void push(int x) { //ваш код
		if (&last->value == nullptr){
			last->value = &x;
		}else{
			Cell newLast;
			newLast.prev = last;
			newLast.value = &x;
			last = &newLast;
		}	   
	}

	void pop() { //ваш код 
		last = last->prev;
	}

	int top() { //ваш код 
		return *last->value; 
	} 

	int getMin() { //ваш код
		Cell *tmp = last;
		int value = *tmp->value;
		do{
			if (*tmp->value < value){value = *tmp->value;}
			tmp = tmp->prev;
		}while(tmp != nullptr);	
		return value; 
	} 
};


int main(){
	MinStack *mstack = new MinStack;
	mstack->getMin();
}
