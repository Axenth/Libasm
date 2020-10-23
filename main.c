/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 02:22:38 by jlensing      #+#    #+#                 */
/*   Updated: 2020/10/17 11:26:44 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libasm.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	char *empty = "";
	char *vlong = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras fringilla ex quam. Etiam imperdiet faucibus ante, in vestibulum odio molestie sed. Praesent tellus ligula, pharetra in maximus vel, luctus non nisl. Proin nisi leo, porta cursus maximus eu, maximus nec urna. Sed et ultricies augue. Pellentesque id risus sit amet lectus semper convallis. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.";
	char *normal = "This is just a regular test string!";

	printf("strlen emtpy %lu Expected %lu \n", ft_strlen(empty), strlen(empty));
	printf("strlen vlong %lu Expected %lu \n", ft_strlen(vlong), strlen(vlong));
	printf("strlen normal %lu Expected %lu\n", ft_strlen(normal), strlen(normal));

	printf("strcmp empty empty %i Expected %i\n", ft_strcmp(empty, empty), strcmp(empty, empty));
	printf("strcmp normal empty %i Expected %i\n", ft_strcmp(normal, empty), strcmp(normal, empty));
	printf("strcmp empty normal %i Expected %i\n", ft_strcmp(empty, normal), strcmp(empty, normal));
	printf("strcmp normal vlong %i Expected %i\n", ft_strcmp(normal, vlong), strcmp(normal, vlong));
	
	char *duptest = ft_strdup(normal);
	if (ft_strcmp(normal, duptest) != 0)
		printf("ft_strdup failed!");
	else
		printf("OK result: %s\n", duptest);
	free(duptest);
	
	duptest = ft_strdup(empty);	
	if (ft_strcmp(empty, duptest) != 0)
		printf("ft_strdup failed!");
	else
		printf("OK result: %s\n", duptest);	
	free(duptest);

	duptest = ft_strdup(vlong);	
	if (ft_strcmp(vlong, duptest) != 0)
		printf("ft_strdup failed!");
	else
		printf("OK result: %s\n", duptest);	
	free(duptest);

	char *cpytest = malloc(sizeof(char) * ft_strlen(normal));
	char *cpyres = ft_strcpy(cpytest, normal);
	if (cpyres != cpytest)
		printf("Failed to match pointers!\n");
	else
		printf("Ok result: %s\n", cpytest);
	free(cpytest);
	
	cpytest = malloc(sizeof(char) * ft_strlen(empty));
	cpyres = ft_strcpy(cpytest, empty);
	if (cpyres != cpytest)
		printf("Failed to match pointers!\n");
	else
		printf("Ok result: %s\n", cpytest);
	free(cpytest);
	
	cpytest = malloc(sizeof(char) * ft_strlen(vlong));
	cpyres = ft_strcpy(cpytest, vlong);
	if (cpyres != cpytest)
		printf("Failed to match pointers!\n");
	else
		printf("Ok result: %s\n", cpytest);
	free(cpytest);
	
	char buf[1024];
	ft_write(1, "Please input something: ", 25);
	ft_read(0, buf, 1024);
	ft_write(1, "You wrote:", 10);
	ft_write(1, buf, ft_strlen(buf));

	errno = 0;
	ft_write(43, buf, 1024);
	printf("Errno write: %s\n", strerror(errno));
	
	errno = 0;
	ft_read(43, buf, 1024);
	printf("Errno read: %s\n", strerror(errno));
}