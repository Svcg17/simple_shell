#ifndef __HEADER_H__
#define __HEADER_H__
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;

/**
 * builtin - struct for builtin system calls
 * @str: the builtin command entered by the user
 * @f: the function to execute if @str is entered
 * Return: the function to execute, 0 if @str is not found
 */
typedef struct builtin
{
	char *str;
	int (*f)(void);
} built;

/* Helper functions */
char *_memset(char *s, char b, unsigned int n);
int _strcmp(char *s1, const char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);

/* helperfunctions2.c */
int _strncmp(char *s1, const char *s2, int n);

/* Functions relating to parsing and tokenizing the command and PATH */
char **getinput(char *input);
char *catdir(char **dirs, char *cmd);
char **parse_dirs(char *str);
char *findvar(void);
char *get_env(char *buff);

/* Built-in functions */
int getbuiltfunc(char *s);
int printenv(void);
int exitt(void);
#endif
