#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAXIMUM 100

int main(int argc, char *argv[])
{
char cmd[MAXIMUM];
char e_path[MAXIMUM];
char command_status;
if (argc < 2)
{
printf("usage:%s cammand \n", argv[0]);
exit(1);
}
char *path = getenv("PATH");
while (1)
{
printf("enter the command:");
fgets(cmd, MAXIMUM, stdin);
if (feof(stdin))
{
exit(0);
}
cmd[strcspn(cmd, "\0")] = '\0';
strcpy(e_path, "");
strcat(e_path, "/");
strcat(e_path, argv[0]);
strcat(e_path, cmd);
if (access(e_path, X_OK) == 0)
{
command_status = system(e_path);
}
else
{
printf("command not found");
continue;
}
}
return (0);
}