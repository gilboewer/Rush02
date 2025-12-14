#include <unistd.h>
#include <stdlib.h>
#include "dict.h"
#include "helper.h"

/*
** LOOKUP A VALUE IN THE DICTIONARY
*/
static char *dict_lookup(t_dict *dict, int size, char *key)
{
	int	i = 0;

	while (i < size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

/*
** PRINT WORD WITH SPACE HANDLING
*/
static void print_word(char *word, int *first)
{
	if (!word)
		return ;
	if (!(*first))
		ft_putchar(' ');
	ft_putstr(word);
	*first = 0;
}

/*
** CONVERT 1–3 DIGIT NUMBER TO WORDS
*/
static void print_hundreds(int n, t_dict *dict, int dsize, int *first)
{
	char	key[4];

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
	if (n <= 20)
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
		if (n % 10)
		{
			key[0] = (n % 10) + '0';
			key[1] = '\0';
			print_word(dict_lookup(dict, dsize, key), first);
		}
	}
}

/*
** MAIN NUMBER → WORDS ENGINE
*/
void	print_number_words(char *num, t_dict *dict, int dsize)
{
	int	len = ft_strlen(num);
	int	first = 1;
	int	group_count;
	int	i = 0;

	/* special case: "0" */
	if (len == 1 && num[0] == '0')
	{
		ft_putstr(dict_lookup(dict, dsize, "0"));
		ft_putchar('\n');
		return ;
	}

	group_count = (len + 2) / 3;

	while (i < group_count)
	{
		int	group_len;
		int	j;
		int	value = 0;
		char	scale_key[32];

		group_len = (i == 0 && len % 3) ? len % 3 : 3;
		if (group_len == 0)
			group_len = 3;

		j = 0;
		while (j < group_len)
		{
			value = value * 10 + (*num - '0');
			num++;
			j++;
		}

		if (value != 0)
		{
			print_hundreds(value, dict, dsize, &first);
			if (group_count - i - 1 > 0)
			{
				int zeros = (group_count - i - 1) * 3;
				scale_key[0] = '1';
				j = 1;
				while (j <= zeros)
				{
					scale_key[j] = '0';
					j++;
				}
				scale_key[j] = '\0';
				print_word(dict_lookup(dict, dsize, scale_key), &first);
			}
		}
		i++;
	}
	ft_putchar('\n');
}
