# Terminal Devices

Terminal devices, often referred to as **terminals**, are hardware or software interfaces that allow users to interact with a computer system, typically through a text-based interface.

### File Types

---

- Regular files (-)
- Directories (d)
- Symbolic Links (l)
- Character special files (c)
- Block special files (b)
- Named pipes (p)
- Sockets (s)

### Device Files

---

#### Character Special Files (c)

These files represents hardware devices that reads or writes a serial
stream of data bytes. Devices connected via serial/parallel ports fall
in this category. Examples of such devices are **terminal devices, sound cards, and tape drives**.

#### Block special files (b)

These files represents hardware devices that reads or writes data in
fixed size blocks. Unlike serial devices they provide random access
to data stored on the device. Examples of such devices are **HDD, SSD, and cdrom**.

### Differences Between Device & Regular Files

---

- A regular file is a container, while a device file is a connection. Thay donot occupy any space on the disk.
  
- The inode block of a regular file contains **pointer** that points to
its **data blocks**, while the inode block of a device file contains
pointer that points to a **function inside the kernel** called the
**device** driver.

- When you see the **long listing** aka **ls -l**, a regular file shows its **size**
while a device file displays the **major and minor number** of the
device driver at the place of size when you see its long listing.

#### Device Numbers

Linux identify devices using a **16 bit number** divided into **two** parts

- **Major number** (8 bits) that identifies the driver program.
- **Minor number** (8 bits) that is used by the driver program to identify the
instance.

```
sudo mknod -m 644 mycharspecialfile c 555, 1
sudo mknod -m 644 myblockspecialfile b 666, 1
```

- *The files cannot be copied we can only move and remove them*.

- Removing device file does not **remove** the device driver.

### Terminal

---

check out terminal files in **/dev/pts/**.

```
la -l /dev/pts/
```

- Contains files like 0, 1, 3, **ptmx** depending upon terminal running in this **ptmx** is the **master** file while all others are **slave** files.

```
echo Hello new termianl 1>/dev/pts/2
```

write msg to specific terminal

```
cp file.txt /dev/pts/1
```

copy file on that terminal

### Modes of Terminal

---

#### Canonical Mode

- Input is made available line by line, and the line goes to the
process only after the user presses the Enter key (mean while
it is buffered inside the tty driver program).
- Line editing is enabled.
  
#### Non-Canonical Mode

- Input is made available immediately as a key is pressed,
without the need to press the Enter key (no buffering is done
by the driver program).
- Line editing is disabled.

### Attributes of Terminal Driver

---

Actions performed by tty driver on the data passing through it can
be grouped into four main categories

- **Input Processing**
Processing performed by tty driver on the
characters received via key board,
before sending them to the process.
Example: icrnl

- **Output Processing** Processing performed by tty driver on the
characters received from process, before sending them to the
display unit. Example: onlcr

- **Control Processing**
How characters are represented? Example:
cs8

- **Local Processing**
What the driver do while the characters are
inside the driver? Example: icanon, echo

```
man stty
```

```
stty sane
```

Set default setting for attributes

```
stty -a
```

To see all terminal attributes

```
stty -icanon
```

To enable non-canonical mode

### Accessing & Modifying Terminal Attributes

---

- Use **system**() library call
- Use **tcgetattr**() and **tcsetattr**() library calls
- Use **ioctl**() system call

### system() Library call

---

```
int system(const char* command);
```

- It executes a command specified in **cmd** by calling /bin/bash -c
command and returns after the command has been completed.

- Return -1 on error and the return status of the cmd other wise
Main cost of system() is **inefficiency**. Executing a command using
system() requires the creation of at least two processes.

  - One for the shell.
  - Other for the command(s) it executes.

### Use tcgetattr() and tcsetattr()

---

```
int tcgetattr(int fd, struct termios* info);
int tcsetattr(int fd,int when,struct termios* info)
```

- The **tcgetattr**() copies current settings from tty driver
associated to the open file fd into the struct pointed by info. Returns
0 on success and -1 on error.
- The **tcsetattr**() sets the tty driver associated to the open file fd
with the settings given in the struct pointed by info. The when
argument tells when to update the driver settings. The when argument
can take **following** values

  - **TCSANOW** update driver settings immediately.
  - **TCSADRAIN** wait until all o/p already queued in the driver has
been transmitted to the terminal and then update the driver.
  - **TCSAFLUSH** wait for o/p queue to be emptied + flush all queued
i/p data and then update the driver.

### Structure termios

---

Some important members of the termios structure that of our interest
right now are shown below:

```
struct termios{
    tcflag_t c_iflag; //contains flags related to input processing
    tcflag_t c_oflag; //contains flags related to output processing
    tcflag_t c_cflag;//contains flags related to control processing
    tcflag_t c_lflag;//contains flags relating to local processing
};
```

### Changing Attributes of Terminal Driver

---

Three steps to change the attributes of a terminal driver

- Get the attributes from the driver.
- Modify the attributes you need to change.
- Send these **revised** attributes back to the driver.

```
struct termios info;
tcgetattr(0, &info);
info.c_lflag = info.c_lflag | ECHO;
tcsetattr(0, TCSANOW, &info);
```

Making **echo** flag ON

```
struct termios info;
tcgetattr(0, &info);
info.c_lflag = info.c_lflag & ~ECHO;
tcsetattr(0, TCSANOW, &info);
```

Making **echo** flag OFF

### ioctl() System call

---

```
int ioctl(int fd, int request[,arg,...]);
```

- We have seen the use of **fcntl**() system call to get/set the attributes
of a disk file. To get/set the attributes of device files we can use the
**ioctl**() system call. Each type of device has its own set of
properties and ioctl operations

- The first argument **fd** specifies an open **file descriptor** that refers to a
device.

- The second argument request specifies the control function to be
performed based upon the device being addressed. Defined
in **/usr/include/asm-generic/ioctls.h**.

- Remaining optional arguments are request specific, defined
in **/usr/include/x86_64-linux-gnu/bits/ioctl-types.h**.

#### Changing echo Flag Bit Using ioctl()

```
//ON
struct termios info;
ioctl(0,TCGETS, &info);
info.c_lflag = info.c_lflag | ECHO;
ioctl(0, TCSETS, &info);


//OFF
struct termios info;
ioctl(0,TCGETS, &info);
info.c_lflag = info.c_lflag & ~ECHO;
ioctl(0, TCSETS, &info);
```

### Getting the Screen Size Using ioctl()

---

A video terminal screen, has size measured in rows and columns or
pixels. The following code snippet displays the dimensions of the screen
using **ioctl**() call

```
struct winsize wbuf;
ioctl(0, TIOCGWINSZ, &wbuf);
printf("%d rows x %d cols \n", wbuf.ws_row,wbuf.ws_col)
```

- Along with many other constants the second argument TIOCGWINSZ
is defined in /usr/include/asm-generic/ioctls.h
- The winsize structure is defined in/usr/include/x86_64-
linux-gnu/bits/ioctl-types.h

## Links

- [stty](https://www.computerhope.com/unix/ustty.htm)
- [Linux Terminal](https://dev.to/napicella/series/4980)
- [Shell Commands](https://www.ibm.com/docs/en/zos/2.2.0?topic=reference-shell-command-descriptions)
- [Set or display terminal options](https://www.ibm.com/docs/en/zos/2.2.0?topic=descriptions-stty-set-display-terminal-options)
