CC = g++

OBJECTS = main.o Date.o Time.o Employee.o Register.o Schedule.o

H_COMPILED = *.h.gch
EXE_COMPILED = *.exe

CLEAN_1 = del

MAIN_PROG = ColdstoneApp

$(MAIN_PROG) : $(OBJECTS)
	$(CC) $^ -o $@
	./$(MAIN_PROG)

%.o : %.cpp %.h
	$(CC) -c $^

clean :
	$(CLEAN_1) $(OBJECTS) $(H_COMPILED) $(EXE_COMPILED)