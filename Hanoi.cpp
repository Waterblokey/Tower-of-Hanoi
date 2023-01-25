#include "Hanoi.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string Hanoi::lookup_moves(int num_discs, int src, int dst) const {
	return ("");
}



string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
	static string result = "";
	ostringstream stream;

	if (num_discs == 0) {
		return("");
	}
	if (num_discs == 1) {
		//stream << src;
		//result = stream.str() + "->";
		//stream.str("");
		//stream << dst;
		result.append(to_string(src) + "->" + to_string(dst) + '\n');
//		return result;
	}
//	else {
//		get_moves(num_discs - 1, src, tmp, dst);
//		//cout << src << "->" << dst << endl;
//		result.append(to_string(src) + "->" + to_string(dst) + '\n');
////		cout << result << endl;
//
//		get_moves(num_discs - 1, tmp, dst, src);
//		
//
//	}


	return(result);
}


string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
//	string preString = "# Below, \'A->B\' means \'move the top disc on pole A to pole B\'";
	return("");
//	return(get_moves(num_discs, src, dst, tmp));
}

//int main() {
//
//	Hanoi guy;
////	cout << "->" << endl;
//	cout << guy.solve(3, 2, 3, 1) << endl;
//}