/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/21 16:58:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	app_context_initialize(t_app_context *app_state, t_display *display)
{
	app_state->active = true;
	app_state->app_over = false;

	app_state->min = 0;
	app_state->max = 100;

	app_state->capacity = 10;
	app_state->at = 0;

	app_state->curves = calloc(sizeof(*(app_state->curves)), app_state->capacity);

	app_state->gradient = calloc(sizeof(*(app_state->gradient)), BAR_WIDTH);

	(void)display;
}

int	main(void)
{
	t_display		display;
	t_app_context	app_state;

	SDLU_start(&display);
	app_context_initialize(&app_state, &display);
	// memset(app_state.gradient, 255, sizeof(*(app_state.gradient)) * BAR_WIDTH);


	while (app_state.active == true)
	{
		process_user_input(&app_state);

		update_app_state(&app_state);

		grad_lerp(app_state.gradient, 0xFF0000, 0x33FF00, 100, 0);
		grad_lerp(app_state.gradient, 0x33FF00, 0x00FF00, 100, 100);

		grad_lerp(app_state.gradient, 0x00FF00, 0x00FFFF, 100, 200);
		// grad_lerp(app_state.gradient, 0x000000, 0x00FF00, 100, 100);
		draw_bar(app_state.gradient, &display, 0);


		// grad_gauss(app_state.gradient, 255, 0, 170);
		// draw_bar(app_state.gradient, &display, 50);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

	}
	SDLU_close(&display);
	return (0);
}
