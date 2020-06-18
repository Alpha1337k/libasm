extern int	_ft_strcmp(char *s1, char *s2);

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = "Hello";
	char *s2 = "Hello";

	printf("%d %d\n",_ft_strcmp(s1,s2), strcmp(s1,s2));
}