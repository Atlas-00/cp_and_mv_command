CC = clang

prog : build/main.o build/cp.o build/mv.o
	${CC} -o bin/prog build/main.o build/cp.o

build/main.o : src/main.c
	${CC} -o build/main.o -c src/main.c

build/cp.o : src/cp.c
	${CC} -o build/cp.o -c src/cp.c

build/mv.o : src/mv.c
	${CC} -o build/mv.o -c src/mv.c