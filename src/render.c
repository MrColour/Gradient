/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2021/01/09 17:16:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	draw_bar(int *colors, t_display *display, int offset)
{
	int	col;
	int	x;
	int	y;

	int	r;
	int	g;
	int	b;

	col = 0;
	x = BAR_LOC_SX;
	y = BAR_LOC_SY + offset;
	while (col < BAR_WIDTH)
	{
		ctoRGB(colors[col], &r, &g, &b);
		SDL_SetRenderDrawColor(display->renderer, r, g, b, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(display->renderer, x, y, x, y + BAR_HEIGHT);
		col++;
		x++;
	}
	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	(void)colors;
}
