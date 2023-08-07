
# Simple Shell Project

Task : Write a simple UNIX command interpreter.



## I- Features :
Simple shell 0.1 :

The Shell should:

- Display a prompt and wait for the user to type a command. 
- A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

Simple shell 0.2 :

- Handle command lines with arguments.

Simple shell 0.3 :

- Handle the PATH.
- fork must not be called if the command doesn’t exist.

Simple shell 0.4 :

- Implement the exit built-in, that exits the shell.
- Usage: exit.
- You don’t have to handle any argument to the built-in exit.

Simple shell 1.0 :

- Implement the env built-in, that prints the current environment.

Simple shell 0.1.1 :

- Write your own getline function.
- Use a buffer to read many chars at once and call the least possible the read system call
- You will need to use static variables
- You are not allowed to use getline

Simple shell 0.2.1 :

- You are not allowed to use strtok.

Simple shell 0.4.1 :

- handle arguments for the built-in exit.
- Usage: exit status, where status is an integer used to exit the shell.


## Acknowledgements

 - [Awesome Readme Templates](https://awesomeopensource.com/project/elangosundar/awesome-README-templates)
 - [Awesome README](https://github.com/matiassingers/awesome-readme)
 - [How to write a Good readme](https://bulldogjob.com/news/449-how-to-write-a-good-readme-for-your-github-project)
 - [Everything you need to know to start coding your own shell](https://intranet.alxswe.com/concepts/64)
 
## Contributing

This project was a result of collaboration :
- Hassnaa Shindou [@shindou7](https://github.com/Shindou7)
- Amine Sehlaoui [@skylimit96](https://github.com/skylimit96)
