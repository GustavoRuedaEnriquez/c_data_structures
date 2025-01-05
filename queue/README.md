Generic queue data structure
====================
Coded a generic queue data structure that supports all C basic data types:
* `unsigned int`
* `int`
* `unsigned long`
* `long`
* `float`
* `double`
* Strings (`char *`)

This directory contains the following files:
* **basic_defs.h** - Header file with commons macros and defines used by all the data structures on this repository.
* **queue.h** - Header file that contains all the declarations for the queue data structure.
* **queue.c** - Implementation of the functions defined on queue.h
* **usage_queue.c** - File with tests on how the queue structure is used. It has examples on how to create and used a queue for all supported data types.

## Queue methods
* `queue_create` - Initializes an empty queue structure.
* `queue_offer` - Adds new entry to the queue's front.
* `queue_peek` - Returns the queue's front.
* `queue_poll` - Removes the queue's front and returns it.
* `queue_size` - Returns current size of the queue.
* `queue_is_empty` - Tells if queue is empty or not.
* `queue_destroy` - Frees the memory used by a queue structure.
* `queue_print` - Prints all the queue's entries.

## Using the queue data structure
Please feel free to use this code, to compile and run the executable usage program do the following:
```bash
$ make
$ ./demo_queue.exe
```