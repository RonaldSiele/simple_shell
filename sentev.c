#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define SENT_MAX 150
/**
 * SENT1 - Sets or unsets enviromnent variables  based on the provided command_line.
 * @argc: the number of command-line arguments.
 * @argv: An array of strings represnting the arguments.
 *
 * Return: Always returns 0.
 */
int SENT1(int argc, char *argv[])
{
if (argc < 2)
{
fprintf(stderr, "usage:%s command \n", argv[0]);
exit(1);
}
if (strcmp(argv[1], "sentev") == 0)
{
if (argc != 4)
{
fprintf(stderr, "usage:sentev VARIABLE VALUE \n");
exit(1);
}
if (setenv(argv[2], argv[3], 1) == -1)
{
fprintf(stderr, "failed to set enviromnet varaible");
}
}
else if (strcmp(argv[1], "unsentev") == 0)
{
if (argc != 3)
{
fprintf(stderr, "usage:unsentev VARIABLE\n");
exit(1);
}
if (unsetenv(argv[2]) == -1)
{
fprintf(stderr, "failed to unset environment variable\n");
}
}
else
{
fprintf(stderr, "unknown command:%s\n", argv[1]);
exit(1);
}
return (0);
}
