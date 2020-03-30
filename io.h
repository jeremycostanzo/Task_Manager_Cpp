#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;
void append_task(ifstream& file, vector<Task>* task_list){ // On suppose que le fichier à lire commence par une tache
	string ids;
	string title;
	string description;
	string creation_times;
	string deadlines;
	string commentaries;
	string status;
	string progresss;
	string priority;
	string substr;
	getline(file,ids);
	getline(file,title);
	getline(file,description);
	getline(file,creation_times);
	getline(file,deadlines);
	getline(file,status);
	getline(file,progresss);
	getline(file,priority);
	getline(file,commentaries);
	getline(file,substr);	
	int id = stoi(ids);
	long creation_time = stol(creation_times);
	long deadline = stol(deadlines);
	int progress = stoi(progresss);
	vector<int> subtasks = string_to_vector(substr);
	Task ts (id, deadline , title, description, creation_time, status, progress, priority, commentaries, subtasks);
	task_list->push_back(ts);
}
vector<Task> of_path(string path){
	ifstream input(path);
	//string st;
	vector<Task> got {};
	string l;
	while (getline(input,l)){
		append_task(input, &got);
	}
	sort(got.begin(),got.end(),[](const Task& a, const Task& b){return (a.id < b.id);});
	return got;
} 

void write(vector<Task> v, string path){
	ofstream tsks;
	tsks.open(path);
	for (Task i : v){
		string s = i.to_string();
		tsks << s;
		tsks << endl;
	}
	tsks.close();	
}