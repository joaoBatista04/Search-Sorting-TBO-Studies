FLAGS = -Wall -Wno-unused-result

DEPS = insert_sort.h
OBJ = insert_sort.c client.c

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

all: $(OBJ)
	gcc -g -o main $(OBJ) $(FLAGS)

clean:
	rm -f main *.o

run: 
	time ./main < ./test/out10.txt
	time ./main < ./test/out100.txt
	time ./main < ./test/out1000.txt
	time ./main < ./test/out10000.txt
	time ./main < ./test/out100000.txt
	time ./main < ./test/out1000000.txt
	time ./main < ./test/out10000000.txt