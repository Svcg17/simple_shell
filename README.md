# Simple Shell - **mango**

Welcome to the **mango** simple shell repository! This repository contains the code for a simple version of a shell. With this shell you can run simple commands, including their flags, as well as a few built-ins. You can also enter the full path of a command if you'd like, but that seems like an awful lot of extra amount of work, y'know?

___

Sample Commands | Description
--------------- | -----------
`ls`		| Displays the contents of a directory
`pwd`		| Displays the path of the current working directory
`echo`		| Prints the contents of whatever follows within quotes
`cat`		| Concatenates the text of a file and displays it

___

Some built-ins are also available should you so choose:

Sample Built-ins | Description
---------------- | -----------
`env`		 | Prints the environmental variables and their values
`exit`		 | Exits the shell

___

### List of Files

File Name | Description
--------- | -----------
[`mango.c`](https://github.com/Svcg17/simple_shell/blob/master/mango.c) | the main file for the simple shell
[`parse.c`](https://github.com/Svcg17/simple_shell/blob/master/parse.c) | holds the functions that parse and tokenizes the command and its location in the PATH
[`builtins.c`](https://github.com/Svcg17/simple_shell/blob/master/builtins.c) | holds the functions that execute if a built-in is called
[`checkline.c`](https://github.com/Svcg17/simple_shell/blob/master/checkline.c) | checks if user input is valid
[`free.c`](https://github.com/Svcg17/simple_shell/blob/master/free.c) | holds the functions that free any allocated memory as well as if execve() fails
[`helperfunctions.c`](https://github.com/Svcg17/simple_shell/blob/master/helperfunctions.c) | holds helper functions to assist in the working of our code
[`helperfunctions2.c`](https://github.com/Svcg17/simple_shell/blob/master/helperfunctions2.c) | holds additional helper functions
[`helperfunctions3.c`](https://github.com/Svcg17/simple_shell/blob/master/helperfunctions3.c) | holds `_puts()`
[`signal.c`](https://github.com/Svcg17/simple_shell/blob/master/signal.c) | accounts for how Ctrl-C is handled in the shell
[`header.h`](https://github.com/Svcg17/simple_shell/blob/master/header.h) | contains the prototypes for all functions

___

### Who is responsible for this?

<blockquote class="imgur-embed-pub" lang="en" data-id="a/UA8vnjN"><a href="//imgur.com/UA8vnjN"></a></blockquote><script async src="//s.imgur.com/min/embed.js" charset="utf-8"></script>

This code was written by [Sofía Cheung](https://github.com/Svcg17) and [Marc Cavigli](https://github.com/MCavigli) with the help of the wonderful human beings in Cohort 8. We accept bitcoin and venmo.