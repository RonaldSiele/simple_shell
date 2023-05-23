#ifndef ALIAS_H
#define ALIAS_H

#define ALIAS_MAX 100

typedef struct
{
char name[ALIAS_MAX];
char value[ALIAS_MAX];
} Alias;

void printAliases(Alias *aliases, int aliasCount);
#endif
