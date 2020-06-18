extern char *_ft_strcpy(char *d, char *s);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *s = "my name jeff";
	// char *d = "wowowoowowowowowow";
	char *d = malloc(sizeof(char) * 100);
	d = _ft_strcpy(d,s);
	printf("%s\n",d);
	return (0);
}