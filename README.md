Pipex

This project is about handling pipes in C programming language. 
The program will take 4 arguments: file1, cmd1, cmd2, and file2. 
The goal of the program is to behave exactly like the shell command: < file1 cmd1 | cmd2 > file2.

How to run:

To run the program, you must execute the following command:

$> ./pipex file1 cmd1 cmd2 file2

Where:

    file1 is the input file
    cmd1 is the first shell command with its parameters
    cmd2 is the second shell command with its parameters
    file2 is the output file

For example, to execute the command: $> < infile ls -l | wc -l > outfile, you should run:

$> ./pipex infile "ls -l" "wc -l" outfile

Files

The project should include the following files:

    Makefile: used to compile the project
    *.h: header files
    *.c: source files

Makefile

The Makefile should include the following rules:

    NAME: the name of the executable file
    all: compile the project
    clean: remove object files
    fclean: remove object files and the executable file
    re: remove object files and the executable file, then compile the project again

External Functions

The project uses the following external functions:

    open
    close
    read
    write
    malloc
    free
    perror
    strerror
    access
    dup
    dup2
    execve
    exit
    fork
    pipe
    unlink
    wait
    waitpid

The project must comply with the following requirements:

    The Makefile must not relink.
    Errors must be handled thoroughly. The program must not quit unexpectedly (segmentation fault, bus error, double free, etc.).
    The program must not have memory leaks.
    If you have any doubt, handle the errors like the shell command: < file1 cmd1 | cmd2 > file2.
