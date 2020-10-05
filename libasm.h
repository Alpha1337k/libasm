/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpha <alpha@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/04 17:52:12 by alpha         #+#    #+#                 */
/*   Updated: 2020/10/05 14:14:51 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

int		ft_strlen(char *s);
int 		ft_strcmp(char *s1, char *s2);
char 	*ft_strcpy(char *dest, const char *src);
int     ft_write(int fd, char *buf, int len);
int     ft_read(int fd, char *buf, int len);
char    *ft_strdup(char *s);

#endif