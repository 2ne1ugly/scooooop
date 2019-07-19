/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:12:00 by mchi              #+#    #+#             */
/*   Updated: 2019/07/19 11:26:38 by mchi             ###   ########.fr       */
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
	if (sscanf(args, "%s", context->name) < 1)
		fatal("invalid obj");
}

void	parse_Ns(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%f", &mtl->exp) < 1)
		fatal("invalid obj");
}

void	parse_Ka(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%f %f %f", 
		&mtl->amb[0], &mtl->amb[1], &mtl->amb[2]) < 3)
		fatal("invalid obj");
}

void	parse_Kd(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%f %f %f", 
		&mtl->dif[0], &mtl->dif[1], &mtl->dif[2]) < 3)
		fatal("invalid obj");
}
