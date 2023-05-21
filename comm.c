#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define COMMENT_MAX 110

int main(void)
{
char input[COMMENT_MAX];
while (1)
{
printf("enter a command");
fgets(input, COMMENT_MAX, stdin);
if (input[0] == '#')
{
continue;
}
}
return (0);

}
