/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:00:17 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 19:27:54 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "helper.h"

#define BUF_SIZE 1024

static void ft_cpybuf(char *dest, char *src, size_t n){
	size_t i = 0;
	while(i < n){
		dest[i] = src[i];
		i++;
	}
}

static void *ft_concatenate(char *str, char *added_str, size_t size, size_t added_size){
	char *newstr = malloc(size + added_size + 1);
	ft_cpybuf(newstr, str, size);
	ft_cpybuf(newstr + size, added_str, added_size);
	newstr[size + added_size] = '\0';
	free(str);
	return newstr;
}

int ft_read_dictionary(char **dict_str_ptr, char *dict_file){
	int fd = open(dict_file, O_RDONLY);
	if(fd == -1)
		return -1;

	char *dict_str = malloc(1);
	size_t size = 0;

	char buf[BUF_SIZE];
	ssize_t bytes = 1;

	while(bytes > 0){
		bytes = read(fd, buf, BUF_SIZE);
		if(bytes == -1)
			return -1;

		dict_str = ft_concatenate(dict_str, buf, size, bytes);
		size += bytes;
	}

	*dict_str_ptr = dict_str;

	close(fd);

	return 0;
}
