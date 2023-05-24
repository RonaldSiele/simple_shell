#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define LOGIC_MAX 100
/**
 * executeCommand - Executes a single command.
 * @command: The command to execute.
 *
 * Return: 0 on success, -1 on failure.
 */
int executeCommand(char *command)
{
int status = system(command);
if (status == -1)
{
printf("Error executing command:%s\n", command);
return (-1);
}
return (0);
}
/**
 * logic - Executes logical commands entered by the user.
 *
 * Return: Always returns 0.
 */
int logic(void)
{
char command[LOGIC_MAX];
char *token;
const char *delimiter = "&&||";
int shouldExecute = 1;
int commandStatus = 0;


while (printf("Enter command:") && fgets(command, LOGIC_MAX, stdin) && strcmp(command, "exit\n"))
{
shouldExecute = 1;
token = strtok(command, delimiter);
while (token != NULL)
{
int status;
if (strcmp(token, "&&") == 0)
{
shouldExecute = (commandStatus == 0);
}
else if (strcmp(token, "||") == 0)
{
shouldExecute = (commandStatus != 0);
}
else
{
if (shouldExecute)
{
status = executeCommand(token);
if (status == -1)
{
commandStatus = -1;
break;
}
commandStatus = WEXITSTATUS(status);
}
}
token = strtok(NULL, delimiter);
}
}
return (0);
}
