/*Ce fichier permet d'écrire un vecteur de taches
dans un fichier et de lire un tableau de taches
depuis un fichier                              */

#ifndef IO
#define IO
#include <fstream>
#include <algorithm>
#include <functional>
#include "Task.h"

using namespace std;
void append_task(ifstream& file, vector<Task>* task_list);

vector<Task> of_path(string pat);

void write(vector<Task> v, string pat);

#endif