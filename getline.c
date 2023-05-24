#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define GETLINE_MAX 100
/**
 * getline_builtin - Reads a line from stdin using getline.
 *
 * Return: The read line or NULL on failure or end of input.
 */
char *getline_builtin()
{
static char buffer[GETLINE_MAX];
static char *line;
static  size_t line_size;
ssize_t read;

printf("Enter the line:");
fflush(stdout);

if (line != NULL)
{
free(line);
line = NULL;
line_size = 0;
}
read = getline(&line, &line_size, stdin);
if (read < 0)
{
return (NULL);
}
if (read > 0 && line[read - 1] == '\n')
{
line[read - 1] = '\0';
}
strncpy(buffer, line, GETLINE_MAX);
return (buffer);
}
/**
 * GETLINE - Reads lines from stdin getline_builtin untill NULL is returned.
 *
 * Return: 0 on success.
 */
int GETLINE(void)
{
char *line;
while (1)
{
line = getline_builtin();
if (line == NULL)
{
printf("Goodbye!\n");
break;
}
printf("You entered:%s\n", line);
}
return (0);
}
