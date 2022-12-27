CC = g++

OBJECTS = main.o Date.o Time.o Employee.o Register.o

H_COMPILED = *.h.gch
EXE_COMPILED = *.exe

CLEAN_1 = del

output : $(OBJECTS)
	$(CC) $^ -o $@

%.o : %.cpp %.h
	$(CC) -c $^

clean :
	$(CLEAN_1) $(OBJECTS) $(H_COMPILED) $(EXE_COMPILED)