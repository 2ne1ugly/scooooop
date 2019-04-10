/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:37:54 by mchi              #+#    #+#             */
/*   Updated: 2019/04/09 17:42:23 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	main(int argc, char **argv)
{
	t_app	*app;

	if (argc != 2)
		return (0);
//		return (print_usage());
	app = init_app();
	init_wnd(app, 800, 800, "scoooop");
	init_glew();
	init_object(app, argv[1]);
	app->vs = load_shader("./resources/vs.glsl", GL_VERTEX_SHADER);
	app->ps = load_shader("./resources/ps.glsl", GL_FRAGMENT_SHADER);
	app->shader_prog = link_vs_ps(app->vs, app->ps);
	mlx_loop(app->h_mlx);
	return (0);
}
