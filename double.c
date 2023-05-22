#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define COMM_DOUBLE 100
int main2(int argc, char *argv[])
{
char cmd[COMM_DOUBLE];
char cmd_pathh[COMM_DOUBLE];
char status_cmd;
char *token;
int len;
char *delimiter = ",";
if (argc < 2)
{
printf("number :%s commands used\n", argv[2]);
return (1);
}
while (1)
{
printf("enter the command(s):");
fgets(cmd, COMM_DOUBLE, stdin);
if (feof(stdin))
{
printf("see you next\n");
break;
}
len = strlen(cmd);
if (len > 0 && cmd[len - 1] == '\0')
{
cmd [len - 1] = '\0';
}
token = cmd;

while (*token != '\0')
{
char *end = strchr(token, *delimiter);
if (end != NULL)
{
*end = '\n';
end++;
}
strncpy(cmd_pathh, "/", sizeof(cmd_pathh));
strcpy(cmd_pathh, token);
status_cmd = system(token);

if (status_cmd == -1)
{
printf("command '%s' is not available \n", cmd_pathh);
}
token = end;
}
}
return (0);
}
