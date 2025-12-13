/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:50 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 13:33:12 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// To implement
// size_t strlen(char *str);
// int strcmp(char *s1, char *s2);
// void putstr(char *str);

void print_dict_error(){
	write(2, "Dict Error\n", 11);
}
