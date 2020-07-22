/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgauss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:16:13 by home              #+#    #+#             */
/*   Updated: 2020/07/21 16:58:01 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int		cgauss_(gaussian_restraints curve, int x)
{
	int		i;
	double	result;
	int		numer;
	int		denom;

	i = 0;
	result = curve.height;
	denom = 2 * (curve.width) * (curve.width);
	numer = -1 * (x - curve.center) * (x - curve.center);
	if (numer / denom > 0)
	{
		while (i < numer / denom)
		{
			result *= 2;
			i++;
		}
	}
	else
	{
		while (i > numer / denom)
		{
			result /= 2;
			i--;
		}
	}
	return (result);
}

int		cgauss(gaussian_restraints curve, int x)
{
	double	numer;
	double	denom;
	double	result;

	denom = 2 * (curve.width) * (curve.width);
	numer = -1 * (x - curve.center) * (x - curve.center);
	result = pow(2, numer / denom) * curve.height;

	return ((int)result);
}

void	grad_gauss(int *colors, integer height, integer center, integer width)
{
	int					i;
	gaussian_restraints curve;
	int					r;

	i = 0;
	curve.height = height;
	curve.center = center;
	curve.width = width;
	while (i < BAR_WIDTH)
	{
		r = cgauss(curve, i);
		colors[i] = r << 16;
		i++;
	}
}
