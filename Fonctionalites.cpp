#include "Fonctionalites.h"
using namespace std;

static string path = "Tasks.ts";
static string helpfile = "Help.ts";


string list_tasks(vector<Task> vt, vector<string> attr, function<bool(Task)> cond){
	vector<Task> vtc = list_filter(cond, vt);
	if (vtc.size() == 0){
		return "";
	}
	vector<string> vtcm = list_map((function<string(Task)>)[&attr](Task t){return (t.print_attr(attr));},vtc);
	stringstream a(ios_base::app | ios_base::out);
	for (int i = 0; i < vtcm.size() - 1; ++i){
		a << vtcm[i] << endl;
	}
	a << vtcm[vtcm.size()-1];
	return a.str();
}

int lowest_id(vector<Task> vt){
	int	lid = 1;
	for (int i = 0; i < vt.size(); i++){
		if (vt[i].id > lid){
			return lid;
		}
		else{
			lid += 1;
		}
	}
	return lid;
}

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
				  string subtasks){//on suppose vt ordonné par id

	std::chrono::high_resolution_clock::time_point p = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(p.time_since_epoch());
	long creation_time {ms.count()};
	int lid = lowest_id(*vt);
	
	tm tmdl = {
		stoi(second_closure),
		stoi(minute_closure),
		stoi(hour_closure),
		stoi(day_closure),
		stoi(month_closure) - 1,
		stoi(year_closure) - 1900,
	};
	chrono::high_resolution_clock::time_point tpdl = chrono::system_clock::from_time_t(mktime(&tmdl));
	ms = chrono::duration_cast<std::chrono::milliseconds>(tpdl.time_since_epoch());
	long deadline {ms.count()};
	Task t = Task(lid, deadline, title, description, creation_time, status, stoi(progress), priority, commentaries, string_to_vector(subtasks));
	vt->push_back(t);
	return t; 
}

bool cond_true(Task t){
		return true;
}


function<bool (Task)> condition (string s){
	return [s](Task t)->bool{t.priority == s;}; 
}

void newt(vector<string> args){
		vector<Task> vt = of_path(path);
		if (args.size() != 14){
			cout << "wrong amount of arguments for new.\nTo append a task, do it like this :\nnew title description month_closure day_closure hour_closure minute_closure second_closure year_closure status progress priority commentaries \"subtasks\"" << endl;
		}
		else{
			string title = args[1];
			string description = args[2];
			string month_closure = args[3];
			string day_closure = args[4];
			string hour_closure = args[5];
			string minute_closure = args[6];
			string second_closure = args[7];
			string year_closure = args[8];
			string status = args[9];
			string progress = args[10];
			string priority = args[11];
			string commentaries = args[12];
			string subtasks = args[13];
			Task t = create_task(
			 &vt,
			 title,
			 description,
			 month_closure,
			 day_closure,
			 hour_closure,
			 minute_closure,
			 second_closure,
			 year_closure,
			 status,
			 progress,
			 priority,
			 commentaries,
			 subtasks);
			 write(vt, path);
			 vector<string> attr = {"id","title","description","creation_time","deadline","status","progress","priority","commentaries","subtasks"};
			 cout << "Created Task : \n\n" << t.print_attr(attr) << endl;
			}
	}

void removet(vector<string> arguments){
	vector<Task> vt = of_path(path);
	if ((arguments.size() != 2) || (!is_int(arguments[1]))){
				cout << "To remove a task call remove id, id is an int\n";
			}
	else {
		int id_remove = stoi(arguments[1]);
		vector<Task>::iterator it = find_if(vt.begin(), vt.end(), [id_remove](Task t){return t.id == id_remove;});
		if (it != vt.end()){
			int index_remove = distance(vt.begin(), it);
			vector<string> attr = {"id","title","description","creation_time","deadline","status","progress","priority","commentaries","subtasks"};
			cout << "Are you sure you want to remove :\n" << vt[index_remove].print_attr(attr) << "y / n ?\n";
			string a;
			cin >> a;
			if (a == "y"){
				vt.erase(vt.begin() + index_remove);
				write(vt, path);
				cout << "task " << id_remove << " removed\n";
			}
		}
		else{
			cout << "There is no task with id " << id_remove << endl;
		}
	}
}

void list(vector<string> arguments){
	vector<Task> vt = of_path(path);
	vector<string> attr = {"id","title","description","creation_time","deadline","status","progress","priority","commentaries","subtasks"};
	function<bool(Task)> cond_true = [](Task t){return true;};
	if (is_in((string)"--title_only", arguments)){
		attr = {"id","title"};
	}
	if (arguments.size() >= 2){
		if (arguments[1] == "--priority"){
			if (arguments.size() == 2){
				cout << "Wrong argument for --priority, it should be High, Medium or Low\n";
				return;
			}
			if (not is_in(arguments[2], vector<string>{"High", "Medium", "Low"})){
					cout << "Priority should be High, Medium or Low" << endl;
					return;
				}
			function<bool (Task)> cond = [arguments](Task t)->bool{t.priority == arguments[2];}; 
			cout << list_tasks(vt, attr, cond);
			return;
		}
	}
	cout << list_tasks(vt, attr, cond_true);
	return;
}
void help(vector<string> arguments){		
	ifstream input_help(helpfile);
	stringstream helpss(ios_base::app | ios_base::out);
	string l;
	string help;
	while (getline(input_help,l)){
		helpss << l << endl;
	}
	help = helpss.str();
	cout << help;
}

void modify(vector<string> arguments){
	if (arguments.size() != 3 or (not is_in(arguments[2],{"--description", "--commentaries", "--title", "--progress", "--subtasks", "--deadline", "--status", "--priority"}))){
		cout << "Type modify id --description, --commentaries, --title, --progress, --subtasks, --status, --priority or --deadline\n";
		return;
	}
	else{
		vector<Task> vt = of_path(path);
		int id_modify = stoi(arguments[1]);
		vector<Task>::iterator it = find_if(vt.begin(), vt.end(), [id_modify](Task t){return t.id == id_modify;});
		if (it != vt.end()){
			int index_modify = distance(vt.begin(), it);
			map<string, function<Task(Task)>> modifyf = {
				{"--commentaries", set_commentaries},
				{"--deadline", set_deadline},
				{"--description", set_description},
				{"--subtasks", set_subtasks},
				{"--progress", set_progress},
				{"--title", set_title},
				{"--status", set_status},
				{"--priority", set_priority}
			};
			vt[index_modify] = modifyf[arguments[2]](vt[index_modify]);
			write(vt, path);
		}
		else{
			cout << "There is no task with id : " << id_modify << endl;
		}
		return;
	}
}
