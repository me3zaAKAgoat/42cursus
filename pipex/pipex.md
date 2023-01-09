<h1 align="center"><strong>Pipex</strong></h1>

Pipex is a program that should mimic/simulate the behaviour of Unix shell's pipe command line utility `|` whilst also allowing for input redirection, output redirection and the use of here_doc CLU.

The issues with pipex:

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

```python

		mandatory = [ TestCase(1, ['infile.txt', 'cat', 'wc', 'outfile.txt'],
		             'Normal parameters, simple commands, everything should go ok'),
		    TestCase(2, ['infile.txt', 'cat', 'wc', 'inexistent.txt'], "Output file does not exist"),
		    TestCase(3, ['infile.txt', 'sed    "s/And/But/"', 'grep But', 'outfile.txt'],
		             'Normal parameters, commands with arguments, everything should go ok'),
		    TestCase(4, ['infile.txt', 'sed "s/And/But/"', "awk '{count++} END {print count}'", 'outfile.txt'],
		             'program that has spaces in the middle of string argument with single quotes (awk argument)'),
		    TestCase(5, ['infile.txt', 'sed "s/And/But/"', 'awk "{count++} END {print count}"', 'outfile.txt'],
		             'program that has spaces in the middle of string argument with double quotes (awk argument)'),
		    TestCase(
		        6, [
		            'infile.txt', 'sed "s/And/But/"', 'awk "{count++} END {printf \\"count: %i\\" , count}"',
		            'outfile.txt'
		        ],
		        'Argument with escaped double quotes and then a space [yellow](\\" ,)[/yellow], inside double quotes (awk argument)'
		    ),
		    TestCase(
		        7,
		        ['infile.txt', 'sed "s/And/But/"', "awk '{count++} END {printf \"count: %i\", count}'", 'outfile.txt'],
		        'program that has double quotes inside single quotes (awk argument)'),
		    TestCase(8, ['infile.txt', "./script.sh", 'wc', 'outfile.txt'], 'Command that is in the same folder'),
		    TestCase(9, ['infile.txt', './script space.sh', 'wc', 'outfile.txt'],
		             'The script is in the same folder, but has a name that contains a space'),
		    TestCase(10, ['infile.txt', './script\\"quote.sh', 'wc', 'outfile.txt'],
		             'The script is in the same folder, but has a name that contains an escaped quote'),
		    TestCase(11, ['infile.txt', "./script space.sh", 'wc', 'outfile.txt'],
		             'The script is in the same folder, but has a name that contains a space'),
		    TestCase(12,
		             ['infile.txt', str((self.tests_dir / "script.sh").resolve()), 'wc', 'outfile.txt'],
		             'Command that contains the complete path'),
		    TestCase(13, ['no_in', 'cat', 'wc', 'outfile.txt'], "Input files does not exist"),
		    TestCase(14, ['infile.txt', 'non_existent_comm', 'wc', 'outfile.txt'], "first command does not exist"),
		    TestCase(15, ['infile.txt', 'cat', 'non_existent_comm', 'outfile.txt'], "second command does not exist"),
		    TestCase(16, ['no_r_perm', 'cat', 'wc', 'outfile.txt'], "Input files does not have read permissions"),
		    TestCase(17, ['infile.txt', 'cat', 'wc', 'no_w_perm'], "Output files does not have write permissions"),
		    TestCase(18, ['infile.txt', './no_x_script.sh', 'wc', 'outfile.txt'],
		             "The first command does not have execution permission"),
		    TestCase(19, ['infile.txt', 'cat', './no_x_script.sh', 'outfile.txt'],
		             "The second command does not have execution permission"),
		    TestCase(20, ['infile.txt', './middle_fail.sh', 'wc', 'outfile.txt'],
		             "The first commands fails in the middle of executing, but produces some output"),
		    TestCase(21, ['infile.txt', 'cat', './middle_fail.sh', 'outfile.txt'],
		             "The second commands fails in the middle of executing, but produces some output"),
		    TestCase(22, ['infile.txt', './script.sh', './script.sh', 'outfile.txt'],
		             "The PATH variable is empty, but the scrips are local",
		             path=""),
		    TestCase(23, ['infile.txt', 'cat', 'wc', 'outfile.txt'], "The PATH variable is empty", path=""),
		    TestCase(24, ['infile.txt', './script.sh', './script.sh', 'outfile.txt'],
		             "The PATH variable does not exist with local scripts",
		             path=None),
		    TestCase(25, ['infile.txt', 'cat', 'wc', 'outfile.txt'],
		             "The PATH variable does not exist with normal commands",
		             path=""),
		    TestCase(26, ['infile.txt', 'cat', 'script.sh', 'outfile.txt'],
		             "Should not match local script if it does not have a dot before the name"),
		    TestCase(27, ['infile.txt', 'cat', 'uname', 'outfile.txt'],
		             "Should search the command by the directory order in PATH",
		             path=f"{self.tests_dir}:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"),
		    TestCase(28, ['infile.txt', 'cat', 'uname', 'outfile.txt'],
		             "Should search the command by the directory order in PATH",
		             path=f"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:{self.tests_dir}"),
		    TestCase(29, ['infile.txt', 'cat', 'wc', 'outfile.txt'],
		             "The PATH is shorter and does not have /usr/bin/ (and thus wc) in it",
		             path=f"/bin"),
		    TestCase(30, ['infile.txt', 'cat', 'wc', 'outfile.txt'],
		             "The PATH has '/' at the end of each entry",
		             path="/:".join("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin".split(':'))),
		    TestCase(31, ['infile.txt', 'subdir/script.sh', 'wc', 'outfile.txt'],
		             "It should execute commands in the subdirectory")
		]

		bonus = [
		    TestCase(32, ['infile.txt', 'cat', 'grep And', "cat -e", 'wc', 'outfile.txt'], "Multiple commands"),
		    TestCase(33, ['infile.txt', 'cat', 'grep And', "cat -e", 'wc', 'no_file.txt'],
		             "output file does not exist"),
		    TestCase(34, ['infile.txt', 'catasdasd', 'asdasd', 'sdfsdf', 'fsdgss', 'outfile.txt'],
		             "Multiple wrong commands"),
		    TestCase(35, ['here_doc', '"EOF"', 'cat', 'cat -e', 'no_file.txt'],
		             "heredoc where output file does not exist",
		             input="teste\nsome_str\nEOF\n"),
		    TestCase(36, ['here_doc', '""', 'cat', 'cat -e', 'outfile.txt'],
		             "heredoc with empty string, but multiple lines",
		             input="teste\nsome_str\n\n"),
		    TestCase(37, ['here_doc', '""', 'cat', 'cat -e', 'outfile.txt'],
		             "heredoc with empty string, with only and enter",
		             input="\n"),
		    TestCase(38, ['here_doc', '"end of line"', 'cat', 'cat -e', 'outfile.txt'],
		             "heredoc with empty string, with only and enter",
		             input="bla\n\nEnd\nend of line\n"),
		    TestCase(39, ['here_doc', 'EOF', 'cat', 'cat -e', 'outfile.txt'],
		             "heredoc with EOF string, but with lines starting and ending in EOF",
		             input="Teste\nEOFx\nEOF some\nx EOF\nEOF\n"),
```
