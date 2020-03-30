/*Ce fichier permet de convertir un vecteur 
d'entiers en string et vice versa              */

#ifndef VECTOR_TO_STRING
#define VECTOR_TO_STRING
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string vector_to_string(vector<int> v);
vector<int> string_to_vector(string s);

#endif