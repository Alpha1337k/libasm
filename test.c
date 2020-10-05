/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/04 17:43:11 by alpha         #+#    #+#                 */
/*   Updated: 2020/10/04 18:58:47 by alpha         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"

#define strlen_test(a) _ft_strlen(a) - protect_strlen(a)
#define cmp_test(a, b) _ft_strcmp(a,b) - _ft_strcmp(a,b)

int protect_strlen(char *a)
{
	if (a != 0)
		return (strlen(a));
	return (0);
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

int	lentest()
{
	strlen_test("Hello!")!= 1 ? success(0) : write_error_msg("Hello!");
	strlen_test("\0") != 1 ? success(1) : write_error_msg("Null term sign");
	strlen_test("llllllllllllllllllllllllllllllllll") != 1 ? success(2) : write_error_msg("llllllllllllllllllllllllllllllllll");
	strlen_test(NULL) != 1 ? success(3) : write_error_msg(NULL);
	strlen_test("") != 1 ? success(4) : write_error_msg("");
}

int cmptest()
{
	cmp_test("Hallo?", "Hallo?")	== 0 ? success(0) : write_error_msg("equal");
	cmp_test(NULL, "Hallo?")		== 0 ? success(1) : write_error_msg("null lhs");
	cmp_test("Hallo?", NULL)		== 0 ? success(2) : write_error_msg("null rhs");
	cmp_test(NULL, NULL)			== 0 ? success(3) : write_error_msg("null");
	cmp_test("Hallo", "Hallo?")		== 0 ? success(4) : write_error_msg("unequal lhs");
	cmp_test("Hallo?", "Hallo")		== 0 ? success(5) : write_error_msg("unequal rhs");
}

int main(void)
{
	printf("Starting Test..\n");
	// lentest();
	// cmptest();
	char *s1 = "Hello";
	char *s2 = "Hello";

	printf("%d %d\n",_ft_strcmp(s1,s2), strcmp(s1,s2));
	// cpytest();
	// duptest();
	// writetest();
	// readtest();
	return (1);
}