/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:04:02 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/13 15:16:56 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "dict.h"
#include "helper.h"
#include "input.h"
#include "error.h"

#define DEFAULT_DICT "numbers.dict"

int read_args(int argc, char *argv[], char *nbr_str, char *dict_file){

}

void print_hnum(char *hnum, size_t size, t_dict *dict);
void print_illion(size_t i, t_dict *dict);
void printpop(char *nbr_str, t_dict *dict);

void print_number_name(char *nbr_str, t_dict *dict){
	// TODO: First check if number isn't in any other number group in the dictionary
	// Check if exact match
	size_t i = 0;
	while(i < dict->n_exacts){
		if(!strmp(nbr_str, dict->exacts[i])){
			putstr(dict->exacts[i]);
			return 0;
		}
		i++;
	}

	// If not exact, combine
	// ######################
	// Print first hundred num
	size_t size = strlen(nbr_str);
	size_t first_hsize = size % 3;
	if(first_hsize == 0)
		first_hsize = 3;
	print_hnum(nbr_str, first_hsize, &dict);
	nbr_str += first_hsize;
	size -= first_hsize;
	print_illion(size, &dict);

	// Print the rest of the number
	while(*nbr_str){
		print_hnum(nbr_str, 3, &dict);
		nbr_str += 3;
		size -= 3;
		print_illion(size, &dict);
	}
	// ######################
}

int main(int argc, char *argv[])
{
	t_dict dict;
	char *dict_file;
	char *nbr_str;
	if(argc == 1)
	{
		nbr_str = argv[1];
		dict_file = DEFAULT_DICT;
	}
	else if(argc == 2)
	{
		nbr_str = argv[2];
		dict_file = argv[1];
	}
	else print_error();
	if(!dict_file[0] || !nbr_str[0])
	{
		print_error();
		return 0;
	}
	if(read_dictionary(&dict, dict_file) == -1)
	{
		print_dict_error();
		return 0;
	}
	print_number_name(nbr_str, &dict);
}
