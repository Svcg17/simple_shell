#include "header.h"


char *free_execcwd(char *str, char *cwd, char *temp)
{
	free(cwd);
	str = _strdup(str);
	free(temp);
	return (str);
}

char *free_abspath(char *cmd, char *cwd, char *temp)
{
	free(cwd);
	free(temp);
	return (cmd);
}

char *free_regcmd(char *cwd, char *str, char *temp)
{
	free(cwd);
	str = _strdup(str);
	free(temp);
	return (str);
}
