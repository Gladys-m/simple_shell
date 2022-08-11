#include "main.h"

/**
 * main - creates a simple shell
 *
 * Return: 0
 */
int main()
{
	char path[100], commands[100], *input[100];
	char prompt[10] = "@valley~$ ";
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1)
	{
		printf("%s", prompt);
		read_command(commands, input);

		if (fork() != 0)
		       wait (NULL);
		else
		{
			strcpy (path, "/bin/");
			strcat (path, commands);
			execve (path, input, envp);
		}
		if (strcmp(commands, "exit") == 0)
			break;
	}
	return (0);
}

/**
 * read_command - reads command from terminal
 * @cmd: the first command
 * @param: the rest of the parameters
 *
 * Return: void
 */
void read_command(char cmd[], char *param[])
{
	char buffer[1024];
	int count = 0, i = 0, j = 0, c;
	char *array[100], *p;

	while (1)
	{
		c = fgetc(stdin);
		buffer[count++] = (char) c;
		if (c == '\n')
			break;
	}
	if (count == 1)
		return;
	p = strtok(buffer, "\n");

	while (p != NULL)
	{
		array[i++] = strdup(p);
		p = strtok(NULL, "\n");	
	}
	strcpy (cmd, array[0]);

	for (j = 0; j < i; j++)
	{
		param[j] = array[j];
		param[i] = NULL;
	}
}
