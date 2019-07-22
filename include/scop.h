/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:17:31 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:22:09 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <tga_header.h>

# define TRUE 1
# define FALSE 0

# define WIDTH 1280
# define HEIGHT 960
# define TITLE "SCOP\tSCOP\tSCOP\tSCOP"

# define PI 3.14159265359f

# define NEAR 0.01f
# define FAR 10000.f

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

typedef struct		s_cam
{
	t_vec3	pos;
	t_vec3	ypr;
	float	fov;
	float	aspect;
	float	c;
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

typedef struct		s_vtx
{
	t_vec3	pos;
	t_vec3	nor;
}					t_vtx;

typedef struct		s_obj
{
	t_vec3		pos;
	t_vec3		ypr;
	GLuint		vtx_buff;
	GLuint		vtx_arr;
	t_cxxvec	*vtx_vec;
	t_cxxvec	*pos_vec;
	t_cxxvec	*mtl_vec;
	t_cxxvec	*poly_vec;
	t_mtl		*curr_mtl;
	int			smooth;
}					t_obj;

typedef struct		s_loc
{
	GLint	world;
	GLint	view;
	GLint	proj;
	GLint	ambient;
	GLint	diffuse;
	GLint	specular;
	GLint	spec_exponent;
	GLint	refract_index;
	GLint	opacity;
	GLint	model;
	GLint	tex;
	GLint	apply_tex;
}					t_loc;

typedef struct		s_app
{
	GLFWwindow	*wnd;
	t_cam		cam;
	GLuint		prog;
	t_obj		obj;
	t_loc		locs;
	t_mat		world;
	t_mat		view;
	t_mat		proj;
	GLuint		texture;
	int			rotation_mode;
	int			tex_mode;
}					t_app;

void				glfw_error_callback(int error, const char *description);
void				glfw_key_callback(GLFWwindow *w, int a, int b, int c);
char				*read_file(const char *path, long *length);
int					fatal(const char *msg);
void				init_glfw(t_app *app);
void				init_resources(t_app *app, int argc, char **argv);
void				init_buffers(t_obj *obj);
void				set_buffers(t_obj *obj);
void				loop(t_app *app);
void				load_program(t_app *app);
void				load_obj(t_obj *obj, const char *path);

void				fill_vtx_vec(t_obj *obj);

t_cxxvec			*create_cxxvec(size_t elem_size);
void				reserve_cxxvec(t_cxxvec *vec);
void				push_back_cxxvec(t_cxxvec *vec, void *elem);
void				*index_cxxvec(t_cxxvec *vec, size_t i);

char				*assert_parse(char **str, char *sep);

void				parse_v(t_obj *obj, char *args);
void				parse_f(t_obj *obj, char *args);
void				parse_o(t_obj *obj, char *args);
void				parse_mtllib(t_obj *obj, char *args, char *dir);
void				parse_usemtl(t_obj *obj, char *args);
void				parse_s(t_obj *obj, char *args);

void				parse_newmtl(t_obj *obj, char *args, t_mtl *mtl);
void				parse_ns(t_mtl *mtl, char *args);
void				parse_ka(t_mtl *mtl, char *args);
void				parse_kd(t_mtl *mtl, char *args);
void				parse_ks(t_mtl *mtl, char *args);
void				parse_d(t_mtl *mtl, char *args);
void				parse_ni(t_mtl *mtl, char *args);
void				parse_illum(t_mtl *mtl, char *args);

void				load_mtl(t_obj *obj, char *path);
void				init_default_mtl(t_mtl *mtl);

void				find_uniform_loc(t_app *app);
void				set_mtl_uniform(t_app *app, t_mtl *obj);
void				update_uniform(t_app *app);

void				init_cam(t_cam *cam);
void				normal_vec(GLfloat *lhs, int size);
void				cross_vec(GLfloat *lhs, GLfloat *rhs, t_vec3 out);
void				zero_vec(GLfloat *v, int size);
void				mul_vec(GLfloat *v, int size, GLfloat k);
GLfloat				dot_vec(GLfloat *lhs, GLfloat *rhs, int size);
void				add_vec(GLfloat *lhs, GLfloat *rhs, int size, GLfloat *out);
void				trans_vec3(t_mat mat, t_vec3 vec);
void				set_vec3(t_vec3 vec, float x, float y, float z);
void				cpy_vec(GLfloat *dst, GLfloat *src, int size);

void				get_world_from_obj(t_obj *obj, t_mat mat);
void				get_view_from_cam(t_cam *cam, t_mat mat);
void				get_proj_from_cam(t_cam *cam, t_mat mat);

void				set_default_mtl(t_obj *obj);

void				key_left(t_app *app);
void				key_right(t_app *app);
void				key_up(t_app *app);
void				key_down(t_app *app);
void				key_w(t_app *app);
void				key_a(t_app *app);
void				key_s(t_app *app);
void				key_d(t_app *app);
void				key_num_4(t_app *app);
void				key_num_6(t_app *app);
void				key_num_8(t_app *app);
void				key_num_2(t_app *app);
void				key_num_9(t_app *app);
void				key_num_1(t_app *app);
void				key_r(t_app *app);
void				key_1(t_app *app);

void				get_xyz_from_ypr(float *ypr, float *x, float *y, float *z);
void				mul_mat(t_mat lhs, t_mat rhs, t_mat mat);
void				get_rot_from_ypr(t_vec3 ypr, t_mat mat);
void				get_trans_from_pos(t_vec3 pos, t_mat mat);
void				get_norm_from_tri(t_vec3 a, t_vec3 b, t_vec3 c, t_vec3 n);
void				set_normals(t_obj *obj);

void				triple_push(t_cxxvec *vec, void *a, void *b, void *c);
void				fill_flat_vtx_vec(t_obj *obj);
void				fill_smooth_vtx_vec(t_obj *obj);

void				load_texture(t_app *app);

#endif
