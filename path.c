#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAXIMUM 100
/**
 * MAXII - Executes a command based on the provided argument.
 * @argc: The number of command_line arguments.
 * @argv: An array of strings representing the arguments.
 *
 *Return: Always returns 0.
 */
int MAXII(int argc, char *argv[])
{
char cmd[MAXIMUM];
char e_path[MAXIMUM];
int command_status;
if (argc < 2)
{
printf("usage:%s cammand \n", argv[0]);
exit(1);
}

while (1)
{
printf("enter the command:");
fgets(cmd, MAXIMUM, stdin);
if (feof(stdin))
{
exit(0);
}
cmd[strcspn(cmd, "\ni")] = '\0';
strcpy(e_path, "");
strcat(e_path, "/");
strcat(e_path, argv[0]);
strcat(e_path, cmd);
if (access(e_path, X_OK) == 0)
{
command_status = system(e_path);
(void)command_status;
}
else
{
printf("command not found");
continue;
}
}
return (0);
}
