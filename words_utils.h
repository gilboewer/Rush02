/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:32:00 by jofiguer          #+#    #+#             */
/*   Updated: 2025/12/14 22:30:22 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDS_UTILS_H
# define WORDS_UTILS_H

# include "dict.h"

char	*dict_lookup(t_dict *dict, int size, char *key);
void	print_word(char *word, int *first);
int		read_group(char **p, int len);
void	print_scale(int zeros, t_dict *dict, int dsize, int *first);

#endif
