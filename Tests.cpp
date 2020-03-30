#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "FP.h"
#include "io.cpp"
#include "vector_string.cpp"
#include "Fonctionalites.cpp"
#include "Task.cpp"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

TEST_CASE() {
	SECTION( "Testing vector string in vector_string.cpp"){
		string s = "0 2 -2 3 42 ";
		vector<int> v = string_to_vector(s);
		string s1 = vector_to_string(v);
		REQUIRE(s1 == s);
	}

    SECTION( "Testing input and output : io.cpp" ) {
		vector<Task> vectest = of_path("testsampleread.txt");
		write(vectest, "testsamplewrite.txt");
		ifstream t1("testsampleread.txt");
		ifstream t2("testsamplewrite.txt");
		stringstream ss1;
		stringstream ss2;
		ss1 << t1.rdbuf();
		ss2 << t2.rdbuf();
		REQUIRE(ss1.str() == ss2.str());
    }
}