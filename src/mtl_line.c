/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:19 by mchi              #+#    #+#             */
/*   Updated: 2019/04/10 19:59:19 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_3val_line(t_vec4 *val, char **tokens)
{
	int length;

	length = array_len(tokens);
	if (length != 3)
		fatal_error("value do not contain 3 values");
	val->x = atof(tokens[0]);
	val->y = atof(tokens[1]);
	val->z = atof(tokens[2]);	
}
