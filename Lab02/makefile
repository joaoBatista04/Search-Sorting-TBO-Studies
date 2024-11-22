FLAGS = -Wall -Wno-unused-result

DEPS = bst.h list.h stack.h queue.h
OBJ = bst.c list.c stack.c queue.c main.c

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

all: $(OBJ)
	gcc -g -o main $(OBJ) $(FLAGS)

clean:
	rm -f main *.o

run: 
	./main

val:
	valgrind --leak-check=full --show-leak-kinds=all -s ./main