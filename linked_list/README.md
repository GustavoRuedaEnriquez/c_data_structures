Generic linked list data structure
====================
Coded a generic linked list data structure that supports all C basic data types:
* `unsigned int`
* `int`
* `unsigned long`
* `long`
* `float`
* `double`
* Strings (`char *`)

This directory contains the following files:
* **basic_defs.h** - Header file with commons macros and defines used by all the data structures on this repository.
* **linked_list.h** - Header file that contains all the declarations for the linked list data structure.
* **linked_list.c** - Implementation of the functions defined on linked_list.h
* **usage_linked_list.c** - File with tests on how the queue structure is used. It has examples on how to create and used a queue for all supported data types.

## Linked list methods
* `linked_list_create` - Initializes an empty queue structure.
* `linked_list_add` - Adds new entry to the queue's front.
* `linked_list_add_front` - Returns the queue's front.
* `linked_list_add_back` - Removes the queue's front and returns it.
* `linked_list_set` - Returns current size of the queue.
* `linked_list_remove_index` - Tells if queue is empty or not.
* `linked_list_remove_front` - Frees the memory used by a queue structure.
* `linked_list_remove_back` - Prints all the queue's entries.
* `linked_list_get_index`
* `linked_list_get_front`
* `linked_list_get_back`
* `linked_list_index_of`
* `linked_list_size`
* `linked_list_is_empty`
* `linked_list_clear`
* `linked_list_destroy`
* `linked_list_print`

## Using the queue data structure
Please feel free to use this code, to compile and run the executable usage program do the following:
```bash
$ make
$ ./demo_queue.exe
```