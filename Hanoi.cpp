#include "Hanoi.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// check if this cache entry exists. If it does, return it.
string Hanoi::lookup_moves(int num_discs, int src, int dst) const {
	if (_cache.size() == 0) {
		return("");
	}
	else if (_cache[num_discs].size() == 0) {
		return("");
	}
	else if (_cache[num_discs][src].size() == 0) {
		return("");
	}
	else if (_cache[num_discs][src][dst] == "") {
		return ("");
	}
	else {
		return(_cache[num_discs][src][dst]);
	}
}



string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
	// this is so they are unsigned, and can be compared with .size()
	size_t unum_discs = num_discs;
	size_t usrc = src;
	size_t udst = dst;
	string temp;


	//  resize cache if necessary
	if (unum_discs >= _cache.size()) {_cache.resize(num_discs + 1);}

	if (usrc >= _cache[num_discs].size()) { _cache[num_discs].resize(src + 1);}

	if (udst >= _cache[num_discs][src].size()) {_cache[num_discs][src].resize(dst + 1);}

	// if path is cached, return and clear previous entries
	if (lookup_moves(num_discs, src, dst) != "") {
		_cache[num_discs - 1].clear();

		return(lookup_moves(num_discs, src, dst));
	}

	// base case to stop recursion
	if (num_discs == 0) {
		_cache[num_discs][src][dst] = "";
		return("");
	}

	// first recursive call simulates moving n-1 discs to the temp pole.
	// second recursive call moves n disc (largest) to bottom of dst,
	// then moves the rest of the discs to dst as well.
	else {
		string prevResult = get_moves(num_discs - 1, src, tmp, dst);

		string currResult = to_string(src) + "->" + to_string(dst) + '\n';
	
		string nextResult = get_moves(num_discs - 1, tmp, dst, src);

		if (_cache[num_discs][src][dst] == "") { //if cache entry DNE, clear previous entries and add this one.
			_cache[num_discs - 1].clear();
			_cache[num_discs][src][dst] = (prevResult + currResult + nextResult);
		}

		return(prevResult + currResult + nextResult);
	}
	
}



string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
	return("# Below, 'A->B' means 'move the top disc on pole A to pole B'\n" + get_moves(num_discs, src, dst, tmp));
}