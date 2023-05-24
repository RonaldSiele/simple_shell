#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MYCD_MAX 100
/**
 * MYCD - changes the current working directory.
 * @argc: The number of comand_line arguments.
 * @argv: An array of strings representing the arguments.
 *
 * Return:Always return 0.
 */
int MYCD(int argc, char *argv[])
{
char newDir[MYCD_MAX];
if (argc == 1 || (argc == 2 && strcmp(argv[2], "-") == 0))
{
const char* homeDir = getenv("HOME");
if (homeDir != NULL)
{
chdir(homeDir);
setenv("PWD", homeDir, 1);
}
else
{
printf("cd : No $HOME environment variable found.\n");
}
}
else if (argc == 2)
{
if (strcmp(argv[1], "-") == 0)
{
const char* prevDir = getenv("OLDPWD");
if (prevDir != NULL)
{
chdir(prevDir);
setenv("PWD", prevDir, 1);
}
else
{
printf("cd: No previous directory found.\n");
}
}
else
{
if (chdir(argv[1]) == 0)
{
getcwd(newDir, sizeof(newDir));
setenv("PWD", newDir, 1);
}
else
{
printf("cd: %s: no such directory. \n", argv[1]);
}
}
}
else
{
printf("cd: Too many arguments .\n");
}
return (0);
}
