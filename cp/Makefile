CC = gcc
EXEC = prog
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o bin/$(EXEC) $^

build/%.o: src/%.c
	$(CC) -o $@ -c $<

clean:
	rm -rf build/*.o
