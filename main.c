#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - PID
 * Return: 0
 */
int main(void)
{
	size_t nac, buffsize = 20;
	char *str;

	str = malloc(sizeof(char) * buffsize);

	printf("$ ");
	nac = getline(&str, &buffsize, stdin);
	printf("%ld characters were read.\n", nac);
	printf("You entered %s\n", str);
	return(0);
}
