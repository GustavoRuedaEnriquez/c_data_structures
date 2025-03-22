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
* `linked_list_create` - Initializes an empty list structure.
* `linked_list_add` - Adds new entry at the end of the list.
* `linked_list_add_front` - Adds a new entry at the end of the list.
* `linked_list_add_back` - Adds a new entry at the beginning of the list.
* `linked_list_set` - Modifies the value of a given index of the list.
* `linked_list_remove_index` - Removes an element from a given index of the list.
* `linked_list_remove_front` - Removes the first element of the list.
* `linked_list_remove_back` - Removes the last element of the list.
* `linked_list_get_index` - Returns the element saved on a given index of the list.
* `linked_list_get_front` - Returns the list first element.
* `linked_list_get_back` - Returns the list last element.
* `linked_list_index_of` - Returns the index of the first instance of a given value.
* `linked_list_size` - Returns the list size.
* `linked_list_is_empty` - Tells if the list is empty or not.
* `linked_list_clear` - Remove all elements of the list.
* `linked_list_destroy` - Delete all list elements and the list structure itself.
* `linked_list_print` - Print the list.

## Using the linked list data structure
Please feel free to use this code, to compile and run the executable usage program do the following:
```bash
$ make
$ ./demo_linked_list.exe
```