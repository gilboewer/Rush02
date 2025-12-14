/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:40:56 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 22:56:20 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "helper.h"
#include "numbertowords.h"
#include "parse.h"
#include "read.h"
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_DICT "numbers.dict"

int	prepare_dict(char *dict_file, t_dict **dict_ptr, int *dsize_ptr)
{
	char	*dict_str;
	int		read_dict_code;
	int		parse_dict_code;

	read_dict_code = ft_read_dictionary(dict_file, &dict_str);
	parse_dict_code = ft_parse_dictionary(dict_str, dict_ptr, dsize_ptr);
	free(dict_str);
	return (read_dict_code + parse_dict_code);
}

int	main(int argc, char *argv[])
{
	char	*num;
	char	*dict_file;
	t_dict	*dict;
	int		dsize;

	num = "2194570323";
	dict_file = DEFAULT_DICT;
	// if(argc == 1)
	// {
	// 	num = argv[1];
	// 	dict_file = DEFAULT_DICT;
	// }
	// else if(argc == 2)
	// {
	// 	num = argv[2];
	// 	dict_file = argv[1];
	// } else write(2, "Error\n", 6);
	if (prepare_dict(dict_file, &dict, &dsize) < 0)
	{
		write(2, "Dict Error\n", 11);
	}
	print_number_words(num, dict, dsize);
	free(dict);
}
