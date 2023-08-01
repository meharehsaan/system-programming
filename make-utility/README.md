# Unix make Utility

***Make** - a **tool** that automatically determines which source files of a program need to be recompiled and/or linked.*

UNIX make utility is a **powerful** tool that allows you to manage compilation of
multiple modules into an executable.

### Introduction

---

Imagine you write a program and divide it into **hundred** .c files and some header
files. To make the executable you need to compile those hundred source files to create
hundred relocatable object files and then you need to link those object files to final
executable.

- What happens if we make changes to one of these files.
  - Recompile all the files and then link all of them.
  - Recompile only the file which has changed and then link.

Make gets its knowledge of how to build your program from a file called the **makefile** (or **Makefile**). You can also use make to **install** and **uninstall** programs and to issue other commands from a makefile.

- Make utility uses this dependency specification in the makefile and the time
when various components were modified, in order to minimize the amount of
recompilation.

### Structure of makefiles

---

```
target: dependencies ...
<tab>   command
    ...
    ...
```

- **target** Name of the executables to be built.
- **dependencies** Name of the files on target depends.
- **command** Shell commands to create target from dependencies.

You need to put a **tab** character at the beginning of each command line.
It is usually easiest to start with an existing makefile and edit it for a new application.

#### Advantages of make utility

- Makes management of large s/w projects with multiple source files easy.
- No need to recompile a source file that has not been modified, only those
files that have been changed are recompiled, others are simply relinked.

### Options to make

---

Check out **man pages** of make utility ([Click here](https://linux.die.net/man/1/make))

The three most commonly used are

- **-f** => By default make looks for a file “makefile” in the current directory. If
doesn't exist, it looks for “Makefile”. To tell make to use a different
file, user -f option followed by filename.

- **-n** To tell make to print out what it would have done w/o actually doing it.

- **-k** Tells make to keep going when an error is found, rather than stopping
as soon as the first problem is detected. You can use this to find out in
one go which source files fail to compile.

### Multiple Targets

---

- A makefile can have multiple targets. We can call a make file with the
name of a particular target.

- To tell make to build a particular target, you can pass the target name to
make as parameter (By default, make will try to make the first target listed
in makefile).

- *Many programmers specify all as the first target in their makefile and
then list the other targets as being **dependencies** for all.*

- A phony target is a target without dependency list. Some important phony
targets are **all, clean, install**.

```
clean:
    -@rm -f *.o
```

If there is no **.o** file in the current working directory, make will return an
**error**. If we want make to ignore error while executing a command we
proceed the command with a hyphen as done above. Moreover, make print
the command to **stdout** before executing. If we want to tell make not to print
the command to stdout before executing we use **@** character.

### Multiple Makefiles

---

Project source divided in multiple directories
●Different developers involved
●Multiple makefiles
●Top level makefile use include directive
●
Include Directive: Tells make to suspend reading the current
makefile and read one or more other makefiles before continuing.

```
include ./d2/makefile ./d3/makefile
```

### Macros (variables) in a Makefile

---

A Makefile allows us to use macros or variables, so that we can
write it in a more generalized form. Variables allow a text string to be
defined once and substituted in multiple places later

- We can define macros/variables in a makefile as
**MACRONAME=value**
- We can access the macros as **$(MACRONAME)**.

Macros can be added to the command line.

```
make myapp CC=gcc
```

Use the command **(*make -p*)** to see a list of all predefined suffixes and macros.

### Special Internal Macros

---

- **$?** List of dependencies changed more recently than the
current target.
- **$@** Name of the current target.
- **$<** Name of the current dependency.
- **$\*** Name of the current dependency w/o extension.

### Example

OBJS=srcfile1.o srcfile2.o srcfile3.o

To use this macro type $(OBJS)

```
myappl: $(OBJS)
    cc -o myapp1 $(OBJS) -lm
srcfile1.o: scrfile1.c myinclude.h
    cc -c srcfile1.c 
srcfile2.o: scrfile2.c myinclude.h
    cc -c srcfile2.c 
srcfile3.o: scrfile3.c myinclude.h
    cc -c srcfile3.c 
clean:
    rm -f myapp1 $(OBJS)

```

## Links

- [GNU Make](https://www.gnu.org/software/make/)
- [The Make Utility](https://www.dartmouth.edu/~rc/classes/soft_dev/make.html)
- [An Introduction to the UNIX Make Utility](https://edoras.sdsu.edu/doc/make.html)
