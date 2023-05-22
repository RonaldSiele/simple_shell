#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define GREAT_NUM 100
void print_environment()	
{
extern char **environ;
int i = 0;
while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
}

}



int environment(int argc, char *argv[])
{
char command[GREAT_NUM];
char command_path[GREAT_NUM];

if (argc < 2)
{
printf("usage:%s command \n", argv[1]);
exit(1);
}
while (1)
{
printf("root@ronaldo:");
fgets(command, GREAT_NUM, stdin);
if (feof(stdin))
{
exit(0);
}
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "env") == 0)
{
print_environment();
continue;
}
strcpy(command_path, "/");
strcat(command_path, "");
strcat(command_path, argv[1]);
}
return (0);
}
