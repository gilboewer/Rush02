/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:40:56 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 21:10:15 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "dict.h"
#include "helper.h"
#include "parse.h"
#include "numbertowords.h"

int main(void){
	char *dict_file = "numbers.dict";
	char *dict_str;
	t_dict *dict;
	int dsize;

	ft_read_dictionary(&dict_str, dict_file);
	// ft_putstr(dict_str);
	ft_parse_dictionary(dict_str, &dict, &dsize);

	char *num = "2194570323";
	print_number_words(num, dict, dsize);
	return 0;
}
