#ifndef FONCH
#define FONCH
#include <string>
#include <iostream>
#include "Task.h"
#include <functional>
#include <sstream>
#include "FP.h"
#include "io.h"
#include <map>
#include <vector>

bool cond_true(Task t);
string list_tasks(vector<Task> vt, vector<string> attr, function<bool(Task)> cond);
int lowest_id(vector<Task> vt);
Task create_task(vector<Task>* vt,
				  string title,
				  string description,
				  string month_closure,
				  string day_closure,
				  string hour_closure,
				  string minute_closure,
				  string second_closure,
				  string year_closure,
				  string status,
				  string progress,
				  string priority,
				  string commentaries,
				  string subtasks);// on suppose vt ordonné par id
function<bool (Task)> condition (string s);
void newt(vector<string> args);
void removet(vector<string> arguments);
void list(vector<string> arguments);
void help(vector<string> arguments);
void modify(vector<string> arguments);

#endif