/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:23:58 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 23:23:18 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>
#include <unistd.h>

static size_t	ft_skip_spaces(char *s, size_t i)
{
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

static char	*ft_parse_number(char *dict_str, size_t *i)
{
	size_t	start;
	size_t	len;
	char	*num;
	size_t	j;

	start = *i;
	while (dict_str[*i] >= '0' && dict_str[*i] <= '9')
		(*i)++;
	len = *i - start;
	num = malloc(len + 1);
	j = 0;
	while (j < len)
	{
		num[j] = dict_str[start + j];
		j++;
	}
	num[len] = '\0';
	*i = ft_skip_spaces(dict_str, *i);
	return (num);
}

static char	*ft_parse_word(char *dict_str, size_t *i)
{
	size_t	start;
	size_t	len;
	char	*word;
	size_t	j;

	*i = ft_skip_spaces(dict_str, *i);
	start = *i;
	while (dict_str[*i] && dict_str[*i] != '\n')
		(*i)++;
	len = *i - start;
	word = malloc(len + 1);
	j = 0;
	while (j < len)
	{
		word[j] = dict_str[start + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

static size_t	ft_count_lines(char *dict_str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (dict_str[i])
	{
		if (dict_str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	ft_parse_dictionary(char *dict_str, t_dict **dicts_ptr, int *dsize)
{
	size_t	i;
	size_t	line;
	size_t	line_count;
	t_dict	*dicts;
	t_dict	dict;

	i = 0;
	line = 0;
	line_count = ft_count_lines(dict_str);
	dicts = malloc(line_count * sizeof(t_dict));
	while (line < line_count)
	{
		dict.key = ft_parse_number(dict_str, &i);
		i++;
		dict.value = ft_parse_word(dict_str, &i);
		i++;
		dicts[line] = dict;
		line++;
	}
	*dicts_ptr = dicts;
	*dsize = line_count;
	return (0);
}
