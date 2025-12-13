/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:14:36 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 14:57:05 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT
#define INPUT

#include <unistd.h> // Check where I need to put this with chatgpt
#include "dict.h"

int read_dictionary(t_dict *dict, char *dict_file);

#endif
