/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:47:06 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 14:47:58 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGA_HEADER_H
# define TGA_HEADER_H

# include <stdlib.h>

struct __attribute__((__packed__))	s_tga_header
{
	uint8_t		idlength;
	uint8_t		colormaptype;
	uint8_t		datatypecode;
	uint16_t	colormaporigin;
	uint16_t	colormaplength;
	uint8_t		colormapdepth;
	uint16_t	x_origin;
	uint16_t	y_origin;
	uint16_t	width;
	uint16_t	height;
	uint8_t		bitsperpixel;
	uint8_t		imagedescriptor;
};

typedef struct s_tga_header			t_tga_header;

#endif
