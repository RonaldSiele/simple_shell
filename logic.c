#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define LOGIC_MAX 100

int logic(void)
{
char command[LOGIC_MAX], *token, *delimiter = "&&||";
int cmd;

while (printf("Enter command:") && fgets(command, LOGIC_MAX, stdin) &&  fgets(command, LOGIC_MAX, stdin) && strcmp(command, "exit\n"))
{
token = strtok(command, delimiter);
while (token != NULL)
{
cmd = system(token);
if (cmd != 0)
{
token = strtok(NULL, delimiter);
if (token != NULL && token[0] == '|')
token = strtok(NULL, delimiter);
continue;
}
token = strtok(NULL, delimiter);
if (token != NULL && token[0] == '&')
token = strtok(NULL, delimiter);
}
}
return (0);
}
