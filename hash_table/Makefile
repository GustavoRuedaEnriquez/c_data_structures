all:
	gcc -c hash_table.c
	gcc -c -I ./ usage_hash_table.c
	gcc -o demo_hash_table hash_table.o usage_hash_table.o

clean:
	rm hash_table.o
	rm usage_hash_table.o
	rm demo_hash_table