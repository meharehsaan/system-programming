## To create lib

-r create a new archive

```
ar -r libfirst.a file1.o file2.o
```

-q append an object file to an existing archive

```
ar -q libfirst.a file3.o
```
## compilation of source file

Compiling and making executable

```
gcc -c filename.c -I .
gcc -L . filename.o -lmath -o myexe
```

- -**I with .** finds the header file in the current directory 

Just like the static libraries, the **-L with .** options searches the directory for library files and the -l that is appended at the beginning of **math** is an implicit search for library files that have a **prefix lib, a suffix .so**, and math in between the two.