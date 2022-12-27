output : main.o Date.o Time.o Employee.o Register.o
	g++ main.o Date.o Employee.o Register.o -o output

main.o : main.cpp
	g++ -c main.cpp

Date.o : Date.cpp Date.h
	g++ -c Date.cpp

Time.o : Time.cpp Time.h
	g++ -c Time.cpp

Employee.o : Employee.cpp Employee.h
	g++ -c Employee.cpp

Register.o : Register.cpp Register.h
	g++ -c Register.cpp

clean :
	del *.o
	del output.exe