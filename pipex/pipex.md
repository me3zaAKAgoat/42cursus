<h1 align="center"><strong>Pipex</strong></h1>

Pipex is a program that should mimic/simulate the behaviour of Unix shell's pipe command line utility `|` whilst also allowing for input redirection, output redirection and the use of here_doc CLU.

The issues with pipex:

- debug the issue with pipe redirection.
- figure out why ./pipex infile.txt "ls -l ./src/util" "grep .c" "wc -l" outfile.txt dosent work
- check why tests 9 10 23 24 25 timeout now that exit is introduced to mid processes and waitpid is functional in the last part of the main process.
- change includes to basic "header.h" instead of "../header.h" and add -I option in compilation in makefile.
- how to run every command.
- each pipe end opened should be closed when use ends **IMMEDIATELY**.
- seperate commands are allowed to fail (they should perror and change the status of the main program) and finish the program.
- seperate concerns more and shorten functions/remove excess responsabilities.
- cleanup pipes' heap allocated space (after making sure all pipes ends FD of the parent process were closed) at the very end of the program.
- handle fork errors. pid == -1
- handle failure of a child process fucking up the last process.
- theres a MAJOR fucking difference between exit and return in processes [check this](https://stackoverflow.com/questions/66914203/waitpid-hangs-even-though-child-process-is-dead).

[very good unix pipes artice](https://www.rozmichelle.com/pipes-forks-dups/)
**add argv and argc to pipex object**

## flow:

- init function
  - check wether there's a minimum of 2 commands and 2 files for input and output
  - initialize the pipex_data structure
    - the **pipex_data structure** holds values that are global to the program and have to often be passed as arguments to most functions.
    - ac, program_paths, envp, argv, pipes.
  - makes pipe for the first and always necessarily existent pipe.
- the first process occurs
  - the infile is opened in read only mode
  - a fork is made
  - the command string is split
  - the path to the command is found
  - check for existence of command errors
  - redirection
  - execution
    ...

# **DO SEPERATE ISOLATED EXPERIMENTS OF PIPE DUP2 TO DEBUG WHAT THE ISSUES REALLY ARE WITH THE MAIN PROGRAM**
