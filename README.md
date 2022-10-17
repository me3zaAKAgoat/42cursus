<h1 align="center" ><strong>42cursus</h1>

# Errors
## Runtime Errors

- ### **Segmentation Fault**
    Segmentation fault occurs when the program tries to access an area of memory that it is not allowed to access.
- ### **Bus Error**
    Bus error occurs when the program gives a processor instruction with an addres that does not satisfyt its alignement requirements.
    Alignement Requirement :interrobang:
## What is errno
- _ERRNO_ is an integer variable that is set by system calls and some library functions to indicate the specifics of an error in the event that one occurs.

## Dealing With Files
**Notes**: 
>- the f that prefixes file handling functions usually refers to the function being a high level routine as opposed to a low level routine.
>- low level routines do not use buffering but take up to one minute before data can be physically written to teh disc (can use fsync to ensure that all data is written to the file).
- ### **Streams**
    - A stream is a flow of from a source to a destination within a GNU system (mostly used in high level routines).
    - Streams are represented by the type FILE*.
    - File position is a character count in the file starting at 0. file position 40 means that the character that is currently being read or written is the 41th character in the file. (**ftell** is a high leve function that takes in a stream as input and outputs an integer representing the file position).
    - EOF is a flag indicating that the current file position is the end of a the file.
- ### **File Descriptors**
    - A file decscriptor is an integer that represents the connetion opened between a source and a destination (mostly used in low level routines).


## Reminders
- need to examine the declarations and the conflics between them and the definitons.
- re read the reddit comment about linking and compilation again.
- Learn about shared and static libraries and how they work in detail.
- read more about implicit rules of a makefile.
- seek and file position.
- download the [c formatter](https://github.com/dawnbeen/c_formatter_42) (norminetter)