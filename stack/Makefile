all:
	gcc -c stack.c
	gcc -c -I ./ usage_stack.c
	gcc -o demo_stack stack.o usage_stack.o

clean:
	rm stack.o
	rm usage_stack.o
	rm demo_stack