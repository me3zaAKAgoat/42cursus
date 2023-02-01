<h1 align="center" ><strong>42cursus</strong></h1>
<p align="center" >Notes I have taken on my journey of learning C.</p>

## **Index**

- [Reminders](https://github.com/me3zaAKAgoat/42cursus#reminders)
- [Memory (RAM)](https://github.com/me3zaAKAgoat/42cursus#memory)
- [Different Types Of Errors](https://github.com/me3zaAKAgoat/42cursus#different-types-of-errors)
- [File Management In Unix](https://github.com/me3zaAKAgoat/42cursus#file-management-in-unix)
- [Virtual Machine Jargon](https://github.com/me3zaAKAgoat/42cursus#virtual-machines)
- [Makefile](https://github.com/me3zaAKAgoat/42cursus#makefile)
- [C Keywords](https://github.com/me3zaAKAgoat/42cursus#keywords)
- [Unix Shells](https://github.com/me3zaAKAgoat/42cursus#unix-shells)
- [Miscellaneous](https://github.com/me3zaAKAgoat/42cursus#miscellaneous)

---

## **Memory (RAM)**

- the RAM is a hardware component that stores data during its uptime and then loses it when turned off, the data is stored in slots of 1 byte and each slot has its own address.
- Addresses are conventionally represented in hexadecimal, the 0x is but a prefix that indicates the base of representation.
- The RAM provides data for CPU operations on demand.
- the OS partitions the RAM into chunks of 4k Bytes called pages.
- A program is either allowed to access an entire page or none of it.
- A CPU cache is a small part of memory within the CPU that is used to provide data to operations faster than demanding it from the RAM.
  - when the CPU wants to read from a certain address, it checks if it's in the cache first.
  - the cache stores in chunks of 64 bytes called _cache lines_.
- the memory we interact with as programmers is usually virtual memory, meaning that the addresses read are not actual physical RAM addresses.

- **Endianness** refers the the order bytes are stored in memory. A big-endian system stores the most significant byte of a word at the smallest memory address and the least significant byte at the largest. A little-endian system, in contrast, stores the least-significant byte at the smallest address.
  [Endianness Wiki artice](https://en.wikipedia.org/wiki/Endianness)

---

## **Different Types Of Errors**

### Runtime Errors

- ##### SEGMENTATION FAULT
  Segmentation fault occurs when the program tries to access an area of memory that it is not allowed to access.
- ##### BUS ERROR

  Bus error occurs when the program gives a processor instruction with an address that does not satisfy its **alignement requirements**.

> **Alignment Requirement:**
>
> All processors have instructions that need to read n bytes from the memory, these processors take the data needed for the instruction from the RAM in blocks of n bytes and put each block in a cache line.
>
> ![memory blocks](/READMEcontent/alignmentMemory.jpg)
>
> Data Structure Alignment is needed because it leads to efficient use of cache lines.
>
> As per the illustration we have a 32 bit processor that reads 4 byte blocks and puts them into cache lines.
>
> E.g In the case of the red 4 byte-long data structure, in order for the processor to execute the instruction it will need to read two blocks thus will use up two cache lines to store what could've just used only one cache line if it were stored at a proper address in the memory.
> The blue stored value respects the alignment requirement and will only use one cache line as needed.
>
> **Important:** Data Structure Alignment is respected when the address at which an n-byte value is stored is divisible by n.
>
> [Video Explanation](https://youtu.be/zyGMyV955Rw)

### What is ERRNO?

- _ERRNO_ is an integer variable that is set by system calls and some library functions to indicate the specifics of the last error that occured.

---

## **File Management In Unix**

> **Important resource**:
>
> - [Artice about Processes, Files, and File Descriptors in Linux](https://medium.com/geekculture/developer-diaries-processes-files-and-file-descriptors-in-linux-ebf007fb78f8)

- The 'f' that prefixes file handling functions usually refers to the function being a high level routine as opposed to a low level routine function.
- low level routines do not use buffering but can take up to one minute before data is physically written to the disc (we can use **fsync** to ensure that all data is written to the file).
- EOF is a flag that holds a negative integer value that indicates that a file position has reached the end of a file. (though it's value should'nt be assumed, it is usually -1)
- File position is a character count in the opened file that starts at 0. for example, File position 40 means that the character that is currently being read from or written to is the 41th character in the file. (**ftell** is a high level function that takes in a stream as input and outputs an integer representing the file position).

- #### **Streams**
  - A **stream** is a flow of data from a source to a destination within a GNU system (mostly used in high level routines).
  - Streams are represented by the type FILE\*.
- #### **File Descriptors**

  - A file decscriptor is an integer that represents the connection opened between a source and a destination (mostly used in low level routines).

- It is good practice to redirect all error messages to stderr, while directing regular output to stdout. It is beneficial to do this because anything written to stderr is not buffered, i.e., it is immediately written to the screen so that the user can be warned immediately.
- Stderr is usually the console because it is the programmer that should be notified when an error occurs.

### Processes and how they relate to files

In **Unix** everything is a file, (sockets, devices ...), and every process has a File Descriptor table that contains an entry for each file used by the process. Naturally, every process has the first 3 integers set to (by deafult) (stdin, stdout and stderror).
When forking, a child process gets an exact copy of the FDtable of its parent.

### Pipes

- A pipe in **Unix** is a tool used to communicate between different processes.
- The C pipe() function takes an array of ints of size 2 that if ran successfully (returns 0 on success and -1 on _error_) will be filled with the smallest available file descriptors of the FD table, fd[0] is the read end of the pipe, while fd[1] is the write end of the pipe.
- Pipes have a read end and a write end represented by file descriptors that reside in the File Descriptor Table of each process.
- Anything that is written to the write end would be available to read from the read end.
- The C dup2(int fd1, int fd2) function makes fd1 and fd2 equivalent, whatever file was opened on fd1 is now open with the same mod and position of the file described by fd2.

---

## **Virtual Machine Jargon**

### **Virtual Machine?**

> Virtual machines are systems that substitute the need for a real machine, and enable the users to run an entire operating system on top of another pre existing one (host) without the need for seperate hardware. The uses for VMs vary from either testing new unsafe software to emulating another system with a completely different architecture (video game consoles on x64 architectures).

### **LVM?**

> LVM is an abstraction layer that resides between file systems and hardware storage devices that makes many obsolete storage decisions' modification hassle-free and provides much greater flexibility compared to traditional partitioners.
> LVM works somewhat like Virtual Memory as in it virtualizes physical storage into a virtual one and handles the indexing of physical space to virtual space usually through a Memory Management Unit.

### **SSH?**

> SSH is a security protocol that allows for secure connections using the cryptographic public-private key model, it is mainly used to log into remote machines and execute commands.
>
> To connect to a remote machine use ssh \<user>@\<ip address> and then use the password.

### **UFW firewall?**

> UFW is a tool that allows for simple management of firewalls and was brought on as a substitute for compilcated tools like iptables.

### **Differences between apt and aptitude?**

> Aptitude is a high-level package manager as opposed to the low-level PM apt, Aptitude offers a great lot of functionalities as it encapsulates all apt-get apt-cache and apt-mark and more.

### **SELinux and AppArmor?**

> SELinux is a tool that defines access control for processes and applications, it relies on Access Vector Cache to check wether apps that request access to files should be granted the access, in case of failure to make a decision SELinux sends the request to a security server that then grants or denies the request based on the context of the app/process.

### **Partitioning?**

> Partitions are isolated sections of a large storage device that behave as their own hard drive independently of one another.

### **Mounting?**

> Mounting is the process of making files of a storage device available to the user through the computers file system.

### **Root?**

> The root is the top most directory a hierarchy, it is the file system on top of which all other file systems are mounted.

### **Swap?**

> The swap partition is the area of the virtual storage volume that virtual memory uses to store pages that are temporarily inactive.

### **extX journaling system?**

> ext2, ext3 and ext4 are extended file systems that provide multiple functionaltites like defragmentation, journaling and time stamping.

### **Journaling?**

> The journal is an on-disk log of metadata, or data about the filesystem, that is kept up-to-date as the filesystem changes. journaling enables fast crash recovery.

### **Packets?**

> packets are chunks of data that form parts of a complete message and contain pertinent address information of the sender and the recipient, packets are seperated into 3 parts, a header, a payload (content) and a trailer (signature).

### **TCP and UDP**?

> Transmission Control Protocol is a communication tool used in the internet that ensures that some general properties (size of a packet) promised when sending a message were fullfilled (receiver side) and does some corrections if packets are were missing.
> User Datagram Protocol is also a communication tool that, contrary to TCP, only sends packets with hopng that they were received (and is faster that TCP for that reason).

### **Cron**?

> Cron is a command line utility that allows users on Unix-like operating systems to schedule repetetive tasks periodically (runnign a command or a shell script). Tasks are setup in a crontab (config file) with a Cron time and a path to the script to run.
> Cron time is of the following form :
>
> ```
>  ┌───────────── minute (0 - 59)
>  │ ┌───────────── hour (0 - 23)
>  │ │ ┌───────────── day of the month (1 - 31)
>  │ │ │ ┌───────────── month (1 - 12)
>  │ │ │ │ ┌───────────── day of the week (0 - 6) (Sunday to Saturday;
>  │ │ │ │ │                                   7 is also Sunday on some systems)
>  │ │ │ │ │
>  │ │ │ │ │
>  * * * * *
> ```

### **TTY**?

> in Unix-like oprating systems, TTY is a terminal emulator that allows users to interact with the system through a comand-line interface, when a user logs in to a Unix system they are usually connectected to a TTY device, which enabls them to type in commands and see the outputs of those commands in a terminal window.

[Second answer of this post is the sexiest visualization ever](https://askubuntu.com/questions/506510/what-is-the-difference-between-terminal-console-shell-and-command-line)

## **Makefile**

> **Important resource**:
>
> - [makefiletutorial.com](https://makefiletutorial.com)
> - [GNU Make](https://www.gnu.org/software/make/manual/make.html)

- We can use variables in a makefile using the conventional assignement operator and then calling the variable's value using $(variable).
- If a command isn't indented with a tabulation (specifically using tab and not spaces) the command will not work.
- Targets are file names.
- The target gets recompiled if the target dosen't exist or the prerequisite's timestamp have changed since target was last compiled.
- Assignement is done either using := or =.
- Variable calling is done either using `${}` or `$()`.
- Make has a huge list of implicit rules that will run by default unless you override them.
- ar is a progarm that makes static libraries out of object files
  - the -c option suppresses a warning where ar requests an update but the archive dosen't already exist, so the archive is created without a warning.
  - the -r option replaces older object files with newer object files.
  - the -s option calls ranlib.
  - ranlib generates an index file within the archive which identifies the symbols (functions and variables) with the object files defining them that exist within the archive.
  - indexing makes linking significantlly faster by allowing routines to call each other without regard to the placement, meaning that the linker only has to look for definitions of symbols from the index and wouldn't have to read every object file in the archive to resolve a symbol.

---

## **C Keywords**

- the **restrict** keyword is a promise from the programmer to the compiler that indicates that no pointer other than restricted pointer will be used to access the object to which it points to. (It is used so that the compiler can max out optimization and not worry about pointer overlap, [Reference](https://en.wikipedia.org/wiki/Restrict).)
- **const** is used to convey that a variable is "read-only", thus the compiler will throw an error when there's an attempt to modify the const declared variable. (used to help code comprehensibility/readability and also allow the compiler further optimization through caching).
- **register** suggests to the compiler storing the variable in a cpu register (and not RAM) for faster access later.
- **volatile** prevents the compiler from making unnecessary optimization knowing the variable will be read and write further ahead (I don't have a concrete understanding of this keyword yet but it's so uselss anyways).
- the **extern** keyword will tell the compiler that the data is defined somewhere else and will be connected through the linker (which is the default assumption the compiler makes)

  - e.g: if two files contain variable that has the same name, both source files will have seperate copies of that variable, but when the variable is declared with the extern keyword in both files, they will both point to the same variable. [Scroll to the second answer in this link](https://stackoverflow.com/questions/496448/how-to-correctly-use-the-extern-keyword-in-c)

- **static** is used to set function-scope-limited global variables and set functions to set their scope to the containing file.

  - Static defined local variables do not lose their value between function calls. In other words they are global variables, but scoped to the local function they are defined in.
  - Static global variables and static functions are not reachable outside of the C file they are defined in.

---

## **Unix Shells**

### here doc/string

- `<<` is a here document where right side of the symbol declares a delimiter at which the input should close and the left side declares the input to which to send the document.

```shell
$ cat << EOF
> hi
> there
> EOF
hi
there
```

- `<<<` is a here string where right side of the symbol declares a string and the left side declares the input to which to send the the string.

```shell
$ cat <<< "lmfao haha"
lmfao haha
```

> the use of "here doc/str" is not similar to piping, because pipes make single command run in seperate subshells.

### Dollar Sign in **Unix** Shells?

- $1, $2, $3, ... are the positional parameters.
- $@ is an array-like construct of all positional parameters, {$1, $2, $3 ...}.
- $\* is the IFS expansion of all positional parameters, $1 $2 $3 ....
- $# is the number of positional parameters.
- $- current options set for the shell.
- $\$ pid of the current shell (not subshell).
- $\_ most recent parameter (or the abs path of the command to start the current shell immediately after startup).
- $IFS is the (input) field separator.
- $? is the most recent foreground pipeline exit status.
- $! is the PID of the most recent background command.
- $0 is the name of the shell or shell script.

- $(...) the commands inside the braces are ran in a subshell and their results are then replaced in the initial command. (similar to backticks `` but can be nested).

### Miscellaneous (Unix Shells)

- `~` home directory.
- `text > file` and `text >> file` are, respectively, for overwriting file content with text, and for appending text to the contents of file.
- `<` redirect input.

---

## **Miscellaneous**

- **lvalue** (comes from left hand side of assignment) is something that can be assigned to. **rvalue** (comes from right hand side of assignment) is something that can be assigned.
- Include guards only prevent a header file from being included multiple times in the same source file. but they will not protect from a header file showing up in multiple source files.
- **size_t** is a unsigned type that is the result of sizeof() operator, it is also the maximum size any C object can hold.
  - **SIZE_MAX** is a macro defined in stddef.h that represents the maximum value of size_t.
- Implicit type conversion in C happens automatically when a value is copied to its compatible data type.
- **malloc**'s arguments:
  - the maximum argument malloc can take is implementation specific and will exceed SIZE_MAX on for example OS X.
  - the minimum argument malloc can take is 0 and behaviour will be implentation specific, malloc will either return NULL or a unique pointer value. [Reference: Page 491, 511](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)
- if the programmer tries to convert from a type that can represent more values to a type that can represent less values (say from long to short) a truncation happens in an implementation defined manner.
- Symbols are functions and variables
- An **archive** is a single file that contains a collection of other files and/or directories. Archive files are typically used for a transfer (locally or over the internet) or make a backup copy of a collection of files and directories which allow you to work with only one file instead of many. Likewise, archives are used for software application packaging. This single file can be easily compressed for ease of transfer while the files in the archive retain the structure and permissions of the original files.
- trying to get the address of a function just evaluates to a pointer to that function, and dereferencing a function pointer also just evaluates back to the function pointer.
- `char(*)[3] and char**` are fundamentally different and the former cannot decay to the latter. `char**` is a pointer to a varible of type `char*`, it might be an array of `char*`, but that's not an array of char of length 3.
- **Variadic functions** [Reference](https://en.wikipedia.org/wiki/Variadic_function#In_C)
  - in order to use variadic functions in C, we need to include the stdarg.h standard header that introduces the type _va_list_ and multiple other macros.
  - _va_list_ is a list that contains the arguments that were given to the variadic function, we can iterate through the elements of this list by initializing it using _va_start_, and then calling _va_arg_, each subsequent call to _va_arg_ scrolls to the next argument.
  - _va_arg_ takes for parameters a _va_list_ and a type.
  - _va_end_ serves as a clean up to afford the programmer the ability to reinitialise the _va_list_.

---
