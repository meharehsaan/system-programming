# Heap

In the context of computer memory, **heap memory** refers to a region of a program's memory that is dynamically allocated during the program's execution. It is **separate** from the stack memory, which is used for storing local variables and function call information. The heap memory is managed explicitly by the programmer (or indirectly through language runtime libraries) to **allocate** and **de-allocate** memory as needed.

### Characteristics

---

- **Dynamic Allocation** Heap memory allows the programmer to request memory blocks of varying sizes at runtime. This is in contrast to the stack memory, where the size of memory allocated is determined during compile-time.

- **Manual Memory Management** The programmer is responsible for managing the memory in the heap explicitly. Memory must be allocated when needed (e.g., using functions like malloc() in C or new operator in C++), and it must be released when no longer required (using functions like free() in C or delete operator in C++). If memory is not properly deallocated, it can lead to memory leaks, where the program consumes more and more memory over time, potentially causing the program to crash or slow down.

- **Random Access** Unlike stack memory, which has a LIFO (Last-In-First-Out) structure, heap memory allows for random access. It means you can access any memory block in the heap, as long as you have a valid pointer to that location.

- **Data Persistence** Heap memory remains allocated until it is explicitly deallocated. This allows data to persist beyond the scope of the functions where it was created. However, it is essential to manage memory properly to prevent memory leaks and avoid unnecessary memory usage.

Languages like C, C++, and others that provide **low-level memory management features** allow programmers to **explicitly** allocate and deallocate memory in the heap. However, manual memory management can be **error-prone**, leading to **bugs** like segmentation faults or memory leaks. To mitigate these issues, modern programming languages and environments provide memory management techniques like garbage collection, which automatically handles the **deallocation** of unused memory to simplify the programming process and reduce the likelihood of memory-related **errors**.

### Heap Allocators

---

- **Explicit allocators**
require the application to explicitly free any
allocated blocks. For example, the C standard library provides an
explicit allocator called the malloc package. C programs allocate a
block by calling the malloc function and free a block by calling the
free function. In C++, we normally use the new and delete
operators.

- **Implicit allocators** require the allocator to detect when an allocated
block is no longer being used by the program and then free the block.
Implicit allocators are also known as garbage collectors, and the
process of automatically freeing unused allocated blocks is known as
garbage collection. For example, higher-level languages such as Lisp,
ML and Java rely on garbage collection to free allocated blocks.

### The malloc family in C

---

```
void *malloc (size_t size);
void*calloc(size_t noOfObjects, size_t size);
void *realloc (void* ptr, size_t newsize );
void free ( void* ptr );
```

- **malloc()** allocates size bytes from the heap and returns a pointer to the start of the newly
allocated block of memory. On failure returns NULL and sets errno to indicate error.

- **calloc()** allocates space for specific number of objects, each of specified size. Returns a
pointer to the start of the newly allocated block of memory. Unlike malloc(),
calloc() initializes the allocated memory to zero. On failure returns NULL and sets
errno to indicate error.

- **realloc()**
is used to resize a block of memory previously allocated by one of the
functions in malloc() package. Ptr argument is the pointer to the block of memory that is
to be resized. On success realloc() returns a pointer to the location of the resized block,
which may be different from its location before the call. On failure, returns NULL and
leaves the previous block pointed to by pointer untouched.

- **free()** deallocates the block of memory pointed to by its pointer.

### System Call => brk()

---

```
int brk(void* end_data_segment);
```

- Resizing the heap is actually telling the **kernel** to adjust the
process's program break, which lies initially just above the end
of the **uninitialized** data segment (i.e end variable).

- **brk()** is a system call that sets the program break to location
specified by **end_data_segment**. Since virtual memory is
allocated in pages, this request is rounded up to the page
boundary. Any attempt to lower the program break than end
results in segmentation fault.

- The upper limit to which the program break can be set depends
on range of factors like:
  - Process resource limit for size of data segment.

  - Location of memory mappings, shared memory segment and
shared libraries

### Library Call => sbrk()

---

```
void *sbrk (intptr_t increment);
```

- **sbrk()** is a C library wrapper implemented on top of brk(). It
increments the program break by increment bytes.

- On success, sbrk()returns a pointer to the end of the heap
before sbrk() was called, i.e., a pointer to the start of new area.

- So calling sbrk(0) returns the current setting of the program
break without changing it.

- On failure -1 is returned with errno **ENOMEM**.

### A Basic Heap Allocator

---

- When a program calls malloc the allocator scans the link list of free
memory blocks as per one of the contiguous memory allocation algorithm's
(first fit, best fit, next fit), assigns the block and update the data structures.

- If no block on the free list is large enough then malloc() calls sbrk()
to allocate more memory.

- To reduce the number of calls to sbrk(), malloc() do not allocate
exact number of bytes required rather increase the program break in
large units (some multiples of virtual memory page size) and putting the
excess memory onto the free list.

***When a process calls free(), how does it know as to how much
memory it needs to free? Does it has any effect on program break
brk?***

- When you call free(), you put a chunk of memory back on the free
list.

- There may be times when the chunk immediately before it in memory,
and/or the chunk immediately after it in memory are also free.

- If so, it make sense to try to merge the free chunks into one free
chunk, rather than having three contiguous free chunks on the free list.

- This is called “coalescing” free chunks.

### Why not use brk() and sbrk()

---

C program use malloc family of functions to allocate & deallocate
memory on the heap instead of brk() & sbrk(), because

- malloc functions are standardized as part of C language.
- malloc functions are easier to use in threaded programs
malloc functions provide a simple interface that allows memory to be
allocated in small units.
- **malloc** functions allow us to deallocate blocks of memory.

***Why free() doesn't lower the program break? rather adds the block of
memory to a lists of free blocks to be used by future calls to malloc()***

#### Reasons

- Block of memory being freed is somewhere in the middle of the heap,
rather than at the end, so lowering the program break is not possible.

- It minimizes the numbers of sbrk()
calls that the program must
perform.

***When a process requests 1-24 B on heap, why the memory allocated is 32 B?***

***When a process requests 25-40 B on heap, why the memory allocated is 48 B?***

***When a process requests 41-56 B on heap, why the memory allocated is 64 B?***

***When a process requests 57-72 B on heap, why the memory allocated is 80 B?***

- Check [Example 01](allocated.c)

### Errors while using heap

---

1. Reading/writing freed memory areas.

2. Reading/writing memory addresses before or after the allocated
memory using faulty pointer arithmetic.

1. Freeing the same piece of allocated memory more than once.

2. Freeing heap memory by a pointer, that wasn't obtained by a call
to malloc package.

1. Memory leaks, i.e., not freeing memory and keep just allocating it.

### Malloc Debugging libraries

---

Tasks of finding dynamic memory allocation bugs can be eased
considerably by using the malloc debugging libraries that
are designed for this purpose

- In order to use these libraries we need to link our program against a
particular library instead of malloc package in the standard C library.

- These libraries operates at the cost of slower run-time operation ,
increased memory consumption or both. So we should use them only for
debugging purpose, and then return to linking with the standard
malloc package for the production version of an application. Some
example libraries are

  1. Electric Fence
  2. Valgrind
  3. Insure++
  4. IBM Rational Purify

## Links

- [Heap in detail](https://opendsa-server.cs.vt.edu/ODSA/Books/CS2/html/HeapMem.html)
- [Stack vs Heap](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)
- [Memory Managment wikipedia](https://en.wikipedia.org/wiki/Memory_management)
