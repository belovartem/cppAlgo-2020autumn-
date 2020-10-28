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
	std::map<char, Point * > move_map;
};

class Automaton {
	private:
	std::vector<Point *> point;
	Point * current_point;

	public:
	Automaton(int A, int N){
		for (int i=0; i<N; i++){
			Point * p = new Point; 
			Point * fantom_point = new Point;

			for (int j=0; j<A; j++){
				fantom_point->move_map.insert(std::pair<char, Point * >('a'+j, fantom_point));
				p->move_map.insert(std::pair<char, Point * >('a'+j, fantom_point));
			}
			point.push_back(p);
		}
	}

	void set_termination(int a){
		point[a]->is_termination = true;
	}

	void set_termination_map(){
		int T;
		std::cin >> T;
		for (int i=0; i<T; i++){
			int a;
			std::cin >> a;
			set_termination(a);
		}		
	}

	void set_motion(int a,int b, char c){
		point[a]->move_map[c] = point[b];
	}

	void set_motion_map(){
		int M;
		std::cin >> M;
		for (int i=0; i<M; i++){
			int a,b;
			char c;
			std::cin >> a >> b >> c;
			set_motion(a,b,c);
		}
	}

	void set_map(){
		set_motion_map();
		set_termination_map();
	}

	bool is_string_stsf(std::string str){
		current_point = point[0];
		for (int j=0; j<str.size(); j++){
			char c = str[j];
			current_point = current_point->move_map[c];
		}
		return current_point->is_termination;
	}

};

int main(){
	int A, N;
	std::cin >> A >> N;
	
	Automaton * autom = new Automaton(A,N); 
	
	autom->set_map();

	int K;
	std::cin >> K;
	std::string str;
	str.reserve(8192);
	for (int i=0; i<K; i++){
		std::cin >> str;
		std::cout << autom->is_string_stsf(str) << std::endl;
	}
}
