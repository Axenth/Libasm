/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/17 00:20:48 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/17 00:20:48 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <unistd.h>
# include <sys/types.h>

ssize_t ft_strlen(const char *str);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
int ft_strcmp(const char *str1, const char *str2);
char *ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s);

#endif