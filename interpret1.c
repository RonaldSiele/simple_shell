#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define CMD_NUMBER 100
int NUMBER(int argc, char *argv[1])
{
char cmd[CMD_NUMBER];
char whole_path[CMD_NUMBER];
char command_status;
if (argc < 2)
{
printf("usage:%s command\n", argv[1]);
exit(1);

}
while (1)
{
printf("enter_promt");
fgets(cmd, CMD_NUMBER, stdin);
if (feof(stdin))
{
exit(0);
}
cmd[strcspn(cmd, "\n")] = '\0';
strcpy(whole_path, argv[1]);
strcat(whole_path, "");
strcat(whole_path, cmd);

command_status = system(whole_path);

if (command_status == -1)
{
printf("command not found");
}
}
return (0);




}
