#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define GETLINE_MAX 100
char *getline_builtin()
{
static char buffer[GETLINE_MAX];
static char *line = NULL;
static  size_t line_size = 0;
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
