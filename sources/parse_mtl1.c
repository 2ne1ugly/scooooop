/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:12:00 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 11:04:19 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_newmtl(t_obj *obj, char *args, t_mtl *context)
{
	if (*context->name)
		push_back_cxxvec(obj->mtl_vec, &context);
	if (!args)
		fatal("invalid obj");
	init_default_mtl(context);
	strcpy(context->name, assert_parse(&args, " "));
}

void	parse_ns(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	mtl->exp = atoi(assert_parse(&args, " "));
}

void	parse_ka(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%f %f %f",
		&mtl->amb[0], &mtl->amb[1], &mtl->amb[2]) < 3)
		fatal("invalid obj");
}

void	parse_kd(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%f %f %f",
		&mtl->dif[0], &mtl->dif[1], &mtl->dif[2]) < 3)
		fatal("invalid obj");
}
