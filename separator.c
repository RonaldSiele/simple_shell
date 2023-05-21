#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define SEPAR_MAX 120

int main(int argc, char *argv[])
{
char cmd[SEPAR_MAX];
char* token;
char* end;
(void)argv;
(void)argc;
printf("shell >");
fgets(cmd, sizeof(cmd), stdin);
token = strtok(cmd, ";");
while (token != NULL)
{
char* triCmd = token;
while (*triCmd == ' ' || *triCmd == '\t')
{
triCmd++;
}
end = triCmd + strlen(triCmd) - 1;
while (end > triCmd && (*end == ' ' || *end == '\t'))
{
*end-- = '\0';
}
if (strlen(triCmd) > 0)
{
int ret = system(triCmd);
if (ret == -1)
{
printf("Error executing command:%s\n", triCmd);
}
}
token = strtok(NULL, ";");
}
return (0);
}

