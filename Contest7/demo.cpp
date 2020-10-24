/*
 * =====================================================================================
 *
 *       Filename:  demo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24.10.2020 09:58:54
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
#include <list>

template <typename Iter, typename Func>

void my_for_each(Iter ItBegin, Iter ItEnd, Func functor){
	for (auto it = ItBegin; it != ItEnd; ++it)
		std::cout << *it << std::endl;
}


int main(){
	std::vector<int> a = {1,2,3,4,5,6};
	std::list<int> lst;
	lst.push_back(1); lst.push_back(2); lst.push_back(3);

	std::list<int>::iterator it = lst.begin();
	*it = 4;

	std::list<int>::const_iterator it = lst.cbegin();
	//*it = 5; //не сработает
	std::cout << ++it << std::endl;
	return 0;

	std::forward_list<int> flst;
	flst.push_front(1); flst.push_front(-2); flst.push_front(3);

	std::for_each(flst.begin(), flst.end(), [](int i){
		std::cout << i << std::endl;
	});
	std::sort(flst.begin(), flst.end());
	std::for_each(flst.begin(), flst.end(), [](int){
		std::cout << i << std::endl;			
	});

}
