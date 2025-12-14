/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofiguer <jofiguer@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:03:29 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 20:00:35 by jofiguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"

int ft_parse_dictionary(char *dict_str, t_dict **dicts_ptr, int *dsize);
