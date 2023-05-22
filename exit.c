#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define NAMBARI 130

int line(void)
{
char cmd_line[NAMBARI];
char cmd_path[NAMBARI];
int cmd_status;

while (1)
{
fgets(cmd_line, NAMBARI, stdin);
if (feof(stdin))
{
exit(0);
}
cmd_line[strcspn(cmd_line, "\n")] = '\0';
if (strcmp(cmd_line, "exit") == 0)
{
exit(0);
}
strcpy(cmd_path, "");
strcat(cmd_path,cmd_line);

cmd_status = system(cmd_path);

if  (cmd_status == -1)
{
printf("command not found");
}
}
return (0);
}
