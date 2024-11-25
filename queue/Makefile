all:
	gcc -c queue.c
	gcc -c -I ./ usage_queue.c
	gcc -o demo_queue queue.o usage_queue.o

clean:
	rm queue.o
	rm usage_queue.o
	rm demo_queue