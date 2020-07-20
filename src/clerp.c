/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clerp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 03:20:28 by home              #+#    #+#             */
/*   Updated: 2020/07/20 03:56:08 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

/**
* \brief Linear interpolates between min and max
* \param min the min value
* \param max the max value
* \param t propotion of interpolation, value between 0 and tmax
* \param tmax the max value t can take
*
* \brief
* Does not handle overflow or underflows well. BEWARE!
*/
integer	lerp(integer min, integer max, int t, int tmax)
{
	return (min + ((max - min) * t) / tmax);
}

int		clerp(int color1, int color2, int t, int tmax)
{
	int	r1;
	int	g1;
	int	b1;

	int	r2;
	int	g2;
	int	b2;

	int	r_res;
	int	g_res;
	int	b_res;

	int result;

	ctoRGB(color1, &r1, &g1, &b1);
	ctoRGB(color2, &r2, &g2, &b2);

	r_res = lerp(r1, r2, t, tmax);
	g_res = lerp(g1, g2, t, tmax);
	b_res = lerp(b1, b2, t, tmax);

	result = 0;
	result = (r_res << 16) |  (g_res <<  8) | (b_res <<  0);
	return (result);
}

void	grad_lerp(int *colors, int start, int end)
{
	int	i;

	i = 0;
	while (i < BAR_WIDTH)
	{
		colors[i] = clerp(start, end, i, BAR_WIDTH);
		i++;
	}
}
