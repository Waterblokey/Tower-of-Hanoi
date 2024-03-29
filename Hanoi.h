// student ID: 20487661

#ifndef Hanoi_h
#define Hanoi_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hanoi {
private:
	// TODO: Declare the _cache member using an appropriate
	// level of nesting within std::vectors to put each string
	// of moves. You should be able to access the cache like so:
	// _cache[num_discs][src][dst] = "move1\nmove2\n..."

	vector<vector<vector<string>>> _cache;
//	int _count = 0;
//	string _result;
	string lookup_moves(int num_discs, int src, int dst) const;
	string get_moves(int num_discs, int src, int dst, int tmp);
public:
	// Use freebie default constructor
	std::string solve(int num_discs, int src, int dst, int tmp);
	friend class Tests; // Don't remove this line
};

#endif