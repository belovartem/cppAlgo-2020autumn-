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
	bool is_termination;
	std::map<char, Point * > move_map;
};

int main(){
	int A, M, N;
	std::cin >> A >> N >> M;
	std::vector<Point *> aut;
	for (int i=0; i<N; i++){
		Point * point = new Point;
		point->is_termination = false;
		std::map<char, Point * > move_map;
		point->move_map = move_map;
		aut.push_back(point);
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
	std::cin >> K;
	std::string str;
	str.reserve(8192);
	for (int i=0; i<K; i++){
		Point *p = aut[0];
		std::cin >> str;
		for (int j=0; j<str.size(); j++){
			char c = str[j];
			p = p->move_map[c];
		}
		std::cout << p->is_termination << std::endl;
	}
}
