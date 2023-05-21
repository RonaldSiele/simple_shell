#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define HANDLE_MAX 120

char* replaceVariables(const char *str)
{
char* replacedStr = malloc(HANDLE_MAX * sizeof(char));
char* token = strtok((char *)str," ");

while (token != NULL)
{
if(strcmp(token, "$?") == 0)
{
int status = system(token);
snprintf(replacedStr + strlen(replacedStr), HANDLE_MAX - strlen(replacedStr), "%d", WEXITSTATUS(status));
}
else if (strcmp(token, "$$") ==0)
{
snprintf(replacedStr + strlen(replacedStr),HANDLE_MAX - strlen(replacedStr), "%d", getpid());
}
else
{
snprintf(replacedStr + strlen(replacedStr), HANDLE_MAX - strlen(replacedStr), "%s", token);
}
token = strtok(NULL, " ");
}
return replacedStr;
}

int main()
{
char cmd[HANDLE_MAX];
char *replacedCmd;
printf("shell > ");
fgets(cmd, sizeof(cmd), stdin);
cmd[strcspn(cmd,"\n")] = '\0';
replacedCmd = replaceVariables(cmd);
system(replacedCmd);
free(replacedCmd);
return 0;
}
