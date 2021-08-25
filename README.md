## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Authors](#authors)


## Description
simple\_shell is a command line interpreter. The shell has a prompt(UNAME$) and it is displayed again each time a command has been executed.
This is a project made for the ALX software engineering program.

## File Structure
| File Name | Description and contents |
| --- | --- |
| [man\_1\_simple\_shell](man_1_simple_shell) | This is the manpage for the simple\_shell, where we can find examples and the correct syntax of the commands.|
| [shell.h](shell.h) |This is the header file with the prototypes of the functions.|
| [shell.c](shell.c) |main function - Prints the prompt in a loop and calls the functions to accept arguments and executes the command.|
| [vector.c](vector.c) |populates argv (which is array of string pointers which are arguments to `execve`).|
| [\_getenv.c](\_getenv.c) |It performs like the builtin function `getenv`.
| [path\_l\_list.c](path\_l\_list.c)| It creates a linked list of directories found in PATH.
| [check\_in\_Path.c](check_in_path.c)| checks if the first argument is located inside the directories found in PATH.
| [AUTHORS](AUTHORS) |List of contributors to this repository.|

## Requirements

simple\_shell is designed to run in the `Ubuntu 20.04 LTS` linux environment and to be compiled using `gcc` with flags`-Wall -Werror -Wextra -pedantic -std=gnu89`

## Installation

   - Clone this repository: `git clone "https://github.com/Henock-Adane/simple_shell.git"`
   - Change directories into the repository: `cd simple_shell`
   - Compile: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`
   - Or run the shell in non-interactive mode: example `echo "/bin/ls" | ./hsh`

## Usage

The simple\_shell is designed to execute commands with given arguments in a way discribed below.
The shell tokenizes written commands into words using " " as a delimiter and the first word is considered as the command and all remaining words as arguments. The command will be searched either in the list of shell builtins or in the elements of the PATH environmental variable and if successful, the shell executes the command with given arguments.  (see man page for complete information on usage):


## Authors
Leykun Weldesemayat | [GitHub] (https://github.com/Bisrat-Aregawi)

Henock Adane | [GitHub] (https://github.com/Henock-Adane)
