#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define CMD_MAX 150
/**
 * max - Executes user commands from stdin.
 *
 * Return:Always return 0.
 */
int max(void)
{
char cmd[CMD_MAX];
char full_path[CMD_MAX];
char cmd_status;
while (1)
{
printf("enter your command\n");
fgets(cmd, CMD_MAX, stdin);
if (feof(stdin))
{
exit(0);
}
cmd[strcspn(cmd, "\n")] = '\0';
strcat(full_path, cmd);
cmd_status = system(full_path);
if (cmd_status == -1)
{
printf("command is not found\n");
}
}
return (0);
}
/**
 *max2 - Calls the max function.
 *
 * Return: The return value of the max function.
 */
int max2(void)
{
return (max());
}
