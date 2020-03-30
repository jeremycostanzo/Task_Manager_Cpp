/*Ce fichier contient la classe Task qui
représente... UNE                     pisTACHE!*/

#ifndef TASK
#define TASK

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "vector_string.h"

using namespace std;

bool is_int(string s);

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
 		 string title,
 		 string description,
 		 long creation_time,
 		 string status,
 		 int progress,
 		 string priority,
 		 string commentaries, 
 		 vector<int> sub_tasks);

 	string to_string();
	~Task();
	Task (const Task& other);
    void operator= (const Task& other);

	string print();

	string print_attr(vector<string> attr);

	void set_comment();

  void set_desc();

  void set_prog();

  void set_subt();

  void set_dl();

  void set_tit();

  void set_stat();

  void set_prio();
}
;

/*Ces fonctions permettent d'être utilisées dans 
un dictionnaire défini dans Fonctionalites.h 
pour ne pas mettre des if de partout           */

Task set_commentaries(Task t);

Task set_description(Task t);

Task set_progress(Task t);

Task set_subtasks(Task t);

Task set_deadline(Task t);

Task set_title(Task t);

Task set_status(Task t);

Task set_priority(Task t);

#endif