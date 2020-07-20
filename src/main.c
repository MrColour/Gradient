/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/19 02:00:55 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	app_context_initialize(t_app_context *app_state, t_display *display)
{
	app_state->active = true;

	app_state->app_over = false;

	(void)display;
}

int	main(void)
{
	t_display		display;
	t_app_context	app_state;

	SDLU_start(&display);
	app_context_initialize(&app_state, &display);
	while (app_state.active == true)
	{
		process_user_input(&app_state);

		update_app_state(&app_state);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

	}
	SDLU_close(&display);
	return (0);
}
