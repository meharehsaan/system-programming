# System Programming With Linux

**System** Programming aims to produce software which provides services to computer **hardware**.
- Disk **Defragmentor** etc

**Application** Programming aims to produce softwares which provides services to the **user**. 
- **Browsers** and **Word** applicaton etc

## Contents


### SP AIMS
---

- **Efficient Resource Management:** System programming aims to efficiently manage system resources such as memory, CPU, and I/O devices. This involves designing algorithms and data structures that optimize resource utilization.

- **Interfacing with Hardware:** System programmers work on low-level code to interact directly with hardware components like disk drives, network cards, and peripherals. This allows applications to communicate with hardware effectively.

- **Operating System Development:** One of the primary goals of system programming is the development and improvement of operating systems. This includes designing kernels, system calls, and other critical components to provide a stable and secure environment for applications to run.

- **Performance Optimization:** System programmers focus on optimizing the performance of the system, making applications run faster and more efficiently. This may involve profiling, debugging, and tuning various parts of the system.

- **Security and Protection:** Ensuring system security and protection against unauthorized access and malicious attacks is a crucial aspect of system programming. This involves implementing security measures at the operating system level.

- **Concurrency and Synchronization:** System programmers deal with managing concurrency and synchronization between multiple processes and threads, ensuring that shared resources are accessed safely.

- **Device Drivers:** Creating device drivers is a key objective of system programming. Device drivers enable communication between the operating system and hardware devices, allowing them to function correctly.

- **Virtualization and Containers:** System programming is involved in building virtualization technologies and containerization platforms that allow for efficient resource utilization and isolation of applications.

- **Real-Time Systems:** For certain applications requiring real-time response, system programming is needed to develop systems capable of meeting strict timing constraints.

- **Portability and Compatibility:** System programmers strive to create systems and software that are portable and compatible across different platforms and architectures.

<br>

### System
---

|    OS on Hardware     |
| :-------------------: |
|       **Users**       |
|    **Applications**    |
| **AUI** ----- **API** |
|   **OS** **Kernal**   |
|     **Hardware**      |

<br>

- System Programmers write programs that may have to acquire data from the
  - **File**
  - **Other** program
  - OS **itself**
   
<br>

- After processing, the programs may have to write results
to a shared resource, which other processes are also
writing, or results may need to be delivered to another
process asynchronously, i.e., not when the process asked
for it, but at some later unpredictable time.

### OS Services
---

- **File** Management
- **Process** Management
- **Memory** Management
- **Information** Management
- **Signal** handling
- **Synchronization**
- **Communication** (IPC)
- **Device** Drivers

<br>

### Service Request 
---

- By making **system call**
- By making **library call** that makes system call

<br>
  
#### System call 

is the controlled entry point into the kernal code allowing a process to request kernal to perform a privieged operation.

- A system call changes the processor state from user mode to
kernel mode, so that the CPU can access protected kernel memory.

- The set of system calls is fixed. Each system call is identified by a
unique number.

- Each system call may have a set of arguments that specify
information to be transferred from user space to kernel space and
vice versa.

