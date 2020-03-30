#include "Fonctionalites.h"
using namespace std;

vector<Task> vt = of_path(path);
	map<string, function<void(vector<string>)>> mf = {
		{"help", help},
		{"list", list},
		{"new", newt},
		{"remove", removet},
		{"modify", modify}
	};

int main(int argc, char** argv){
	vector<string> arguments (argv + 1, argv + argc); 
 	
	if (arguments.size() == 0){
		help(arguments);
		return(0);
	}
	else{
		mf[arguments[0]](arguments);
		return 0;
	}
}