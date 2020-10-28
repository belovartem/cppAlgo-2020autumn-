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
	bool is_fantom = false;
	std::map<char,std::vector< Point * > > move_map;
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
			fantom_point->is_fantom = true;

			for (int j=0; j<A; j++){
				std::vector<Point * > move_spec;
				move_spec.push_back(fantom_point);
				p->move_map.insert(std::pair<char, std::vector<Point * > >('a'+j,  move_spec));
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
		if (point[a]->move_map[c][0]->is_fantom == true){point[a]->move_map[c][0] = point[b];}
		else{point[a]->move_map[c].push_back(point[b]);}
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
		if (current_point->is_fantom){return false;}
		if (str.length() == 0){return current_point->is_termination;}
		else{
			Point * aux_point = new Point;
			aux_point = current_point;
			for (int i=0; i<aux_point->move_map.size(); i++){
				current_point = aux_point->move_map[str[0]][i];
				if (is_string_stsf(str.erase(0,1))){return true;}
			}
		}
		return false;
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
