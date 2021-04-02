/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2021/01/09 17:51:39 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int			clerp_sort(const void *ptr1, const void *ptr2)
{
	const clerps	*clerp1;
	const clerps	*clerp2;

	clerp1 = ptr1;
	clerp2 = ptr2;

	if (clerp1->start > clerp2->start)
		return (1);
	else
		return (0);
}

void		update_app_state(t_app_context *app_state)
{
	qsort(app_state->curves, app_state->curve_count, sizeof(*app_state->curves), clerp_sort);

	create_gradient(app_state->gradient, app_state->curve_count, app_state->curves);
}
