/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/04 18:59:48 by alpha         #+#    #+#                 */
/*   Updated: 2020/10/04 18:59:49 by alpha         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

extern int	_ft_strcmp(char *s1, char *s2);

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = "Hello";
	char *s2 = "Hello";

	printf("%d %d\n",_ft_strcmp(s1,s2), strcmp(s1,s2));
}