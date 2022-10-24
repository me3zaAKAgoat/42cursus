<h1 align="center" ><strong>42cursus</strong></h1>
<p align="center" >Notes for my journey of learning C.</p>

## **Reminders**

- ```
  Still need to fix
  - ft_strlcat (edge cases)
  - ft_substr (memory leaks)
  - ft_split (memory leaks)
  - need to examine the declarations and the conflics between them and the definitons.
  ```
- `Ar program options (-rc??).`
- `what is relinking in makefile`
- re read the reddit comment about linking and compilation again.
- Learn about shared and static libraries and how they work in detail.
- read more about implicit rules of a makefile.
- read more about alignement requirement.
- Why should I use all in my libft makefile?
- What does '\*' Wildcard do?
- Learn about regex, patterns, wildcard meaning and what stem means in makefile.
- read about virtual memory.

## **Index**
- [Memory](https://github.com/me3zaAKAgoat/42cursus#memory)
- [Different Types Of Errors](https://github.com/me3zaAKAgoat/42cursus#different-types-of-errors)
- [Dealing With Files](https://github.com/me3zaAKAgoat/42cursus#dealing-with-files)
- [Makefile](https://github.com/me3zaAKAgoat/42cursus#makefile)
- [Keywords](https://github.com/me3zaAKAgoat/42cursus#keywords)
- [Miscellaneous](https://github.com/me3zaAKAgoat/42cursus#miscellaneous)
- [Reminders](https://github.com/me3zaAKAgoat/42cursus#reminders)

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

## **Different Types Of Errors**

### Runtime Errors

- ##### SEGMENTATION FAULT
  Segmentation fault occurs when the program tries to access an area of memory that it is not allowed to access.
- ##### BUS ERROR
  Bus error occurs when the program gives a processor instruction with an addres that does not satisfy its `alignement requirements`.

### What is ERRNO?

- *ERRNO* is an integer variable that is set by system calls and some library functions to indicate the specifics of an error in the event that one occurs.

## **Dealing With Files**

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
- Variable calling is done either using \$\{\} or \$\(\).
- Make has a huge list of implicit rules that will run by default unless you override them.

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

- **lvalue** is something that can be assigned to. **rvalue** is something that can be assigned.
- Include guards only prevent a header file from being included multiple times in the same source file. but they will not protect from a header file showing up in multiple source files.
- **size_t** is a unsigned type that is the result of sizeof() operator, it is also the maximum size any c object can hold.
  - **SIZE_MAX** is a macro defined in stddef.h that represents the maximum value of size_t.
- Implicit type conversion in C happens automatically when a value is copied to its compatible data type.
- **malloc**'s arguments:
  - the maximum argument malloc can take is implementation specific and will exceed SIZE_MAX on for example OS X.
  - the minimum argument malloc can take is 0 and behaviour will be implentation specific, malloc will either return NULL or a unique pointer value.
  - if the programmer tries to convert from a type that can represent more values to a type that can represent less values (say from long to short) a truncation happens in an implementation defined manner.


