# Static and Dynamic linking in detail

## Using a linker with static libraries

Static libraries are created by copying all necessary library modules used in a program into the final executable image. The linker links static libraries as a last step in the compilation process. An executable is created by resolving external references, combining the library routines with program code.

* Command line order matters.
* Put libraries at the end of the command line.

#### Create the object files

create the header file **mymath.h**

```
int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int divi(int a, int b);
```

Create add.c, sub.c , mult.c and divi.c with these function definitions

```
// add.c
int add(int a, int b){
return (a+b);
}

//sub.c
int sub(int a, int b){
return (a-b);
}

//mult.c
int mult(int a, int b){
return (a*b);
}

//div.c
int divi(int a, int b){
return (a/b);
}
```

It will genrate the .o object files

```
gcc -c add.c sub.c mult.c divi.c
```

The -c option skips the linking step and creates only object files.

Create a static library called **libmymath.a**, then remove the object files, as they're no longer required.

```
ar rs libmymath.a add.o sub.o mult.o divi.o
```

```
trash *.o
```

### When to use static linking

---

Dynamically linked executables are generally preferred over statically linked executables because dynamic linking keeps an application's components modular. Should a library receive a critical security update, it can be easily patched because it exists outside of the applications that use it.

When you use static linking, a library's code gets "hidden" within the executable you create, meaning the only way to patch it is to re-compile and re-release a new executable every time a library gets an update—and you have better things to do with your time, trust me.

However, static linking is a reasonable option if the code of a library exists either in the same code base as the executable using it or in specialized embedded devices that are expected to receive no updates.

### Dynamic Linking

---

Creating dynamic **libraries** is slightly different from static libraries, but the concepts are generally the same. I have the same number of .c files and the header file that defines their prototypes in a file called **mymath.h**

To create the dynamic library, which has a .so (standing for shared object), the following compilation command can be entered

```
gcc -fPIC *.c -shared -o libmath.so
```

* The -**shared** flag allows a shared **archive** to be created and the -o option allows us to rename the output file to libmath.so

* -**fPIC** flag is used to generate **Position Independent Code** which is required for dynamic linking. The meaning of this is exactly what it sounds like — since dynamically linked libraries can be stored anywhere in memory where they fit, this flag allows the library file to be used regardless of where it is stored.

### Using the library

---

```
#include "libmath.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    add(2, 3);
}
```

Compiling and making executable

```
gcc -L . file.c -lmath -o myexe
```

Just like the static libraries, the **-L with .** options searches the directory for library files and the -l that is appended at the beginning of **math** is an implicit search for library files that have a **prefix lib, a suffix .so**, and math in between the two.
