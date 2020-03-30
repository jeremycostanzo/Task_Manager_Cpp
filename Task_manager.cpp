#include "Task_manager.h"
using namespace std;

static string path = "Tasks.ts";

vector<string> all_attr = {"id","title","description","creation_time","deadline","status","progress","priority","commentaries","subtasks"};
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