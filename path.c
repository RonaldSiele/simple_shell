#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

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
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(1);
}
else if (pid ==0)
{
command_status = system(e_path);
exit(command_status);
}
else
{
int child_status;
waitpid(pid, &child_status, 0);
printf("command excited with status:%d\n",WEXITSTATUS(command_status));
}
}
else
{
printf("command not found");
continue;
}
}
return (0);
}
int man(int argc, char *argv[])
{
MAXII(argc,argv);
return 0;
}
