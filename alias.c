#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "alias.h"

#define ALIAS_MAX 100
typedef struct
{
char name[ALIAS_MAX];
char value[ALIAS_MAX];
}Alias;
Alias aliases[ALIAS_MAX];
int aliasCount=0;
void printAliases()
{
int i;
for ( i = 0; i < aliasCount;i++)
{
printf("%s='%s'\n",aliases[i].name,aliases[i].value);
}
}
int main(int argc, char *argv[])
{
if (argc == 1)
{
printAliases();
}
else if(argc > 1 && strchr(argv[1], '=') == NULL)
{
int i;
for (i = 1; i < argc; i++)
{
printAliases(argv[i]);
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
for (j = 0; j < aliasCount;j++)
{
if (strcmp(aliases[j].name,name) ==0)
{
strcpy(aliases[j].value, value);
existingAlias = 1;
break;
}
}
if(!existingAlias)
{
strcpy(aliases[aliasCount].name, name);
strcpy(aliases[aliasCount].value, name);
aliasCount++;
}
}
}
return (0);
}
