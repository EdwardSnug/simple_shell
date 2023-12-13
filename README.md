# 0x16. C - Simple Shell
A C simple shell project created by Ochego Haryon in collaboration with Edward Kamande.

		1.SIMPLE_SHELL 01
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments

		2.SIMPLE_SHELL 02
Handle command lines with arguments

		3.SIMPLE_SHELL 03
Handle the PATH
fork must not be called if the command doesn’t exist

		4.SIMPLE_SHELL 04
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

On successful compilation the simple_shell program will be able to accept user input, tokenize the input and run on the user commands or exit on failure with an appropriate error message.

Our simple_shell only accepts the most of basic commands that are present in the bash shell and runs them. All files in the repository are compiled using  gcc -Wall -Werror -Wextra -pedantic *.c

	BUILTINS
Simple shell above uses only two inbuilt commands
1. env - Displays all environment variables in the path.  
2. exit - If the user wishes to exit the simple_shell program or CTRL-D
