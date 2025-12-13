/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:21 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 13:52:20 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER
#define HELPER

#include <unistd.h> // Check where I need to put this with chatgpt

size_t strlen(char *str);
int strcmp(char *s1, char *s2);
void putstr(char *str);
void print_dict_error(void);

#endif
