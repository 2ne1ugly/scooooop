/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:42:41 by mchi              #+#    #+#             */
/*   Updated: 2019/04/08 16:25:01 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_app	*init_app(void)
{
	t_app *app;

	app = malloc(sizeof(t_app));
	app->h_mlx = mlx_init();
	app->update = 1;
	mlx_loop_hook(app->h_mlx, app_loop, app);
	return (app);
}

void	init_cam(t_cam *cam, t_app *app)
{
	cam->pos = (t_vec4){0.0f, 0.0f, -5.0f, 0.0f};
	cam->ypr = (t_vec4){0.0f, 0.0f, 0.0f, 0.0f};
	cam->c = 1 / tan(PI / 4.0f);
	cam->aspect = app->width / app->height;
	cam->far = 10000;
	cam->near = 0.01;
}

void	init_wnd(t_app *app, int width, int height, char *title)
{
	app->h_wnd = mlx_new_opengl_window(app->h_mlx, width, height, title);
	app->width = width;
	app->height = height;
	init_cam(&app->cam, app);
	mlx_hook(app->h_wnd, 2, 0, key_press, app);
}

void	init_glew(void)
{
	GLenum	error;

	error = glewInit();
	if (error != GLEW_OK)
	{
		printf("glew failed!\n");
		exit(1);
	}
}
