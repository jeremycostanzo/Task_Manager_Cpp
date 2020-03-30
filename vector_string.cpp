#include "vector_string.h"

using namespace std;
string vector_to_string(vector<int> v){
	string s = "";
	for (int i : v){
		s += to_string(i);
		s += ' ';
	}
	return s;
}
vector<int> string_to_vector(string s){
	vector<int> v {};
	istringstream ss(s);
	string entier;
	while (ss >> entier){
		v.push_back(stoi(entier));
	}
	return(v);
}