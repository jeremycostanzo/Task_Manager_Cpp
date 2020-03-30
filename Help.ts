This is a task manager.
The arguments are :

help : prints this message

list : list all tasks
	--title_only : displays only the title and id of tasks
	--priority a : lists only the tasks with priority a, a being High, Low or Medium

new : To append a task, do it like this :
	  new title description month_closure day_closure hour_closure minute_closure second_closure year_closure status progress priority commentaries "subtasks"

remove : To remove a task call remove id, id is an int

modify : To modify a task, type modify id --description, --commentaries, --title, --progress, --subtasks, --status, --priority or --deadline


