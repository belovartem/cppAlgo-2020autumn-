/*
 * =====================================================================================
 *
 *       Filename:  demo2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.09.2020 09:44:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

struct EdgeInfo final {
	EdgeInfo(): EdgeInfo(0,0) { }
	EdgeInfo(unsigned count, unsigned full_weight): count(count), full_weight(full_weight) { }
	unsigned count, full_weight;
};

int main(){

	std::map<int, EdgeInfo> edge_map;

	unsigned vout_id, vin_id, weight;
	std::cin >> vout_id >> vin_id >> weight;

	auto it = edge_map.find(vout_id);
/*	if (edge_map.end() == it){
		edge_map.insert(std::make_pair(vout_id, EdgeInfo{1,weight}))
	}*/

	auto &info = edge_map[vout_id];
	++info.cout; info.full_weight += weight;

	for (auto &x : edge_map)
		std::cout << x->first << ' ' << x->second.count << ' ' << x->second.full_weight << std::endl;


	return 0;
}


