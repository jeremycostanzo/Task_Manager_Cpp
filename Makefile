# make
CXX = g++
EXE = Task_manager.out
OBJS = Fonctionalites.o io.o Task.o vector_string.o Task_manager.o
all: Task_manager.out
Task_manager.out: $(OBJS)
		$(CXX) $^ -o $@
%.o: %.cpp
	$(CXX) $< -c
clean:
	rm $(OBJS) $(EXE)