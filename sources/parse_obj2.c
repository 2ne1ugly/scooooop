/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:06:42 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 12:10:40 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_s(t_obj *obj, char *args)
{
	char	*arg;

	if (!args)
		fatal("invalid obj");
	arg = assert_parse(&args, " ");
	if (strcmp(arg, "on") == 0)
		obj->smooth = 1;
	else
		obj->smooth = atoi(arg);
}
