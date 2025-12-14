/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:03:29 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 23:05:56 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "dict.h"
# include <unistd.h>

int	ft_parse_dictionary(char *dict_str, t_dict **dicts_ptr, int *dsize);

#endif
