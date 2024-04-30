FLAGS = -Wall -Wno-unused-result

DEPS = sieve.h
OBJ = sieve.c main.c

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

all: $(OBJ)
	gcc -g -o main $(OBJ) $(FLAGS)

clean:
	rm -f main *.o

run: 
	./main

val:
	valgrind --leak-check=full --show-leak-kinds=possible ./main