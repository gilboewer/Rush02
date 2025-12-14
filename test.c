/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:40:56 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 19:33:58 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "dict.h"
#include "helper.h"
#include "parse.h"

int main(void){
	char *dict_file = "numbers.dict";
	char *dict_str;
	t_dict *dicts;
	ft_read_dictionary(&dict_str, dict_file);
	// ft_putstr(dict_str);
	ft_parse_dictionary(dict_str, &dicts);
	ft_putstr(dicts[1].value);
	return 0;
}
