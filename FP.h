/*Ce fichier contient des fonctions que j'aimais 
utiliser en CAML mais qui n'existent pas ou dont 
la syntaxe est plus compliquée en
C++                                            */

#ifndef FP
#define FP
#include "Task.h"
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

template <class G, class T>
vector<T> list_map(function <T(G)> f, vector<G> v){
	vector<T> nv = {};
	for (G i: v){
		nv.push_back(f(i));
	}
	return nv;
}

template <class T>
vector<T> list_filter(function <bool(T)> f, vector<T> v){
	vector<T> nv = {};
	for (T i: v){
		if (f(i)){
			nv.push_back(i);
		}
	}
	return nv;
}
template <class T>
bool is_in(T a, vector<T> v){
	for (T i : v){
		if (a == i)
			return true;
	}
	return false;
}
#endif