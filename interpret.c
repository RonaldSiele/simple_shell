#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define CMD_MAX 150
/*
 * max - The main function of the interpret program.
 * The function takes no input parameters
 * @CMD_MAX: command line charactors
 * @void:no input parameter
 * @cmd_status:Exit status of the program
 * Return:0 always return succes
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
int max2(void)
{
return max();
}
