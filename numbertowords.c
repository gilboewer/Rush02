#include <stdlib.h>
#include "helper.h"
#include "dict.h"

static char	*dict_lookup(t_dict *dict, int dsize, char *key)
{
	int	i;
	i = 0;
	while (i < dsize)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

static void	print_word(char *word, int *first)
{
	if (word == NULL)
		return ;
	if (*first == 0)
		ft_putchar(' ');
	ft_putstr(word);
	*first = 0;
}

static void	print_scale(int zeros, t_dict *dict, int dsize, int *first)
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

static void	print_hundreds(int n, t_dict *dict, int dsize, int *first)
{
	char	key[3];
	if (n >= 100)
	{
		key[0] = (n / 100) + '0';
		key[1] = '\0';
		print_word(dict_lookup(dict, dsize, key), first);
		print_word(dict_lookup(dict, dsize, "100"), first);
		n = n % 100;
	}
	if (n == 0)
		return ;
	if (n < 20)
	{
		if (n >= 10)
		{
			key[0] = '1';
			key[1] = (n % 10) + '0';
			key[2] = '\0';
		}
		else
		{
			key[0] = n + '0';
			key[1] = '\0';
		}
		print_word(dict_lookup(dict, dsize, key), first);
	}
	else
	{
		key[0] = (n / 10) + '0';
		key[1] = '0';
		key[2] = '\0';
		print_word(dict_lookup(dict, dsize, key), first);
		if ((n % 10) != 0)
		{
			key[0] = (n % 10) + '0';
			key[1] = '\0';
			print_word(dict_lookup(dict, dsize, key), first);
		}
	}
}

void	print_number_words(char *num, t_dict *dict, int dsize)
{
	int	len;
	int	group_count;
	int	first;
	int	i;
	int	pos;
	while (*num == '0' && *(num + 1) != '\0')
		num++;
	len = ft_strlen(num);
	first = 1;
	pos = 0;
	if (len == 1 && num[0] == '0')
	{
		ft_putstr(dict_lookup(dict, dsize, "0"));
		ft_putchar('\n');
		return ;
	}
	group_count = (len + 2) / 3;
	i = 0;
	while (i < group_count)
	{
		int	group_len;
		int	j;
		int	value;
		int	remaining_groups;
		group_len = 3;
		if (i == 0 && (len % 3) != 0)
			group_len = len % 3;
		value = 0;
		j = 0;
		while (j < group_len)
		{
			value = (value * 10) + (num[pos] - '0');
			pos++;
			j++;
		}
		if (value != 0)
		{
			print_hundreds(value, dict, dsize, &first);
			remaining_groups = group_count - i - 1;
			if (remaining_groups > 0)
				print_scale(remaining_groups * 3, dict, dsize, &first);
		}
		i++;
	}
	ft_putchar('\n');
}
