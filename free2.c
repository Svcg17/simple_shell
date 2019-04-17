#include "header.h"
/**
 * free_execcwd - frees when command exists in cwd.
 * @str: command + directory in path
 * @cwd: command + cwd
 * @temp: temp variable that holds array of strings containing dirs
 * Return: str
 */
char *free_execcwd(char *str, char *cwd, char *temp)
{
	free(cwd);
	str = _strdup(str);
	free(temp);
	return (str);
}


/**
 * free_regcmd - frees regular commands found in path
 * @cwd: command + cwd;
 * @str: command + directory in path
 * @temp: temp variable that holds array of strings containing dirs.
 * Return: str
 */
char *free_regcmd(char *cwd, char *str, char *temp)
{
	free(cwd);
	str = _strdup(str);
	free(temp);
	return (str);
}
