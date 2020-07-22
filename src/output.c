/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:52:34 by home              #+#    #+#             */
/*   Updated: 2020/07/22 01:02:54 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

#include <unistd.h>

void	generate_c_file(clerps *curves, int curve_count)
{
	int			i;
	int			fd;
	int			offset;
	const char *file_name;

	file_name = "clerp_control_flow.c";

	remove(file_name);
	usleep(100);
	fd = open(file_name, O_RDWR | O_CREAT);


	dprintf(fd, "void	set_color(int val, int *r, int *g, int *b)\n");
	dprintf(fd, "{\n");
	dprintf(fd, "	int result;\n");
	dprintf(fd, "\n");
	dprintf(fd, "	result = 0;\n");

	i = 1;
	offset = curves[0].start;
	dprintf(fd, "	if (val < %d)\n", curves[1].start);
	dprintf(fd, "		result = clerp(0x%.6X, 0x%.6X, val - %d, %d);\n", curves[0].s_color, curves[1].s_color, curves[0].start, curves[1].start);
	while (i < curve_count)
	{
		dprintf(fd, "	else if (val < %d)\n", curves[i + 1].start);
		dprintf(fd, "		result = clerp(0x%.6X, 0x%.6X, val - %d, %d);\n", curves[i].s_color, curves[i + 1].s_color, curves[i].start, curves[i + 1].start - curves[i].start);
		offset += curves[i].start;
		i++;
	}

	dprintf(fd, "	ctoRGB(result, r, g, b);\n");
	dprintf(fd, "}\n");

	(void)curve_count;
	(void)curves;
}

