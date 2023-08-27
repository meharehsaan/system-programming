# Shared Memory

Shared Memory allows two or more processes to share a region of memory or segment of memory for reading and writing purposes.

- The problem with pipes and fifo's and message queues is that [**mode**](https://www.ibm.com/docs/en/aix/7.1?topic=performance-mode-switching) switch is required to **pass data** from processes buffer to **kernel buffer** and then to processes buffer again.

- In shared memory does not require a **mode** switch, therefore, shared memory is **considered** on the **quickest** means of **Inter-Process Communication**(IPC).

```bash
ipcs -m  // List information about shared memory segments
ipcs -a
ipcrm -m <shmid>  // Remove a shared memory segment
ls /dev/shm
```

### API to Shared Memory

---

|Interface| System V API| POSIX API |
|:-------:|:-----------:|:--------:|
|**Header File**|<sys/shm.h>|<mqueue.h>|
|**Data Structure** |shmid_ds|File descriptor|
|**Create/open** |shmget(), shmat()|shm_open()|
|**Close**  |shmdet()|shm_unlink()|
|**Perform IPC** |Access Memory|namp(), memcpy()|
|**Control operations** |shmctl()| |

### Creating Shared Memory

---

The shmget() function is a system call in Unix-like operating systems that is used to create or access a shared memory segment. Shared memory allows multiple processes to share a region of memory, providing a high-performance means of inter-process communication (IPC). Processes can read from and write to the shared memory segment, allowing them to exchange data efficiently.

```C
int shmget(key_t key, size_t size, int shmflg);
```

- **key** A key used to identify the shared memory segment. This key can be obtained using the ftok() function, similar to using it for message queues and semaphores.
- **size** The size of the shared memory segment in bytes.
- **shmflg** Flags for controlling the behavior of the shared memory segment creation or access. Common flags include **IPC_CREAT** (create the segment if it doesn't exist) and permission settings (e.g., **0666** for read/write permissions for all users).

#### Return Value

- On success, **shmget**() returns the shared memory identifier (an integer).
- On failure, it returns -1 and sets errno to indicate the specific error.

### Attaching SM

---

The shmat() function is a system call in Unix-like operating systems that is used to attach a shared memory segment to the address space of a process. Once attached, the process can read from and write to the shared memory segment. This allows multiple processes to share and exchange data efficiently using a common memory area.

```C
void *shmat(int shmid, const void *shmaddr, int shmflg);
```

- **shmid** The shared memory identifier obtained from the shmget() function.
- **shmaddr** The desired address where the shared memory segment should be attached. If set to NULL, the system selects a suitable address.
- **shmflg** Flags for controlling the behavior of attaching the shared memory segment. Common flags include SHM_RDONLY (attach in read-only mode) and 0 (no special behavior).

#### Return Value

- On success, shmat() returns the address at which the shared memory segment is attached.
- On failure, it returns (void *)-1 and sets errno to indicate the specific error.

### Deattching SM

---

The shmdt() function is a system call in Unix-like operating systems that is used to detach a shared memory segment from the address space of a process. Once detached, the process can no longer access the contents of the shared memory segment. This function should be used when a process is done using the shared memory and wants to release the resources associated with it.

```C
int shmdt(const void *shmaddr);
```

- **shmaddr** The address of the shared memory segment that you want to detach.
  
#### Return Value

- On success, shmdt() returns 0.
- On failure, it returns -1 and sets errno to indicate the specific error.

### Control Operaton on SM

---

The **shmctl**() function is a system call in Unix-like operating systems that is used to perform control operations on a shared memory segment. It provides a way to perform various operations on a shared memory segment, such as obtaining information about the segment, changing its properties, and removing it from the system.

```C
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```

- **shmid** The shared memory identifier obtained from the **shmget**() function.
- **cmd** The command that specifies the operation to be performed. Common commands include **IPC_STAT** (get information about the segment), **IPC_SET** (set information about the segment), and **IPC_RMID** (remove the segment).
- **buf** A pointer to a struct **shmid_ds** structure that holds information about the shared memory segment. This structure is used with some commands to pass or retrieve information.

#### Return Value

- On success, shmctl() returns 0 for most commands.
- On failure, it returns -1 and sets errno to indicate the specific error.

## Links

- [Shared memory in C](https://stackoverflow.com/questions/5656530/how-to-use-shared-memory-with-linux-in-c)
- [IPC - Shared Memory](https://users.cs.cf.ac.uk/dave/C/node27.html)
- [What is Shared Memory?](https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/shm/what-is-shm.html#:~:text=Shared%20memory%20is%20a%20feature,shared%20area%20can%20access%20it.)
- [POSIX Shared Memory in Linux](https://www.softprayog.in/programming/interprocess-communication-using-posix-shared-memory-in-linux)
