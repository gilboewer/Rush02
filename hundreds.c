/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundreds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:32:00 by jofiguer          #+#    #+#             */
/*   Updated: 2025/12/14 22:38:51 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "words_utils.h"

static void	print_under_20(int n, t_dict *dict, int dsize, int *first)
{
	char	key[3];

	if (n < 10)
	{
		key[0] = n + '0';
		key[1] = '\0';
	}
	else
	{
		key[0] = '1';
		key[1] = (n % 10) + '0';
		key[2] = '\0';
	}
	print_word(dict_lookup(dict, dsize, key), first);
}

static void	print_tens(int n, t_dict *dict, int dsize, int *first)
{
	char	key[3];

	key[0] = (n / 10) + '0';
	key[1] = '0';
	key[2] = '\0';
	print_word(dict_lookup(dict, dsize, key), first);
	if (n % 10)
	{
		key[0] = (n % 10) + '0';
		key[1] = '\0';
		print_word(dict_lookup(dict, dsize, key), first);
	}
}

void	print_hundreds(int n, t_dict *dict, int dsize, int *first)
{
	char	key[2];

	if (n >= 100)
	{
		key[0] = (n / 100) + '0';
		key[1] = '\0';
		print_word(dict_lookup(dict, dsize, key), first);
		print_word(dict_lookup(dict, dsize, "100"), first);
		n %= 100;
	}
	if (n == 0)
		return ;
	if (n < 20)
		print_under_20(n, dict, dsize, first);
	else
		print_tens(n, dict, dsize, first);
}
