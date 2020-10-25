/*
 * =====================================================================================
 *
 *       Filename:  solC.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25.10.2020 12:48:19
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
#include <map>
#include <utility>



struct Point {
	bool is_termination = false;
	std::map<char, Point *> move_map;
};

int main(){
	int A, M, N;
	std::cin >> A >> N >> M;
	std::vector<Point *> aut;
	for (int i=0; i<N; i++){
		Point * point = new Point;
		aut[i] = point;
		std::cout << "hello" << std::endl;
	}

	for (int i=0; i<M; i++){
		int a, b;
		char c;
		std::cin >> a >> b >> c;
		aut[a]->move_map.insert(std::pair<char, Point *>(c, aut[b]));
	}

	int T;
	std::cin >> T;
	for (int i=0; i<T; i++){
		int a;
		std::cin >> a;
		aut[a]->is_termination = true;
	}
	
	int K;
	std::string str;
	for (int i=0; i<K; i++){
		Point *point = aut[0];
		std::getline(std::cin, str);
		for (int j=0; j<str.length(); j++){
			char c = str.front();
			str.erase(0,1);
			point = point->move_map[c];
		}
		std::cout << point->is_termination << std::endl;
	}
}
