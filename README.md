<h1 align="center" ><strong>42cursus</strong></h1>
<p align="center" >Notes I have taken on my journey of learning C.</p>

## **Index**
- [Reminders](https://github.com/me3zaAKAgoat/42cursus#reminders)
- [Memory](https://github.com/me3zaAKAgoat/42cursus#memory)
- [Different Types Of Errors](https://github.com/me3zaAKAgoat/42cursus#different-types-of-errors)
- [File Management In Unix](https://github.com/me3zaAKAgoat/42cursus#dealing-with-files)
- [Makefile](https://github.com/me3zaAKAgoat/42cursus#makefile)
- [Keywords](https://github.com/me3zaAKAgoat/42cursus#keywords)
- [Miscellaneous](https://github.com/me3zaAKAgoat/42cursus#miscellaneous)

## **Reminders**

- Need to examine the declarations and the conflicts between them and the definitons.
- What does '*' Wildcard do?
- Learn about regex, patterns, wildcard meaning and what stem means in makefile.
- Read about virtual memory.

## **Memory**
- the RAM is a piece of hardware that stores data for it's uptime, the data is stored in slots of 1 byte and each slot has it's own address.
- Addresses are conventionally represented in hexadecimal, the 0x in addresses is but a prefix that indicates the base that represents the slot.
- The RAM makes data available for the CPU operations on demand.
- the OS partitions the RAM into Pages, these Pages are chunks of 4k Bytes.
- A program is either allowed to acess an entire page or none of it.
- A CPU cache is a small part of memory within the CPU that it uses so it dosen't have to keep asking the RAM for everything.
  - when the CPU wants to read from a certain address, it checks if it's in the cache first.
  - the cache stores in chunks of 64 bytes called *cache lines*.
- the memory we interact with as programmers is usually virtual memory, meaning that the addresses read are not actual RAM addresses.
- **Alignment Requirement:**

  All processors have instructions that need to read n bytes from the memory, these processors take the data needed for the instruction from the RAM in blocks of n bytes and put each block in a cache line.
  
  ![memory blocks](/READMEcontent/alignmentMemory.jpg)

  Data Structure Alignment is needed because it leads to efficient use of cache lines. 

  As per the illustration we have a 32 bit processor that reads 4 byte blocks and puts them into cache lines.
  
  E.g In the case of the red 4 byte-long data structure, in order for the processor to execute the instruction it will need to read two blocks thus will use up two cache lines to store what could've just used only one cache line if it were stored at a proper address in the memory.
  The blue stored value respects the alignment requirement and will only use one cache line as needed.

  **Important:** Data Structure Alignment is respected when the address at which an n-byte value is stored is divisible by n.

  [Video Explanation](https://youtu.be/zyGMyV955Rw)
- **Endianness** refers the the order bytes are stored in memory. A big-endian system stores the most significant byte of a word at the smallest memory address and the least significant byte at the largest. A little-endian system, in contrast, stores the least-significant byte at the smallest address.
[Endianness Wiki artice](https://en.wikipedia.org/wiki/Endianness)

## **Different Types Of Errors**

### Runtime Errors

- ##### SEGMENTATION FAULT
  Segmentation fault occurs when the program tries to access an area of memory that it is not allowed to access.
- ##### BUS ERROR
  Bus error occurs when the program gives a processor instruction with an addres that does not satisfy its `alignement requirements`.

### What is ERRNO?

- *ERRNO* is an integer variable that is set by system calls and some library functions to indicate the specifics of an error in the event that one occurs.

## **File Management In Unix**

> **Important resource**:
>
> - [Artice about Processes, Files, and File Descriptors in Linux](https://medium.com/geekculture/developer-diaries-processes-files-and-file-descriptors-in-linux-ebf007fb78f8)

- The 'f' that prefixes file handling functions usually refers to the function being a high level routine as opposed to a low level routine function.
- low level routines do not use buffering but can take up to one minute before data is physically written to the disc (we can use **fsync** to ensure that all data is written to the file).
- EOF is a flag that holds a negative integer value (though one should assume the value, it is usually -1) that indicates that a file position has reached the end of a file.
- File position is a character count in the opened file that starts at 0. for example, File position 40 means that the character that is currently being read from or written to is the 41th character in the file. (**ftell** is a high level function that takes in a stream as input and outputs an integer representing the file position).

- #### **Streams**
  - A **stream** is a flow of data from a source to a destination within a GNU system (mostly used in high level routines).
  - Streams are represented by the type FILE\*.
- #### **File Descriptors**
  - A file decscriptor is an integer that represents the connection opened between a source and a destination (mostly used in low level routines).

- It is good practice to redirect all error messages to stderr, while directing regular output to stdout. It is beneficial to do this because anything written to stderr is not buffered, i.e., it is immediately written to the screen so that the user can be warned immediately.
- Stderr is usually the console because it is the programmer tha should be notified when an error occurs.

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
- Variable calling is done either using '${}' or '$()'.
- Make has a huge list of implicit rules that will run by default unless you override them.
- ar is a progarm that makes static libraries out of object files
  - the -c option tells ar to create the library if it dosen't already exist.
  - the -r option replaces older object files with newer object files.
  - the -s option calls ranlib.
  - ranlib generates an index file within the archive which identifies the symbols (functions and variables) with the object files defining them that exist within the archive.
  - indexing makes linking significantlly faster by allowing routines to call each other without regard to the placement, meaning that the linker only has to look for definitions of symbols from the index and wouldn't have to read every object file in the archive to resolve a symbol.
## **Keywords**

- the **restrict** keyword is a promise from the programmer to the compiler that indicates that no pointer other than restricted pointer will be used to access the object to which it points to. (It is used so that the compiler can max out optimization and not worry about pointer overlap, [Reference](https://en.wikipedia.org/wiki/Restrict).)
- **const** is used to convey that a variabel is "read-only", thus the compiler will throw an error when there's an attempt to modify the const declared variable. (used to help code comprehensibility/readability and also allow the compiler further optimization through caching)
- **register** suggests to the compiler storing the variable in a cpu register (and not RAM) for faster access later.
- **volatile** prevents the compiler from making unnecessary optimization knowing the variable will be read and write further ahead (I don't have a concrete understanding of this keyword yet but it's so uselss anyways).
- the **extern** keyword will tell the compiler that the data is defined somewhere else and will be connected through the linker (which is the default assumption the compiler makes)

  - e.g: if we have two files with a variable that has the same name, both source files will have seperate copies of that variable, but when the variable is declared with the extern keyword in both files, they will both point to the same variable. [Scroll to the second answer in this link](https://stackoverflow.com/questions/496448/how-to-correctly-use-the-extern-keyword-in-c)

- **static** is used with global variables and functions to set their scope to the containing file

  - Static defined local variables do not lose their value between function calls. In other words they are global variables, but scoped to the local function they are defined in.
  - Static global variables and static functions are not visible outside of the C file they are defined in.

## **Miscellaneous**

- **lvalue** (comes from left hand side of assignment) is something that can be assigned to. **rvalue** (comes from right hand side of assignment) is something that can be assigned.
- Include guards only prevent a header file from being included multiple times in the same source file. but they will not protect from a header file showing up in multiple source files.
- **size_t** is a unsigned type that is the result of sizeof() operator, it is also the maximum size any c object can hold.
  - **SIZE_MAX** is a macro defined in stddef.h that represents the maximum value of size_t.
- Implicit type conversion in C happens automatically when a value is copied to its compatible data type.
- **malloc**'s arguments:
  - the maximum argument malloc can take is implementation specific and will exceed SIZE_MAX on for example OS X.
  - the minimum argument malloc can take is 0 and behaviour will be implentation specific, malloc will either return NULL or a unique pointer value. [Reference: Page 491, 511](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)
- if the programmer tries to convert from a type that can represent more values to a type that can represent less values (say from long to short) a truncation happens in an implementation defined manner.
- Symbols are functions and variables
- An **archive** is a single file that contains a collection of other files and/or directories. Archive files are typically used for a transfer (locally or over the internet) or make a backup copy of a collection of files and directories which allow you to work with only one file instead of many. Likewise, archives are used for software application packaging. This single file can be easily compressed for ease of transfer while the files in the archive retain the structure and permissions of the original files.
- Dereferencing or taking the address of a function just evaluates to a pointer to that function, and dereferencing a function pointer just evaluates back to the function pointer.


