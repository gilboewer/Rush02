/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:04:02 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 21:24:44 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "dict.h"
#include "helper.h"
#include "read.h"
#include "error.h"

#define DEFAULT_DICT "numbers.dict"

int main(int argc, char *argv[])
{
	t_dict dict;
	char *dict_file;
	char *nbr_str;

	if(argc == 1) {
		nbr_str = argv[1];
		dict_file = DEFAULT_DICT;
	}
	else if(argc == 2){
		nbr_str = argv[2];
		dict_file = argv[1];
	} else write(2, "Error\n", 6);

	if(read_dictionary(&dict, dict_file) == -1)
	{
		write(2, "Dict Error\n", 11);
		return 0;
	}

	print_number_name(nbr_str, &dict);
}
