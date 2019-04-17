#ifndef __HEADER_H__
#define __HEADER_H__
#include <signal.h>
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

/* signal.c - Signal handler function*/
void signals(int sign);

/* checkline.c - Checks getline return value */
int checkline(char *buff);

/* free.c - Free functions for mango.c */
void free_all(char *buff, char **bigb, char *cmd);
void free_some(char *buff, char **bigb);
void free_parent(char *buff, char **bigb, char *cmd);
int execerror(char *buff, char **bigb, int counter, char *arg);
int child_fail(char *buff, char**bigb);

/* free2.c - More free functions for parse.c */
char *free_execcwd(char *str, char *cwd, char *temp);
char *free_abspath(char *cmd, char *cwd, char *temp);
char *free_regcmd(char *cwd, char *str, char *temp);

/* helperfunctions.c - Helper functions */
int _strcmp(char *s1, const char *s2);
int _strlen(char *s);
char *_memset(char *s, char b, unsigned int n);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

/* helperfunctions2.c - More helper functions */
int _strncmp(char *s1, const char *s2, int n);
char *str_concat(char *s1, char *s2);
int digit_number(int num);
char *_itoa(int num);
int _putchar(char c);

/* helperfunctions3.c - Even more helper funcitons */
void _puts(char *str);

/* parse.c - Functions relating to parsing/tokenizing the command and PATH */
char *catdir(char **dirs, char *cmd);
char **parse_dirs(char *str);
char *findvar(void);
char *get_env(char *buff);
char **getinput(char *input);

/* builtins.c - Built-in functions */
int getbuiltfunc(char *s);
int printenv(void);
int exitt(void);

void child_split(char *buff, char **bigb, char *cmd, char **argv, int counter);
#endif
