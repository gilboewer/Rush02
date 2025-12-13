/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:54:48 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 13:55:45 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_dict_error(void){
	write(2, "Dict Error\n", 11);
}

void print_error(void){
	write(2, "Error\n", 6);
}
