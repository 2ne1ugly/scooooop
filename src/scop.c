/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:37:54 by mchi              #+#    #+#             */
/*   Updated: 2019/04/11 19:11:29 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	fatal_error(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}

void GLAPIENTRY MessageCallback( GLenum source, GLenum type, GLuint id,
	GLenum severity, GLsizei length,
	const GLchar* message, const void* userParam)
{
	(void)source;
	(void)id;
	(void)length;
	(void)userParam;
	fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
		type, severity, message );
}

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
