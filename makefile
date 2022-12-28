CC = g++

OBJECTS = main.o Date.o Time.o Employee.o Register.o Schedule.o

H_COMPILED = *.h.gch
EXE_COMPILED = *.exe

CLEAN_1 = del

EXECUTABLE = ColdstoneApp

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@
	./$(EXECUTABLE)

%.o : %.cpp %.h
	$(CC) -c $^

clean :
	$(CLEAN_1) $(OBJECTS) $(H_COMPILED) $(EXE_COMPILED)