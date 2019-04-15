#include "header.h"

/**
 * catdir - concatenates the absolute path to the command
 * @dirs: array of strings holding the directories in PATH
 * @cmd: the command entered by user
 * Return: the concatenated string with the command
 */

char *catdir(char **dirs, char *cmd)
{
	char *str;
	char *cwdtemp;
	struct stat st;
/*
static
*/
	char *temp = malloc(sizeof(char) * 256);
	char *cwd = malloc(sizeof(char) * 256);
	int i = 0;

	if (temp == NULL)
		return (NULL);

	if (cwd == NULL)
		return (NULL);

	getcwd(cwd, 256);
	cwdtemp = _strcat(cwd, "/");
	cwdtemp = _strcat(cwd, cmd);
	while (dirs[i])
	{
			temp[0] = 0;

			str = _strcat(temp, dirs[i]);
			str = _strcat(temp, "/");
			str = _strcat(temp, cmd);
                        /* to account for `ls` executable files in cwd */
			if (stat(cwdtemp, &st) == 0 && stat(str, &st) == 0)
			{
				free(cwd);
				str = _strdup(str);
				free(temp);
				return (str);
			}

                        /* to account for /bin/ls */
			if (stat(cmd, &st) == 0 && stat(cwdtemp, &st) < 0)
			{
				free(cwd);
				free(temp);
				return (cmd);
			}
			/* for regular command inputs */
			if (stat(str, &st) == 0 && stat(cwdtemp, &st) < 0)
			{
				free(cwd);
				str = _strdup(str);
				free(temp);
				return (str);
			}
		_memset(temp, '\0', 256);
		i++;
	}
	free(cwd);
	free(temp);
	return (NULL);
}
/**
 * parse_dirs - parses an environmental variables value into array of strings
 * @str: the directories of chosen environmental variable
 * Return: an array of strings holding PATH's directories
 */

char **parse_dirs(char *str)
{
	char **bigb = malloc(sizeof(char *) * 1024);
	char *token;
	int i;

	token = strtok(str, ":");
	i = 0;
	printf("%s\n", token);
	while (token)
	{
		bigb[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	bigb[i] = NULL;
	return (bigb);
}

/**
 * findvar - gets an environment variable
 * name: name of variable to get
 * Return: pointer to variable
 */

char *findvar(void)
{
	int i;
	char *copy = NULL;
	char *token = NULL;

	for (i = 0; environ[i]; i++)
	{
		copy = _strdup(environ[i]);
		token = strtok(copy, "=");
		if (_strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "PATH");
			break;
		}
/*		else if (_strcmp(token, ":PATH") == 0)
		{
			token = strtok(NULL, ":PATH");
			break;
			}*/
		else
		{
			token = NULL;
			free(copy);
		}
	}
	if (token)
	{
		token = _strdup(token);
		/* if (token */
		free(copy); /*cpy*/
	}

	return (token);
/*
	for (i = 0; environ[i]; i++)
		if (_strncmp(environ[i], "PATH=", 5) == 0)
			return (strdup(environ[i] + 5));

	return (NULL);
*/

}

/**
 * get_env - helper function that sends a command through the whole process
 * to be concatenated
 * @buff: the command
 * Return: a string that has the absolute path of the command
 */

char *get_env(char *buff)
{
	char **bigb;
	char *envvar;
	char *concatstr;
	struct stat st;

	envvar = findvar();

	if (envvar == NULL)
	{
		free(envvar);
		return(buff);
	}
	if (envvar[0] == ':')
	{
		if(stat(buff, &st) == 0)
		{
			free(envvar);
			return (buff);
		}
	}

	bigb = parse_dirs(envvar);
	concatstr = catdir(bigb, buff);

	free(envvar);
	free(bigb);
	return (concatstr);
}

/**
 * getinput - tokenizes the entered command
 * @input: the command
 * Return: an array of strings that holds the command and its arguments
 */

char **getinput(char *input)
{
        char **bigb = malloc(10 * (sizeof(char *)));
        char *token;
        int i = 0;

        while (input[i])
                i++;
        input[i - 1] = '\0';

        token = strtok(input, " ");
        i = 0;
        while (token)
        {
                bigb[i] = token;
                i++;
                token = strtok(NULL, " ");
        }
        bigb[i] = NULL;
	/* free(token); should be free with main()::free(buff) */
        return (bigb);
}
