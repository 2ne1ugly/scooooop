/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:19:39 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:23:10 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_texture_buffer(t_app *app, char *data, t_tga_header *h)
{
	glGenTextures(1, &app->texture);
	glBindTexture(GL_TEXTURE_2D, app->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, h->width, h->height,
		0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE0);
	glUniform1f(app->locs.tex, 0);
}

void	load_texture(t_app *app)
{
	char			*data;
	char			*img_data;
	long			len;
	t_tga_header	*h;

	(void)app;
	data = read_file("resources/cropster.tga", &len);
	h = (t_tga_header *)data;
	if ((unsigned long)len < sizeof(t_tga_header) || h->datatypecode != 2)
		fatal("invalid texture");
	if (h->bitsperpixel != 24 || h->colormaptype != 0)
		fatal("invalid texture");
	img_data = (data + sizeof(t_tga_header) + h->idlength);
	if (len - sizeof(t_tga_header) - h->idlength < 3 * h->width * h->height)
		fatal("invalid texture");
	init_texture_buffer(app, img_data, h);
	free(data);
}
