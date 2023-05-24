#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define HANDLE_MAX 120

/**
 * replaceVariables - replace variables in the command
 * @str: The input command String
 *
 * Return:The modified command string
 */
char* replaceVariables(const char *str)
{
char* replacedStr = malloc(HANDLE_MAX * sizeof(char));
char* token = strtok((char *)str, " ");

while (token != NULL)
{
if (strcmp(token, "$?") == 0)
{
int status = system(token);
snprintf(replacedStr + strlen(replacedStr), HANDLE_MAX - strlen(replacedStr), "%d", WEXITSTATUS(status));
}
else if (strcmp(token, "$$") == 0)
{
snprintf(replacedStr + strlen(replacedStr), HANDLE_MAX - strlen(replacedStr), "%d", getpid());
}
else
{
snprintf(replacedStr + strlen(replacedStr), HANDLE_MAX - strlen(replacedStr), "%s", token);
}
token = strtok(NULL, " ");
}
return (replacedStr);
}
/**
 * HANDLE -	Handles the shell input and executes the command
 *
 * Return:Always return 0
 */
int HANDLE(void)
{
char cmd[HANDLE_MAX];
char *replacedCmd;
printf("shell > ");
fgets(cmd, sizeof(cmd), stdin);
cmd[strcspn(cmd, "\n")] = '\0';
replacedCmd = replaceVariables(cmd);
system(replacedCmd);
free(replacedCmd);
return (0);
}
