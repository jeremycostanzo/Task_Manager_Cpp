#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "vector_string.h"

using namespace std;

bool is_int(string s){
    char* p;
    int converted = strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

class Task{
 private:
  string title;
  string description;
  long creation_time;
  long deadline;
  int progress;
  string commentaries;
  vector<int> sub_tasks; // Contient les identifiants des sous taches
 public:
 	int id;	
 	string status; //"" / "Closed" / "In Progress".
 	string priority;
 	Task (int id,
 		 long deadline,
 		 string title  = "",
 		 string description = "",
 		 long creation_time = 0,
 		 string status = "",
 		 int progress = 0,
 		 string priority = "Medium",
 		 string commentaries = "", 
 		 vector<int> sub_tasks  = {}):

 		 id (id),
 		 title (title),
 		 description (description),
 		 creation_time(creation_time),
 		 deadline(deadline),
 		 status(status),
 		 progress(progress), 
 		 priority(priority),
 		 commentaries(commentaries),
 		 sub_tasks(sub_tasks) {}

 	string to_string(){
 		string subtstr = vector_to_string(sub_tasks);
 		stringstream a(ios_base::app | ios_base::out);
 		a << '\n' << id << '\n' << title << '\n' << description << '\n' << creation_time << '\n' << deadline << '\n' << status << '\n' << progress << '\n' << priority << '\n' << commentaries << '\n' << subtstr;
		return a.str();
	}
	~Task(){
		vector<int>().swap(sub_tasks);
	}

	Task (const Task& other):
    	id(other.id),
    	deadline(other.deadline),
    	title(other.title),
    	description(other.description),
    	creation_time(other.creation_time),
    	status(other.status),
    	progress(other.progress),
    	priority(other.priority),
    	commentaries(other.commentaries),
    	sub_tasks({})
    {
    for (auto i: other.sub_tasks){
    	sub_tasks.push_back(i);
    }
    }
    void operator= (const Task& other){
    	id = other.id;
    	deadline = other.deadline;
    	title = other.title;
    	description = other.description;
    	creation_time = other.creation_time;
    	status = other.status;
    	progress = other.progress;
    	priority = other.priority;
    	commentaries = other.commentaries;
    	sub_tasks.resize(0);
    	for (auto i: other.sub_tasks){
    		sub_tasks.push_back(i);
    	}
    }

	string print(){
 		string subtstr = vector_to_string(sub_tasks);
 		stringstream a(ios_base::app | ios_base::out);
 		chrono::high_resolution_clock::time_point t0 = std::chrono::time_point<std::chrono::high_resolution_clock>();

 		chrono::milliseconds crms (creation_time);
 		chrono::seconds crs = std::chrono::duration_cast<std::chrono::seconds>(crms);
 		chrono::high_resolution_clock::time_point crtp = t0 + crs;
 		time_t ctc = std::chrono::system_clock::to_time_t(crtp);
 		
 		chrono::milliseconds dlms (deadline);
 		chrono::seconds dls = std::chrono::duration_cast<std::chrono::seconds>(dlms);
 		chrono::high_resolution_clock::time_point dltp = t0 + dls;
 		time_t dlc = std::chrono::system_clock::to_time_t(dltp);

 		a << id << '\n' << title << '\n' << description << '\n' << ctime(&ctc) << '\n' << ctime(&dlc) << '\n' << status << '\n' << progress << '\n' << priority << '\n' << commentaries << '\n' << subtstr << '\n';
		return a.str();
	}

	string print_attr(vector<string> attr){
		string subtstr = vector_to_string(sub_tasks);
 		stringstream a(ios_base::app | ios_base::out);

 		chrono::high_resolution_clock::time_point t0 = std::chrono::time_point<std::chrono::high_resolution_clock>();

 		chrono::milliseconds crms (creation_time);
 		chrono::seconds crs = std::chrono::duration_cast<std::chrono::seconds>(crms);
 		chrono::high_resolution_clock::time_point crtp = t0 + crs;
 		time_t ctc = std::chrono::system_clock::to_time_t(crtp);
 		
 		chrono::milliseconds dlms (deadline);
 		chrono::seconds dls = std::chrono::duration_cast<std::chrono::seconds>(dlms);
 		chrono::high_resolution_clock::time_point dltp = t0 + dls;
 		time_t dlc = std::chrono::system_clock::to_time_t(dltp);

 		if (std::find(attr.begin(), attr.end(), "id") != attr.end())
 			a << "Id : " << id << endl;
 		if (std::find(attr.begin(), attr.end(), "title") != attr.end())
 			a << "Title : " << title << endl;
 		if (std::find(attr.begin(), attr.end(), "description") != attr.end())
 			a << "Description : " << description << endl;
 		if (std::find(attr.begin(), attr.end(), "creation_time") != attr.end())
 			a << "Creation time : " << ctime(&ctc);
 		if (std::find(attr.begin(), attr.end(), "deadline") != attr.end())
 			a << "Deadline : " << ctime(&dlc);
 		if (std::find(attr.begin(), attr.end(), "status") != attr.end())
 			a << "Status : " << status << endl;
 		if (std::find(attr.begin(), attr.end(), "progress") != attr.end())
 			a << "Progress : " << progress << endl;
 		if (std::find(attr.begin(), attr.end(), "priority") != attr.end())
 			a << "Priority : " << priority << endl;
 		if (std::find(attr.begin(), attr.end(), "commentaries") != attr.end())
 			a << "Commentaries : " << commentaries << endl;
 		if (std::find(attr.begin(), attr.end(), "subtasks") != attr.end())
 			a << "Subtasks : " << subtstr << endl;
		return a.str();

	}
	void set_comment(){
        cout << commentaries << endl << "New Commentaries :" << endl;
		getline(cin,commentaries);
	}	 
    void set_desc(){
        cout << description << endl << "New Description :" << endl;
        getline(cin, description);
    }
    void set_prog(){
        cout << progress << endl << "New Progress :" << endl;
        string s;
        cin >> s;
        progress = stoi(s);
    }
    void set_subt(){
        cout << vector_to_string(sub_tasks) << endl << "New Subtasks :" << endl;
        string s;
        getline(cin, s);
        sub_tasks = string_to_vector(s);
    }
    void set_dl(){
        chrono::milliseconds dlms (deadline);
        chrono::seconds dls = std::chrono::duration_cast<std::chrono::seconds>(dlms);
        chrono::high_resolution_clock::time_point t0 = std::chrono::time_point<std::chrono::high_resolution_clock>();
        chrono::high_resolution_clock::time_point dltp = t0 + dls;
        time_t dlc = std::chrono::system_clock::to_time_t(dltp);
        cout << ctime(&dlc) << endl << "New deadline as second minute hour day month year:" << endl;
        string s;
        getline(cin, s);
        istringstream ss(s);
        vector<string> fields;
        string field;
        while (ss >> field){
            fields.push_back(field);
        }
        if (all_of(fields.begin(), fields.end(), [](string s){return is_int(s);}) and fields.size() == 6){
            tm tmdl = {
            stoi(fields[0]), // Second
            stoi(fields[1]), // Minute
            stoi(fields[2]) - 1, // Hour je met un -1 parce que sinon ça marche pas
            stoi(fields[3]), // Day
            stoi(fields[4]) - 1, // Month Pareil pour le -1
            stoi(fields[5]) - 1900, // Year La il faut mettre -1900, vive le C
            };
            chrono::high_resolution_clock::time_point tpdl = chrono::system_clock::from_time_t(mktime(&tmdl));
            chrono::milliseconds ms = chrono::duration_cast<std::chrono::milliseconds>(tpdl.time_since_epoch());
            deadline = long{ms.count()};
        }
        else{
            cout << "invalid format\n";
        }        
    }
    void set_tit(){
        cout << title << endl << "New title:" << endl;
        getline(cin, title);
    }
    void set_stat(){
        cout << status << endl << "New Status:" << endl;
        getline(cin, status);   
    }
    void set_prio(){
        cout << priority << endl << "New priority in\nHigh, Medium, Low :" << endl;
        getline(cin, status);      
    }
}
;
Task set_commentaries(Task t){
    t.set_comment();
    return t;
}
Task set_description(Task t){
    t.set_desc();
    return t;
}
Task set_progress(Task t){
    t.set_prog();
    return t;
}
Task set_subtasks(Task t){
    t.set_subt();
    return t;
}
Task set_deadline(Task t){
    t.set_dl();
    return t;
}
Task set_title(Task t){
    t.set_tit();
    return t;
}
Task set_status(Task t){
    t.set_stat();
    return t;
}
Task set_priority(Task t){
    t.set_prio();
    return t;
}