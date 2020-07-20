/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/07/20 02:40:16 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef int integer;

typedef struct	gaussian_restraints
{
	integer	height;
	integer	center;
	integer	width;
}				gaussian_restraints;

typedef struct	s_app_context
{
	bool		active;
	bool		app_over;

	integer		min;
	integer		max;

	int			capacity;
	int			at;

	gaussian_restraints	*curves;

	int			*gradient;
}				t_app_context;

#endif
