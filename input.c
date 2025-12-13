/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:00:17 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 15:18:45 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "dict.h"
#include "helper.h"

int parse_dictionary(char *dict_str, t_dict *dict);

void *realloc(void *ptr, size_t size);

int init_dictionary(t_dict *dict, char *dict_file){
	int fd = open(dict_file, O_RDONLY);
	if(fd == -1)
		return -1;

	char *dict_str = malloc(1);
	size_t size = 0;

	const size_t BUF_SIZE = 1024;
	char buf[BUF_SIZE];
	ssize_t bytes = 1;

	while(bytes > 0){
		bytes = read(fd, buf, BUF_SIZE);
		dict_str = realloc(dict_str, size + bytes + 1);

		if(bytes == -1)
			return -1;

		size_t i = 0;
		while(i < bytes){
			dict_str[size + i] = buf[i];
			i++;
		}
		size += bytes;
	}
	dict_str[size] = '\0';
	putstr(dict_str);

	parse_dict(dict_str, dict);
}
