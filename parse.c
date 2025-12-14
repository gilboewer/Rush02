/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofiguer <jofiguer@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:23:58 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 19:58:17 by jofiguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "dict.h"

static size_t ft_skip_spaces(char *s, size_t i)
{
    while (s[i] == ' ' || s[i] == '\t')
        i++;
    return i;
}

static char *ft_parse_number(char *dict_str, size_t *i)
{
    size_t start;
    size_t len;
    char *num;

    start = *i;
    while (dict_str[*i] >= '0' && dict_str[*i] <= '9')
        (*i)++;
    len = *i - start;

    num = malloc(len + 1);

    size_t j = 0;
    while(j < len){
        num[j] = dict_str[start + j];
		j++;
	}
    num[len] = '\0';
    return num;
}

static char *ft_parse_word(char *dict_str, size_t *i)
{
    size_t start;
    size_t len;
    char *word;

    start = *i;
    while (dict_str[*i] && dict_str[*i] != '\n')
        (*i)++;
    len = *i - start;

    word = malloc(len + 1);

	size_t j = 0;
    while(j < len){
        word[j] = dict_str[start + j];
		j++;
	}
    word[len] = '\0';
    return word;
}

static size_t ft_count_lines(char *dict_str){
	size_t count = 0;
	size_t i = 0;
	while(dict_str[i]){
		if(dict_str[i] == '\n')
			count++;
		i++;
	}
	return count;
}

int ft_parse_dictionary(char *dict_str, t_dict **dicts_ptr, int *dsize)
{
    size_t i = 0;
	size_t line = 0;
	size_t line_count = ft_count_lines(dict_str);
    char *number;
    char *word;

	t_dict *dicts = malloc(line_count * sizeof(t_dict));

    while (line < line_count)
    {
		t_dict dict;
        dict.key = ft_parse_number(dict_str, &i);
		i = ft_skip_spaces(dict_str, i);
        i++;
		i = ft_skip_spaces(dict_str, i);
        dict.value = ft_parse_word(dict_str, &i);
		i++;
		dicts[line] = dict;
		line++;
    }
	*dicts_ptr = dicts;
    *dsize = line_count;
	return 0;
}
