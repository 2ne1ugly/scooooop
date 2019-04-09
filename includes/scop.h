/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:35:06 by mchi              #+#    #+#             */
/*   Updated: 2019/04/09 05:34:34 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <mlx.h>
#include <mlx_opengl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

typedef struct	s_vec4
{
	GLfloat	x;
	GLfloat	y;
	GLfloat	z;
	GLfloat	w;
}				t_vec4;

typedef	struct	s_mat
{
	GLfloat	v[16];
}				t_mat;

typedef struct	s_cam
{
	t_vec4	pos;
	t_vec4	ypr;
	float	c;
	float	aspect;
	float	far;
	float	near;
}				t_cam;

typedef struct	s_obj
{
	t_vec4	pos;
	t_vec4	ypr;
	t_vec4	*vertices;
	int		vertex_count;
	GLuint	*indices;
	int		index_count;
	t_mat	world_view_proj;
}				t_obj;

typedef struct	s_app
{
	void	*h_mlx;
	void	*h_wnd;
	int		width;
	int		height;
	GLuint	ind_buff;
	GLuint	vbo;
	GLuint	vao;
	GLuint 	vs;
	GLuint	ps;
	GLuint	shader_prog;
	t_cam	cam;
	t_obj	obj;
	int		update;
}				t_app;

t_app		*init_app(void);
void		init_wnd(t_app *app, int width, int height, char *title);
void		init_glew(void);
void		init_object(t_app *app);
int			app_loop(void *param);

int			key_press(int keycode, void *param);

t_mat		mat_identity(void);

t_vec4		vec4_norm(t_vec4 vec);
t_vec4		vec4_add(t_vec4 lhs, t_vec4 rhs);
t_vec4		vec4_sub(t_vec4 lhs, t_vec4 rhs);
t_vec4		vec4_cross(t_vec4 lhs, t_vec4 rhs);
float		vec4_dot(t_vec4 lhs, t_vec4 rhs);
t_vec4		vec4_trans(t_mat *mat, t_vec4 lhs);
float		vec4_abs(t_vec4 vec);
t_vec4		vec4_mul(t_vec4 lhs, float rhs);

t_mat		mat_world(t_obj *obj);
t_mat		mat_proj(t_cam *cam);
t_mat		mat_look_at(t_vec4 eye, float pitch, float yaw);

t_mat		mat_ypr(t_vec4 *ypr);

GLuint		load_shader(char *path, int type);
GLuint		link_vs_ps(GLuint vs, GLuint ps);
t_mat		mat_mul(t_mat *lhs, t_mat *rhs);
