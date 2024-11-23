FLAGS = -Wall -Wno-unused-result

DEPS = item.h

OBJ=./methods/$(shell bash -c 'read sort; echo $$sort')_sort.c main.c

all: sort
	gcc -g -o main $(OBJ) $(FLAGS)

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

sort:
	@echo "Select your sorting method \
	\n1 - Bubble Sort (type bubble)\n2 - Shaker Sort (type shaker)\n3 - Selection Sort (type selection)\n4 - Insertion Sort (type insertion)\nPut your choice: "

clean:
	rm -f main *.o

run: 
	@echo Nearly Sorted 1K
	./main < in/nearly_sorted/1Knearly_sorted.txt
	@echo Nearly Sorted 10K
	./main < in/nearly_sorted/10Knearly_sorted.txt
	@echo Nearly Sorted 100K
	./main < in/nearly_sorted/100Knearly_sorted.txt
	@echo Reverse Sorted 1K
	./main < in/reverse_sorted/1Kreverse_sorted.txt
	@echo Reverse Sorted 10K
	./main < in/reverse_sorted/10Kreverse_sorted.txt
	@echo Reverse Sorted 100K
	./main < in/reverse_sorted/100Kreverse_sorted.txt
	@echo Sorted 1K
	./main < in/sorted/1Ksorted.txt
	@echo Sorted 10K
	./main < in/sorted/10Ksorted.txt
	@echo Sorted 100K
	./main < in/sorted/100Ksorted.txt
	@echo Unif Rand 1K
	./main < in/unif_rand/1Kunif_rand.txt
	@echo Unif Rand 10K
	./main < in/unif_rand/10Kunif_rand.txt
	@echo Unif Rand 100K
	./main < in/unif_rand/100Kunif_rand.txt

val:
	valgrind --leak-check=full --show-leak-kinds=all -s ./main