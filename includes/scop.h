/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:35:06 by mchi              #+#    #+#             */
/*   Updated: 2019/04/10 13:39:05 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <mlx.h>
#include <mlx_opengl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <libft.h>

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

typedef struct	s_line
{
	int vertex_count;
	GLuint	*vertex;
}				t_line;

typedef struct	s_poly
{
	int vertex_count;
	GLuint	*vertex;
	GLuint	*tex_coord;
	GLuint	*normal;
}				t_poly;

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

typedef struct	s_obj_file
{
	char	*data;
	t_vec4	*vertices;
	int		vertex_count;
	t_vec4	*tex_coords;
	int		tex_coord_count;
	t_vec4	*normals;
	int		normal_count;
	t_vec4	*par_vertices;
	int		par_vertex_count;
	t_poly	*polies;
	int		poly_count;

}				t_obj_file;

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
void		init_object(t_app *app, char *object);
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

char		*read_file(char *path);
void		fatal_error(char *msg);
void		parse_obj(t_obj_file *obj_file);

void	parse_vertex_line(t_vec4 *vec, char **tokens);
void	parse_tex_line(t_vec4 *tex, char **tokens);
void	parse_normal_line(t_vec4 *norm, char **tokens);
void	parse_par_vert_line(t_vec4 **norm, char **tokens);
void	parse_face_line(t_poly *poly, char **tokens);
