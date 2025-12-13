/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:40:56 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 14:02:30 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "dict.h"

int main(void){
	t_dict dict;
	char *dict_file = "numbers.dict";
	int read_code = read_dictionary(&dict, dict_file);
}
