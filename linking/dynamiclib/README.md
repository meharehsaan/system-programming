## Creation of dynamic lib

To create the dynamic library, which has a .so (standing for shared object), the following compilation command can be entered

```
gcc -c -fPIC *.c -I .
gcc -shared *.o -o libmath.so
```

* The -**shared** flag allows a shared **archive** to be created and the -o option allows us to rename the output file to libmath.so

* -**fPIC** flag is used to generate **Position Independent Code** which is required for dynamic linking. The meaning of this is exactly what it sounds like — since dynamically linked libraries can be stored anywhere in memory where they fit, this flag allows the library file to be used regardless of where it is stored.

## compilation of source file

*To run execuable in dynamic linking you have to place .**so** library either in **standard** location of c libraries in /usr/lib/ or update environmental variable **LD_LIBRARY_PATH** by giving it path of the you dynamic library path other wise compiler searches it in standard location and give error on execution of final executable*.

```
gcc -c filename.c -I .
gcc -L . filename.o -lmath -o myexe
```

- -**I with .** finds the header file in the current directory 

Just like the static libraries, the **-L with .** options searches the directory for library files and the -**l** that is appended at the beginning of **math** is an implicit search for library files that have a **prefix lib, a suffix .so**, and math in between the two.


