/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:50 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 19:33:40 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str){
	while(*str){
		write(1, str, 1);
		str++;
	}
}

void ft_print_dict_error(){
	write(2, "Dict Error\n", 11);
}
