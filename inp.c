#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define INPUT_MAX 100

int main(int argc, char *argv[])
{
FILE *file;
char command[INPUT_MAX];
int ret;
if (argc != 2)
{
printf("usage :%s [filename]\n", argv[0]);
return (1);
}


file = fopen(argv[1], "r");
if (file == NULL)
{
printf("error opening file:%s\n", argv[1]);
return (1);
}
while (fgets(command, sizeof(command), file) !=  NULL)
{
command[strcspn(command, "\n")] = '\0';
ret = system(command);
if (ret == -1)
{
printf("Error executing command: %s\n", command);
}
}
fclose(file);
return (0);
}
