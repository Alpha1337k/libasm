/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/04 17:43:11 by alpha         #+#    #+#                 */
/*   Updated: 2020/10/05 14:49:30 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "libasm.h"

#define strlen_test(a) ft_strlen(a) - protect_strlen(a)
#define cpy_test(a, b) strcpy(a,b) && protect_strlen(a) - protect_strlen(b)

int protect_strlen(char *a)
{
	if (a != 0)
		return (strlen(a));
	return (0);
}

int cmp_test(char *a, char *b)
{
	return (ft_strcmp(a,b) - strcmp(a,b));
}

// int strlen_test(char *a)
// {
// 	return ((_ft_strlen(a) - protect_strlen(a)));
// }

void write_error_msg(char *a)
{
	printf("\033[0;31mERROR!\033[0m input: '%s' ", a);
	printf("\n");
}

void success(int d)
{
	printf("test %d succesfull\n", d);
}

void	lentest()
{
	strlen_test("Hello!")!= 1 	?							success(0) : write_error_msg("Hello!");
	strlen_test("\0") != 1 ? 								success(1) : write_error_msg("Null term sign");
	strlen_test("llllllllllllllllllllllllllllllllll") != 1 ? success(2) : write_error_msg("llllllllllllllllllllllllllllllllll");
	strlen_test(NULL) != 1 ? 								success(3) : write_error_msg(NULL);
	strlen_test("") != 1 ? 									success(4) : write_error_msg("");
}

void cmptest()
{
	cmp_test("Hallo?", "Hallo?")	== 0 ? success(0) : write_error_msg("equal");
	cmp_test(NULL, "Hallo?")		== 0 ? success(1) : write_error_msg("null lhs");
	cmp_test("Hallo?", NULL)		== 0 ? success(2) : write_error_msg("null rhs");
	cmp_test(NULL, NULL)			== 0 ? success(3) : write_error_msg("null");
	cmp_test("Hallo", "Hallo?")		== 0 ? success(4) : write_error_msg("unequal lhs");
	cmp_test("Hallo?", "Hallo")		== 0 ? success(5) : write_error_msg("unequal rhs");
}

void cpytest()
{
   char str1[20] = "C programming";
   char str2[20];

   	// copying str1 to str2
   	ft_strcpy(str2, str1);
	printf("%s$\n",str2);
	printf("%d\n",strcmp("hello", "hello"));
	printf("%d\n",ft_strcmp("hello", "hello"));
	// cpy_test("hello", "hallo")					== 0 ? success(0) : write_error_msg("hallo wereld!");
}

void writetest()
{
	int fd = open("test.txt", O_CREAT | O_TRUNC | O_RDWR,0644);
	ft_write(fd, "hallo wereld\n", 10);
	char *ret = malloc(100);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ft_read(fd, ret, 10);
	printf("read:%s$\n", ret);
}

int main(void)
{
	printf("Starting Test..\n");
	 lentest();
	// cmptest();
	char *s1 = "Hello";
	char *s2 = "Hello";

	//printf("%d %d\n" ,ft_strcmp(s1,s2), strcmp(s1,s2));
	cpytest();
	// duptest();
	writetest();
	char *a = ft_strdup(NULL);
	printf("%s\n", a);
	// readtest();
	return (1);
}