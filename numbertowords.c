/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbertowords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:32:00 by jofiguer          #+#    #+#             */
/*   Updated: 2025/12/14 23:16:02 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include "hundreds.h"
#include "words_utils.h"

static int	group_len(int len, int i)
{
	int	r;

	r = len % 3;
	if (i == 0 && r != 0)
		return (r);
	return (3);
}

static void	print_chunk(int v, int rem, t_dict *d, int s, int *f)
{
	if (v == 0)
		return ;
	print_hundreds(v, d, s, f);
	if (rem > 0)
		print_scale(rem * 3, d, s, f);
}

void	print_number_words(char *num, t_dict *dict, int dsize)
{
	int	len;
	int	groups;
	int	first;
	int	glen;
	int	val;
	int	i;

	while (*num == '0' && num[1])
		num++;
	len = ft_strlen(num);
	first = 1;
	if (len == 1 && num[0] == '0')
	{
		print_word(dict_lookup(dict, dsize, "0"), &first);
		ft_putchar('\n');
		return ;
	}
	groups = (len + 2) / 3;
	i = 0;
	while (i < groups)
	{
		glen = group_len(len, i);
		val = read_group(&num, glen);
		print_chunk(val, groups - i - 1, dict, dsize, &first);
		i++;
	}
	ft_putchar('\n');
}
