/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboewer <gboewer@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:12:29 by gboewer           #+#    #+#             */
/*   Updated: 2025/12/14 19:07:32 by gboewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // Check where to put this

typedef struct s_dict {
	char *key;
	char *value;
} t_dict;
