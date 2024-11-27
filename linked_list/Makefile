all:
	gcc -c linked_list.c
	gcc -c -I ./ usage_linked_list.c
	gcc -o demo_linked_list linked_list.o usage_linked_list.o

clean:
	rm linked_list.o
	rm usage_linked_list.o
	rm demo_linked_list