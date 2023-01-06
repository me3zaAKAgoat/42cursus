<h1 align="center"><strong>Pipex</strong></h1>

Pipex is a program that should mimic/simulate the behaviour of Unix shell's pipe command line utility `|` whilst also allowing for input redirection, output redirection and the use of here_doc CLU.

The issues with pipex:

- how to run every command.
- each pipe end opened should be closed when use ends **IMMEDIATELY**.
- seperate commands are allowed to fail (they should perror and change the status of the main program) and finish the program.
- seperate concerns more and shorten functions/remove excess responsabilities.
- cleanup pipes' heap allocated space (after making sure all pipes ends FD of the parent process were closed) at the very end of the program.

**add argv and argc to pipex object**

## flow:

- init function does the initialization that ALWAYS occurs:
  - checks wether the number of arguments is valid
  - looks for programs path in env
  - allocates memory for the array of pipes
    - every 2 boxes of the array constitute one pipe
  - makes the first pipe
- the status variable only changes value if a process returns non zero value, this variable's value is then returned at the end of the main program.
- every process cleans up its heap allocated space for cmd_path and cmd_args, and also closes every non servicable pipe end.
- for the intermediate commands a while loop is started at index 1 resembling the second command, and is stopped at ac - 4.
  - inside this while loop a pipe is created at i \* 2 (the iterations' corresponding boxes in the heap allocated array).
