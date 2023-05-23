#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "alias.h"

#define MAX_ALIASES 100

/**
 * Prints the aliases stored in an array.
 * @param aliases The array of aliases
 * @param aliasCount The number of aliases in the array
 */
void printAliases(Alias *aliases, int aliasCount)
{
	int i;
	for (i = 0; i < aliasCount; i++)
	{
	printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * The main function.
 * @param argc The number of command-line arguments
 * @param argv An array of strings representing the arguments
 * @return The exit status of the program
 */
int main(int argc, char *argv[])
{
	Alias aliases[MAX_ALIASES];
	int aliasCount = 0;

	if (argc == 1)
	{
	printAliases(aliases, aliasCount);
	}
	else if (argc > 1 && strchr(argv[1], '=') == NULL)
	{
	int i;
	for (i = 1; i < argc; i++)
	{
	printAliases(aliases, aliasCount);
	}
	}
	else
	{
	int i;
	for (i = 1; i < argc; i++)
	{
	char *name = strtok(argv[i], "=");
	char *value = strtok(NULL, "=");
	int existingAlias = 0;
	int j;
	for (j = 0; j < aliasCount; j++)
	{
	if (strcmp(aliases[j].name, name) == 0)
	{
	strcpy(aliases[j].value, value);
	existingAlias = 1;
	break;
	}
	}
	if (!existingAlias)
	{
	strcpy(aliases[aliasCount].name, name);
	strcpy(aliases[aliasCount].value, name);
	aliasCount++;
	}
	}
	}

	return (0);
}

