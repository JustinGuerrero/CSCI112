pgm01: main.o parseLine.o printStatements.o queryUser.o readClasses.o
	gcc -o pgm01 main.o parseLine.o printStatements.o queryUser.o readClasses.o

main.o: main.c student.h
	gcc -c -g -Wall main.c

pareseLine.o: parseLine.c student.h
	gcc -c -g -Wall parseLine.c

printStatement.o: printStatements.c student.h
	gcc -c -g -Wall printStatements.c

queryUser.o: queryUser.c student.h
	gcc -c -g -Wall queryUser.c

readClasses.o: readClasses.c student.h
	gcc -c -g -Wall readClasses.c
