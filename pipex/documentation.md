<h1 align="center"><strong>Pipex</strong></h1>

<h4 align="center"><strong>This is an explanation of the flow of the program for the bonus part.</strong></h4>

---

For usage of multiple pipes, the solution I came up with is an array of ints that's gonna be heap allocated and pointed to by a structures member, and pipe() will be called every 2 indexes of this array.

_N.B_: Whenever the following syntax is used:

> pipex_data->pipes[arr_cursor + 0] = file descriptor

is equivalent to:

> $\text{PIPE} \small{arr\_ cursor}\text{[0]} $ = file descriptor

is also equivalent to:

> the write end of the pipe n° arr_cursor

---

# **main**

## **setup_heredoc**

- checks wether a here document should be prompted, if so then prompt and offset arguments afterwards by 1, achieved by the t_pipex_obj structure's member heredoc offset.

  _N.B_: **pipex_data.heredoc_offset** is to be added next to ac whenver we want to take arguments from argv.

## **init**

- initialize the structures members pipes, program_paths, ac, argv, envp
- this structure makes it easier to pass variables that are "global" to the program to every step of said program.

## **children**

- child functions are called, these functions do the setup and initiation for the forked child processes (child_process_core functions)

## **cleanup_all**

- frees heap allocated members of the structures.

## **wait**

- halts the execution of the main process until its children terminate and stores the exit status of the last child process in the status variable.
