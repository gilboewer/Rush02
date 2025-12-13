/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:29 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 15:57:10 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // Check where to put this

#ifndef DICT
#define DICT

typedef struct s_dict {
	char *b20[20];
	char *teners[10];
	char *hundred;
	char **illions; // Unknown size
	char **exacts; // Unknown size
	size_t n_illions;
	size_t n_exacts;
} t_dict;

#endif
