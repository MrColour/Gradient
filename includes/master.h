/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2020/07/21 17:12:27 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <stdio.h>

# include <SDL_image.h>

# include "structs.h"
# include "window_config.h"

# define BAR_WIDTH (500)
# define BAR_HEIGHT (5)

# define BAR_LOC_SX (100)
# define BAR_LOC_SY (100)

void		SDLU_start(t_display *dest);
void		SDLU_close(t_display *display);

void		process_user_input(t_app_context *app_state);
void		update_app_state(t_app_context *app_state);

void		draw_bar(int *colors, t_display *display, int offset);

void		ctoRGB(int color, int *r, int *g, int *b);

int			clerp(int color1, int color2, int t, int tmax);
void		grad_lerp(int *colors, int start, int end, int tmax, int offset);

void		create_gradient(int *dest, int curve_amount, clerps *lerp_info);

void		grad_gauss(int *colors, integer height, integer center, integer width);

// void		itow(int n, SDL_Rect dest, t_display *dislay);

#endif
