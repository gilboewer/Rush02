/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:32:00 by jofiguer          #+#    #+#             */
/*   Updated: 2025/12/14 22:29:05 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "helper.h"
#include "dict.h"

char	*dict_lookup(t_dict *dict, int size, char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

void	print_word(char *word, int *first)
{
	if (word == NULL)
		return ;
	if (*first == 0)
		ft_putchar(' ');
	ft_putstr(word);
	*first = 0;
}

int	read_group(char **p, int len)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (i < len)
	{
		value = (value * 10) + (**p - '0');
		(*p)++;
		i++;
	}
	return (value);
}

void	print_scale(int zeros, t_dict *dict, int dsize, int *first)
{
	char	*key;
	int		i;

	key = (char *)malloc(zeros + 2);
	if (key == NULL)
		return ;
	key[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	print_word(dict_lookup(dict, dsize, key), first);
	free(key);
}
