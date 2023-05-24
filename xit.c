#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define EXIT_SHELL_MAX 150
/**
 * EXIT1 - Exits the shell with a specified exit status.
 * @argc: The number of commandline arguments.
 * @argv: An array of strings representing the arguments.
 *
 * Return: This function does not return a value.
 */
int EXIT1(int argc, char *argv[])
{
int exit_status;
if (argc < 2)
{
printf("usage:%s status \n", argv[2]);
exit(1);
}
exit_status = atoi(argv[1]);
exit(exit_status);
}
