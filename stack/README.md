Generic stack data structure
====================
Coded a generic stack data structure that supports all C basic data types:
* `unsigned int`
* `int`
* `unsigned long`
* `long`
* `float`
* `double`
* Strings (`char *`)

This directory contains the following files:
* **basic_defs.h** - Header file with commons macros and defines used by all the data structures on this repository.
* **stack.h** - Header file that contains all the declarations for the stack data structure.
* **stack.c** - Implementation of the functions defined on stack.c
* **usage_stack.c** - File with tests on how the stack structure is used. It has examples on how to create and used a stack for all supported data types.

## Stack methods
* `stack_create` - Initializes an empty stack structure.
* `stack_push` - Adds new entry to the stack's top.
* `stack_top` - Returns the stack's top.
* `stack_pop` - Removes the stack's top and returns it.
* `stack_size` - Returns current size of the stack.
* `stack_is_empty` - Tells if stack is empty or not.
* `stack_destroy` - Frees the memory used by a stack structure.
* `stack_print` - Prints all the stack's entries.

## Using the stack data structure
Please feel free to use this code, to compile and run the executable usage program do the following:
```bash
$ make
$ ./demo_stack.exe
```