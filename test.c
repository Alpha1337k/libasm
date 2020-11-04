/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/04 17:43:11 by alpha         #+#    #+#                 */
/*   Updated: 2020/10/06 14:05:09 by okruitho      ########   odam.nl         */
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

void write_error_msg(char *a)
{
	printf("\033[0;31mERROR!\033[0m input: '%s' ", a);
	printf("\n");
}

void success(int d)
{
	printf("test %d succesfull\n", d);
}

int protect_strlen(char *a)
{
	if (a != 0)
		return (strlen(a));
	return (0);
}

int cmp_test(char *a, char *b)
{
	int strcmp_v = strcmp(a, b);
	if (strcmp_v > 0)
		strcmp_v = 1;
	else if (strcmp_v < 0)
		strcmp_v = -1;
	if (ft_strcmp(a,b) == strcmp_v)
		return (0);
	return (1);
}

int cpy_test(char *o, char *a, char *b)
{
	a = ft_strcpy(a, o);
	b = strcpy(b, o);
	return (strcmp(a, b));
}

int dup_test(char *s)
{
	char *s1 = ft_strdup(s);
	char *s2 = strdup(s);
	int rval = strcmp(s1, s2);
	free(s1);
	free(s2);
	return (rval);
}

int readcmp(int fd, int fd2, int len)
{
	char l1[1000];
	char l2[1000];
	int rv1;
	int rv2;
	int errn;
	
	rv1 = ft_read(fd, l1, len);
	errn = errno;
	rv2 = read(fd, l2, len);
	if (errn != errno)
		perror("errno's not the same!");
	errno = 0;
	if (rv1 != rv2)
		return (-1);
	if (strcmp(l1, l2) == 0)
		return (0);
	return (0);
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
	cmp_test("Hallo?", "Hallo?")		== 0 ? success(0) : write_error_msg("equal");
	cmp_test("hullo?", "Hallo?")		== 0 ? success(1) : write_error_msg("null lhs");
	cmp_test("Hallo?", "Hall")			== 0 ? success(2) : write_error_msg("null rhs");
	cmp_test("aaaaaaaaaaaaaa", "")		== 0 ? success(3) : write_error_msg("null");
	cmp_test("", "")					== 0 ? success(4) : write_error_msg("unequal lhs");
	cmp_test("H", "")					== 0 ? success(5) : write_error_msg("unequal rhs");
}

void cpytest()
{
	char *a = malloc(100);
	char *b = malloc(100);

	cpy_test("hallo?", a, b)				== 0 ? success(0) : write_error_msg("basic test fail");
	cpy_test("", a, b)						== 0 ? success(1) : write_error_msg("empty string fail");
	cpy_test("jajajjajajajajja", a, b)		== 0 ? success(2) : write_error_msg("basic test fail");
	cpy_test("hallo?", a, b)				== 0 ? success(3) : write_error_msg("basic test fail");
	cpy_test("hal\0lo?", a, b)				== 0 ? success(4) : write_error_msg("basic test fail");

	free(a);
	free(b);
}

void duptest()
{
	dup_test("")								== 0 ? success(0) : write_error_msg("empty_string");
	dup_test("hallo?")							== 0 ? success(1) : write_error_msg("basic string");
	dup_test("hal\0lo")							== 0 ? success(2) : write_error_msg("null in string");
	dup_test("sicc men")						== 0 ? success(3) : write_error_msg("sicc string");
	dup_test("\0 huh")							== 0 ? success(4) : write_error_msg("starting null");
	dup_test("\n\n\n\n\n")						== 0 ? success(5) : write_error_msg("newlines idk");
}

void writetest()
{
	int fd = open("test.txt", O_CREAT | O_TRUNC | O_RDWR,0644);	
	ft_write(fd, "hallo wereld\n", 14) 			!= -1 ? success(0) : perror("valid fd");
	if (errno)
		perror("ERRNO:");
	errno = 0;
	ft_write(fd, "hallo wereld\n", 1) 			!= -1 ? success(1) : perror("valid fd with cutoff");
	if (errno)
		perror("ERRNO:");
	errno = 0;
	ft_write(1, "hallo wereld\n", 14) 			!= -1 ? success(2) : perror("valid fd");
	if (errno)
		perror("ERRNO:");
	errno = 0;
	ft_write(fd, "hallo wereld\n", 10000)		!= -1 ? success(3) : perror("valid fd");
	if (errno)
		perror("ERRNO:");
	errno = 0;
	ft_write(10, "hallo wereld\n", 10000)		== -1 ? success(4) : write_error_msg("invalid fd");
	if (errno != 9)
		perror("ERRNO:");
	errno = 0;
	ft_write(-1, "hallo wereld\n", 10) 			== -1 ? success(5) : write_error_msg("invalid fd");
	if (errno != 9)
		perror("ERRNO:");
	errno = 0;
	close (fd);
	fd = open("test.txt", O_RDONLY);
	ft_write(fd, "hallo wereld\n", 10) 			== -1 ? success(6) : write_error_msg("readonly fd");
	if (errno != 9)
		perror("ERRNO:");
	errno = 0;	
}

void readtest()
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test.txt", O_RDONLY);

	readcmp(fd, fd2, 10) == 0 ?		success(0) : write_error_msg("basic read");
	readcmp(fd, fd2, -1) == 0 ?		success(0) : write_error_msg("invalid byte");
	readcmp(-1, -1, 10) == 0 ?		success(0) : write_error_msg("invalid fd");
	readcmp(fd, fd2, 1000) == 0 ?	success(0) : write_error_msg("big read");
	close(fd);
	close(fd2);
}

int main(void)
{
	printf("Starting Test.. \t[STRLEN]\n");
	lentest();
	printf("Starting Test.. \t[STRCMP]\n");
	cmptest();
	printf("Starting Test.. \t[STRCPY]\n");
	cpytest();
	printf("Starting Test.. \t[STRDUP]\n");
	duptest();
	printf("Starting Test.. \t[WRITE]\n");
	writetest();
	printf("Starting Test.. \t[READ]\n");
	readtest();
	printf("done! GJ\n");
	system("leaks libasm-test");
	return (0);
}