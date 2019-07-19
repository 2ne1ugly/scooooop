/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:17:31 by mchi              #+#    #+#             */
/*   Updated: 2019/07/19 11:26:25 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

# define WIDTH 1280
# define HEIGHT 960
# define TITLE "SCOP\tSCOP\tSCOP\tSCOP"

# define PI 3.14159265359

# define NEAR 0.1
# define FAR 100

typedef GLfloat		t_vec3[3];
typedef GLfloat		t_vec4[4];
typedef GLfloat		t_mat[4][4];

typedef struct		s_cxxvec
{
	size_t	cap;
	size_t	size;
	size_t	elem_size;
	void	*data;
}					t_cxxvec;

typedef struct		s_vtx
{
	t_vec3	pos;
	t_vec3	norm;
}					t_vtx;

typedef struct		s_cam
{
	t_vec3	pos;
	t_vec3	ypr;
	float	fov;
}					t_cam;

typedef struct		s_mtl
{
	char	name[256];
	t_vec3	amb;
	t_vec3	dif;
	t_vec3	spec;
	float	exp;
	float	ir;
	float	opac;
	int		model;
}					t_mtl;

typedef struct		s_obj
{
	GLuint		vtx_buff;
	GLuint		vtx_arr;
	GLuint		idx_buff;
	t_cxxvec	*vtx_vec;
	t_cxxvec	*idx_vec;
	t_cxxvec	*mtl_vec;
	t_mtl		*curr_mtl;
}					t_obj;

typedef struct		s_loc
{
	GLint	world_view;
	GLint	proj;
	GLint	ambient;
	GLint	diffuse;
	GLint	specular;
	GLint	specular_exponent;
	GLint	refractive_index;
	GLint	opacity;
	GLint	model;
}					t_loc;

typedef struct		s_app
{
	GLFWwindow	*wnd;
	t_cam		cam;
	GLuint		prog;
	t_obj		obj;
	t_loc		*locs;
}					t_app;

void				glfw_error_callback(int error, const char *description);
void				glfw_key_callback(GLFWwindow *w, int a, int b, int c);
char				*read_file(const char *path, long *length);
int					fatal(const char *msg);
void				init_glfw(t_app *app);
void				init_resources(t_app *app, int argc, char **argv);
void				init_buffers(t_obj *obj);
void				loop(t_app *app);
void				load_program(t_app *app);
void				load_obj(t_obj *obj, const char *path);

t_cxxvec			*create_cxxvec(size_t elem_size);
void				reserve_cxxvec(t_cxxvec *vec);
void				push_back_cxxvec(t_cxxvec *vec, void *elem);
void				*index_cxxvec(t_cxxvec *vec, size_t i);

void				parse_v(t_obj *obj, char *args);
void				parse_f(t_obj *obj, char *args);
void				parse_o(t_obj *obj, char *args);
void				parse_mtllib(t_obj *obj, char *args, char *dir);
void				parse_usemtl(t_obj *obj, char *args);

void				parse_newmtl(t_obj *obj, char *args, t_mtl *mtl);
void				parse_Ns(t_mtl *mtl, char *args);
void				parse_Ka(t_mtl *mtl, char *args);
void				parse_Kd(t_mtl *mtl, char *args);
void				parse_Ks(t_mtl *mtl, char *args);
void				parse_d(t_mtl *mtl, char *args);
void				parse_Ni(t_mtl *mtl, char *args);
void				parse_illum(t_mtl *mtl, char *args);

void				load_mtl(t_obj *obj, char *path);
void				init_default_mtl(t_mtl *mtl);

void				set_mtl_uniform(t_app *app, t_obj *obj);

void				init_cam(t_cam *cam);
void				zero_vec(GLfloat *v, int size);

#endif
